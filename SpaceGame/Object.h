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
class Distance	
{
protected:
	long double distance;// in light seconds
public:
	operator long double() const
	{
		return distance;
	}
	Distance();
	template<typename T>	Distance(T _Value);
	// returns distance in light seconds
	long double ToLS();
	// returns distance in meters
	long double ToMeters();
	//Distance to Light Seconds
	static long double ToLS(Distance dist);
	//Distance to meters
	static long double ToMeters(Distance dist);
	//Meters to light seconds
	static long double MToLS(long double meters);
	//Light seconds to meters
	static long double LSToM(long double LightSeconds);
	template<typename T>	Distance		operator+(T _Value);
	template<typename T>	Distance		operator-(T _Value);
	template<typename T>	Distance		operator*(T _Value);
	template<typename T>	Distance		operator/(T _Value);
	template<typename T>	Distance&		operator+=(T _Value);
	template<typename T>	Distance&		operator-=(T _Value);
	template<typename T>	Distance&		operator*=(T _Value);
	template<typename T>	Distance&		operator/=(T _Value);
	template<typename T>	bool			operator==(T _Value);
	template<typename T>	bool			operator>=(T _Value);
	template<typename T>	bool			operator<=(T _Value);
	template<typename T>	bool			operator!=(T _Value);
	template<typename T>	bool			operator>(T _Value);
	template<typename T>	bool			operator<(T _Value);
	Distance*								operator=(Distance _Value);
	Distance								operator+(Distance _Value);
	Distance								operator-(Distance _Value);
	Distance								operator*(Distance _Value);
	Distance								operator/(Distance _Value);
	bool									operator==(Distance  _Value);
	bool									operator<=(Distance  _Value);
	bool									operator>=(Distance  _Value);
	bool									operator<(Distance  _Value);
	bool									operator>(Distance  _Value);
	bool									operator!=(Distance  _Value);
	Distance&								operator+=(Distance _Value);
	Distance&								operator-=(Distance _Value);
	Distance&								operator*=(Distance _Value);
	Distance&								operator/=(Distance _Value);
	template<typename T>	Distance		operator=(T _Value)
	{
		distance = _Value;
		return (*this);
	}
	long double								operator()()
	{
		return distance;
	}
};
class StarMass
{
protected:
	long double mass;// in solar masses
public:
	operator long double() const
	{
		return mass;
	}
	// returns mass in solar masses
	long double SMass();
	// returns mass in KGs
	long double KGs();
	//KGs to solar masses
	static long double KGToSSM(long double KGs);
	//Solar masses to kgs
	static long double SSMToKGs(long double StarMass);
	StarMass();
	template<typename T>	StarMass(T _Value);
	template<typename T>	StarMass		operator+(T _Value);
	template<typename T>	StarMass		operator-(T _Value);
	template<typename T>	StarMass		operator*(T _Value);
	template<typename T>	StarMass		operator/(T _Value);
	template<typename T>	bool			operator==(T _Value);
	template<typename T>	bool			operator>=(T _Value);
	template<typename T>	bool			operator<=(T _Value);
	template<typename T>	bool			operator!=(T _Value);
	template<typename T>	bool			operator>(T _Value);
	template<typename T>	bool			operator<(T _Value);
	template<typename T>	StarMass&		operator+=(T _Value);
	template<typename T>	StarMass&		operator-=(T _Value);
	template<typename T>	StarMass&		operator*=(T _Value);
	template<typename T>	StarMass&		operator/=(T _Value);
	StarMass*								operator=(StarMass _Value);
	StarMass								operator+(StarMass _Value);
	StarMass								operator-(StarMass _Value);
	StarMass								operator*(StarMass _Value);
	StarMass								operator/(StarMass _Value);
	bool									operator==(StarMass  _Value);
	bool									operator<=(StarMass  _Value);
	bool									operator>=(StarMass  _Value);
	bool									operator<(StarMass  _Value);
	bool									operator>(StarMass  _Value);
	bool									operator!=(StarMass  _Value);
	StarMass&								operator+=(StarMass _Value);
	StarMass&								operator-=(StarMass _Value);
	StarMass&								operator*=(StarMass _Value);
	StarMass&								operator/=(StarMass _Value);
	template<typename T>	StarMass*		operator=(T _Value)
	{
		mass = _Value;
		return this;
	}
	long double								operator()()
	{
		return mass;
	}
}; 
class PlanetMass
{
protected:
	long double mass;// in earth masses
public:
	// returns mass in earth masses
	long double EMass();
	// returns mass in KGs
	long double KGs();
	// kgs to earth masses
	static long double KGsToEM(long double mass);
	// earth masses to kgs
	static long double EMToKGs(long double mass);
	PlanetMass();
	template<typename T>	PlanetMass(T _Value);
	template<typename T>	PlanetMass		operator+(T _Value);
	template<typename T>	PlanetMass		operator-(T _Value);
	template<typename T>	PlanetMass		operator*(T _Value);
	template<typename T>	PlanetMass		operator/(T _Value);
	template<typename T>	bool			operator==(T _Value);
	template<typename T>	bool			operator>=(T _Value);
	template<typename T>	bool			operator<=(T _Value);
	template<typename T>	bool			operator!=(T _Value);
	template<typename T>	bool			operator>(T _Value);
	template<typename T>	bool			operator<(T _Value);
	template<typename T>	PlanetMass&		operator+=(T _Value);
	template<typename T>	PlanetMass&		operator-=(T _Value);
	template<typename T>	PlanetMass&		operator*=(T _Value);
	template<typename T>	PlanetMass&		operator/=(T _Value);
	PlanetMass*								operator=(PlanetMass _Value);
	PlanetMass								operator+(PlanetMass _Value);
	PlanetMass								operator-(PlanetMass _Value);
	PlanetMass								operator*(PlanetMass _Value);
	PlanetMass								operator/(PlanetMass _Value);
	bool									operator==(PlanetMass  _Value);
	bool									operator<=(PlanetMass  _Value);
	bool									operator>=(PlanetMass  _Value);
	bool									operator<(PlanetMass  _Value);
	bool									operator>(PlanetMass  _Value);
	bool									operator!=(PlanetMass  _Value);
	PlanetMass&								operator+=(PlanetMass _Value);
	PlanetMass&								operator-=(PlanetMass _Value);
	PlanetMass&								operator*=(PlanetMass _Value);
	PlanetMass&								operator/=(PlanetMass _Value);
	template<typename T>	PlanetMass*		operator=(T _Value)
	{
		mass = _Value;
		return this;
	}
	long double								operator()()
	{
		return mass;
	}
	operator long double() const
	{
		return mass;
	}
};
namespace Calculation
{
	//https://ru.wikipedia.org/wiki/%D0%9E%D1%80%D0%B1%D0%B8%D1%82%D0%B0%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D1%81%D0%BA%D0%BE%D1%80%D0%BE%D1%81%D1%82%D1%8C
	long double CalculateOrbitalSpeed(StarMass sMass, PlanetMass pMass, Distance dist, Distance major_semiaxis);
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
	StarMass myMass;
	Distance myRadius;
	long double 
		myLuminosity;	// in Solar Luminosities
public:
	StarMass Mass();
	Distance Radius();
	long double Luminosity();
	long double Type();
	Star(uc*, Object*);
};
struct Orbit
{	
	Distance
		Major_Semiaxis,
		Minor_Semiaxis,	
		Focal_Length;	
	long double	eccentricity;

	Orbit(long double MaSMin, long double MiSMin, u64 random1, u64 random2, u64 random3)
	{
		Major_Semiaxis	= (Object::dRand(MaSMin, MaSMin + (MaSMin / 10), random1));
		Minor_Semiaxis	= (Object::dRand(MiSMin, MiSMin + (MiSMin / 10), random1));
		Focal_Length	= (Object::dRand(
			Major_Semiaxis * 0.30,
			Major_Semiaxis * 0.70, random3));
		eccentricity = Focal_Length / Major_Semiaxis;
	}
};
class Planet : public Object
{
private:
	PlanetMass	myMass;
	Distance	myRadius;	
	Orbit		myOrbit;
	long double MyCoords; // angle (1-360)
public:
	PlanetMass Mass();
	Distance  Radius();
	long double	Now_Coords();
	Orbit GetOrbit();
	Planet(long double MaSMin, long double MiSMin, uc* seed, Object* parent);
};
class StarSystem : public Object
{
private:
	u8	planetNum=0,
		sNum=1;
public:
	Star * starPtr;
	Planet ** Planets;
	u8 getPlanetNum();
	u8 getSNum();
	StarSystem(int64_t, int64_t, int64_t, uc*);
};