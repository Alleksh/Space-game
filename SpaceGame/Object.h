#pragma once
#include "CalcSeed.h"
#include <random>
#define SEED_SIZE 32
constexpr long double _Pi = 3.14159265358979323846264338327950288L;
constexpr long double _Exp1 = 2.71828182845904523536028747135266250L;
#define uc unsigned char
#define u8 uc
#define u16 unsigned short int
#define u32 unsigned int
#define u64 unsigned long long int
class Object
{
private:
	uc	pSeed[32],
		*mySeed;
protected:
	Object(int64_t, int64_t, int64_t, uc*);
	u64 mySeedToNum();
	std::linear_congruential_engine<u64, 6364136223846793005
		, 1442695040888963407, 18446744073709551615> lce;
public:
	static u64 SeedToNum(uc*);
	void getObjectSeed(uc*);
	Object()
	{
		throw  "This is a global class for descendants. You can't construct him without a descendant.";
	}
	~Object()
	{
		delete mySeed;
		~lce();
	}
};
class StarSystem : public Object
{
private:
	u8	planetNum=0,
		sNum=1;
public:
	u8 getPlanetNum()
	{
		return planetNum;
	}
	u8 getSNum()
	{
		return sNum;
	}
	StarSystem(int64_t x, int64_t y, int64_t z, uc* seed);
};