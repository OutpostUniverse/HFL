
// Note: This file contains the defintion of the TethysGame class and 
//		 GameMap class exported from Outpost2.exe. These two classes
//		 control the map and overall game environment of the level.




// Note: The TethysGame class controls creation of units and disasters, 
//		 sending custom in game messages to the player, playing recorded 
//		 sounds for extra effects (you still have no control over the 
//		 default sounds the game engine plays by itself), morale controls,
//		 day and night controls, and more!
//		 It also provides some useful information on the current game.
//		 Basically anything related to the game as a whole is done through
//		 this class.
// Note: This class has all static member functions and no local variables.
//		 Don't try to create an instance of this class. You don't need to 
//		 create your own and you aren't meant to do it. Just use the 
//		 class namespace for all your Outpost 2 level needs. =)
//		 Example: numberOfPlayers = TethysGame::NoPlayers();

class OP2 TethysGame
{
public:
	class TethysGame & operator = (class TethysGame const &);
	// Note: Recorded voice messages can be played by specifying the right soundID
	static void __fastcall AddGameSound(int soundID, int recipientPlayerNum);
	static void __fastcall AddMapSound(int soundID, struct LOCATION location);
	static void __fastcall AddMessage(int pixelX, int pixelY, char *message, int recipientPlayerNum, int soundID);
	static void __fastcall AddMessage(class Unit owner, char *message, int recipientPlayerNum, int soundID);
	static int __fastcall CanAllowCheats();
	static int __fastcall CanHaveDisasters();
	static int __fastcall CreateBeacon(enum map_id beaconType, int x, int y, 
			int commonRareType, int barYield, int barVariant);
	static int __fastcall CreateUnit(class Unit &returnedUnit, enum map_id unitType, 
			struct LOCATION location, int playerNum, enum map_id weaponCargoType, int rotation);
	static int __fastcall CreateUnitBlock(class _Player &owner, char const *exportedName, int);
	static int __fastcall CreateWallOrTube(int tileX, int tileY, int, enum map_id wallTubeType);
	static int __fastcall CreateWreck(int tileX, int tileY, enum map_id techID, int boolAllPlayers); // Note: techID must be >= 8000 but < (8000+4096)
	static struct LOCATION  __fastcall FindEMPMissleTarget(int,int,int,int,int);
	static void __fastcall ForceMoraleGood(int playerNum);
	static void __fastcall ForceMoraleGreat(int playerNum);
	static void __fastcall ForceMoraleOK(int playerNum);
	static void __fastcall ForceMoralePoor(int playerNum);
	static void __fastcall ForceMoraleRotten(int playerNum);
	static void __fastcall FreeMoraleLevel(int playerNum);
	static int __fastcall GetRand(int range);		// Returns a number from 0 to (range-1)
	static int __fastcall InitialUnits();
	static void __fastcall LoadGame(char const *fileName);
	static int __fastcall LocalPlayer();			// Returns the local player number
	static int __fastcall NoPlayers();				// Returns number of players (including comp)
	static int __fastcall PlaceMarker(class Unit &returnedUnit, int x, int y, int markerType);
	static void __fastcall SaveGame(char const *fileName);				// Useless
	static void __fastcall SetCheatFastProduction(int boolOn);			// Useless
	static void __fastcall SetCheatFastUnits(int boolOn);				// Useless
	static void __fastcall SetCheatProduceAll(int boolOn);				// Useless
	static void __fastcall SetCheatUnlimitedResources(int boolOn);		// Useless
	static void __fastcall SetDaylightEverywhere(int boolOn);
	static void __fastcall SetDaylightMoves(int boolOn);
	static void __fastcall SetEMPMissile(int launchTileX, int launchTileY, int setToZero, int 
			destTileX, int destTileY);				// Set third param to 0
	static void __fastcall SetEarthquake(int tileX, int tileY, int magnitude);
	static void __fastcall SetEruption(int tileX, int tileY, int initialSpeed);
	static void __fastcall SetLavaSpeed(int speed);
	static void __fastcall SetLightning(int startTileX, int startTileY, int duration, int endTileX, int endTileY);
	static void __fastcall SetMeteor(int tileX, int tileY, int size);
	static void __fastcall SetMicrobeSpreadSpeed(int speed);
	static void __fastcall SetMusicPlayList(int numSongs, int repeatStartIndex, enum SongIds *songIdList);
	static void __fastcall SetSeed(unsigned int randNumSeed);	// Set random number seed
	static void __fastcall SetTornado(int startTileX, int startTileY, int duration, int endTileX, int endTileY, int boolImmediate);
	static int __fastcall Tick();
	static int __fastcall Time();
	static int __fastcall UsesDayNight();
	static int __fastcall UsesMorale();
private:
	static void __fastcall sIssueOptPacket(int setting, int value);
};



// Note: This class is used to control the displayed tiles on the map as well
//		 as the movement/passability characteristics of the terrain.
// Note: This class has all static member functions and no local variables.
//		 Don't try to create an instance of this class. You don't need to 
//		 create your own and you aren't meant to do it. Just use the 
//		 class namespace for all your Outpost 2 level needs. =)
//		 Example: GameMap::SetInitialLightLevel(0);

class OP2 GameMap
{
public:
	class GameMap & operator=(class GameMap const &);
	static int __fastcall GetCellType(struct LOCATION location);
	static int __fastcall GetTile(struct LOCATION location);
	static void __fastcall InitialSetTile(struct LOCATION where, int what);
	static void __fastcall SetCellType(struct LOCATION where, int what);
	static void __fastcall SetInitialLightLevel(int lightPosition);
	static void __fastcall SetLavaPossible(struct LOCATION where, int boolLavaPossible);
	static void __fastcall SetTile(struct LOCATION where, int what);
	static void __fastcall SetVirusUL(struct LOCATION where, int initialSpeed);
};

