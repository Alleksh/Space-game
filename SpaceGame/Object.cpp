#include "Object.h"
//Object types
//define useful macro
#define __ERR_UNKNOWN_OBJ	0xFF
#define __UNIVERSE			0x0
#define __GALAXY_CLUSTER	0x1
#define __GALAXY			0x2
#define __STAR_SYSTEM		0x3
#define __STARS				0x4
#define __PLANET			0x5
#define SEED_SIZE			0x20
#if 1
Distance::Distance()
{
	distance = 0;
}
template<typename T>	Distance::Distance(T _Value)
{
	distance = _Value;
}
long double Distance::ToLS()
{
	return distance;
}
long double Distance::ToMeters()
{
	return distance * _LightSpeedConst;
}
long double Distance::ToLS(Distance dist)
{
	return dist.distance;
}
long double Distance::ToMeters(Distance dist)
{
	return dist.distance * _LightSpeedConst;
}
long double Distance::MToLS(long double meters)
{
	return meters / _LightSpeedConst;
}
long double Distance::LSToM(long double LightSeconds)
{
	return LightSeconds * _LightSpeedConst;
}
template<typename T>	Distance		Distance::operator+(T _Value)
{
	Distance ReturnValue;
	ReturnValue.distance = distance;
	ReturnValue += _Value;
	return ReturnValue;
}
template<typename T>	Distance		Distance::operator-(T _Value)
{
	Distance ReturnValue;
	ReturnValue.distance = distance;
	ReturnValue -= _Value;
	return ReturnValue;
}
template<typename T>	Distance		Distance::operator*(T _Value)
{
	Distance ReturnValue;
	ReturnValue.distance = distance;
	ReturnValue *= _Value;
	return ReturnValue;
}
template<typename T>	Distance		Distance::operator/(T _Value)
{
	Distance ReturnValue;
	ReturnValue.distance = distance;
	ReturnValue /= _Value;
	return ReturnValue;
}
template<typename T>	Distance&		Distance::operator+=(T _Value)
{
	distance += _Value;
	return (*this);
}
template<typename T>	Distance&		Distance::operator-=(T _Value)
{
	distance -= _Value;
	return (*this);
}
template<typename T>	Distance&		Distance::operator*=(T _Value)
{
	distance *= _Value;
	return (*this);
}
template<typename T>	Distance&		Distance::operator/=(T _Value)
{
	distance /= _Value;
	return (*this);
}
template<typename T>	bool			Distance::operator==(T _Value)
{
	return distance == _Value;
}
template<typename T>	bool			Distance::operator>=(T _Value)
{
	return distance >= _Value;
}
template<typename T>	bool			Distance::operator<=(T _Value)
{
	return distance <= _Value;
}
template<typename T>	bool			Distance::operator!=(T _Value)
{
	return distance != _Value;
}
template<typename T>	bool			Distance::operator>(T _Value)
{
	return distance >_Value;
}
template<typename T>	bool			Distance::operator<(T _Value)
{
	return distance < _Value;
}
Distance*								Distance::operator=(Distance _Value)
{
	distance = _Value.distance;
	return this;
}
Distance								Distance::operator+(Distance _Value)
{
	_Value += distance;
	return _Value;
}
Distance								Distance::operator-(Distance _Value)
{
	_Value -= distance;
	return _Value;
}
Distance								Distance::operator*(Distance _Value)
{
	_Value *= distance;
	return _Value;
}
Distance								Distance::operator/(Distance _Value)
{
	_Value /= distance;
	return _Value;
}
bool									Distance::operator==(Distance  _Value)
{
	return distance == _Value.distance;
}
bool									Distance::operator<=(Distance  _Value)
{
	return distance <= _Value.distance;
}
bool									Distance::operator>=(Distance  _Value)
{
	return distance >= _Value.distance;
}
bool									Distance::operator<(Distance  _Value)
{
	return distance < _Value.distance;
}
bool									Distance::operator>(Distance  _Value)
{
	return distance > _Value.distance;
}
bool									Distance::operator!=(Distance  _Value)
{
	return distance != _Value.distance;
}
Distance&								Distance::operator+=(Distance _Value)
{
	distance += _Value.distance;
	return (*this);
}
Distance&								Distance::operator-=(Distance _Value)
{
	distance -= _Value.distance;
	return (*this);
}
Distance&								Distance::operator*=(Distance _Value)
{
	distance *= _Value.distance;
	return (*this);
}
Distance&								Distance::operator/=(Distance _Value)
{
	distance /= _Value.distance;
	return (*this);
}
#endif // Distance funcs
#if 1
StarMass::StarMass()
{
	mass = 0;
}
template<typename T>	
StarMass::StarMass(T _Value)
{
	mass = _Value;
}
long double StarMass::SMass()
{
	return mass;
}
long double StarMass::KGs()
{
	return mass * _SolarStarMassConst;
}
long double StarMass::KGToSSM(long double KGs)
{
	return KGs / _SolarStarMassConst;
}
long double StarMass::SSMToKGs(long double StarMass)
{
	return StarMass * _SolarStarMassConst;
}
template<typename T>	StarMass		StarMass::operator+(T _Value)
{
	StarMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue += KGToSSM(_Value);
	return ReturnValue;
}
template<typename T>	StarMass		StarMass::operator-(T _Value)
{
	StarMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue -= KGToSSM(_Value);
	return ReturnValue;
}
template<typename T>	StarMass		StarMass::operator*(T _Value)
{
	StarMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue *= KGToSSM(_Value);
	return ReturnValue;
}
template<typename T>	StarMass		StarMass::operator/(T _Value)
{
	StarMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue /= KGToSSM(_Value);
	return ReturnValue;
}
template<typename T>	bool			StarMass::operator==(T _Value)
{
	return mass == _Value;
}
template<typename T>	bool			StarMass::operator>=(T _Value)
{
	return mass >= _Value;
}
template<typename T>	bool			StarMass::operator<=(T _Value)
{
	return mass <= _Value;
}
template<typename T>	bool			StarMass::operator!=(T _Value)
{
	return mass != _Value;
}
template<typename T>	bool			StarMass::operator>(T _Value)
{
	return mass > _Value;
}
template<typename T>	bool			StarMass::operator<(T _Value)
{
	return mass < _Value;
}
template<typename T>	StarMass&		StarMass::operator+=(T _Value)
{
	mass += _Value;
	return (*this);
}
template<typename T>	StarMass&		StarMass::operator-=(T _Value)
{
	mass -= _Value;
	return (*this);
}
template<typename T>	StarMass&		StarMass::operator*=(T _Value)
{
	mass *= _Value;
	return (*this);
}
template<typename T>	StarMass&		StarMass::operator/=(T _Value)
{
	mass /= _Value;
	return (*this);
}
StarMass*								StarMass::operator=(StarMass _Value)
{
	mass = _Value.mass;
	return this;
}
StarMass								StarMass::operator+(StarMass _Value)
{
	_Value += mass;
	return _Value;
}
StarMass								StarMass::operator-(StarMass _Value)
{
	_Value -= mass;
	return _Value;
}
StarMass								StarMass::operator*(StarMass _Value)
{
	_Value *= mass;
	return _Value;
}
StarMass								StarMass::operator/(StarMass _Value)
{
	_Value /= mass;
	return _Value;
}
bool									StarMass::operator==(StarMass  _Value)
{
	return mass == _Value.mass;
}
bool									StarMass::operator<=(StarMass  _Value)
{
	return mass <= _Value.mass;
}
bool									StarMass::operator>=(StarMass  _Value)
{
	return mass >= _Value.mass;
}
bool									StarMass::operator<(StarMass  _Value)
{
	return mass < _Value.mass;
}
bool									StarMass::operator>(StarMass  _Value)
{
	return mass > _Value.mass;
}
bool									StarMass::operator!=(StarMass  _Value)
{
	return mass != _Value.mass;
}
StarMass&								StarMass::operator+=(StarMass _Value)
{
	mass += _Value.mass;
	return (*this);
}
StarMass&								StarMass::operator-=(StarMass _Value)
{
	mass -= _Value.mass;
	return (*this);
}
StarMass&								StarMass::operator*=(StarMass _Value)
{
	mass *= _Value.mass;
	return (*this);
}
StarMass&								StarMass::operator/=(StarMass _Value)
{
	mass /= _Value.mass;
	return (*this);
}
#endif // StarMass funcs
#if 1
long double PlanetMass::EMass()
{
	return mass;
}
long double PlanetMass::KGs()
{
	return mass * _EarthPlanetMassConst;
}
long double PlanetMass::KGsToEM(long double mass)
{
	return mass / _EarthPlanetMassConst;
}
long double PlanetMass::EMToKGs(long double mass)
{
	return mass * _EarthPlanetMassConst;
}
PlanetMass::PlanetMass()
{
	mass = 0;
}
template<typename T>	PlanetMass::PlanetMass(T _Value)
{
	mass = KGsToEM(_Value);
}
template<typename T>	PlanetMass		PlanetMass::operator+(T _Value)
{
	PlanetMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue += _Value;
	return ReturnValue;
}
template<typename T>	PlanetMass		PlanetMass::operator-(T _Value)
{
	PlanetMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue -= _Value;
	return ReturnValue;
}
template<typename T>	PlanetMass		PlanetMass::operator*(T _Value)
{
	PlanetMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue *= _Value;
	return ReturnValue;
}
template<typename T>	PlanetMass		PlanetMass::operator/(T _Value)
{
	PlanetMass ReturnValue;
	ReturnValue.mass = mass;
	ReturnValue /= _Value;
	return ReturnValue;
}
template<typename T>	bool			PlanetMass::operator==(T _Value)
{
	return mass == _Value;
}
template<typename T>	bool			PlanetMass::operator>=(T _Value)
{
	return mass >= _Value;
}
template<typename T>	bool			PlanetMass::operator<=(T _Value)
{
	return mass <= _Value;
}
template<typename T>	bool			PlanetMass::operator!=(T _Value)
{
	return mass != _Value;
}
template<typename T>	bool			PlanetMass::operator>(T _Value)
{
	return mass > _Value;
}
template<typename T>	bool			PlanetMass::operator<(T _Value)
{
	return mass < _Value;
}
template<typename T>	PlanetMass&		PlanetMass::operator+=(T _Value)
{
	mass += _Value;
	return (*this);
}
template<typename T>	PlanetMass&		PlanetMass::operator-=(T _Value)
{
	mass -= _Value;
	return (*this);
}
template<typename T>	PlanetMass&		PlanetMass::operator*=(T _Value)
{
	mass *= _Value;
	return (*this);
}
template<typename T>	PlanetMass&		PlanetMass::operator/=(T _Value)
{
	mass /= _Value;
	return (*this);
}
PlanetMass*								PlanetMass::operator=(PlanetMass _Value)
{
	mass = _Value.mass;
	return this;
}
PlanetMass								PlanetMass::operator+(PlanetMass _Value)
{
	_Value += mass;
	return _Value;
}
PlanetMass								PlanetMass::operator-(PlanetMass _Value)
{
	_Value -= mass;
	return _Value;
}
PlanetMass								PlanetMass::operator*(PlanetMass _Value)
{
	_Value *= mass;
	return _Value;
}
PlanetMass								PlanetMass::operator/(PlanetMass _Value)
{
	_Value /= mass;
	return _Value;
}
bool									PlanetMass::operator==(PlanetMass  _Value)
{
	return mass == _Value.mass;
}
bool									PlanetMass::operator<=(PlanetMass  _Value)
{
	return mass <= _Value.mass;
}
bool									PlanetMass::operator>=(PlanetMass  _Value)
{
	return mass >= _Value.mass;
}
bool									PlanetMass::operator<(PlanetMass  _Value)
{
	return mass < _Value.mass;
}
bool									PlanetMass::operator>(PlanetMass  _Value)
{
	return mass > _Value.mass;
}
bool									PlanetMass::operator!=(PlanetMass  _Value)
{
	return mass != _Value.mass;
}
PlanetMass&								PlanetMass::operator+=(PlanetMass _Value)
{
	mass += _Value.mass;
	return (*this);
}
PlanetMass&								PlanetMass::operator-=(PlanetMass _Value)
{
	mass -= _Value.mass;
	return (*this);
}
PlanetMass&								PlanetMass::operator*=(PlanetMass _Value)
{
	mass *= _Value.mass;
	return (*this);
}
PlanetMass&								PlanetMass::operator/=(PlanetMass _Value)
{
	mass /= _Value.mass;
	return (*this);
}
#endif // PlanetMass funcs
//Calculation
long double Calculation::CalculateOrbitalSpeed(StarMass sMass, PlanetMass pMass, Distance dist, Distance major_semiaxis)
{
	long double
		returnVal = ((sMass.KGs() + pMass.KGs()) * _GravityConstant);
	returnVal *= ((long double)(2) / dist.ToMeters()) - // 2/dist
		((long double)(1) / major_semiaxis.ToMeters());	// 1/major_semiaxis
	return std::sqrt(returnVal);
}

