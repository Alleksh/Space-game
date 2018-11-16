#include "Object.h"
 void Object::getObjectSeed(uc* dest)
{
	memcpy(dest, mySeed, SEED_SIZE);
}
u64 Object::mySeedToNum()
{
	return SeedToNum(mySeed);
}
u64 Object::SeedToNum(uc* seed)
{
	u64 returnValue = 0;
	u64 len = sizeof(u64);
	int res = 0;
	for (int i = 0; i<len; i++)
	{
		res *= 256;
		res += seed[rand() % 32];
	}
	return returnValue;
}
Object::Object(int64_t x, int64_t y, int64_t z, uc *data)
{
	memcpy(pSeed, data, SEED_SIZE);
	mySeed = SHA2::CalcXYZHash(x, y, z, data);
	std::string str(reinterpret_cast<char const*>(mySeed), SEED_SIZE);
	std::seed_seq returnValue(str.begin(), str.end());
	lce.seed(returnValue);
}
bool getPChance(const u8 itr, u64 randomNum)
{
	if (itr > 32) return 0;
	else	
	{
		randomNum %= 9223372035781033984;
		u64 _v = u64((((long double)(1.0) / (itr + 2))
			* 2147483648))*u64(8589934591);
		return 	randomNum <_v;
	}
	return 1;
}
int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}
bool getSChance(const u8 itr, u64 randomNum)
{
	if (itr > 8) return 0;
	else
	{
		randomNum %= 9223372035781033984;
		u64 _v = u64((((long double)(1.0) / (factorial(itr + 3))) *
			2147483648))*u64(8589934591);
		return 	randomNum <_v;
	}
	return 1;
}
StarSystem::StarSystem(int64_t x, int64_t y, int64_t z, uc* seed) : Object(x, y, z, seed)
{
	while (getPChance(planetNum, lce())) planetNum++;
	while (getSChance(sNum, lce())) sNum++;
}