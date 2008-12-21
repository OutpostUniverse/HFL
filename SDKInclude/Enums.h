

// Note: This file stores all the enums exported from Outpost2.exe except for the
//		 map_id enum, which is important enough to get it's own file. =)


// Used by various trigger creation functions
enum compare_mode 
{
	cmpEqual = 0,				// 0
	cmpLowerEqual,				// 1
	cmpGreaterEqual,			// 2
	cmpLower,					// 3
	cmpGreater					// 4
};

// Used by CreateResourceTrigger
enum trig_res 
{
	resFood = 0,				// 0
	resCommonOre,				// 1
	resRareOre,					// 2
	resKids,					// 3
	resWorkers,					// 4
	resScientists,				// 5
	resColonists				// 6
};

// Used by Unit.SetCargo
enum Truck_Cargo {
	truckEmpty = 0,				// 0
	truckFood,					// 1
	truckCommonOre,				// 2
	truckRareOre,				// 3
	truckCommonMetal,			// 4
	truckRareMetal,				// 5
	truckCommonRubble,			// 6
	truckRareRubble,			// 7
	truckSpaceport,				// 8
	truckGarbage,				// 9

	truckUnit = 0x03F8			// 3F8
};

// Returned by _Player.FoodSupply()
enum FoodStatus 
{
	foodRising = 0,				// 0
	foodNoChange,				// 1 - pretty hard, if not impossible to achieve with food
	foodFalling,				// 2
	foodShortage				// 3
};

// Returned by _Player.MoraleLevel()
enum MoraleLevels 
{
	moraleGreat = 0,			// 0
	moraleGood,					// 1
	moraleOK,					// 2
	moralePoor,					// 3
	moraleRotten				// 4
};

// Used by ScGroup.GetFirstOfType, ScGroup.UnitCount, and classes
// derived from ScGroup which inherit these functions
// (BuildingGroup, FightGroup, MiningGroup)
enum UnitClassifactions 
{
	clsAttack = 0,				// 0 (Lynx, Panther, Tiger, Scorpion)
	clsESG,						// 1 (Lynx, Panther, Tiger)
	clsEMP,						// 2 (Lynx, Panther, Tiger)
	clsStickyfoam,				// 3 (Lynx, Panther, Tiger)
	clsSpider,					// 4
	clsConvec,					// 5
	clsRepairVehicle,			// 6
	clsCargoTruck,				// 7
	clsEarthworker,				// 8
	clsColony,					// 9 (RoboSurveyor, RoboMiner, GeoCon, Scout, RoboDozer, EvacuationTransport)
	clsVehicleFactory,			// A
	clsArachnidFactory,			// B
	clsStructureFactory,		// C

	clsUnknownD,				// D

	clsGuardPost,				// E
	clsBuilding,				// F (does not include Arachnid Factory, includes beacons, disasters, Blast, Tube, pretty much any non vehicle?)

	clsUnknown10,				// 10

	clsAll						// 11 All vehicles and buildings
};
// Note: clsAttack applies to all attack vehicles with the following weapons:
//		Microwave
//		Laser
//		Rail Gun
//		Starflare
//		Supernova
//		RPG
//		Acid Cloud
//		Thor's Hammer
//		Energy Cannon (Scorpions)
// Note: Scorpions always appear in this classification (clsAttack), even
//		 if the weapon is changes to ESG, EMP, Stickyfoam



// Used to define music playlists
enum SongIds 
{
	songEden11 = 0,
	songEden21,
	songEden22,
	songEden31,
	songEden32,
	songEden33,
	songEP41,
	songEP42,
	songEP43,
	songEP51,
	songEP52,
	songEP61,
	songEP62,
	songEP63,
	songPlymth11,
	songPlymth12,
	songPlymth21,
	songPlymth22,
	songPlymth31,
	songPlymth32,
	songPlymth33,
	songStatic01,
	songStatic02,
	songStatic03,
	songStatic04,
	songStatic05
};

