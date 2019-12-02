#pragma once

// Extends the Player class defined in Outpost2DLL
class PlayerEx : public _Player
{
public:
	char* GetPlayerName();
	void SetPlayerName(char *newName);
	int GetSatelliteCount(map_id objectType);
	void SetSatelliteCount(map_id objectType, int count);
	int GetColorNumber();
	int IsAlliedTo(int playerId);
	int GetNumBuildingsBuilt();
	int ProcessCommandPacket(CommandPacket *packet);
	void Starve(int numToStarve, int boolSkipMoraleUpdate);
	CommandPacket* GetNextCommandPacketAddress();
	int GetMaxOre();
	int GetMaxRareOre();
	void RecalculateValues();
	// todo: anything else?
};

// ExtPlayer array that references the Player array
extern PlayerEx *ExtPlayer;

struct OP2Player;
extern OP2Player *playerArray;