//Object
Object::Object(int64_t x, int64_t y, int64_t z, uc *data, u8 ObjType, Object* parent) : ObjectType(ObjType)
{
	this->parent = parent;
	memcpy(pSeed, data, SEED_SIZE);
	mySeed = SHA2::CalcXYZHash(x, y, z, data);
	std::string str(reinterpret_cast<char const*>(mySeed), SEED_SIZE);
	std::seed_seq returnValue(str.begin(), str.end());
	lce.seed(returnValue);
}
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
	u64 returnVal = 0;
	u8 len = sizeof(u64);
	for (u8 i = 0; i<len; i++)
	{
		returnVal *= 256;
		returnVal += seed[rand() % 32];
	}
	return returnVal;
}


//Star
Star::Star(uc* seed, Object* parent) 
	: Object(0,0,0,seed, __STARS, parent)
{
	double	StarType = dRand(0,100,lce()),
		props[7] = { 76.4563, 12.1359, 7.6456, 3.03398, 0.6068, 0.1214, 0.00003034 };
	u8 type = 0;

	double sum = 0.0;
	for (u8 i = 0; i < 7; i++)
	{
		if (StarType >= sum && StarType <= sum + props[i])
		{
			type = i;
			break;
		}
		sum += props[i];
	}
	switch (type)
	{
	case 0:
		myMass = 0.3;
		myRadius = 0.4;
		myLuminosity = 0.04;
		break;
	case 1:
		myMass = 0.8;
		myRadius = 0.9;
		myLuminosity = 0.4;
		break;
	case 2:
		myMass = 1.1;
		myRadius = 1.1;
		myLuminosity = 1.2;
		break;
	case 3:
		myMass = 1.7;
		myRadius = 1.3;
		myLuminosity = 6;
		break;
	case 4:
		myMass = 3.1;
		myRadius = 2.1;
		myLuminosity = 80;
		break;
	case 5:
		myMass = 18;
		myRadius = 7;
		myLuminosity = 20000;
		break;
	case 6:
		myMass = 60;
		myRadius = 15;
		myLuminosity = 1400000;
		break;
	}
	myMass			+=  dRand(-myMass.SMass()		/ 10,	
							  myMass.SMass()		/ 10, lce());
	myRadius		+= dRand(-myRadius		/ 10,	myRadius	/ 10, lce());
	myLuminosity	+= dRand(-myLuminosity	/ 10,	myLuminosity/ 10, lce());
	myType			= type;
}
StarMass Star::Mass()
{ 
	return myMass;
}
Distance Star::Radius()
{ 
	return myRadius;
}
long double Star::Luminosity() 
{ 
	return myLuminosity;
}
long double Star::Type()
{
	return myType;
}
//Planet
Planet::Planet(long double MaSMin, long double MiSMin, uc* seed, Object* parent) 
	: Object(u64(MaSMin), u64(MiSMin), (u64(MiSMin)>>10), seed, __PLANET, parent),
	myOrbit(MaSMin, MiSMin, lce(), lce(), lce())
{
	myMass = log(1 - (long double)(lce()) / 18446744073709551615) / -0.8039728L;
	myRadius = Distance::MToLS(std::cbrt(
		(myMass.KGs()
		/ dRand(400, 8000, lce()))
		/ 4.1887902));
}
PlanetMass Planet::Mass()
{
	return myMass;
}
Distance  Planet::Radius()
{
	return myRadius;
}
long double	Planet::Now_Coords()
{
	return MyCoords;
}
Orbit		Planet::GetOrbit()
{
	return myOrbit;
}
//Star System
StarSystem::StarSystem(int64_t x, int64_t y, int64_t z, uc* seed) : Object(x, y, z, seed, __STAR_SYSTEM)
{
	planetNum = u8((log(1 - (long double)(lce()) / 18446744073709551615) / (-0.0802027073L))) % 25;
	sNum = 1 /*+ u16((log(1 - (long double)(lce()) / 18446744073709551615) / (-1.9039728L))) % 7*/;
	starPtr = new Star(mySeed, this);
	long double MaDist = (starPtr->Radius()*2);
	long double MiDist = (starPtr->Radius()*2);
	Planets = new Planet*[planetNum];
	if(planetNum>=1)
		Planets[0] = new Planet(MaDist, MiDist, mySeed, this);
	for (u8 i = 1; i < planetNum; i++)
	{
		MaDist = Planets[i-1]->GetOrbit().Major_Semiaxis.ToLS()
			* u8(
				u8(log(1 - (long double)(lce()) 
					/ 18446744073709551615) 
					/ (-0.1802027073L)) % 5) + MaDist;
		MiDist = Planets[i-1]->GetOrbit().Minor_Semiaxis.ToLS()
			* u8(
				u8(log(1 - (long double)(lce()) 
					/ 18446744073709551615) 
					/ (-0.1802027073L)) % 5) + MiDist;
		Planets[i] = new Planet(MaDist, MiDist, mySeed, this);
	}
}
u8 StarSystem::getPlanetNum()
{
	return planetNum;
}
u8 StarSystem::getSNum()
{
	return sNum;
}

#undef __ERR_UNKNOWN_OBJ
#undef __UNIVERSE		
#undef __GALAXY_CLUSTER	
#undef __GALAXY			
#undef __STAR_SYSTEM		
#undef __STAR				
#undef __PLANET		
#undef SEED_SIZE
// undef useless macro