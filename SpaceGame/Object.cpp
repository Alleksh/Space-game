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
	myMass			+= dRand(-myMass		/ 10,	myMass		/ 10, lce());
	myRadius		+= dRand(-myRadius		/ 10,	myRadius	/ 10, lce());
	myLuminosity	+= dRand(-myLuminosity	/ 10,	myLuminosity/ 10, lce());
	myType			= type;
}
long double Star::Mass() 
{ 
	return myMass;
}
long double Star::Radius() 
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
long double Star::CalculateOrbitalSpeed(long double pMass, long double dist, long double major_semiaxis)
{
	return CalculateOrbitalSpeed(myMass,pMass,dist, major_semiaxis);
}
//https://ru.wikipedia.org/wiki/%D0%9E%D1%80%D0%B1%D0%B8%D1%82%D0%B0%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D1%81%D0%BA%D0%BE%D1%80%D0%BE%D1%81%D1%82%D1%8C
long double Star::CalculateOrbitalSpeed(long double sMass, long double pMass, long double dist, long double major_semiaxis)
{
	long double 
		returnVal = _GravityConstant*(//G(M+m) 
			sMass * 1.989 * std::pow(10, 30)//transfer sMass to KGs
			+ pMass * 5.972 * std::pow(10,24));//transfer pMass to KGs
	returnVal *= ((long double)(2) / (_LightSpeedConst*dist)) - // 2/dist
		((long double)(1) / (_LightSpeedConst * major_semiaxis));	// 1/major_semiaxis
	return std::sqrt(returnVal);
}

//Planet
Planet::Planet(long double MaSMin, long double MiSMin, uc* seed, Object* parent) 
	: Object(u64(MaSMin), u64(MiSMin), (u64(MiSMin)>>10), seed, __PLANET, parent),
	myOrbit(MaSMin, MiSMin, lce(), lce(), lce())
{
	myMass = log(1 - (long double)(lce()) / 18446744073709551615) / -0.8039728L;
	myRadius = std::cbrt(
		((myMass * std::pow(10, 24) * 5.972)
		/dRand(400, 8000, lce()))
		/ 4.1887902);
}
long double Planet::Mass()
{
	return myMass;
}
long double Planet::Radius()
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
	long double MaDist = (starPtr->Radius() * 50);
	long double MiDist = (starPtr->Radius() * 100);
	Planets = new Planet*[planetNum];
	if(planetNum>=1)
		Planets[0] = new Planet(MaDist, MiDist, mySeed, this);
	for (u8 i = 1; i < planetNum; i++)
	{
		MaDist = Planets[i-1]->GetOrbit().Major_Semiaxis 
			* u8(
				u8(log(1 - (long double)(lce()) 
					/ 18446744073709551615) 
					/ (-0.1802027073L)) % 10) + MaDist;
		MiDist = Planets[i-1]->GetOrbit().Minor_Semiaxis 
			* u8(
				u8(log(1 - (long double)(lce()) 
					/ 18446744073709551615) 
					/ (-0.1802027073L)) % 10) + MiDist;
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