/*
	Tyler Paulley
	11/10/2017
	Map.h

	Header file for Map class
*/

#ifndef MAP_H
#define MAP_H
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <random>
#include <time.h>
#include "Structs.h"
#include "Room.h"


class Map
{
	protected:
		int rows;
		int cols;
		tile startTile;
		tile endTile = {-1, -1};
		tile cursor;							//defines the location we are currently at when adding a new room
		std::vector<std::vector<mapTile>> matrix;
		std::vector<mapNode> nodeList;
		std::vector<doorLoc> possibleDoors; 
		int emptyTiles;
		int tilesToFill;

	public:
		Map(int m, int n);			//Constructors and Destructors
		~Map();
		int getRows();
		int getCols();

		bool testIsFilled();
		std::vector<std::vector<mapTile>> scanAroundCursor();		//scans a 5x5 matrix around the cursor location and returns the matrix indicating what tiles are filled
		void setCursorByDoorLoc(doorLoc);

		void pushNewDoor(doorLoc);
		doorLoc popRandomDoor();			//select a door from possibleDoors at random and remove it from the list of possibleDoors

		void pushNewNode(mapNode);
		mapNode popMapNode();	//remove a node if it leaves no possible doors

		void regenMap();
		void addNewRoom(std::vector<Room>);
		void setStartTile();		//set random location in the matrix to be the start (should it not touch the edge?)
		void setEndTile();

		void printPossibleDoors();
		void printMap();
		void printMapNodes();
		void printMapPoints();		
};

#endif