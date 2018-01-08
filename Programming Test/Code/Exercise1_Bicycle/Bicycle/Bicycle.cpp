/*
	Tyler Paulley
	10/13/2017
	Bicycle.cpp
	Exercise 1

	Definitions for functions of Bicycle class

	Assumptions: 
	- This class assumes that when currentGear = 0, the bicycle is in neutral.
	- When setting the number of gears on a bicycle, do not include neutral. 
	  (i.e. a bicycle with numberOfGears = 3 has gears: neutral, 1, 2, and 3)
*/

#include "Bicycle.h"
#include <cstdlib>		
#include <iostream>

std::string colors[] = { "black", "blue", "red" };
std::string types[] = { "offroad", "street" };

Bicycle::Bicycle(bicycleColor c, bicycleType t, float speed, int gears)
{
    color = c;
	type = t;
	topSpeed = speed;
	numberOfGears = gears;
	currentGear = 0;
}

Bicycle::~Bicycle()
{}

//Get Methods
Bicycle::bicycleColor Bicycle::getColor()
{
	return color;
}

Bicycle::bicycleType Bicycle::getType()
{
	return type;
}

float Bicycle::getTopSpeed()
{
	return topSpeed;
}

int Bicycle::getNumberOfGears()
{
	return numberOfGears;
}

int Bicycle::getCurrentGear()
{
	return currentGear;
}


//Set Methods
void Bicycle::setColor(Bicycle::bicycleColor c)
{
	this->color = color;
}

void Bicycle::setType(Bicycle::bicycleType t)
{
	this->type = t;
}

void Bicycle::setTopSpeed(float speed)
{
	this->topSpeed = speed;
}

void Bicycle::setNumberOfGears(int gears)
{
	this->numberOfGears = gears;
}

//increment currentGear
void Bicycle::shiftUp()
{
	if (currentGear < numberOfGears)
	{
		currentGear++;
		std::cout << "Shifted up to gear " << getCurrentGear() << "\n";
	}
	else
		std::cout << "You cannot shift up a gear since you are already in your top gear.\n";
}

//decrement currentGear
void Bicycle::shiftDown()
{
	if (currentGear > 0)
	{
		currentGear--;
		std::cout << "Shifted down to gear " << getCurrentGear() << "\n";
	}
	else
		std::cout << "You cannot shift down a gear since you in neutral.\n";

}

//prints how long it will take a distance in meters on a bicycle, considering terrain
void Bicycle::ride(float distance, bool isOffroad)
{
	float speed = this->topSpeed;

	//the top speed of street bikes are slowed by 25% if they are taken offroad
	if (this->getType() == 1 && isOffroad)
	{
		speed *= .75;
		std::cout << "Riding your street bike offroad slowed it from " << this->topSpeed << "m/s to " << speed << "m/s.\n";
	}

	float time = distance / speed;
	std::cout << "You traveled " << distance << " meters in " << time
			  << " seconds, travelling at a speed of " << speed << " m/s.\n";
}

void Bicycle::printSpecs()
{
	std::cout << "Color: " << colors[(int)this->getColor()] << "\n"
			  << "Type: " << types[(int)this->getType()] << "\n"
			  << "Top Speed: " << this->getTopSpeed() << "m/s\n"
			  << "Gears: " << this->getNumberOfGears() << "\n";
}