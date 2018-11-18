#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
#include <sstream>
int main()
{
	srand(time(0));
	while(1)
	{
		std::cout << std::endl << std::endl;
		std::cout << "enter plz data here: ";
		unsigned char data[32];
		std::cin >> data;
		StarSystem system(0, 0, 0, data);
		for (int i = 0; i < system.getPlanetNum(); i++)
		{
			std::cout
				<< "Planet number:   "		<< i << std::endl
				<< "Mass:   "				<< system.Planets[i]->Mass() * std::pow(10, 24) * 5.972				<< "   KGs" << std::endl
				<< "Radius:   "				<< system.Planets[i]->Radius()										<< "   Ms" << std::endl
				<< "Major semiaxis:   "	<< system.Planets[i]->GetOrbit().Major_Semiaxis * _LightSpeedConst 	<< "   Ms" << std::endl
				<< "Minor semiaxis:   "	<< system.Planets[i]->GetOrbit().Minor_Semiaxis * _LightSpeedConst	<< "   Ms" << std::endl
				<< "Focal length:   "		<< system.Planets[i]->GetOrbit().Focal_Length	* _LightSpeedConst	<< "   Ms" << std::endl
				<< "Eccentricity:   "		<< system.Planets[i]->GetOrbit().eccentricity << std::endl << std::endl;
		}
	}
	std::this_thread::sleep_for(std::chrono::hours(1));
}