// Note: This is the main DLL SDK include file. Including this file
//		 will in turn include every other header file which defines
//		 the exports from Outpost2.exe needed for level programming
//		 and the header files that define the exports from the 
//		 level DLLs needed for Outpost2.exe to recognize the level.

// Common header stuff to prevent redefinition errors
// if the header is included more than once
#ifndef OUTPOST2DLL_H
#define OUTPOST2DLL_H

// A define used to make importing things easier
#define OP2 __declspec(dllimport)

// Include all the header files which contain 
// defintions of exports from Outpost2.exe
#include <MapIdEnum.h>
#include <Enums.h>
#include <Structs.h>
#include <Player.h>
#include <Units.h>
#include <Groups.h>
#include <Enumerators.h>
#include <TethysGame.h>
#include <NonExportedEnums.h>
#include <Functions.h>
// Include the header file which contains definitions
// of required exports from the level DLL
#include <RequiredExports.h>

#endif	// End of redefinition error protection
