#pragma once
#include "CalcSeed.h"
#include <random>
#include <math.h>
struct coords
{
	__int64
		x,
		y,
		z;
};
class Object
{
private:
	Object* parent;
protected:
	uc	pSeed[32],
		*mySeed;
	std::linear_congruential_engine<u64, 6364136223846793005
		, 1442695040888963407, 18446744073709551615> lce;
	Object(int64_t, int64_t, int64_t, uc*, u8, Object* parent = NULL);
	u64 mySeedToNum();
public:
	static long double dRand(long double dMin, long double dMax, u64 randomNum)
	{
		long double saveValue = dMin;
		if (dMin < 0)
		{
			dMax -= dMin;
			dMin -= dMin;
		}
		u64 from = u64(1000000000000000 * dMin);
		u64 to = u64(1000000000000000 * dMax);
		uint64_t returnValue = from + (randomNum % ((to == 0) ? 1 : to));
		long double returnValue1 = (long double)(returnValue) / 1000000000000000;
		if (saveValue<0)
			returnValue1 += saveValue;
		return returnValue1;
	}
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
	}
};
class Star : public Object
{
private:
	u8 myType;
	long double 
		myMass,			// in Solar masses
		myRadius,		// in kms
		myLuminosity;	// in Solar Luminosities
public:
	long double Mass();
	long double Radius();
	long double Luminosity();
	long double Type();

	long double CalculateOrbitalSpeed(long double, long double, long double);
	long double CalculateOrbitalSpeed(long double, long double, long double, long double);
	Star(uc*, Object*);
};
struct Orbit
{
	const long double
		Major_Semiaxis,	// in light seconds
		Minor_Semiaxis,	// in light seconds
		Focal_Length,	// in light seconds
		eccentricity;

	Orbit(long double MaSMin, long double MiSMin, u64 random1, u64 random2, u64 random3)
		: Major_Semiaxis(Object::dRand(MaSMin, MaSMin + (MaSMin / 10), random1)),
		Minor_Semiaxis(Object::dRand(MiSMin, MiSMin + (MiSMin / 10), random1)),
		Focal_Length(Object::dRand(Major_Semiaxis * 0.5, Major_Semiaxis * 0.55, random3)),
		eccentricity(Focal_Length/Major_Semiaxis)
	{
		
	}
};
class Planet : public Object
{
private:
	long double
		myMass,		// in Earth masses
		myRadius;	// in kms
	Orbit myOrbit;
	long double MyCoords; // angle (1-360)
public:
	long double Mass();
	long double Radius();
	long double	Now_Coords();
	Orbit GetOrbit();
	Planet(long double MaSMin, long double MiSMin, uc* seed, Object* parent);
};
class StarSystem : public Object
{
private:
	u8	planetNum=0,
		sNum=1;
	Star* starPtr;
public:
	Planet ** Planets;
	u8 getPlanetNum();
	u8 getSNum();
	StarSystem(int64_t, int64_t, int64_t, uc*);
};