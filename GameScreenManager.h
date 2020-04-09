#pragma once
#include "GameScreenManager.h"
#include "GameScreen.h"
#include <string>
#include <iostream>
#include "Commons.h"
#include <SDL_main.h>
#include <SDL.h>
using namespace ::std;

class GameScreen
{
private:
	SDL_Renderer* mRenderer;
	GameScreen* mCurrentScreen;

public:
	GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen);
	~GameScreenManager();

	void Render();
	Void Update(Float deltaTime, SDL_Event e);

	void ChangeScreen(SCREENS newScreen);
	
};
