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
	// returns distance in light seconds
	long double ToLS()
	{
		return distance;
	}
	// returns distance in meters
	long double ToMeters()
	{
		return distance * _LightSpeedConst;
	}
	//Distance to Light Seconds
	static long double ToLS(Distance dist)
	{
		return dist.distance;
	}
	//Distance to meters
	static long double ToMeters(Distance dist)
	{
		return dist.distance * _LightSpeedConst;
	}
	//Meters to light seconds
	static long double MToLS(long double meters)
	{
		return meters / _LightSpeedConst;
	}
	//Light seconds to meters
	static long double LSToM(long double LightSeconds)
	{
		return LightSeconds * _LightSpeedConst;
	}
	Distance()
	{
		distance = 0;
	}
	template<typename T>	Distance(T _Value)
	{
		distance = MToLS(_Value);
	}
	template<typename T>	Distance		operator=(T _Value)
	{
		distance = _Value;
		return (*this);
	}
	template<typename T>	Distance		operator+(T _Value)
	{
		Distance ReturnValue;
		ReturnValue.distance = distance;
		ReturnValue += _Value;
		return ReturnValue;
	}
	template<typename T>	Distance		operator-(T _Value)
	{
		Distance ReturnValue;
		ReturnValue.distance = distance;
		ReturnValue -= _Value;
		return ReturnValue;
	}
	template<typename T>	Distance		operator*(T _Value)
	{
		Distance ReturnValue;
		ReturnValue.distance = distance;
		ReturnValue *= _Value;
		return ReturnValue;
	}
	template<typename T>	Distance		operator/(T _Value)
	{
		Distance ReturnValue;
		ReturnValue.distance = distance;
		ReturnValue /= _Value;
		return ReturnValue;
	}
	template<typename T>	bool			operator==(T _Value)
	{
		return distance == MToLS(_Value);
	}
	template<typename T>	bool			operator>=(T _Value)
	{
		return distance >= MToLS(_Value);
	}
	template<typename T>	bool			operator<=(T _Value)
	{
		return distance <= MToLS(_Value);
	}
	template<typename T>	bool			operator!=(T _Value)
	{
		return distance != MToLS(_Value);
	}
	template<typename T>	bool			operator>(T _Value)
	{
		return distance > MToLS(_Value);
	}
	template<typename T>	bool			operator<(T _Value)
	{
		return distance < MToLS(_Value);
	}
	template<typename T>	Distance&		operator+=(T _Value)
	{
		distance += MToLS(_Value);
		return (*this);
	}
	template<typename T>	Distance&		operator-=(T _Value)
	{
		distance -= MToLS(_Value);
		return (*this);
	}
	template<typename T>	Distance&		operator*=(T _Value)
	{
		distance *= MToLS(_Value);
		return (*this);
	}
	template<typename T>	Distance&		operator/=(T _Value)
	{
		distance /= MToLS(_Value);
		return (*this);
	}
	Distance*								operator=(Distance _Value)
	{
		distance = _Value.distance;
		return this;
	}
	Distance								operator+(Distance _Value)
	{
		_Value += distance;
		return _Value;
	}
	Distance								operator-(Distance _Value)
	{
		_Value -= distance;
		return _Value;
	}
	Distance								operator*(Distance _Value)
	{
		_Value *= distance;
		return _Value;
	}
	Distance								operator/(Distance _Value)
	{
		_Value /= distance;
		return _Value;
	}
	bool									operator==(Distance  _Value)
	{
		return distance == _Value.distance;
	}
	bool									operator<=(Distance  _Value)
	{
		return distance <= _Value.distance;
	}
	bool									operator>=(Distance  _Value)
	{
		return distance >= _Value.distance;
	}
	bool									operator<(Distance  _Value)
	{
		return distance < _Value.distance;
	}
	bool									operator>(Distance  _Value)
	{
		return distance > _Value.distance;
	}
	bool									operator!=(Distance  _Value)
	{
		return distance != _Value.distance;
	}
	Distance&								operator+=(Distance _Value)
	{
		distance += _Value.distance;
		return (*this);
	}
	Distance&								operator-=(Distance _Value)
	{
		distance -= _Value.distance;
		return (*this);
	}
	Distance&								operator*=(Distance _Value)
	{
		distance *= _Value.distance;
		return (*this);
	}
	Distance&								operator/=(Distance _Value)
	{
		distance /= _Value.distance;
		return (*this);
	}
	long double								operator()()
	{
		return LSToM(distance);
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
	long double SMass()
	{
		return mass;
	}
	// returns mass in KGs
	long double KGs()
	{
		return mass * _SolarStarMassConst;
	}
	//KGs to solar masses
	static long double KGToSSM(long double KGs)
	{
		return KGs / _SolarStarMassConst;
	}
	//Solar masses to kgs
	static long double SSMToKGs(long double StarMass)
	{
		return StarMass * _SolarStarMassConst;
	}
	StarMass()
	{
		mass = 0;
	}
	template<typename T>	StarMass(T _Value)
	{
		mass = KGToSSM(_Value);
	}
	template<typename T>	StarMass*		operator=(T _Value)
	{
		mass = _Value;
		return this;
	}
	template<typename T>	StarMass		operator+(T _Value)
	{
		StarMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue += KGToSSM(_Value);
		return ReturnValue;
	}
	template<typename T>	StarMass		operator-(T _Value)
	{
		StarMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue -= KGToSSM(_Value);
		return ReturnValue;
	}
	template<typename T>	StarMass		operator*(T _Value)
	{
		StarMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue *= KGToSSM(_Value);
		return ReturnValue;
	}
	template<typename T>	StarMass		operator/(T _Value)
	{
		StarMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue /= KGToSSM(_Value);
		return ReturnValue;
	}
	template<typename T>	bool			operator==(T _Value)
	{
		return mass == KGToSSM(_Value);
	}
	template<typename T>	bool			operator>=(T _Value)
	{
		return mass >= KGToSSM(_Value);
	}
	template<typename T>	bool			operator<=(T _Value)
	{
		return mass <= KGToSSM(_Value);
	}
	template<typename T>	bool			operator!=(T _Value)
	{
		return mass != KGToSSM(_Value);
	}
	template<typename T>	bool			operator>(T _Value)
	{
		return mass > KGToSSM(_Value);
	}
	template<typename T>	bool			operator<(T _Value)
	{
		return mass < KGToSSM(_Value);
	}
	template<typename T>	StarMass&		operator+=(T _Value)
	{
		mass += KGToSSM(_Value);
		return (*this);
	}
	template<typename T>	StarMass&		operator-=(T _Value)
	{
		mass -= KGToSSM(_Value);
		return (*this);
	}
	template<typename T>	StarMass&		operator*=(T _Value)
	{
		mass *= KGToSSM(_Value);
		return (*this);
	}
	template<typename T>	StarMass&		operator/=(T _Value)
	{
		mass /= KGToSSM(_Value);
		return (*this);
	}
	StarMass*								operator=(StarMass _Value)
	{
		mass = _Value.mass;
		return this;
	}
	StarMass								operator+(StarMass _Value)
	{
		_Value += mass;
		return _Value;
	}
	StarMass								operator-(StarMass _Value)
	{
		_Value -= mass;
		return _Value;
	}
	StarMass								operator*(StarMass _Value)
	{
		_Value *= mass;
		return _Value;
	}
	StarMass								operator/(StarMass _Value)
	{
		_Value /= mass;
		return _Value;
	}
	bool									operator==(StarMass  _Value)
	{
		return mass == _Value.mass;
	}
	bool									operator<=(StarMass  _Value)
	{
		return mass <= _Value.mass;
	}
	bool									operator>=(StarMass  _Value)
	{
		return mass >= _Value.mass;
	}
	bool									operator<(StarMass  _Value)
	{
		return mass < _Value.mass;
	}
	bool									operator>(StarMass  _Value)
	{
		return mass > _Value.mass;
	}
	bool									operator!=(StarMass  _Value)
	{
		return mass != _Value.mass;
	}
	StarMass&								operator+=(StarMass _Value)
	{
		mass += _Value.mass;
		return (*this);
	}
	StarMass&								operator-=(StarMass _Value)
	{
		mass -= _Value.mass;
		return (*this);
	}
	StarMass&								operator*=(StarMass _Value)
	{
		mass *= _Value.mass;
		return (*this);
	}
	StarMass&								operator/=(StarMass _Value)
	{
		mass /= _Value.mass;
		return (*this);
	}
	long double								operator()()
	{
		return SSMToKGs(mass);
	}
}; 
class PlanetMass
{
protected:
	long double mass;// in earth masses
public:
	operator long double() const
	{
		return mass;
	}
	// returns mass in earth masses
	long double EMass()
	{
		return mass;
	}
	// returns mass in KGs
	long double KGs()
	{
		return mass * _EarthPlanetMassConst;
	}
	// kgs to earth masses
	static long double KGsToEM(long double mass)
	{
		return mass / _EarthPlanetMassConst;
	}
	// earth masses to kgs
	static long double EMToKGs(long double mass)
	{
		return mass * _EarthPlanetMassConst;
	}
	PlanetMass()
	{
		mass = 0;
	}
	template<typename T>	PlanetMass(T _Value)
	{
		mass = KGsToEM(_Value);
	}
	template<typename T>	PlanetMass*		operator=(T _Value)
	{
		mass = _Value;
		return this;
	}
	template<typename T>	PlanetMass		operator+(T _Value)
	{
		PlanetMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue += KGsToEM(_Value);
		return ReturnValue;
	}
	template<typename T>	PlanetMass		operator-(T _Value)
	{
		PlanetMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue -= KGsToEM(_Value);
		return ReturnValue;
	}
	template<typename T>	PlanetMass		operator*(T _Value)
	{
		PlanetMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue *= KGsToEM(_Value);
		return ReturnValue;
	}
	template<typename T>	PlanetMass		operator/(T _Value)
	{
		PlanetMass ReturnValue;
		ReturnValue.mass = mass;
		ReturnValue /= KGsToEM(_Value);
		return ReturnValue;
	}
	template<typename T>	bool			operator==(T _Value)
	{
		return mass == KGsToEM(_Value);
	}
	template<typename T>	bool			operator>=(T _Value)
	{
		return mass >= KGsToEM(_Value);
	}
	template<typename T>	bool			operator<=(T _Value)
	{
		return mass <= KGsToEM(_Value);
	}
	template<typename T>	bool			operator!=(T _Value)
	{
		return mass != KGsToEM(_Value);
	}
	template<typename T>	bool			operator>(T _Value)
	{
		return mass > KGsToEM(_Value);
	}
	template<typename T>	bool			operator<(T _Value)
	{
		return mass < KGsToEM(_Value);
	}
	template<typename T>	PlanetMass&		operator+=(T _Value)
	{
		mass += KGsToEM(_Value);
		return (*this);
	}
	template<typename T>	PlanetMass&		operator-=(T _Value)
	{
		mass -= KGsToEM(_Value);
		return (*this);
	}
	template<typename T>	PlanetMass&		operator*=(T _Value)
	{
		mass *= KGsToEM(_Value);
		return (*this);
	}
	template<typename T>	PlanetMass&		operator/=(T _Value)
	{
		mass /= KGsToEM(_Value);
		return (*this);
	}
	PlanetMass*								operator=(PlanetMass _Value)
	{
		mass = _Value.mass;
		return this;
	}
	PlanetMass								operator+(PlanetMass _Value)
	{
		_Value += mass;
		return _Value;
	}
	PlanetMass								operator-(PlanetMass _Value)
	{
		_Value -= mass;
		return _Value;
	}
	PlanetMass								operator*(PlanetMass _Value)
	{
		_Value *= mass;
		return _Value;
	}
	PlanetMass								operator/(PlanetMass _Value)
	{
		_Value /= mass;
		return _Value;
	}
	bool									operator==(PlanetMass  _Value)
	{
		return mass == _Value.mass;
	}
	bool									operator<=(PlanetMass  _Value)
	{
		return mass <= _Value.mass;
	}
	bool									operator>=(PlanetMass  _Value)
	{
		return mass >= _Value.mass;
	}
	bool									operator<(PlanetMass  _Value)
	{
		return mass < _Value.mass;
	}
	bool									operator>(PlanetMass  _Value)
	{
		return mass > _Value.mass;
	}
	bool									operator!=(PlanetMass  _Value)
	{
		return mass != _Value.mass;
	}
	PlanetMass&								operator+=(PlanetMass _Value)
	{
		mass += _Value.mass;
		return (*this);
	}
	PlanetMass&								operator-=(PlanetMass _Value)
	{
		mass -= _Value.mass;
		return (*this);
	}
	PlanetMass&								operator*=(PlanetMass _Value)
	{
		mass *= _Value.mass;
		return (*this);
	}
	PlanetMass&								operator/=(PlanetMass _Value)
	{
		mass /= _Value.mass;
		return (*this);
	}
	long double								operator()()
	{
		return EMToKGs(mass);
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
	long double 
		myRadius,		// in kms
		myLuminosity;	// in Solar Luminosities
public:
	StarMass Mass();
	long double Radius();
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
		Major_Semiaxis.ToLS() * 0.30,
		Major_Semiaxis.ToLS() * 0.70, random3));
	eccentricity = Focal_Length.ToLS() / Major_Semiaxis.ToLS();
	}
};
class Planet : public Object
{
private:
	PlanetMass myMass;
	long double
		myRadius;	// in kms
	Orbit myOrbit;
	long double MyCoords; // angle (1-360)
public:
	PlanetMass Mass();
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