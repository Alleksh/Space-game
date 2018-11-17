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
	std::this_thread::sleep_for(std::chrono::seconds(5550));
}