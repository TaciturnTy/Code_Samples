/*
	Tyler Paulley
	10/15/2017
	main.cpp
	Exercise 1

	Test functions of Bicycle class
*/

#include <iostream>
#include "Bicycle.h"

int main(int argv, char** argc)
{
	Bicycle bike1(Bicycle::bicycleColor::red, Bicycle::bicycleType::street, 8, 2);
	Bicycle bike2(Bicycle::bicycleColor::black, Bicycle::bicycleType::offroad, 5, 4);

	//test printSpecs
	bike1.printSpecs();

	//test shift fuctions
	std::cout << "\n";
	bike1.shiftDown();				//shift from gears 0 to -1 is not allowed
	bike1.shiftUp();				//shift from gear 0 to 1
	bike1.shiftUp();				//shift from gear 1 to 2
	bike1.shiftUp();				//can't shift above 2nd gear

	//test ride
	std::cout << "\n";	
	bike1.ride(300.0, false);		//street bike will be not be slowed on road

	std::cout << "\n";
	bike1.ride(500.0, true);		//street bike will be slowed offroad

	//test set and get functions
	bike1.setColor(bike2.getColor());
	bike1.setType(bike2.getType());
	bike1.setTopSpeed(bike2.getTopSpeed());
	bike1.setNumberOfGears(bike2.getNumberOfGears());

	std::cout << "\n\n";
	bike1.printSpecs();

	std::cout << "\n";
	bike1.ride(300.0, false);		//offroad bike will not be slowed on road

	std::cout << "\n";
	bike1.ride(500.0, true);		//offroad bike will not be slowed offroad

	getchar();
	return 0;
}
