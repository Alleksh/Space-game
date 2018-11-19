#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
#include <sstream>
#include "SFML/Graphics.hpp"
int main()
{
	srand(time(0));
	Distance dist = 200.0f;
	std::cout << (dist / 100)() << std::endl;
	std::cout << (dist * 100)();
	std::this_thread::sleep_for(std::chrono::hours(1));
}