#include "HFL.h"

#pragma pack(push,1)
struct OP2UnitInfoVtbl
{
	void* (__fastcall *CreateUnit)(void *classPtr, int dummy, int pixelX, int pixelY, int unitIdx);
	char* (__fastcall *GetCodeName)(void *classPtr);
	int (__fastcall *SaveData)(void *classPtr, int dummy, void *streamIO);
	int (__fastcall *LoadData)(void *classPtr, int dummy, void *streamIO);
	int (__fastcall *Init)(void *classPtr);
	int (__fastcall *unknown1)(void *classPtr);
	int (__fastcall *unknown2)(void *classPtr);
};

struct OP2UnitInfo
{
	OP2UnitInfoVtbl *vtbl;
	int unitType;
	struct {
		int hitPoints;
		int repairAmt;
		int armor;
		int commonCost;
		int rareCost;
		int buildTime;
		int sightRange;
		int unk[2];
		int powerRequired;
		int concussionDmg;
		int penetrationDmg;
		int reloadTime;
		int weapSightRange;
		int numBays;
		int unk2[2];
	} playerChunk[7];
	int techId;
	int trackType;
	int unk3[2];
	unsigned int ownerType;
	char unitName[40];
	char produceName[40];
	unsigned short xSize; // dmg radius, vehicle flags
	short ySize;
	unsigned int pixelsSkipped; // building flags
	char resPriority;
	char rareRubble;
	char unk4;
	char commonRubble;
	char edenDockLoc;
	char plyDockLoc;
	// ...
};
#pragma pack(pop)

OP2UnitInfo **unitInfoArray;
void *unitInfoObj;

UnitInfo::UnitInfo(map_id unitType)
{
	internalPtr = nullptr;

	if (!isInited) // automatic initialization since objects in static storage will be constructed before InitProc is reached
	{
		if (HFLInit() == HFLCANTINIT)
		{
			return;
		}
	}

	if (unitType >= 1 && unitType <= 0x72) {
		internalPtr = unitInfoArray[unitType];
	}
}

UnitInfo::UnitInfo(char *codeName)
{
	internalPtr = nullptr;

	if (!isInited) // automatic initialization since objects in static storage will be constructed before InitProc is reached
	{
		if (HFLInit() == HFLCANTINIT)
		{
			return;
		}
	}

	for (int i=1; i<0x72; i++)
	{
		OP2UnitInfo* p = unitInfoArray[i];
		if (strcmp(p->vtbl->GetCodeName(p), codeName) == 0)
		{
			internalPtr = p;
			return;
		}
	}
}

int UnitInfo::IsValid()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr != nullptr;
}

int UnitInfo::GetHitPoints(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].hitPoints;
}

void UnitInfo::SetHitPoints(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].hitPoints = value;
}

int UnitInfo::GetRepairAmt(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].repairAmt;
}

void UnitInfo::SetRepairAmt(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].repairAmt = value;
}

int UnitInfo::GetArmor(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].armor;
}

void UnitInfo::SetArmor(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].armor = value;
}

int UnitInfo::GetOreCost(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].commonCost;
}

void UnitInfo::SetOreCost(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].commonCost = value;
}

int UnitInfo::GetRareOreCost(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].rareCost;
}

void UnitInfo::SetRareOreCost(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].rareCost = value;
}

int UnitInfo::GetBuildTime(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].buildTime;
}

void UnitInfo::SetBuildTime(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].buildTime = value;
}

int UnitInfo::GetSightRange(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].sightRange;
}

void UnitInfo::SetSightRange(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].sightRange = value;
}

int UnitInfo::GetWeaponRange(int player)
{
	return GetSightRange(player);
}

void UnitInfo::SetWeaponRange(int player, int value)
{
	SetSightRange(player, value);
}

int UnitInfo::GetPowerRequired(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].powerRequired;
}

void UnitInfo::SetPowerRequired(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].powerRequired = value;
}

