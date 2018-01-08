/*
	Tyler Paulley
	11/10/2017
	Map.cpp

	Definitions for functions of Map class
*/

#include "Map.h"
#include <cstdlib>		

Map::Map(int m, int n)
{
	rows = m;
	cols = n;

	//initialize matrix elements
	matrix.resize(rows);
	for (unsigned i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(cols);
	}
	
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j].row = i;
			matrix[i][j].col = j;
			matrix[i][j].isFilled = false;
		}
	}
	emptyTiles = rows * cols;
	tilesToFill = emptyTiles / 2;
}

Map::~Map()
{}


int Map::getRows()
{
	return rows;
}

int Map::getCols()
{
	return cols;
}

bool Map::testIsFilled()
{
	if (emptyTiles <= tilesToFill)
	{
		return true;
	}
	return false;
}

std::vector<std::vector<mapTile>> Map::scanAroundCursor()
{
	std::vector<std::vector<mapTile>> matrix5x5;
	matrix5x5.resize(5);
	for (unsigned i = 0; i < matrix5x5.size(); i++)
	{
		matrix5x5[i].resize(5);
	}
	std::cout << "Cursor R: " << this->cursor.row << " Cursor C: " << this->cursor.col << "\n";
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix5x5[i][j].row = i - 2;
			matrix5x5[i][j].col = j - 2;
			//test if tile is in bounds of matrix
			
			if (((i + cursor.row - 2) > -1 && (i + cursor.row - 2) < this->rows) && ((j + cursor.col - 2) > -1 && (j + cursor.col - 2) < this->cols))
			{
				matrix5x5[i][j].isFilled = matrix[i + cursor.row - 2][j + cursor.col - 2].isFilled;
			}
			else
				matrix5x5[i][j].isFilled = true;
				
		}
	}
	//
	std::cout << "Scanning around " << cursor.row << "," << cursor.col << "\n";
for (int i = 0; i < 5; i++)
{
	std::cout << "\n";
	for (int j = 0; j < 5; j++)
	{
		if (matrix5x5[i][j].isFilled)
		{
			std::cout << "#";
		}
		else
		{
			std::cout << "_";
		}
	}
}
std::cout << "\n\n";

return matrix5x5;
}

void Map::setCursorByDoorLoc(doorLoc locRef)
{
	if (locRef.isLeft)
	{
		this->cursor = { locRef.row, locRef.col - 1 };
	}
	else
	{
		this->cursor = { locRef.row, locRef.col + 1 };
	}
}

void Map::pushNewDoor(doorLoc newDoor)
{
	possibleDoors.push_back(newDoor);
}

//select a door from possibleDoors at random and remove it from the list of possibleDoors
doorLoc Map::popRandomDoor()
{
	int index = std::rand() % possibleDoors.size();
	doorLoc refLoc = possibleDoors[index];

	std::cout << "\nPopping Door: " << this->possibleDoors[index].row << "," << this->possibleDoors[index].col << " ";
	if (this->possibleDoors[index].isLeft)
	{
		std::cout << "LEFT\n";
	}
	else
	{
		std::cout << "RIGHT\n";
	}
	possibleDoors.erase(possibleDoors.begin() + index);
	return refLoc;
}

