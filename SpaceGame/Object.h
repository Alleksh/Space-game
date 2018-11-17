#pragma once
#include "CalcSeed.h"
#include <random>

class Object
{
private:
	uc	pSeed[32],
		*mySeed;
	Object* parent;
protected:
	std::linear_congruential_engine<u64, 6364136223846793005
		, 1442695040888963407, 18446744073709551615> lce;
	Object(int64_t, int64_t, int64_t, uc*, u8, Object* parent = NULL);
	u64 mySeedToNum();
	virtual void setParameters(u32*);
public:
	const u8 ObjectType;
	static u64 SeedToNum(uc*);
	void getObjectSeed(uc*);
	Object() : ObjectType(0xFF) // __ERR_UNKNOWN_OBJ
	{
		throw  "This is a global class for descendants. You can't construct him without a descendant.";
	}
	~Object()
	{
		delete mySeed;
		~lce();
	}
};
class Star : public Object
{
private:
	u8 sNum = 1;
	Object* objects;
public:
	Star(int64_t, uc*, Object*);
};
class Planet : public Object
{
private:
	Object* objects;
public:
	Planet(int64_t, int64_t, int64_t, uc*, Object*);
};
class StarSystem : public Object
{
private:
	u8	planetNum=0,
		sNum=1;
	Object* objects;
public:
	u8 getPlanetNum();
	u8 getSNum();
	StarSystem(int64_t, int64_t, int64_t, uc*);
};