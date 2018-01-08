#ifndef ROOM_DATA_H
#define ROOM_DATA_H

#include "Structs.h"
#include "Room.h"
#include <vector>
#include <string>
//MASTER LIST OF ROOM DATA

/*
REFERENCE FOR NEEDED GRIDS

[-2,-2] [-2,-1] [-2, 0] [-2, 1] [-2, 2]
[-1,-2] [-1,-1] [-1, 0] [-1, 1] [-1, 2]
[ 0,-2] [ 0,-1] [ 0, 0] [ 0, 1] [ 0, 2]
[ 1,-2] [ 1,-1] [ 1, 0] [ 1, 1] [ 1, 2]
[ 2,-2] [ 2,-1] [ 2, 0] [ 2, 1] [ 2, 2]

*/

//RECTANGULAR DOORS
std::vector<door> DOORS_L_1x1 = { { 0, 0, { { 0, 0 } } } };			// Looks like: #
std::vector<door> DOORS_R_1x1 = { { 0, 0, { { 0, 0 } } } };	
Room ROOM_1x1("ROOM_1x1", DOORS_L_1x1, DOORS_R_1x1);										

std::vector<door> DOORS_L_1x2 = { { 0, 0, { { 0, 0 }, { 0, 1 } } } };				// Looks like: ##
std::vector<door> DOORS_R_1x2 = { { 0, 1, { { 0, 0 }, { 0,-1 } } } };																		//
Room ROOM_1x2("ROOM_1x2", DOORS_L_1x2, DOORS_R_1x2);

std::vector<door> DOORS_L_1x3 = { { 0, 0, { { 0, 0 }, { 0, 1 }, { 0, 2 } } } };				// Looks like: ###
std::vector<door> DOORS_R_1x3 = { { 0, 2, { { 0, 0 }, { 0,-1 }, { 0,-2 } } } };																	//
Room ROOM_1x3("ROOM_1x3", DOORS_L_1x3, DOORS_R_1x3);

std::vector<door> DOORS_L_2x1 = { { 0, 0, { { 0, 0 }, { 1, 0 } } }, 					// Looks like: #
								  { 1, 0, { { 0, 0 }, {-1, 0 } } } };									//			   #
std::vector<door> DOORS_R_2x1 = { { 0, 0, { { 0, 0 }, { 1, 0 } } },					// Looks like: #
								  { 1, 0, { { 0, 0 }, {-1, 0 } } } };	
Room ROOM_2x1("ROOM_2x1", DOORS_L_2x1, DOORS_R_2x1);

std::vector<door> DOORS_L_3x1 = { { 0, 0, { { 0, 0 }, { 1, 0 }, { 2, 0 } } },				// Looks like: #
								  { 1, 0, { {-1, 0 }, { 0, 0 }, { 1, 0 } } }, 									//			   #
								  { 2, 0, { {-2, 0 }, {-1, 0 }, { 0, 0 } } } };									//		       #
std::vector<door> DOORS_R_3x1 = { { 0, 0, { { 0, 0 }, { 1, 0 }, { 2, 0 } } },				// Looks like: #
								  { 1, 0, { {-1, 0 }, { 0, 0 }, { 1, 0 } } }, 									//			   #
								  { 2, 0, { {-2, 0 }, {-1, 0 }, { 0, 0 } } } };
Room ROOM_3x1("ROOM_3x1", DOORS_L_3x1, DOORS_R_3x1);

std::vector<door> DOORS_L_2x2 = { { 0, 0, { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } } },					// Looks like: ##
								  { 1, 0, { { 0, 0 }, { 0, 1 }, {-1, 0 }, {-1, 1 } } } };									//		       ##
std::vector<door> DOORS_R_2x2 = { { 0, 1, { { 0, 0 }, { 0,-1 }, { 1, 0 }, { 1,-1 } } },					// Looks like: ##
								  { 1, 1, { { 0, 0 }, { 0,-1 }, {-1, 0 }, {-1,-1 } } } };	//		       
Room ROOM_2x2("ROOM_2x2", DOORS_L_2x2, DOORS_R_2x2);

