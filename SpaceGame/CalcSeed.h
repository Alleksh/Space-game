#pragma once
#include <string>
#define SHA256_BLOCK_SIZE   64
#define SHA256_DIGEST_SIZE  32// Seed size
namespace SHA2
{
	unsigned char* CalcXYZHash(int64_t, int64_t, int64_t, unsigned char[]);
	unsigned char* CalcHash(unsigned char[], unsigned long);
}