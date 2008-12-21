// Common header stuff to prevent redefinition errors
//  if the header is included more than once
#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <Outpost2DLL.h>

// Note: The following structures are used to 
//		 define resource and base layouts.

struct BeaconInfo
{
	int x;
	int y;
	enum map_id type;
	int rare;
	int bar;
	int variant;
};

struct BuildingInfo
{
	int x;
	int y;
	enum map_id type;
};

struct VehicleInfo
{
	int x;
	int y;
	enum map_id type;
	enum map_id weaponCargo;
	int dir;
};

struct TubeWallInfo
{
	int fromX;
	int fromY;
	int toX;
	int toY;
};

struct BaseInfo
{
	int numBeacons;
	struct BeaconInfo *beaconInfo;
	int numBuilding;
	struct BuildingInfo *bldnInfo;
	int numTubeLine;
	struct TubeWallInfo *tubeInfo;
	int numWallLine;
	struct TubeWallInfo *wallInfo;
	int numVehicle;
	struct VehicleInfo *vehicleInfo;
};

struct StartLocation
{
	int x;
	int y;
	BaseInfo *baseInfo;
};


// Note: These are very useful for randomizing player start locations and
//		 beacon starting locations, among other things.
// Note: If used for placing beacons, it would be wise to have a seperate
//		 list for each starting location so not all the beacons end up
//		 appearing in a single player's base, and so you don't get only a
//		 single resource type placed on the map.
// Note: These functions are based off of RandomizeList and is used to
//		 generate a random permutation of the given list.

void RandomizeResources(int numItems, struct BeaconInfo resources[]);
void RandomizeStartingLocations(int numLocations, struct StartLocation location[]);

// Base/Resource Placement
void CreateBase(int player, int x, int y, BaseInfo &baseInfo);
void CreateBeacons(int numBeacons, struct BeaconInfo beacon[]);

#endif	// End of redefinition error protection
