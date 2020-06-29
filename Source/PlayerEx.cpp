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
	int numAvailableWorkers;             // 56EFC0 0x0A4
	int numAvailableScientists;
	int amountPowerGenerated;
	int inactivePowerCapacity;
	int amountPowerConsumed;
	int amountPowerAvailable;
	int numIdleBuildings;
	int numActiveBuildings;
	int numBuildings;
	int numUnpoweredStructures;
	int numWorkersRequired;              // 56EFE8 0x0CC
	int numScientistsRequired;           // 56EFEC 0x0D0
	int numScientistsAsWorkers;
	int numScientistsAssignedToResearch;
	int totalFoodProduction;
	int totalFoodConsumption;
	int foodLacking;                     // 56F000 0x0E4
	int netFoodProduction;
	int numSolarSatellites;	             // 56F008 0x0EC

	// 56F00C 0x0F0 TotalCapacities
	int totalRecreationFacilityCapacity; // 56F00C 0x0F0
	int totalForumCapacity;              // 56F010 0x0F4
	int totalMedCenterCapacity;          // 56F014 0x0F8
	int totalResidenceCapacity;          // 56F018 0x0FC
	int unk3[47];
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
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	char* (__fastcall *func)(OP2Player *classPtr) = (char* (__fastcall *)(OP2Player*))(imageBase + 0x90C80);
	return func(&playerArray[playerNum]);
}

void PlayerEx::SetPlayerName(char *newName)
{
	if (!isInited) {
		return;
	}

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
	return isInited ? playerArray[playerNum].colorNumber : HFLNOTINITED;
}

int PlayerEx::IsAlliedTo(int playerId)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (playerId < 0 || playerId > 6) {
		return -1;
	}

	return (playerArray[playerNum].playerBitmask >> playerId) & 1;
}

int PlayerEx::GetNumBuildingsBuilt()
{
	return isInited ? playerArray[playerNum].numBuildingsBuilt : HFLNOTINITED;
}

int PlayerEx::ProcessCommandPacket(CommandPacket *packet)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	int (__fastcall *func)(OP2Player *classPtr, int dummy, CommandPacket *packet) = (int (__fastcall *)(OP2Player*,int,CommandPacket*))(imageBase + 0x0E300);
	return func(&playerArray[playerNum], 0, packet);
}

void PlayerEx::Starve(int numToStarve, int boolSkipMoraleUpdate)
{
	if (!isInited) {
		return;
	}

	void (__fastcall *func)(OP2Player *classPtr, int dummy, int numStarve, int skipMoraleUpdate) = (void (__fastcall *)(OP2Player*,int,int,int))(imageBase + 0x71C70);
	func(&playerArray[playerNum], 0, numToStarve, boolSkipMoraleUpdate);
}

CommandPacket* PlayerEx::GetNextCommandPacketAddress()
{
	if (!isInited) {
		return (CommandPacket*)HFLNOTINITED;
	}

	CommandPacket* (__fastcall *func)(OP2Player *classPtr) = (CommandPacket* (__fastcall *)(OP2Player*))(imageBase + 0x90810);
	return func(&playerArray[playerNum]);
}

int PlayerEx::GetMaxOre()
{
	return isInited ? playerArray[playerNum].maxCommonOre : HFLNOTINITED;
}

int PlayerEx::GetMaxRareOre()
{
	return isInited ? playerArray[playerNum].maxRareOre : HFLNOTINITED;
}

void PlayerEx::RecalculateValues()
{
	if (!isInited) {
		return;
	}

	playerArray[playerNum].boolRecalcValues = 1;
}

int PlayerEx::GetNumAvailableWorkers()
{ 
	return isInited ? playerArray[playerNum].numAvailableWorkers : HFLNOTINITED;
}

int PlayerEx::GetNumAvailableScientists()
{ 
	return isInited ? playerArray[playerNum].numAvailableScientists : HFLNOTINITED;
}

int PlayerEx::GetAmountPowerGenerated()
{ 
	return isInited ? playerArray[playerNum].amountPowerGenerated : HFLNOTINITED;
}

int PlayerEx::GetInactivePowerCapacity()
{ 
	return isInited ? playerArray[playerNum].inactivePowerCapacity : HFLNOTINITED;
}

int PlayerEx::GetAmountPowerConsumed()
{ 
	return isInited ? playerArray[playerNum].amountPowerConsumed : HFLNOTINITED;
}

int PlayerEx::GetAmountPowerAvailable()
{
	return isInited ? playerArray[playerNum].amountPowerAvailable : HFLNOTINITED;
}

int PlayerEx::GetNumIdleBuildings()
{
	return isInited ? playerArray[playerNum].numIdleBuildings : HFLNOTINITED;
}

int PlayerEx::GetNumActiveBuildings()
{
	return isInited ? playerArray[playerNum].numActiveBuildings : HFLNOTINITED;
}

int PlayerEx::GetNumBuildings() 
{
	return isInited ? playerArray[playerNum].numBuildings : HFLNOTINITED;
}

int PlayerEx::GetNumUnpoweredStructures()
{
	return isInited ? playerArray[playerNum].numUnpoweredStructures : HFLNOTINITED;
}

int PlayerEx::GetNumWorkersRequired()
{
	return isInited ? playerArray[playerNum].numWorkersRequired : HFLNOTINITED;
}

int PlayerEx::GetNumScientistsRequired()
{
	return isInited ? playerArray[playerNum].numScientistsRequired : HFLNOTINITED;
}

int PlayerEx::GetNumScientistsAsWorkers()
{
	return isInited ? playerArray[playerNum].numScientistsAsWorkers : HFLNOTINITED;
}

int PlayerEx::GetNumScientistsAssignedToResearch()
{
	return isInited ? playerArray[playerNum].numScientistsAssignedToResearch : HFLNOTINITED;
}

int PlayerEx::GetTotalFoodProduction()
{
	return isInited ? playerArray[playerNum].totalFoodProduction : HFLNOTINITED;
}

int PlayerEx::GetTotalFoodConsumption()
{
	return isInited ? playerArray[playerNum].totalFoodConsumption : HFLNOTINITED;
}

int PlayerEx::GetFoodLacking()
{
	return isInited ? playerArray[playerNum].foodLacking : HFLNOTINITED;
}

int PlayerEx::GetNetFoodProduction()
{
	return isInited ? playerArray[playerNum].netFoodProduction : HFLNOTINITED;
}

int PlayerEx::GetNumSolarSatellites()
{
	return isInited ? playerArray[playerNum].numSolarSatellites : HFLNOTINITED;
}


int PlayerEx::GetTotalRecreationFacilityCapacity()
{
	return isInited ? playerArray[playerNum].totalRecreationFacilityCapacity : HFLNOTINITED;
}

int PlayerEx::GetTotalForumCapacity()
{
	return isInited ? playerArray[playerNum].totalForumCapacity : HFLNOTINITED;
}

int PlayerEx::GetTotalMedCenterCapacity()
{
	return isInited ? playerArray[playerNum].totalMedCenterCapacity : HFLNOTINITED;
}

int PlayerEx::GetTotalResidenceCapacity()
{
	return isInited ? playerArray[playerNum].totalResidenceCapacity : HFLNOTINITED;
}
