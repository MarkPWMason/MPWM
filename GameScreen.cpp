#include <string>
#include <iostream>
#include "Commons.h"
#include <SDL_main.h>
#include <SDL.h>
#include "GameScreen.h"
#include "Texture2D.h"
using namespace ::std;


GameScreen::GameScreen(SDL_Renderer* renderer)
{
	mRenderer = renderer;
}

GameScreen::~GameScreen()
{
	
	mRenderer = NULL;
}



void GameScreen::Render()
{
}

void GameScreen::Update(float deltaTime, SDL_Event e)
{
}
