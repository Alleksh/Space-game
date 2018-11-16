#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
int main()
{
	srand(time(0));
	unsigned char data[32];
	int massive[33];
	memcpy(data, data, SEED_SIZE);
	for (int i = 0; i < 33; i++) massive[i] = 0;
	for (int i = 0; i < 100000; i++)
	{
		StarSystem sys(1, 2, 3, data);
		sys.getObjectSeed(data);
		massive[sys.getSNum()]++;
	}
	for (int i = 0; i < 33; i++) std::cout << i << ":  " << massive[i] << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(50));
}