
// Note: This file contains the _Player class definition exported from
//		 Outpost2.exe. Use this class to modify anything associated
//		 with a player (human or AI).
// Note: The AI in Outpost 2 is sadly faked. Using _Player.GoAI() is
//		 essentially creating a computer controlled player that cheats.
//		 It's given essentially unlimited population resources and so
//		 it doesn't have to worry about food or idling buildings due
//		 to lack of workers. You can make a much more realistic AI
//		 if you leave the player set as human and just program all
//		 the actions yourself (which you'd have to do anyways since 
//		 Outpost 2 has no real AI and all computer actions are
//		 hardcoded into each DLL).


class OP2 _Player
{
public:
	_Player(int);
	class _Player & operator=(class _Player const &);
	void AllyWith(int playerId);
	void CaptureRLV(int);
	void CenterViewOn(int tileX, int tileY);
	int Difficulty() const;
	int FoodStored() const;
	enum FoodStatus FoodSupply() const;
	class ScGroup GetDefaultGroup();
	int GetPlayerStrength(struct MAP_RECT &area);
	int GetRLVCount();
	int GetTotalPlayerStrength();
	void GoAI();
	void GoEden();
	void GoHuman();
	void GoPlymouth();
	int HasTechnology(int techID) const;
	int IsEden();
	int IsHuman();
	int Kids() const;
	void MarkResearchComplete(int techID);
	enum MoraleLevels MoraleLevel() const;
	int Ore() const;
	int RareOre() const;
	int Scientists() const;
	void SetColorNumber(int colorId);
	void SetDefaultGroup(class ScGroup &);
	void SetFoodStored(int foodAmt);
	void SetKids(int numKids);
	void SetOre(int commonOreAmt);
	void SetRareOre(int rareOreAmt);
	void SetScientists(int numScis);
	void SetSolarSat(int numSats);
	void SetTechLevel(int techLevelId);
	void SetWorkers(int numWorkers);
	int Workers() const;
	int canAccumulateOre();
	int canAccumulateRareOre();
	int canBuildBuilding();
	int canBuildSpace();
	int canBuildVehicle(int vehicleType);
	int canDoResearch(int techID);
	int hasActiveCommand();
	int hasVehicle(enum map_id vehicleType, enum map_id cargoType);
	void resetChecks();

	int playerNum, unknown2, unknown3;
};