std::vector<door> DOORS_L_2x3 = { { 0, 0, { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 } } },					// Looks like: ###
								  { 1, 0, { { 0, 0 }, { 0, 1 }, { 0, 2 }, {-1, 0 }, {-1, 1 }, {-1, 2 } } } };									//		       ###
std::vector<door> DOORS_R_2x3 = { { 0, 2, { { 0, 0 }, { 0,-1 }, { 0,-2 }, { 1, 0 }, { 1,-1 }, { 1,-2 } } },					// Looks like: ###
								  { 1, 2, { { 0, 0 }, { 0,-1 }, { 0,-2 }, {-1, 0 }, {-1,-1 }, {-1,-2 } } } };	//			   
Room ROOM_2x3("ROOM_2x3", DOORS_L_2x3, DOORS_R_2x3);

std::vector<door> DOORS_L_3x2 = { { 0, 0, { { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 0 }, { 2, 1 } } },					// Looks like: ##
								  { 1, 0, { {-1, 0 }, {-1, 1 }, { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } } }, 									//			   ##
								  { 2, 0, { {-2, 0 }, {-2, 1 }, {-1, 0 }, {-1, 1 }, { 0, 0 }, { 0, 1 } } } };									//		       ##
std::vector<door> DOORS_R_3x2 = { { 0, 1, { { 0,-1 }, { 0, 0 }, { 1,-1 }, { 1, 0 }, { 2,-1 }, { 2, 0 } } },					// Looks like: ##
								  { 1, 1, { {-1,-1 }, {-1, 0 }, { 0,-1 }, { 0, 0 }, { 1,-1 }, { 1, 0 } } },
								  { 2, 1, { {-2,-1 }, {-2, 0 }, {-1,-1 }, {-1, 0 }, { 0,-1 }, { 0, 0 } } } };
Room ROOM_3x2("ROOM_3x2", DOORS_L_3x2, DOORS_R_3x2);

std::vector<door> DOORS_L_3x3 = { { 0, 0, { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2,2 } } },				// Looks like: ###
								  { 1, 0, { {-1, 0 }, {-1, 1 }, {-1, 2 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1,2 } } }, 									//			   ###
								  { 2, 0, { {-2, 0 }, {-2, 1 }, {-2, 2 }, {-1, 0 }, {-1, 1 }, {-1, 2 }, { 0, 0 }, { 0, 1 }, { 0,2 } } } };									//		       ###
std::vector<door> DOORS_R_3x3 = { { 0, 2, { { 0,-2 }, { 0,-1 }, { 0, 0 }, { 1,-2 }, { 1,-1 }, { 1, 0 }, { 2,-2 }, { 2,-1 }, { 2,0 } } },					// Looks like: ###
								  { 1, 2, { {-1,-2 }, {-1,-1 }, {-1, 0 }, { 0,-2 }, { 0,-1 }, { 0, 0 }, { 1,-2 }, { 1,-1 }, { 1,0 } } }, 									//			   ###
								  { 2, 2, { {-2,-2 }, {-2,-1 }, {-2, 0 }, {-1,-2 }, {-1,-1 }, {-1, 0 }, { 0,-2 }, { 0,-1 }, { 0,0 } } } };
Room ROOM_3x3("ROOM_3x3", DOORS_L_3x3, DOORS_R_3x3);

