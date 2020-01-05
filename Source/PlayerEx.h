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

	int GetNumAvailableWorkers();
	int GetNumAvailableScientists();
	int GetAmountPowerGenerated();
	int GetInactivePowerCapacity();
	int GetAmountPowerConsumed();
	int GetAmountPowerAvailable();
	int GetNumIdleBuildings();
	int GetNumActiveBuildings();
	int GetNumBuildings();
	int GetNumUnpoweredStructures();
	int GetNumWorkersRequired(); // Assigned workers and scientists
	int GetNumScientistsRequired(); // Assigned to buildings or researching
	int GetNumScientistsAsWorkers();
	int GetNumScientistsAssignedToResearch();
	int GetTotalFoodProduction();
	int GetTotalFoodConsumption();
	int GetFoodLacking(); // How much food if required to stop people from starving. This can be 0 even if there is a food deficit
	int GetNetFoodProduction();
	int GetNumSolarSatellites(); // Copy from bitfield at offset 8

	int GetTotalRecreationFacilityCapacity();
	int GetTotalForumCapacity();
	int GetTotalMedCenterCapacity();
	int GetTotalResidenceCapacity();
};

// ExtPlayer array that references the Player array
extern PlayerEx *ExtPlayer;

struct OP2Player;
extern OP2Player *playerArray;
