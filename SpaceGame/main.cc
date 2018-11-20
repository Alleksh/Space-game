#include <iostream>
#include <sstream>
#include <thread>
#include "CalcSeed.h"
#include "Object.h"
#include <random>
#include <sstream>
#include "SFML/Graphics.hpp"
#define sleep std::this_thread::sleep_for(std::chrono::hours(12));
int main()
{
	std::linear_congruential_engine<u64, 6364136223846793005
		, 1442695040888963407, 18446744073709551615> lce;

	sleep
}