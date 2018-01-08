/*
	Tyler Paulley
	10/13/2017
	Bicycle.h
	Exercise 1

	Header file for Bicycle class
*/

#ifndef BICYCLE_H
#define BICYCLE_H
#include <string>

class Bicycle
{
	public:
		enum bicycleColor
		{
			black,
			blue,
			red
		};
		enum bicycleType
		{
			offroad,
			street
		};

	private:
		bicycleColor color;
		bicycleType type;
		float topSpeed;
		int numberOfGears;
		int currentGear;

	public:
		//Constructors and Destructors
		Bicycle(enum bicycleColor, enum bicycleType, float speed, int gears);
		~Bicycle();

		//Get Methods
		bicycleColor getColor();
		bicycleType getType();
		float getTopSpeed();
		int getNumberOfGears();
		int getCurrentGear();

		//Set Methods
		void setColor(bicycleColor c);					
		void setType(bicycleType t);
		void setTopSpeed(float speed);
		void setNumberOfGears(int gears);

		void shiftUp();
		void shiftDown();
		void ride(float distance, bool isOffroad);
		void printSpecs();
};

#endif