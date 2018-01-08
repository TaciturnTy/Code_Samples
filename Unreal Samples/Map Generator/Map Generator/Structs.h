/*
Tyler Paulley
11/10/2017
Structs.h

Define custom structs
*/

#ifndef STRUCTS_H
#define STRUCTS_H

#include <vector>
#include "Room.h"
#include <string>
struct tile
{
	int row;
	int col;
};

struct mapTile
{
	int row;
	int col;
	bool isFilled;
};

//defines a location on the world map where a new door can be placed
struct doorLoc
{
	int row;
	int col;
	bool isLeft;
};

//used for defining rooms, tells location of door in a room and what tiles 
//must be open in the world map to place the room using that door
struct door
{
	int row;
	int col;
	std::vector<tile> neededGrid;
};

//used for defining a map, tells what room is attached where, each node represents one room
struct mapNode
{
	doorLoc doorOutOfOldRoom;
	std::string attachedRoomName;		//to read tag and get attached door easily, might just need the tag string...
	bool attachedDoorIsLeft;
	int attachedDoorIndex;		//get the door in the array in attachedRoom Room
	char roomType;				//0 is normal room, S is start, E is end...

	//when redrawing map in game engine, attach door/teleporters to the doorLoc locations of each mapNode, 
	//after this is done, for other possible door of each room in the map, attach a destroyed door sprite

	//the room tilesets in the game engine should leave the locations of doors empty to be covered up with a random sprite or door if they are connected
};

#endif