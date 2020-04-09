#include "GameScreenLevel1.h"
#include <iostream>
#include "Texture2D.h"
#include "GameScreen.h"
using namespace ::std;

GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer)
{
	SetUpLevel1();
}

GameScreenLevel1::~GameScreenLevel1()
{
	delete mBackgroundTexture;
	mBackgroundTexture = NULL;
}

void GameScreenLevel1::Update(float deltaTime, SDL_Event e)
{

}

void GameScreenLevel1::Render()
{
	mBackgroundTexture->Render(Vector2D(), SDL_FLIP_NONE);
}

bool GameScreenLevel1::SetUpLevel1()
{
	mBackgroundTexture = new Texture2D(mRenderer);
	if (!mBackgroundTexture->LoadFromFile("Images/Test.bmp"))
	{
		cout << "Failed to load background texture";
		return false;
	}
	return true;
}
