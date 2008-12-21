// GameMapEx.cpp
#include "HFL.h"

#pragma pack(push,1)
struct OP2Map
{
	int unknown;
	unsigned int pixelWidthMask;
	int pixelWidth;
	unsigned int tileXMask;
	int tileWidth;
	unsigned char logTileWidth; // base 2 log
	char filler1[3];
	MAP_RECT clipRect;
	int numTiles;
	int numTileSets;
	unsigned char logTileHeight; // base 2 log
	char filler2[3];
	int unknown2;
	int numUnits;
	int unknown3[4];
};
#pragma pack(pop)

GameMapEx gMap;
void *mapObj;
void *mapTileData;

MapTile GameMapEx::GetTileEx(LOCATION where)
{
	MapTile t;
	memset(&t, 0, sizeof(t));

	if (!isInited)
		return t;

	OP2Map *p = (OP2Map*)mapObj;
	MapTile *tiles = (MapTile*)mapTileData;

	unsigned int a = where.x & p->tileXMask;
	unsigned int b = (((a & 31) / 32) << p->logTileHeight) + where.y;

	t = tiles[b * 32 + a];
	return t;
}

void GameMapEx::SetTileEx(LOCATION where, MapTile newData)
{
	if (!isInited)
		return;

	OP2Map *p = (OP2Map*)mapObj;
	MapTile *tiles = (MapTile*)mapTileData;

	unsigned int a = where.x & p->tileXMask;
	unsigned int b = (((a & 31) / 32) << p->logTileHeight) + where.y;

	tiles[b * 32 + a] = newData;
}

int GameMapEx::GetMapWidth()
{
	if (!isInited)
		return HFLNOTINITED;

	OP2Map *p = (OP2Map*)mapObj;

	return 1 << p->logTileWidth;
}

int GameMapEx::GetMapHeight()
{
	if (!isInited)
		return HFLNOTINITED;

	OP2Map *p = (OP2Map*)mapObj;

	return 1 << p->logTileHeight;
}

int GameMapEx::GetNumUnits()
{
	if (!isInited)
		return HFLNOTINITED;

	OP2Map *p = (OP2Map*)mapObj;
	return p->numUnits;
}

int GameMapEx::LoadMap(char *fileName)
{
	if (!isInited)
		return HFLNOTINITED;

	OP2Map *p = (OP2Map*)mapObj;

	int (__fastcall *func)(OP2Map* classPtr, int dummy, char *fileName) = (int (__fastcall *)(OP2Map*,int,char*))(imageBase + 0x37310);
	
	return func(p, 0, fileName);
}
