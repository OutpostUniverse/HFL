#pragma once

// Extensions to the GameMap class
class GameMapEx : public GameMap
{
public:
	static MapTile GetTileEx(LOCATION where);
	static void SetTileEx(LOCATION where, MapTile newData);
	static int GetMapWidth();
	static int GetMapHeight();
	static int GetNumUnits();
	static int LoadMap(char *fileName);
	
	// Copies the visible area of the internal map to the destination array.
	// The array must be at least the width*height*sizeof(MapTile) of the visible area.
	// When accessing the copied map, the index used should not include padding.
	//
	// You should use CopyTileMap for the following situations:
	// - Multithreaded processing
	// - Maintaining a static map state across multiple ticks
	// - Restoring the map to a previous or original state
	// - Tracking changes to the map
	static void CopyTileMap(MapTile* destTileMap);
};

extern GameMapEx gMap;
extern void *mapObj;
extern void *mapTileData;
