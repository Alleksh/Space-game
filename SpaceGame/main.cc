#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
int main()
{
	srand(time(0));
	Star star(1,(unsigned char*)"12341234123412341234123412341232",NULL);
	std::cout << star.Type()	<< std::endl
		<< star.Mass()			<< std::endl
		<< star.Radius() << std::endl
		<< star.Luminosity() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5550));
}