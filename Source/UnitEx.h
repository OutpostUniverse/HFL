#pragma once

// Extends the Unit class defined in Outpost2DLL
class UnitEx : public Unit
{
public:
	void DoAttack(LOCATION where);
	void DoDeployMiner(LOCATION where);
	void DoDoze(MAP_RECT area);
	void DoDock(LOCATION dockLocation);
	void DoDockAtGarage(LOCATION dockLocation);
	void DoStandGround(LOCATION where);
	void DoBuildWall(map_id wallType, MAP_RECT area);
	void DoRemoveWall(MAP_RECT area);
	void DoProduce(map_id unitType, map_id cargoWeaponType);
	void DoTransferCargo(int bay);
	void DoLoadCargo();
	void DoUnloadCargo();
	void DoDumpCargo();
	void DoResearch(int techID, int numScientists);
	void DoTrainScientists(int numToTrain);
	void DoRepair(Unit what);
	void DoReprogram(Unit what);
	void DoDismantle(Unit what);
	void DoSalvage(MAP_RECT area, Unit gorf);
	void DoGuard(Unit what);
	void DoPoof();
	CommandType GetLastCommand();
	ActionType GetCurAction();
	int CreatorID();
	int GetTimeEMPed();
	int GetTimeStickyfoamed();
	bool IsStickyfoamed();
	int GetTimeESGed();
	bool IsESGed();
	int GetDamage();
	int GetCargoAmount();
	Truck_Cargo GetCargoType();
	int GetWorkersInTraining();
	map_id GetFactoryCargo(int bay);
	map_id GetFactoryCargoWeapon(int bay);
	map_id GetLaunchPadCargo();
	void SetLaunchPadCargo(map_id moduleType);
	map_id GetConVecCargoTurret();
	int GetLights();
	int GetDoubleFireRate();
	int GetInvisible();
	int HasPower();
	int HasWorkers();
	int HasScientists();
	int IsInfected();
	void SetDoubleFireRate(int boolOn);
	void SetInvisible(int boolOn);
	LOCATION GetDockLocation();
	UnitInfo GetUnitInfo();
	void SetAnimation(int animIdx, int animDelay, int animStartDelay, int boolInvisible, int boolSkipDoDeath);
	// todo: add/remove from owner list, SetCreator, etc?

	// Mining Beacon
	int GetNumTruckLoadsSoFar();
	int GetBarYield();
	int GetVariant();
	int GetOreType(); // [0 = common, 1 = rare]
	int GetSurveyedBy(); // [player bit vector]

	// Lab
	int GetLabCurrentTopic();
	int GetLabScientistCount();
	void SetLabScientistCount(int numScientists);
};

struct OP2Unit;
extern OP2Unit **unitArray;
