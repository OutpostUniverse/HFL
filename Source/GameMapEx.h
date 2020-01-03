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
	static void CopyTileMap(int* tileMap);
};

extern GameMapEx gMap;
extern void *mapObj;
extern void *mapTileData;
