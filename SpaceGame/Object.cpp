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
Star::Star(int64_t x,  uc* seed, Object* parent) : Object((x>>16), (x >> 32), (x >> 48), seed, __STARS, parent)
{

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