void printNewRoomDoors(std::vector<Room> allRooms, std::vector<int> roomReferenceList, std::vector<std::vector<int>> doorList, bool newDoorsAreLeft)
{
	if (newDoorsAreLeft)
	{
		std::cout << "Possible New Rooms: Left\n";

		for (int i = 0; i < roomReferenceList.size(); i++)
		{
			std::cout << allRooms[roomReferenceList[i]].getRoomTag() << ": ";

			for (int j = 0; j < doorList[i].size(); j++)
			{
				std::cout << doorList[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	else
	{
		std::cout << "Possible New Rooms: Right\n";

		for (int i = 0; i < roomReferenceList.size(); i++)
		{
			std::cout << allRooms[roomReferenceList[i]].getRoomTag() << ": ";

			for (int j = 0; j < doorList[i].size(); j++)
			{
				std::cout << doorList[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
}

void Map::regenMap()
{
	this->nodeList.resize(0);
	this->possibleDoors.resize(0);

	for (unsigned i = 0; i < this->matrix.size(); i++)
	{
		for (unsigned j = 0; j < this->matrix[i].size(); j++)
		{
			this->matrix[i][j].isFilled = false;
		}
	}
	setStartTile();
}

void Map::addNewRoom(std::vector<Room> allRooms)
{
	if (this->possibleDoors.size() == 0)
	{
		//no possible doors exist, regen map
		regenMap();
		return;
	}
	doorLoc newLoc = this->popRandomDoor();
	this->setCursorByDoorLoc(newLoc);
	std::vector<std::vector<mapTile>> matrix5x5 = this->scanAroundCursor();
	if (matrix5x5[2][2].isFilled)
	{
		std::cout << "\nNo Options For This Door";
		return;
	}
	std::vector<int> roomReferenceList;							//stores index of what room each row of doorList refers to
																//e.g. [3,4,6] means that the rooms at indexes 3,4,6 in allRooms have a door(s) that fit
	std::vector<std::vector<int>> doorList;						//stores indexes of allRooms doors that fit
																//e.g. [0][1,2] means that the room at index [0] of roomReferenceList (3) has doors at index 1,2 that fit
	//newDoorOptions.resize(allRooms.size());		//make x vectors where x is the number of different rooms
	
	
	for (unsigned i = 0; i < allRooms.size(); i++)
	{
		std::vector<int> temp;
		bool roomHasDoorThatFits = false;
		bool doorFits = false;
		if (!newLoc.isLeft)
		{
			for (unsigned j = 0; j < allRooms[i].getDoorListL().size(); j++)	//for each left door in a room
			{
				doorFits = true;

				for (unsigned k = 0; k < allRooms[i].getDoorListL()[j].neededGrid.size(); k++)		//check that each required tile is not filled
				{
					tile currentTile = allRooms[i].getDoorListL()[j].neededGrid[k];
					if (matrix5x5[currentTile.row + 2][currentTile.col + 2].isFilled)
					{
						doorFits = false;
					}
				}
				if (doorFits)
				{
					temp.push_back(j);
					roomHasDoorThatFits = true;
				}
			}

			if (roomHasDoorThatFits)
			{
				roomReferenceList.push_back(i);
				doorList.resize(doorList.size() + 1);
				for (unsigned count = 0; count < temp.size(); count++)
				{
					doorList[doorList.size() - 1].push_back(temp[count]);
				}
			}
		}
		else
		{
			for (unsigned j = 0; j < allRooms[i].getDoorListR().size(); j++)	//for each right door in a room
			{
				doorFits = true;

				for (unsigned k = 0; k < allRooms[i].getDoorListR()[j].neededGrid.size(); k++)		//check that each required tile is not filled
				{
					tile currentTile = allRooms[i].getDoorListR()[j].neededGrid[k];
					if (matrix5x5[currentTile.row + 2][currentTile.col + 2].isFilled)
					{
						doorFits = false;
					}
				}
				if (doorFits)
				{
					temp.push_back(j);
					roomHasDoorThatFits = true;
				}
			}

			if (roomHasDoorThatFits)
			{
				roomReferenceList.push_back(i);
				doorList.resize(doorList.size() + 1);
				for (unsigned count = 0; count < temp.size(); count++)
				{
					doorList[doorList.size() - 1].push_back(temp[count]);
				}
			}
		}
	}
	
	printNewRoomDoors(allRooms, roomReferenceList, doorList, !newLoc.isLeft);
	
	int randRoom = std::rand() % roomReferenceList.size();
	int randDoor = std::rand() % doorList[randRoom].size();
	std::cout << "Rand Room: " << randRoom << " Rand Door: " << randDoor << "\n";
	door attachedDoor;
	std::string attachedDoorDirection;
	bool attachedDoorIsLeft;
	if (!newLoc.isLeft)
	{
		attachedDoor = allRooms[roomReferenceList[randRoom]].getDoorListL()[doorList[randRoom][randDoor]];
		attachedDoorDirection = "LEFT";
		attachedDoorIsLeft = true;
	}
	else
	{
		attachedDoor = allRooms[roomReferenceList[randRoom]].getDoorListR()[doorList[randRoom][randDoor]];
		attachedDoorDirection = "RIGHT";
		attachedDoorIsLeft = false;
	}
	
	std::cout << "\nSelected Door: " << allRooms[roomReferenceList[randRoom]].getRoomTag() << " -- " << doorList[randRoom][randDoor] << " ";
	std::cout << "\nThe attached door is: " << attachedDoor.row << "," << attachedDoor.col << " " << attachedDoorDirection;
	
	//set all tiles as filled
	for (unsigned l = 0; l < attachedDoor.neededGrid.size(); l++)
	{
		this->matrix[this->cursor.row + attachedDoor.neededGrid[l].row][this->cursor.col + attachedDoor.neededGrid[l].col].isFilled = true;
		this->emptyTiles--;
	}
	std::cout << "\nEmpty Tiles Remaining: " << this->emptyTiles;

	std::cout << "\nFINISHED STABLE SECTION";

	
	//cursor + door loc - attached door == cursor if door loc and attached door are the same
	//push new doors into list
	for (unsigned l = 0; l < allRooms[roomReferenceList[randRoom]].getDoorListL().size(); l++)
	{
		if (!newLoc.isLeft && doorList[randRoom][randDoor] == l)
		{
			//don't add the door that was used to attach the room
			std::cout << "\nDOOR WASNT PUSHED SINCE IS ATTACHED";
			continue;
		}
		if((allRooms[roomReferenceList[randRoom]].getDoorListL()[l].col + cursor.col - attachedDoor.col - 1) < 0)
		{
			//don't add a door that touches the map's edge
			std::cout << "\nDOOR WASNT PUSHED SINCE TOUCHES EDGE" ;

		}
		else if ((matrix[allRooms[roomReferenceList[randRoom]].getDoorListL()[l].row + cursor.row - attachedDoor.row]
					    [allRooms[roomReferenceList[randRoom]].getDoorListL()[l].col + cursor.col - attachedDoor.col - 1].isFilled))
		{
			//don't add a door that touches another filled room
			std::cout << "\nDOOR WASNT PUSHED SINCE TOUCHES FILLED";
		}
		else//doorList[randRoom][randDoor]
		{
			doorLoc newDoor = 
			{ 
				allRooms[roomReferenceList[randRoom]].getDoorListL()[l].row + cursor.row - attachedDoor.row,
				allRooms[roomReferenceList[randRoom]].getDoorListL()[l].col + cursor.col - attachedDoor.col, true
			};
			std::cout << "\nPushing New Door: " << newDoor.row << "," << newDoor.col << " " << "LEFT";
			possibleDoors.push_back(newDoor);
		}
	}
	for (unsigned l = 0; l < allRooms[roomReferenceList[randRoom]].getDoorListR().size(); l++)
	{
		if (newLoc.isLeft && doorList[randRoom][randDoor] == l)
		{
			//don't add the door that was used to attach the room
			std::cout << "\nDOOR WASNT PUSHED SINCE IS ATTACHED";

			continue;
		}
		if ((allRooms[roomReferenceList[randRoom]].getDoorListR()[l].col + cursor.col - attachedDoor.col + 1) >= this->cols)
		{
			//don't add a door that touches the map's edge
			std::cout << "\nDOOR WASNT PUSHED SINCE TOUCHES EDGE";

		}
		else if ((matrix[allRooms[roomReferenceList[randRoom]].getDoorListR()[l].row + cursor.row - attachedDoor.row]
				        [allRooms[roomReferenceList[randRoom]].getDoorListR()[l].col + cursor.col - attachedDoor.col + 1].isFilled))
		{
			//don't add a door that touches another filled room
			std::cout << "\nDOOR WASNT PUSHED SINCE TOUCHES FILLED";

		}
		else
		{
			doorLoc newDoor =
			{
				allRooms[roomReferenceList[randRoom]].getDoorListR()[l].row + cursor.row - attachedDoor.row,
				allRooms[roomReferenceList[randRoom]].getDoorListR()[l].col + cursor.col - attachedDoor.col, false
			};
			possibleDoors.push_back(newDoor);
			std::cout << "\nPushing New Door: " << newDoor.row << "," << newDoor.col << " " << "RIGHT";
		}
	}

	if (this->testIsFilled())
	{
		//will call regen on map if no sufficient ending is found
		this->setEndTile();
	}
	
	mapNode newNode = { newLoc, allRooms[roomReferenceList[randRoom]].getRoomTag(), attachedDoorIsLeft, doorList[randRoom][randDoor], '0' };
	this->pushNewNode(newNode);
}

void Map::setStartTile()
{
	int indexR = std::rand() % rows;
	int indexC = std::rand() % cols;
	cursor = { indexR, indexC };

	std::cout << "Set Starting Tile to " << cursor.row << "," << cursor.col << "\n";
	matrix[indexR][indexC].isFilled = true;
	emptyTiles--;

	this->startTile = {indexR, indexC};

	if (startTile.col - 1 < 0)
	{
		//cannot add left door to possibleDoors bc left of start is touching edge of matrix
	}
	else
	{
		doorLoc startLeftDoor = { startTile.row, startTile.col, true };
		this->possibleDoors.push_back(startLeftDoor);
	}
	if (startTile.col + 1 >= this->cols)
	{
		//cannot add right door to possibleDoors bc right of start is touching edge of matrix
	}
	else
	{
		doorLoc startRightDoor = { startTile.row, startTile.col, false };
		this->possibleDoors.push_back(startRightDoor);
	}
}

void Map::setEndTile()
{
	std::vector<doorLoc> tempDoorList;
	//create a copy to remove blocked doors from
	for (int i = 0; i < possibleDoors.size(); i++)
	{
		tempDoorList.push_back(possibleDoors[i]);
	}
	possibleDoors.resize(0);

	//remove blocked doors from possibleDoors
	for (int i = 0; i < tempDoorList.size(); i++)
	{ 
		if (tempDoorList[i].isLeft)
		{
			if (matrix[tempDoorList[i].row][tempDoorList[i].col - 1].isFilled)
			{
				//dont push since is blocked
			}
			else
			{
				possibleDoors.push_back(tempDoorList[i]);
			}
		}
		else
		{
			if (matrix[tempDoorList[i].row][tempDoorList[i].col + 1].isFilled)
			{
				//dont push since is blocked
			}
			else
			{
				possibleDoors.push_back(tempDoorList[i]);
			}
		}
	}

	if (possibleDoors.size() == 0)
	{
		std::cout << "\nREGENERATED MAP 1";
		this->regenMap();
		return;
	}

	int minDistFromStart = 3;
	int startR = startTile.row;
	int startC = startTile.col;
	int farthestDist = 0;
	int indexOfFarthest;

	for (int i = 0; i < possibleDoors.size(); i++)
	{
		int thisDist = abs(possibleDoors[i].row - startR) + abs(possibleDoors[i].col - startC);
		if ( thisDist > minDistFromStart && thisDist > farthestDist)
		{
			farthestDist = thisDist;
			indexOfFarthest = i;
		}
	}

	if (farthestDist < minDistFromStart)
	{
		std::cout << "\nREGENERATED MAP 2";
		this->regenMap();
		return;
	}

	doorLoc endLoc = this->possibleDoors[indexOfFarthest];
	mapNode endNode = { endLoc, "Room_1x1", !endLoc.isLeft, 0, 'E'};
	nodeList.push_back(endNode);
	this->endTile = { endLoc.row, endLoc.col };
	emptyTiles--;
	possibleDoors.erase(possibleDoors.begin() + indexOfFarthest);
}

void Map::pushNewNode(mapNode newNode)
{
	this->nodeList.push_back(newNode);
}

mapNode Map::popMapNode()
{
	//return a node that resulted in no possible doors, when selecting a new room, do not select this one
	mapNode invalidNode = nodeList.back();
	nodeList.pop_back();
	return invalidNode;
}

void Map::printPossibleDoors()
{
	std::cout << "PossibleDoors: \n";
	for (unsigned i = 0; i < this->possibleDoors.size(); i++)
	{
		std::cout << this->possibleDoors[i].row << "," << this->possibleDoors[i].col << " ";
		if(this->possibleDoors[i].isLeft)
		{
			std::cout << "LEFT\n";
		}
		else 
		{
			std::cout << "RIGHT\n";
		}
	}
}

void Map::printMap()
{
	for (int i = 0; i < this->rows; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < this->cols; j++)
		{
			if (startTile.row == i && startTile.col == j)
			{
				std::cout << "S";
			}
			else if (endTile.row == i && endTile.col == j)
			{
				std::cout << "E";
			}
			else if (matrix[i][j].isFilled)
			{
				std::cout << "#";
			}
			else
			{
				std::cout << "_";
			}
		}
	}
	std::cout << "\n\n";
}

void Map::printMapNodes()
{
	std::cout << "Map Nodes: \n";
	std::cout << "Start: " << startTile.row << "," << startTile.col << "\n";
	std::cout << "End: " << endTile.row << "," << endTile.col << "\n";

	for (unsigned i = 0; i < this->nodeList.size(); i++)
	{
		std::cout << "Attach Door at: " << nodeList[i].doorOutOfOldRoom.row << "," << nodeList[i].doorOutOfOldRoom.col << " ";
		if (this->nodeList[i].doorOutOfOldRoom.isLeft)
		{
			std::cout << "LEFT ";
		}
		else
		{
			std::cout << "RIGHT ";
		}
		std::cout << "to the new Room: " << nodeList[i].attachedRoomName << " at its door " << nodeList[i].attachedDoorIndex << " ";
		if (this->nodeList[i].attachedDoorIsLeft)
		{
			std::cout << "LEFT\n";
		}
		else
		{
			std::cout << "RIGHT\n";
		}
	}
}

void Map::printMapPoints()
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < cols; j++)
		{
			std::cout << "[" << matrix[i][j].row << ", " << matrix[i][j].col << "] ";
		}
	}
	std::cout << "\n\n";
}



