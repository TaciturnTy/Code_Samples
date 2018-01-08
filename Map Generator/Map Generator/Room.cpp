/*
Tyler Paulley
11/10/2017
Room.cpp

Definitions for functions of Map class
*/

#include "Room.h"
#include <cstdlib>		
#include <iostream>

Room::Room(std::string tag, std::vector<door> DLL, std::vector<door> DLR)
{
	roomTag = tag;
	totalRows = DLL.size();
	totalCols = DLR.size();
	doorListL = DLL;
	doorListR = DLR;
}

Room::~Room()
{}

//get world location of door
//used after a room is added to add other door possibilities
//cursor is the location is worldspace where the door is located
//entryD is the door where the room was attached at, other room locations 
// need to be shifted according to door where the room is attached
doorLoc Room::getDoorLocL(door newD, tile cursor, door entryD)
{
	doorLoc newLoc = { newD.row + cursor.row - entryD.row, newD.col + cursor.col - entryD.col, true };
	return newLoc;
}

doorLoc Room::getDoorLocR(door newD, tile cursor, door entryD)
{
	doorLoc newLoc = { newD.row + cursor.row - entryD.row, newD.col + cursor.col - entryD.col, false };
	return newLoc;
}

std::string Room::getRoomTag()
{
	return this->roomTag;
}

std::vector<door> Room::getDoorListL() 
{
	return this->doorListL;
}
std::vector<door> Room::getDoorListR()
{
	return this->doorListR;
}

void Room::printDoorList(std::vector<door> doorList)
{
	for (unsigned i = 0; i < doorList.size(); i++)
	{
		std::cout << "\n\tDoor Location: (" << doorList[i].row << ", "
				  << doorList[i].col << ")\n\t" << "Empty Tiles Required: ";

		for (unsigned j = 0; j < doorList[i].neededGrid.size(); j++)
		{
			std::cout << "[" << doorList[i].neededGrid[j].row << ","
					  << doorList[i].neededGrid[j].col << "] ";
		}
	}
	std::cout << "\n";
}

void Room::printRoomData()
{
	std::cout << "TotalRows: " << totalRows << "\n"
			  << "TotalCols: " << totalCols << "\n";

	std::cout << "LeftDoors: ";
	printDoorList(doorListL);

	std::cout << "RightDoors: ";
	printDoorList(doorListR);
}