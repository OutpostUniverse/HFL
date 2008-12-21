// Common header stuff to prevent redefinition errors
//  if the header is included more than once
#ifndef OP2HELPER_H
#define OP2HELPER_H

// Include the main DLL SDK header file
#include <Outpost2DLL.h>

// Include other helper header files
#include <EnumTechID.h>
#include <EnumSoundID.h>
#include <BaseBuilder.h>

// Useful macros
#define MkXY(x,y) (LOCATION(x+31,y-1))
#define MkRect(x1,y1,x2,y2) (MAP_RECT(LOCATION(x1+31,y1-1),LOCATION(x2+31,y2-1)))
#define XYPos(x,y) x+31,y-1
#define RectPos(x1,y1,x2,y2) x1+31,y1-1,x2+31,y2-1

// X and Y offset consts
const int X_ = 31;
const int Y_ = -1;

// *************************************************
// Note: The following are general purpose functions
//		 to help you implement your map.

// Starting Resources
void InitPlayerResources(int playerNum);

// Constructing Tubes/Walls
void CreateTubeOrWallLine(int x1, int y1, int x2, int y2, map_id type);

// Victory Conditions
void CreateStarshipVictoryCondition();
void CreateLastOneStandingVictoryCondition();
void CreateNoCommandCenterFailureCondition();


// Randomizing Lists
// Note: This function creates a random permutation of a given list.
//		 All permutations are equally likely to be generated.
// Note: Using these functions requires having a preset list of possible
//		 locations (or values). This allows more control than having things
//		 spread all over the map completely random but still allows things
//		 to vary each time the level is played.
// Note: See BaseBuilder.h for specifically designed functions to permute
//		 a list of starting locations, or a list of mining beacons.
void RandomizeList(int numItems, int list[]);



#endif	// End of redefinition error protection
