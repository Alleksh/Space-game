#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
void CalcuAsm(int *x, int *y, int lengthOfArray)
{

}
int main()
{
	srand(time(0));
	unsigned char *data = SHA2::CalcHash((unsigned char*)"42",2);
	for (int i = 0; i < 100; i++)
	{
		uint64_t	
			X = rand()*rand(),
			Y = rand()*rand(),
			Z = rand()*rand();
		data = SHA2::CalcXYZHash(X, Y, Z, data);
		std::stringstream val;
		val << std::hex;
		for (int i = 0; i < 32; i++) val << int(data[i]) << " ";
		std::cout <<"x: " + std::to_string(X) 
					+ " Y: "+ std::to_string(Y)
					+ " Z: "+ std::to_string(Z) 
					+ " GenSeed: " + val.str() << std::endl << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::seconds(50));
}