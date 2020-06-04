// PlayerEx.cpp
#include "HFL.h"

#pragma pack(push,1)
struct OP2Player
{
	int playerId;
	unsigned int playerBitmask;
	struct {
		unsigned int rlv :4;
		unsigned int solarSat :4;
		unsigned int sUnk0 : 1;
		unsigned int edwardSat :4;
		unsigned int ionDrive : 1;
		unsigned int fusionDrive : 1;
		unsigned int commandModule : 1;
		unsigned int fuelingSystems : 1;
		unsigned int habitatRing : 1;
		unsigned int sensorPackage : 1;
		unsigned int skydock :1;
		unsigned int stasisSystems : 1;
		unsigned int orbitalPackage : 1;
		unsigned int phoenixModule : 1;
		unsigned int rareCargo : 1;
		unsigned int commonCargo : 1;
		unsigned int foodCargo : 1;
		unsigned int evacModule : 1;
		unsigned int childCargo :1;
		unsigned int sUnk1 :4;
	} satellites;
	int difficulty;
	int foodStored;
	int unk0;
	int maxCommonOre;
	int maxRareOre;
	int commonOre;
	int rareOre;
	int isHuman;
	int isEden;
	int colorNumber;
	int moraleLevel;
	int unk1[5];
	int foodSupply;
	int unk2[17];
	int workers;
	int scientists;
	int kids;
	int boolRecalcValues;
	int unk3[70];
	int numBuildingsBuilt;
	int unk4[662];
	Unit *buildingList;
	Unit *vehicleList;
	int unk5;
};
#pragma pack(pop)

OP2Player *playerArray;

PlayerEx *ExtPlayer = (PlayerEx*)&Player[0];

char* PlayerEx::GetPlayerName()
{
	if (!isInited)
		return (char*)HFLNOTINITED;

	char* (__fastcall *func)(OP2Player *classPtr) = (char* (__fastcall *)(OP2Player*))(imageBase + 0x90C80);
	return func(&playerArray[playerNum]);
}

void PlayerEx::SetPlayerName(char *newName)
{
	if (!isInited)
		return;

	void (__fastcall *func)(OP2Player *classPtr, int dummy, char *name) = (void (__fastcall *)(OP2Player*,int,char*))(imageBase + 0x90CB0);
	func(&playerArray[playerNum], 0, newName);
}

int PlayerEx::GetSatelliteCount(map_id objectType)
{
	if (!isInited)
		return HFLNOTINITED;

	switch (objectType)
	{
	case mapRLV:
		return playerArray[playerNum].satellites.rlv;
	case mapSolarSatellite:
		return playerArray[playerNum].satellites.solarSat;
	case mapEDWARDSatellite:
		return playerArray[playerNum].satellites.edwardSat;
	case mapEvacuationModule:
		return playerArray[playerNum].satellites.evacModule;
	case mapChildrenModule:
		return playerArray[playerNum].satellites.childCargo;
	case mapRareMetalsCargo:
		return playerArray[playerNum].satellites.rareCargo;
	case mapCommonMetalsCargo:
		return playerArray[playerNum].satellites.commonCargo;
	case mapFoodCargo:
		return playerArray[playerNum].satellites.foodCargo;
	case mapPhoenixModule:
		return playerArray[playerNum].satellites.phoenixModule;
	case mapOrbitalPackage:
		return playerArray[playerNum].satellites.orbitalPackage;
	case mapStasisSystems:
		return playerArray[playerNum].satellites.stasisSystems;
	case mapSkydock:
		return playerArray[playerNum].satellites.skydock;
	case mapSensorPackage:
		return playerArray[playerNum].satellites.sensorPackage;
	case mapHabitatRing:
		return playerArray[playerNum].satellites.habitatRing;
	case mapFuelingSystems:
		return playerArray[playerNum].satellites.fuelingSystems;
	case mapCommandModule:
		return playerArray[playerNum].satellites.commandModule;
	case mapFusionDriveModule:
		return playerArray[playerNum].satellites.fusionDrive;
	case mapIonDriveModule:
		return playerArray[playerNum].satellites.ionDrive;
	default:
		return 0;
	}
}

