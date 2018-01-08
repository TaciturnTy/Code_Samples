/*
	Tyler Paulley
	11/10/2017
	main.cpp

	Test functions of Map and Room classes

	NOTE: Why Vectors over Pointer Arrays?
		Concensus seemed to be that vector should be the 
		default answer to putting items in an array in C++
		since there is little to no overhead to vectors. It
		seemed that in many cases, vectors are actually faster
		than using C arrays. Nonetheless, C arrays must have 
		their size stored somewhere to be iterated through.
		Using (sizeof(myArray) / sizeof(myArray[0])) to get
		the length of the array doesn't work when the array
		uses pointers since this will only return the bytesize 
		of the pointer and not the total bytesize of the array. 
		There didn't seem to be a way to declare a vector 
		without using a pointer. The array variables in a class 
		must be declared without knowing the size that the 
		array will be.
*/

/*
Known Bugs:
 - doesn't always place ending at farthest door from start
 - one time showed a map that was cleared all but start and end



*/

#include <iostream>
#include "Map.h"
#include "Room.h"
#include "ROOM_DATA.h"

int main(int argv, char** argc)
{
	srand(time(NULL));

	std::vector<Room> ROOM_MASTER_LIST = { ROOM_1x1, ROOM_1x2, ROOM_1x3,
									       ROOM_2x1, ROOM_2x2, ROOM_2x3,
										   ROOM_3x1, ROOM_3x2, ROOM_3x3 };
	Map myMap2(8,16);
	
	myMap2.printMap();
	myMap2.setStartTile();
	myMap2.printMap();
	myMap2.printPossibleDoors();

	while (!myMap2.testIsFilled())
	{
		myMap2.addNewRoom(ROOM_MASTER_LIST);
		myMap2.printMap();
		myMap2.printPossibleDoors();
	}

	myMap2.setEndTile();

	myMap2.printMapNodes();
	myMap2.printMap();

	std::cout << "\n\nFinished Generating Map";
	getchar();
	return 0;
}