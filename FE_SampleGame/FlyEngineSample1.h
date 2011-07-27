#ifndef _FE_SAMPLE_GAME_H_
#define _FE_SAMPLE_GAME_H_

#include "../FlyEngine/game.h"
#include "Game.h"

class FlyEngineSample1 : public Game
{
public:
	FlyEngineSample1();
	~FlyEngineSample1();
	
	void Initialise();
	void LoadContent();
	void Update();
	void Draw();

	void Shutdown();
};

#endif

