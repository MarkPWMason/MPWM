#include "GameScreenManager.h"
#include "GameScreen.h"
#include "GameScreenLevel1.h"

using namespace ::std;

GameScreenManager::GameScreenManager(SDL_Renderer* renderer, SCREENS startScreen)
{
	mRenderer = renderer;
	mCurrentScreen = NULL;
	ChangeScreen(startScreen);


}

GameScreenManager::~GameScreenManager()
{
	mRenderer = NULL;
	delete mCurrentScreen;
	mCurrentScreen = NULL;
}


void GameScreenManager::Render()
{
	mCurrentScreen->Render();
}

void GameScreenManager::Update(float deltaTime, SDL_Event e)
{
	mCurrentScreen->Update(deltaTime, e);
}

void GameScreenManager::ChangeScreen(SCREENS newScreen)
{
	if (mCurrentScreen != NULL)
	{
		delete mCurrentScreen;
	}

	GameScreenLevel1* tempScreen;

	switch (newScreen)
	{
	case SCREEN_LEVEL1:
		tempScreen = new GameScreenLevel1(mRenderer);
		mCurrentScreen = (GameScreen*)tempScreen;
		tempScreen = NULL;
		break;
	}
}