//																	//ELBOW ROOMS
//																	//Letters correspond to location of corner: TL = Top Left
//std::vector<door> DOORS_2x2_ELBOW_TL = { { 0, 0, true },{ 0, 1, false },		// Looks like: ##
//{ 1, 0, true },{ 1, 0, false } };									//			   #	
//																	//
//
//std::vector<door> DOORS_2x2_ELBOW_TR = { { 0, 0, true },{ 0, 1, false },		// Looks like: ##
//{ 1, 1, true },{ 1, 1, false } };									//				#
//																	//
//
//std::vector<door> DOORS_2x2_ELBOW_BL = { { 0, 0, true },{ 0, 0, false },		// Looks like: #
//{ 1, 0, true },{ 1, 1, false } };									//			   ##
//																	//
//
//std::vector<door> DOORS_2x2_ELBOW_BR = { { 0, 1, true },{ 0, 1, false },		// Looks like:  #
//{ 1, 0, true },{ 1, 1, false } };									//			   ##
//																	//
//
//std::vector<door> DOORS_2x3_ELBOW_TL = { { 0, 0, true },{ 0, 2, false },		// Looks like: ###
//{ 1, 0, true },{ 1, 0, false } };									//			   #
//																	//
//
//std::vector<door> DOORS_2x3_ELBOW__TR = { { 0, 2, true },{ 0, 2, false },		// Looks like: ###
//{ 1, 2, true },{ 1, 2, false } };									//				 # 
//																	//
//
//std::vector<door> DOORS_2x3_ELBOW_BL = { { 0, 0, true },{ 0, 0, false },		// Looks like: #
//{ 1, 0, true },{ 1, 2, false } };									//			   ###	
//																	//
//
//std::vector<door> DOORS_2x3_ELBOW_BR = { { 0, 2, true },{ 0, 2, false },		// Looks like:   #
//{ 1, 0, true },{ 1, 2, false } };									//			   ###
//																	//
//
//std::vector<door> DOORS_3x2_ELBOW_TL = { { 0, 0, true },{ 0, 1, false },		// Looks like: ##
//{ 1, 0, true },{ 1, 0, false },										//			   #
//{ 2, 0, true },{ 2, 0, false } };									//			   #
//
//std::vector<door> DOORS_3x2_ELBOW__TR = { { 0, 0, true },{ 0, 1, false },		// Looks like: ##
//{ 1, 1, true },{ 1, 1, false },										//				#
//{ 2, 1, true },{ 2, 1, false } };									//				#
//
//std::vector<door> DOORS_3x2_ELBOW_BL = { { 0, 0, true },{ 0, 0, false },		// Looks like: #
//{ 1, 0, true },{ 1, 0, false },		//			   #
//{ 2, 0, true },{ 2, 1, false } };		//			   ##
//
//std::vector<door> DOORS_3x2_ELBOW_BR = { { 0, 1, true },{ 0, 1, false },		// Looks like:  #
//{ 1, 1, true },{ 1, 1, false },		//				#
//{ 2, 0, true },{ 2, 1, false } };		//			   ##
//
//										//OTHER SHAPES
//										//Letter corresponds to location of middle piece: T = top
//std::vector<door> DOORS_T_T = { { 0, 1, true },{ 0, 1, false },				// Looks like:  #
//{ 1, 0, true },{ 1, 2, false } };				//			   ###
//												//
//
//std::vector<door> DOORS_T_B = { { 0, 0, true },{ 0, 2, false },				// Looks like: ###
//{ 1, 1, true },{ 1, 1, false } };				//				#
//												//
//
//std::vector<door> DOORS_T_L = { { 0, 1, true },{ 0, 1, false },				// Looks like:  #
//{ 1, 0, true },{ 1, 1, false },				//			   ##
//{ 2, 1, true },{ 2, 1, false } };				//				#
//
//
//std::vector<door> DOORS_T_R = { { 0, 0, true },{ 0, 0, false },				// Looks like: #
//{ 1, 0, true },{ 1, 1, false },				//			   ##
//{ 2, 0, true },{ 2, 0, false } };				//			   #
//
//
//std::vector<door> DOORS_PLUS = { { 0, 1, true },{ 0, 1, false },				// Looks like:  #
//{ 1, 0, true },{ 1, 2, false },				//			   ###
//{ 2, 1, true },{ 2, 1, false } };				//				#
//
//std::vector<door> DOORS_TAILED_L = { { 0, 1, true },{ 0, 2, false },			// Looks like: ##
//{ 1, 0, true },{ 1, 2, false } };			//			   ###
//											//
//
//std::vector<door> DOORS_TAILED_R = { { 0, 0, true },{ 0, 1, false },			// Looks like:  ##
//{ 1, 0, true },{ 1, 2, false } };			//			   ###
//											//


#endif