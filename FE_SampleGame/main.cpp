#include <Windows.h>

#include "engine.h"
#include "FlyEngineSample1.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Create and init window
	GameWindow Window(hInstance);
	Window.Initialise();

	Window.Width = 1600;

	Window.ApplySettings();
	
	// initialise FlyGameEngie
	InitFlyGameEngine();



	FlyEngineSample1 flyEngineSample = FlyEngineSample1();

	flyEngineSample.Start();


	
	// shutdown FlyGameEngie
	ShutdownFlyGameEngine();

	// shutdown window
	Window.Shutdown();

	return 0;
}

