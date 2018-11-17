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
long double dRand(long double dMin,long double dMax, u64 randomNum)
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
	returnValue1 += saveValue;
	return returnValue1;
}
Star::Star(int64_t x,  uc* seed, Object* parent) : Object((x>>16), (x >> 32), (x >> 48), seed, __STARS, parent)
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
long double Star::CalculateOrbitalSpeed(long double pMass, long double dist, long double a)
{
	return CalculateOrbitalSpeed(myMass,pMass,dist,a);
}
//https://ru.wikipedia.org/wiki/%D0%9E%D1%80%D0%B1%D0%B8%D1%82%D0%B0%D0%BB%D1%8C%D0%BD%D0%B0%D1%8F_%D1%81%D0%BA%D0%BE%D1%80%D0%BE%D1%81%D1%82%D1%8C
long double Star::CalculateOrbitalSpeed(long double sMass, long double pMass, long double dist, long double a)
{
	long double 
		returnVal = _GravityConstant*(//G(M+m) 
			sMass * 1.989 * std::pow(10, 30)//transfer sMass to KGs
			+ pMass * 5.972 * std::pow(10,24));//transfer pMass to KGs
	returnVal *= ((long double)(2) / (_LightSpeedConst*dist)) - // 2/dist
		((long double)(1) / (_LightSpeedConst * a));	// 1/a
	return std::sqrt(returnVal);
}


//Planet
Planet::Planet(int64_t x, int64_t y, int64_t z, uc* seed, Object* parent) : Object(x, y, z, seed, __PLANET, parent)
{

}

//Star System
StarSystem::StarSystem(int64_t x, int64_t y, int64_t z, uc* seed) : Object(x, y, z, seed, __STAR_SYSTEM)
{
	planetNum = u16((log(1 - (long double)(lce()) / 18446744073709551615) / (-0.0802027073L))) % 25;
	sNum = 1 /*+ u16((log(1 - (long double)(lce()) / 18446744073709551615) / (-1.9039728L))) % 7*/;
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