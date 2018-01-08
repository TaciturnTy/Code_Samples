/*
Tyler Paulley
11/10/2017
Room.h

Header file for Room class
*/

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include "Structs.h"

struct door;
struct doorLoc;
struct tile;

class Room
{
protected:
	std::string roomTag;
	int totalRows;
	int totalCols;
	std::vector<door> doorListL;
	std::vector<door> doorListR;

public:
	//Constructors and Destructors
	Room(std::string, std::vector<door>, std::vector<door>);
	~Room();
	std::string getRoomTag();
	std::vector<door> getDoorListL();
	std::vector<door> getDoorListR();

	doorLoc getDoorLocL(door, tile, door);
	doorLoc getDoorLocR(door, tile, door);
	void printDoorList(std::vector<door>);
	void printRoomData();
	//Get Methods

	//Set Methods

};

#endif