#pragma once
#include <string>
#include <iostream>
#include "Commons.h"
#include <SDL_main.h>
#include <SDL.h>
#include "GameScreen.h"
using namespace ::std;

class Texture2D;

class GameScreenLevel1 : GameScreen
{
private:
	bool SetUpLevel1();
	Texture2D* mBackgroundTexture;

public:
	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render();
	void Update(float deltaTime, SDL_Event e);
};
