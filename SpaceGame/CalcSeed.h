#pragma once
#include <string>
namespace SHA2
{
	unsigned char* CalcXYZHash(int64_t, int64_t, int64_t, unsigned char[]);
	unsigned char* CalcHash(unsigned char[], unsigned long);
}