int UnitInfo::GetMovePoints(int player)
{
	return GetPowerRequired(player);
}

void UnitInfo::SetMovePoints(int player, int value)
{
	SetPowerRequired(player, value);
}

int UnitInfo::GetTurretTurnRate(int player)
{
	return GetPowerRequired(player);
}

void UnitInfo::SetTurretTurnRate(int player, int value)
{
	SetPowerRequired(player, value);
}

int UnitInfo::GetConcussionDamage(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].concussionDmg;
}

void UnitInfo::SetConcussionDamage(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].concussionDmg = value;
}

int UnitInfo::GetWorkersRequired(int player)
{
	return GetConcussionDamage(player);
}

void UnitInfo::SetWorkersRequired(int player, int value)
{
	SetConcussionDamage(player, value);
}

int UnitInfo::GetTurnRate(int player)
{
	return GetConcussionDamage(player);
}

void UnitInfo::SetTurnRate(int player, int value)
{
	SetConcussionDamage(player, value);
}

int UnitInfo::GetPenetrationDamage(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].penetrationDmg;
}

void UnitInfo::SetPenetrationDamage(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].penetrationDmg = value;
}

int UnitInfo::GetScientistsRequired(int player)
{
	return GetPenetrationDamage(player);
}

void UnitInfo::SetScientistsRequired(int player, int value)
{
	SetPenetrationDamage(player, value);
}

int UnitInfo::GetProductionRate(int player)
{
	return GetPenetrationDamage(player);
}

void UnitInfo::SetProductionRate(int player, int value)
{
	SetPenetrationDamage(player, value);
}

int UnitInfo::GetReloadTime(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].reloadTime;
}

void UnitInfo::SetReloadTime(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].reloadTime = value;
}

int UnitInfo::GetStorageCapacity(int player)
{
	return GetReloadTime(player);
}

void UnitInfo::SetStorageCapacity(int player, int value)
{
	SetReloadTime(player, value);
}

int UnitInfo::GetWeaponSightRange(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].weapSightRange;
}

void UnitInfo::SetWeaponSightRange(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].weapSightRange = value;
}

int UnitInfo::GetProductionCapacity(int player)
{
	return GetWeaponSightRange(player);
}

void UnitInfo::SetProductionCapacity(int player, int value)
{
	SetWeaponSightRange(player, value);
}

int UnitInfo::GetNumStorageBays(int player)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	if (player < 0 || player > 6) {
		return -1;
	}

	return internalPtr->playerChunk[player].numBays;
}

void UnitInfo::SetNumStorageBays(int player, int value)
{
	if (!isInited) {
		return;
	}

	if (player < 0 || player > 6) {
		return;
	}

	internalPtr->playerChunk[player].numBays = value;
}

int UnitInfo::GetCargoCapacity(int player)
{
	return GetNumStorageBays(player);
}

void UnitInfo::SetCargoCapacity(int player, int value)
{
	SetNumStorageBays(player, value);
}

int UnitInfo::GetResearchTopic()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->techId;
}

void UnitInfo::SetResearchTopic(int techId)
{
	if (!isInited) {
		return;
	}

	internalPtr->techId = techId;
}

TrackType UnitInfo::GetTrackType()
{
	if (!isInited) {
		return (TrackType)HFLNOTINITED;
	}

	return static_cast<TrackType>(internalPtr->trackType);
}

void UnitInfo::SetTrackType(TrackType type)
{
	if (!isInited) {
		return;
	}

	internalPtr->trackType = type;
}

int UnitInfo::GetOwnerFlags()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->ownerType;
}

void UnitInfo::SetOwnerFlags(int flags)
{
	if (!isInited) {
		return;
	}

	internalPtr->ownerType = flags;
}

char* UnitInfo::GetUnitName()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->unitName;
}

