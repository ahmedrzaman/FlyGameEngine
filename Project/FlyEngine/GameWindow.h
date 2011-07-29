#ifndef _FLYENGINE_GAMEWINDOW_H
#define _FLYENGINE_GAMEWINDOW_H

#include <Windows.h>
#include <ctime>

#include "Vector.h"
#include "headers.h"

#pragma comment(lib, "winmm.lib")

struct GameWindow
{
private:
	char * Title;
	
	HINSTANCE hInstance;
	FGE_HWND hWnd;
	
    WNDCLASSEX wc;
public:
	int X, Y, Width, Height;
	bool FullScreen;

	friend class Game;
	
public:
	GameWindow();
	GameWindow(HINSTANCE hInstance);

	~GameWindow() { }

	char * GetClassName();
	char * GetWindowCaption();
	Vector2 GetPosition();
	Vector2 GetSize();
	
	void SetWindowTitle(char * title);
	void SetWindowPosition(Vector2 position);
	void SetWindowSize(Vector2 size);

	void ApplySettings();

	void Initialise();

	void Shutdown();
};

#endif