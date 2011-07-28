#include "GameWindow.h"

LRESULT WINAPI WindowProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
   switch(msg)
      {
         case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
            break;

         case WM_KEYDOWN:
            if(wp == VK_ESCAPE) PostQuitMessage(0);
            break;
      }

   return DefWindowProc(hWnd, msg, wp, lp);
}
	GameWindow::GameWindow()
	{
		// set title
		Title = "FEGameWindow1";

		// set default x y width height
		X = Y = 0;
		Width = 800;
		Height = 600;

		//Initialise();
	}

	GameWindow::GameWindow(HINSTANCE hInst)
	{
		this->hInstance = hInst;

		// set title
		Title = "FEGameWindow1";

		// set default x y width height
		X = Y = 0;
		Width = 800;
		Height = 600;

		Initialise();
	}

	void GameWindow::Initialise()
	{
		// WINDOWS CODE
		ZeroMemory(&wc, sizeof(WNDCLASSEX));
	
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_CLASSDC; //CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = WindowProc;
		wc.hInstance = hInstance;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.lpszClassName = "FEGameWindow";

		RegisterClassEx(&wc);

		hWnd = CreateWindowEx(
			NULL,
			"FEGameWindow",		// name of the window class
			Title,	// caption in title bar or window
			WS_OVERLAPPEDWINDOW,	// the window's style
			X,		// x position
			Y,		// y position
			Width,	// width 
			Height,	// height
			GetDesktopWindow(),		// there is no parent window
			NULL,			// not using any menus
			hInstance,			// application handle
			NULL);			// used with multiple windows

		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);
	}

	void GameWindow::Shutdown() 
	{
		CloseWindow(hWnd);
		UnregisterClass("FEGameWindow", wc.hInstance);
	}

	void GameWindow::ApplySettings()
	{
		SetWindowText(hWnd, Title);
		MoveWindow(hWnd, X, Y, Width, Height, true);
	}
		
	char * GameWindow::GetWindowCaption()
	{
		return Title;
	}
	Vector2 GameWindow::GetPosition()
	{
		return (Vector2((float)X, (float)Y));
	}
	Vector2 GameWindow::GetSize()
	{
		return (Vector2((float)Width, (float)Height));
	}
	
	void GameWindow::SetWindowTitle(char * title)
	{
		Title = title;
	}

	void GameWindow::SetWindowPosition(Vector2 position)
	{
		X = (int)position.X;
		Y = (int)position.Y;
	}

	void GameWindow::SetWindowSize(Vector2 size)
	{
		Width = (int)size.X;
		Height = (int)size.Y;
	}