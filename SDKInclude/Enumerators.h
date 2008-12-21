
// Note: This file is used to define the enumerator classes exported
//		 from Outpost2.exe. These classes can be used to search for
//		 or traverse a list of units one unit at a time.


// Group (enumerate all units in a group)
class OP2 GroupEnumerator
{
public:
	GroupEnumerator(class ScGroup &group);
	class GroupEnumerator & operator = (class GroupEnumerator const &);
	int GetNext(class Unit &currentUnit);

	int unknown;
};

// Vehicles (enumerate all units for a certain player)
class OP2 PlayerVehicleEnum
{
public:
	PlayerVehicleEnum(int playerNum);
	class PlayerVehicleEnum & operator = (class PlayerVehicleEnum const &);
	int GetNext(class Unit &currentUnit);	// Returns 1 and fills in Unit.unitID or Returns 0 when done

	int unknown;
};

// Buildings (enumerate all buildings of a certain type for a certain player)
class OP2 PlayerBuildingEnum
{
public:
	PlayerBuildingEnum(int playerNum, map_id buildingType);
	class PlayerBuildingEnum & operator = (class PlayerBuildingEnum const &);
	int GetNext(class Unit &currentUnit);	// Returns 0 when done

	int unknown1, unknown2;
};

// Units (enumerate all units of a certain player)
class OP2 PlayerUnitEnum
{
public:
	PlayerUnitEnum(int playerNum);
	class PlayerUnitEnum & operator = (class PlayerUnitEnum const &);
	int GetNext(class Unit &currentUnit);	// Returns 0 when done

	int unknown1, unknown2;
};

// Closest (enumerate all units ordered by their distance to a given location)
class OP2 ClosestEnumerator
{
public:
	ClosestEnumerator(struct LOCATION const &location);
	class ClosestEnumerator & operator = (class ClosestEnumerator const &);
	int GetNext(class Unit &currentUnit, unsigned long &distance);

	int unknown[13];
};

// InRange (enumerate all units within a given distance of a given location)
class OP2 InRangeEnumerator
{
public:
	InRangeEnumerator(struct LOCATION const &location, int distance);
	class InRangeEnumerator & operator = (class InRangeEnumerator const &);
	int GetNext(class Unit &currentUnit);

	int unknown[13];
};

// InRect (enumerate all units within a given rectangle)
class OP2 InRectEnumerator
{
public:
	InRectEnumerator(struct MAP_RECT const &rect);
	class InRectEnumerator & operator = (class InRectEnumerator const &);
	int GetNext(class Unit &currentUnit);

	int unknown[13];
};

// Location (enumerate all units at a given location)
class OP2 LocationEnumerator
{
public:
	LocationEnumerator(struct LOCATION const &location);
	class LocationEnumerator & operator = (class LocationEnumerator const &);
	int GetNext(class Unit &currentUnit);

	int unknown[13];
};

