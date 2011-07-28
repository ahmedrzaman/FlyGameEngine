#include <Windows.h>

#include "engine.h"
#include "FlyEngineSample1.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{	
	FlyEngineSample1 flyEngineSample = FlyEngineSample1();

	// initialise FlyGameEngie
	InitFlyGameEngine();

	flyEngineSample.Start();
		
	// shutdown FlyGameEngie
	ShutdownFlyGameEngine();
	
	return 0;
}

