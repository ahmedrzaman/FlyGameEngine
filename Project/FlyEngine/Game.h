#ifndef _FLYENGINE_GAME_H
#define _FLYENGINE_GAME_H

#include <Windows.h>
#include <stdio.h>

#include "GameWindow.h"
//class GameWindow;
#include "Renderer.h"

class Game
{
private:
    //WNDCLASSEX wc;

	double currentTime, lastTime;
		
	bool InitialiseRenderer();
	
protected:
	// GraphicsDeviceManager GraphicsManager
	// GraphicsDevice GraphicsDevice

	// Value indicating if the mouse is hidden or visible.
	bool MouseIsVisible;

	// Frames rendered every second. Default at 60
	int FramesPerSecond;
	
	// The game loop	
	void Run();

public:
	Game();
	~Game();
	
	virtual void Initialise();

	void Start();
	
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();

	virtual void Shutdown();
};



#endif