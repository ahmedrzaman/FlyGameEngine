#include "game.h"

Game::Game()
{
	currentTime = lastTime = 0.0;
	GameSpeed = 60;
	
	Window.Initialise();
}

Game::~Game() 
{ }

void Game::Start()
{
	// initialise
	Initialise();
	// load
	LoadContent();
	// run
	Run();
	// shutdown
	Shutdown();
}

void Game::Initialise()
{
	renderer->Initialise(Window.hWnd, Window.Width, Window.Height, Window.FullScreen);
}

void Game::Run()
{
	// this struct holds Windows event messages
	MSG msg;

	ZeroMemory(&msg, sizeof(msg));
		
	// wait for the next message in the queue, store the result in 'msg'
	//while(GetMessage(&msg, NULL, 0, 0))
	while (msg.message != WM_QUIT)
	{
		currentTime = timeGetTime() - lastTime;

		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			// translate keystroke messages into the right format
			TranslateMessage(&msg);

			// send the message to the WindowProc function
			DispatchMessage(&msg);

		}
		else
		{
			currentTime = timeGetTime() - lastTime;

			if (currentTime < GameSpeed)
				return;

			// game declarations
			//UpdateFunction();
			Update();
			//RenderFunction();
			Draw();

			lastTime = timeGetTime();
		}
	}
}

void Game::LoadContent()
{ }

void Game::Update()
{ }

void Game::Draw()
{ }

void Game::Shutdown()
{ 
	Window.Shutdown();
}