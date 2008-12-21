
// Note: This file is used to define all the group related classes exported
//		 from Outpost2.exe. It also contains the Pinwheel class (which is
//		 like a group class in many ways) and the Trigger class (which
//		 derives from the same base class as all the others).



// Note: ScStub is the main parent class of all other classes in this file.
//		 Any functions defined here on this class are available to any
//		 instance of the derived classes.
// Note: Do not try to create an instance of this class. It was meant
//		 simply as a base parent class from which other classes inherit
//		 functions from. Creating an instance of this class serves little
//		 (or no) purpose and may even crash the game.

class OP2 ScStub
{
public:
	ScStub();
	~ScStub();
	class ScStub & operator=(class ScStub const &);
	// void * ScStub::`vector deleting destructor'(unsigned int);
	// void * ScStub::`scalar deleting destructor'(unsigned int);
	void Destroy();
	void Disable();
	void Enable();
	int Id() const;
	int IsEnabled();
	int IsInitialized();
	void SetId(int id);

	int ID;
};



// Note: This is the trigger class returned by all the trigger creation
//		 functions. It can be used to control an active trigger.
// Note: The trigger class is only a stub that refers to an internal
//		 class that handles the trigger. It is seldom necessary to use
//		 this class to control a trigger and it is usually destroyed
//		 shortly after it is returned from the trigger creation function.

class OP2 Trigger : public ScStub
{
public:
	Trigger();
	~Trigger() {};
	class Trigger & operator=(class Trigger const &);
	// void * Trigger::`vector deleting destructor'(unsigned int);
	// void * Trigger::`scalar deleting destructor'(unsigned int);
	void Disable();
	void Enable();
	int HasFired(int player);
};


// Note: The Pinwheel class seems to be used for controlling waves
//		 of attacks.

class OP2 Pinwheel : public ScStub
{
public:
	Pinwheel();
	~Pinwheel() {};
	class Pinwheel & operator=(class Pinwheel const &);
	// void * Pinwheel::`vector deleting destructor'(unsigned int);
	// void * Pinwheel::`scalar deleting destructor'(unsigned int);
	void SendWaveNow(int);
	void SetAttackComp(int,int,struct MrRec *);
	void SetAttackFraction(int);
	void SetContactDelay(int);
	void SetGuardComp(int,int,struct MrRec *);
	void SetNoRange(int,int);
	void SetPoints(struct PWDef *);
	void SetSapperComp(int,int,struct MrRec *);
	void SetWavePeriod(int,int);
};




// Note: ScGroup is the main parent class of all other group classes.
//		 Any functions defined here on this class are available to any
//		 instance of the derived classes.
// Note: Do not try to create an instance of this class. It was meant
//		 simply as a base parent class from which other classes inherit
//		 functions from. Creating an instance of this class serves little
//		 (or no) purpose and may even crash the game.

class OP2 ScGroup : public ScStub
{
public:
	ScGroup();
	~ScGroup() {};
	class ScGroup & operator=(class ScGroup const &);
	// void * ScGroup::`vector deleting destructor'(unsigned int);
	// void * ScGroup::`scalar deleting destructor'(unsigned int);
	void AddUnits(class UnitBlock &unitsToAdd);
	void ClearTargCount();
	int GetFirstOfType(class Unit &returnedUnit, enum UnitClassifactions unitType);
	int GetFirstOfType(class Unit &returnedUnit, enum map_id unitType, enum map_id weaponType);
	int HasBeenAttacked();
	void RemoveUnit(class Unit unitToRemove);
	void SetDeleteWhenEmpty(int boolDelete);
	void SetLights(int boolOn);
	void SetTargCount(class UnitBlock &unitTypes);
	void SetTargCount(enum map_id unitType, enum map_id weaponType, int refValue);
	void TakeAllUnits(class ScGroup &groupToAdd);
	void TakeUnit(class Unit unitToAdd);
	int TotalUnitCount();
	int UnitCount(enum UnitClassifactions criteria);
};




// Note: Do not try to create any of the following classes using only their
//		 constructors. Doing so will likely crash the game. Instead, create
//		 these classes by calling the group creation functions defined in
//		 Functions.h.



// Note: The BuildingGroup class is used to control Structure Factories,
//		 ConVecs, and Earthworkers to build/rebuild a base.

class OP2 BuildingGroup : public ScGroup
{
public:
	BuildingGroup();
	~BuildingGroup() {};
	class BuildingGroup & operator=(class BuildingGroup const &);
	// void * BuildingGroup::`vector deleting destructor'(unsigned int);
	// void * BuildingGroup::`scalar deleting destructor'(unsigned int);
	void RecordBuilding(struct LOCATION &where,enum map_id unitType,enum map_id cargoWeapType);
	void RecordBuilding(struct LOCATION &,enum map_id,enum map_id,class ScGroup &);
	void RecordTube(struct LOCATION &where);
	void RecordTubesTouching(struct LOCATION &where);
	void RecordUnitBlock(class UnitBlock &);
	void RecordUnitBlock(class UnitBlock &,class ScGroup &);
	void RecordVehReinforceGroup(class ScGroup &destination, int priority); // 0 = lowest priority, 0xFFFF = highest
	void RecordWall(struct LOCATION &where,enum map_id wallType);
	void SetRect(struct MAP_RECT &defaultArea);
	void UnRecordVehGroup(class ScGroup &group);
};


// Note: The FightGroup class is used to control military units and is
//		 used to attack or defend a base. It can be used to cause an AI
//		 to produce units at a Vehicle Factory to attack with.

class OP2 FightGroup : public ScGroup
{
public:
	FightGroup();
	~FightGroup() {};
	class FightGroup & operator=(class FightGroup const &);
	// void * FightGroup::`vector deleting destructor'(unsigned int);
	// void * FightGroup::`scalar deleting destructor'(unsigned int);
	void AddGuardedRect(struct MAP_RECT &);
	void ClearCombineFire();
	void ClearGuarderdRects();
	void ClearPatrolMode();
	void DoAttackEnemy();
	void DoAttackUnit();
	void DoExitMap();
	void DoGuardGroup();
	void DoGuardRect();
	void DoGuardUnit();
	void DoPatrolOnly();
	void SetAttackType(enum map_id);	// Use in combination with DoAttackEnemy()
	void SetCombineFire();
	void SetFollowMode(int);
	void SetPatrolMode(struct PatrolRoute &waypts);
	void SetRect(struct MAP_RECT &defaultArea);
	void SetTargetGroup(class ScGroup); // Use in combination with DoGuardGroup()
	void SetTargetUnit(class Unit);
};


// Note: The MiningGroup is a class used to setup mining routes with
//		 cargo trucks.

class OP2 MiningGroup : public ScGroup
{
public:
	MiningGroup();
	~MiningGroup() {};
	class MiningGroup & operator=(class MiningGroup const &);
	// void * MiningGroup::`vector deleting destructor'(unsigned int);
	// void * MiningGroup::`scalar deleting destructor'(unsigned int);
	void Setup(struct LOCATION &,struct LOCATION &,struct MAP_RECT &);
	void Setup(struct LOCATION &,struct LOCATION &,enum map_id,enum map_id,struct MAP_RECT &);
	void Setup(class Unit smelter,class Unit mine,struct MAP_RECT &smelterArea);
};


