#ifndef _FLYENGINE_HEADERS_H
#define _FLYENGINE_HEADERS_H

#include <Windows.h>

enum FGE_RESULTFLAG
{
	FGE_ERROR = -1,
	FGE_OK = 1,
	FGE_FAIL = 0,
};

// Kept here for possibility of porting to other platforms, HWND may not be found in MacOSX or Linux
#define FGE_HWND HWND

#endif