void PlayerEx::SetSatelliteCount(map_id objectType, int count)
{
	if (!isInited)
		return;

	switch (objectType)
	{
	case mapRLV:
		// Note: changing the player's RLV count doesn't seem to actually give that player RLVs - I'm guessing there's some kind of "landing timer" that needs to be set, otherwise they remain in orbit forever.
		playerArray[playerNum].satellites.rlv = count;
		break;
	case mapSolarSatellite:
		playerArray[playerNum].satellites.solarSat = count;
		break;
	case mapEDWARDSatellite:
		playerArray[playerNum].satellites.edwardSat = count;
		break;
	case mapEvacuationModule:
		playerArray[playerNum].satellites.evacModule = 1;
		break;
	case mapChildrenModule:
		playerArray[playerNum].satellites.childCargo = 1;
		break;
	case mapRareMetalsCargo:
		playerArray[playerNum].satellites.rareCargo = 1;
		break;
	case mapCommonMetalsCargo:
		playerArray[playerNum].satellites.commonCargo = 1;
		break;
	case mapFoodCargo:
		playerArray[playerNum].satellites.foodCargo = 1;
		break;
	case mapPhoenixModule:
		playerArray[playerNum].satellites.phoenixModule = 1;
		break;
	case mapOrbitalPackage:
		playerArray[playerNum].satellites.orbitalPackage = 1;
		break;
	case mapStasisSystems:
		playerArray[playerNum].satellites.stasisSystems = 1;
		break;
	case mapSkydock:
		playerArray[playerNum].satellites.skydock = 1;
		break;
	case mapSensorPackage:
		playerArray[playerNum].satellites.sensorPackage = 1;
		break;
	case mapHabitatRing:
		playerArray[playerNum].satellites.habitatRing = 1;
		break;
	case mapFuelingSystems:
		playerArray[playerNum].satellites.fuelingSystems = 1;
		break;
	case mapCommandModule:
		playerArray[playerNum].satellites.commandModule = 1;
		break;
	case mapFusionDriveModule:
		playerArray[playerNum].satellites.fusionDrive = 1;
		break;
	case mapIonDriveModule:
		playerArray[playerNum].satellites.ionDrive = 1;
		break;
	}
}

int PlayerEx::GetColorNumber()
{
	if (!isInited)
		return HFLNOTINITED;

	return playerArray[playerNum].colorNumber;
}

int PlayerEx::IsAlliedTo(int playerId)
{
	if (!isInited)
		return HFLNOTINITED;

	if (playerId < 0 || playerId > 6)
		return -1;

	return (playerArray[playerNum].playerBitmask >> playerId) & 1;
}

int PlayerEx::GetNumBuildingsBuilt()
{
	if (!isInited)
		return HFLNOTINITED;

	return playerArray[playerNum].numBuildingsBuilt;
}

int PlayerEx::ProcessCommandPacket(CommandPacket *packet)
{
	if (!isInited)
		return HFLNOTINITED;

	int (__fastcall *func)(OP2Player *classPtr, int dummy, CommandPacket *packet) = (int (__fastcall *)(OP2Player*,int,CommandPacket*))(imageBase + 0x0E300);
	return func(&playerArray[playerNum], 0, packet);
}

void PlayerEx::Starve(int numToStarve, int boolSkipMoraleUpdate)
{
	if (!isInited)
		return;

	void (__fastcall *func)(OP2Player *classPtr, int dummy, int numStarve, int skipMoraleUpdate) = (void (__fastcall *)(OP2Player*,int,int,int))(imageBase + 0x71C70);
	func(&playerArray[playerNum], 0, numToStarve, boolSkipMoraleUpdate);
}

CommandPacket* PlayerEx::GetNextCommandPacketAddress()
{
	if (!isInited)
		return (CommandPacket*)HFLNOTINITED;

	CommandPacket* (__fastcall *func)(OP2Player *classPtr) = (CommandPacket* (__fastcall *)(OP2Player*))(imageBase + 0x90810);
	return func(&playerArray[playerNum]);
}

int PlayerEx::GetMaxOre()
{
	if (!isInited)
		return HFLNOTINITED;

	return playerArray[playerNum].maxCommonOre;
}

int PlayerEx::GetMaxRareOre()
{
	if (!isInited)
		return HFLNOTINITED;

	return playerArray[playerNum].maxRareOre;
}

void PlayerEx::RecalculateValues()
{
	if (!isInited)
		return;

	playerArray[playerNum].boolRecalcValues = 1;
}
