#include "CalcSeed.h"
#define SHA256_BLOCK_SIZE   0x40
#define SHA256_DIGEST_SIZE  0x20
static const double PrimalSqrt[8]
{
	0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
	0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
};

static const unsigned long int PrimalCbrt[64]
{
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};
struct sha256_ctx
{
	uint32_t count[2];
	uint32_t hash[8];
	uint32_t wbuf[16];
};

#define rotr32(x,n)   (((x) >> n) | ((x) << (32 - n)))
#define s_0(x)  (rotr32((x), 2) ^ rotr32((x), 13) ^ rotr32((x), 22))
#define s_1(x)  (rotr32((x),  6) ^ rotr32((x), 11) ^ rotr32((x), 25))
#define g_0(x)  (rotr32((x),  7) ^ rotr32((x), 18) ^ ((x) >>  3))
#define g_1(x)  (rotr32((x), 17) ^ rotr32((x), 19) ^ ((x) >> 10))
#define k_0     PrimalCbrt
#define vf(n,i) v[(n - i) & 7]
#define hf(i) (p[i & 15] += \
    g_1(p[(i + 14) & 15]) + p[(i + 9) & 15] + g_0(p[(i + 1) & 15]))
#define maj(x,y,z)      (((x) & (y)) | ((z) & ((x) ^ (y))))
#define ch(x,y,z)       ((z) ^ ((x) & ((y) ^ (z))))
#define v_cycle(i, j) \
		vf(7, i) += (j ? hf(i) : p[i]) + k_0[i + j] \
		+ s_1(vf(4, i)) + ch(vf(4, i), vf(5, i), vf(6, i)); \
		vf(3, i) += vf(7, i); \
		vf(7, i) += s_0(vf(0, i)) + maj(vf(0, i), vf(1, i), vf(2, i))

void sha256_compile(sha256_ctx ctx[1])
{

	uint32_t j, *p = ctx->wbuf, v[8];

	memcpy(v, ctx->hash, 8 * sizeof(uint32_t));

	for (j = 0; j < 64; j += 16)
	{
		v_cycle(0, j); v_cycle(1, j);
		v_cycle(2, j); v_cycle(3, j);
		v_cycle(4, j); v_cycle(5, j);
		v_cycle(6, j); v_cycle(7, j);
		v_cycle(8, j); v_cycle(9, j);
		v_cycle(10, j); v_cycle(11, j);
		v_cycle(12, j); v_cycle(13, j);
		v_cycle(14, j); v_cycle(15, j);
	}

	ctx->hash[0] += v[0]; ctx->hash[1] += v[1];
	ctx->hash[2] += v[2]; ctx->hash[3] += v[3];
	ctx->hash[4] += v[4]; ctx->hash[5] += v[5];
	ctx->hash[6] += v[6]; ctx->hash[7] += v[7];
}
#define SHA256_MASK (SHA256_BLOCK_SIZE - 1)
#define bswap_32(x) ((rotr32((x), 24) & 0x00ff00ff) | (rotr32((x), 8) & 0xff00ff00))
#define bsw_32(p,n) \
    { int _i = (n); while(_i--) ((uint32_t*)p)[_i] = bswap_32(((uint32_t*)p)[_i]); }


void sha256_hash(const unsigned char data[], unsigned long len, sha256_ctx ctx[1])
{
	uint32_t pos = (uint32_t)(ctx->count[0] & SHA256_MASK),
		space = SHA256_BLOCK_SIZE - pos;
	const unsigned char *sp = data;

	if ((ctx->count[0] += len) < len)
		++(ctx->count[1]);

	while (len >= space)     /* tranfer whole blocks while possible  */
	{
		memcpy(((unsigned char*)ctx->wbuf) + pos, sp, space);
		sp += space; len -= space; space = SHA256_BLOCK_SIZE; pos = 0;
		bsw_32(ctx->wbuf, SHA256_BLOCK_SIZE >> 2)
			sha256_compile(ctx);
	}

	memcpy(((unsigned char*)ctx->wbuf) + pos, sp, len);
}
void sha256_begin(sha256_ctx ctx[1])
{
	ctx->count[0] = ctx->count[1] = 0;
	memcpy(ctx->hash, PrimalSqrt, 8 * sizeof(uint32_t));
}

static void sha_end1(unsigned char hval[], sha256_ctx ctx[1], const unsigned int hlen)
{
	uint32_t    i = (uint32_t)(ctx->count[0] & SHA256_MASK);
	bsw_32(ctx->wbuf, (i + 3) >> 2)
		ctx->wbuf[i >> 2] &= 0xffffff80 << 8 * (~i & 3);
	ctx->wbuf[i >> 2] |= 0x00000080 << 8 * (~i & 3);
	if (i > SHA256_BLOCK_SIZE - 9)
	{
		if (i < 60) ctx->wbuf[15] = 0;
		sha256_compile(ctx);
		i = 0;
	}
	else i = (i >> 2) + 1;

	while (i < 14)
		ctx->wbuf[i++] = 0;
	ctx->wbuf[14] = (ctx->count[1] << 3) | (ctx->count[0] >> 29);
	ctx->wbuf[15] = ctx->count[0] << 3;
	sha256_compile(ctx);
	for (i = 0; i < hlen; ++i)
		hval[i] = (unsigned char)(ctx->hash[i >> 2] >> (8 * (~i & 3)));
}
void sha256(unsigned char hval[], const unsigned char data[], unsigned long len)
{
	sha256_ctx  cx[1];

	sha256_begin(cx);
	sha256_hash(data, len, cx);
	sha_end1(hval, cx, SHA256_DIGEST_SIZE);
}
#define len SHA256_DIGEST_SIZE
unsigned char* SHA2::CalcXYZHash(int64_t x, int64_t y, int64_t z,
	unsigned char seed[])
{
	std::string _Val = std::to_string(x) +
		std::to_string(y) +
		std::to_string(z);
	unsigned char* Val = new unsigned char[len + _Val.size()];
	for (unsigned int i = 0; i < len; i++)
		Val[i] = seed[i];
	for (unsigned int i = 0; i < _Val.size(); i++)
		Val[i + len] = _Val[i];
	auto ptr = SHA2::CalcHash(seed, len + _Val.size());
	delete Val;
	return ptr;
}
unsigned char* SHA2::CalcHash(unsigned char data[], unsigned long length)
{
	unsigned char *hval = new unsigned char[SHA256_DIGEST_SIZE];
	sha256(hval, data, length);
	return hval;
}


// undef useless macro
#undef SHA256_BLOCK_SIZE   
#undef SHA256_DIGEST_SIZE  