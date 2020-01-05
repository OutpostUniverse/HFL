// Research.cpp
#include "HFL.h"

#pragma pack(push,1)
struct OP2TechInfo
{
	int techID;
	int category;
	int techLevel;
	int plymouthCost;
	int edenCost;
	int maxScientists;
	int lab; // (basic = 1, standard = 2, advanced = 3)
	int playerHasTech; // (bit vector, bit set if player has tech)
	int numUpgrades; // (number of "UNIT_PROP"s specified in the tech file)
	int numRequiredTechs; // (number of "REQUIRES"s specified in the tech file)
	char* techName;
	char* description;
	char* teaser;
	char* improveDesc;
	int* requiredTechNum; // (pointer to array of techNums that are required for this tech)
	void* upgrade; // (pointer to struct containing upgrade info)
	int numDependentTech; // (number of techs that depend on this one) (below is a pointer to an int? list of this many elements)
	int* dependentTechNum; // (pointer to array of techNums of techs that depend on this one)
};


// [Global] 0x56C230
struct OP2Research
{
	int numTechs;
	OP2TechInfo** techInfo;
	int maxTechID; // [maxTechLevel * 1000 + 999]
};

#pragma pack(pop)

OP2Research *researchObj;

int Research::GetTechCount()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return researchObj->numTechs;
}

TechInfo Research::GetTechInfo(int index)
{
	TechInfo info;
	info.internalPtr = nullptr;

	if (!isInited) {
		return info;
	}

	if (index < 0 || index >= researchObj->numTechs) {
		return info;
	}

	info.internalPtr = researchObj->techInfo[index];
	return info;
}

int Research::GetMaxTechID()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return researchObj->maxTechID;
}

int TechInfo::IsValid()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return (internalPtr != nullptr);
}

int TechInfo::GetTechID()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->techID;
}

TechCategory TechInfo::GetCategory()
{
	if (!isInited) {
		return static_cast<TechCategory>(HFLNOTINITED);
	}

	return static_cast<TechCategory>(internalPtr->category);
}

int TechInfo::GetTechLevel()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->techLevel;
}

int TechInfo::GetPlymouthCost()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->plymouthCost;
}

int TechInfo::GetEdenCost()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->edenCost;
}

int TechInfo::GetMaxScientists()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->maxScientists;
}

LabType TechInfo::GetLab()
{
	if (!isInited) {
		return static_cast<LabType>(HFLNOTINITED);
	}

	return static_cast<LabType>(internalPtr->lab);
}

int TechInfo::GetPlayerHasTech()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->playerHasTech;
}

int TechInfo::GetNumUpgrades()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->numUpgrades;
}

int TechInfo::GetNumRequiredTechs()
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->numRequiredTechs;
}

char* TechInfo::GetTechName()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->techName;
}

char* TechInfo::GetDescription()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->description;
}

char* TechInfo::GetTeaser()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->teaser;
}

char* TechInfo::GetImproveDesc()
{
	if (!isInited) {
		return (char*)HFLNOTINITED;
	}

	return internalPtr->improveDesc;
}

int TechInfo::GetRequiredTechIndex(int index)
{
	if (!isInited) {
		return HFLNOTINITED;
	}

	return internalPtr->requiredTechNum[index];
}
