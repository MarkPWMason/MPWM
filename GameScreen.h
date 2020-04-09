#pragma once
#include <string>
#include <iostream>
#include "Commons.h"
#include <SDL_main.h>
#include <SDL.h>
using namespace ::std;

class GameScreen
{
protected:
	SDL_Renderer* mRenderer;

public:
	GameScreen(SDL_Renderer* renderer);
	~GameScreen();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
};