void UnitInfo::SetUnitName(char *newName)
{
	if (!isInited) {
		return;
	}

	if (strlen(newName) > 39) { // 39chars + null maximum
		return;
	}

	strcpy_s(internalPtr->unitName, newName);
}

char* UnitInfo::GetProduceListName()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->produceName;
}

void UnitInfo::SetProduceListName(char *newName)
{
	if (!isInited) {
		return;
	}

	if (strlen(newName) > 39) { // 39chars + null maximum
		return;
	}

	strcpy_s(internalPtr->produceName, newName);
}

int UnitInfo::GetXSize()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->xSize;
}

void UnitInfo::SetXSize(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->xSize = value;
}

int UnitInfo::GetDamageRadius()
{
	return GetXSize();
}

void UnitInfo::SetDamageRadius(int value)
{
	SetXSize(value);
}

int UnitInfo::GetVehicleFlags()
{
	return GetXSize();
}

void UnitInfo::SetVehicleFlags(int flags)
{
	SetXSize(flags);
}

int UnitInfo::GetYSize()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->ySize;
}

void UnitInfo::SetYSize(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->ySize = value;
}

int UnitInfo::GetPixelsSkippedWhenFiring()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->pixelsSkipped;
}

void UnitInfo::SetPixelsSkippedWhenFiring(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->pixelsSkipped = value;
}

int UnitInfo::GetBuildingFlags()
{
	return GetPixelsSkippedWhenFiring() & 0x7F;
}

void UnitInfo::SetBuildingFlags(int flags)
{
	// first 7 bits altered, rest left alone
	int bits = GetPixelsSkippedWhenFiring();
	bits &= ~0x7F; // mask out bits
	bits |= flags & 0x7F; // set bits

	SetPixelsSkippedWhenFiring(bits);
}

int UnitInfo::GetExplosionSize()
{
	return (GetPixelsSkippedWhenFiring() >> 7) & 3;
}

void UnitInfo::SetExplosionSize(int value)
{
	// first 7 bits altered, rest left alone
	int bits = GetPixelsSkippedWhenFiring();
	bits &= ~0x180; // mask out bits
	bits |= ((value & 3) << 7); // set bits

	SetPixelsSkippedWhenFiring(bits);
}

int UnitInfo::GetResourcePriority()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->resPriority;
}

void UnitInfo::SetResourcePriority(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->resPriority = value;
}

int UnitInfo::GetRareRubble()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->rareRubble;
}

void UnitInfo::SetRareRubble(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->rareRubble = value;
}

int UnitInfo::GetRubble()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->commonRubble;
}

void UnitInfo::SetRubble(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->commonRubble = value;
}

int UnitInfo::GetEdenDockPos()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->edenDockLoc;
}

void UnitInfo::SetEdenDockPos(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->edenDockLoc = value;
}

int UnitInfo::GetPlymDockPos()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->plyDockLoc;
}

void UnitInfo::SetPlymDockPos(int value)
{
	if (!isInited) {
		return;
	}

	internalPtr->plyDockLoc = value;
}

char* UnitInfo::GetCodeName()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->vtbl->GetCodeName(internalPtr);
}

map_id UnitInfo::GetMapID()
{
	if (!isInited) {
		return (map_id)HFLNOTINITED;
	}

	return (map_id)internalPtr->unitType;
}

Unit UnitInfo::CreateUnit(LOCATION where, int unitId)
{
	Unit u;

	if (!isInited)
	{
		u.unitID = 0;
		return u;
	}

	struct _unit {
		int vtbl;
		int isLive;
		int prev;
		int next;
		int id;
		// ... more, but not needed for this purpose
	} *unitPtr;
	unitPtr = (_unit*)internalPtr->vtbl->CreateUnit(internalPtr, 0, where.x*32, where.y*32, unitId);
	if (unitPtr)
	{
		u.unitID = unitPtr->id;
	} else {
		u.unitID = 0;
	}

	return u;
}
