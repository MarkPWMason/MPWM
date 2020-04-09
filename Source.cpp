#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "Constants.h"
#include <iostream>
#include <SDL_main.h>
#include "Texture2D.h"
#include "Commons.h"
#include "GameScreenManager.h"

using namespace::std;


//Globals
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
GameScreenManager* gameScreenManager;
Uint32 gOLDTime;


//Function Prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void Render();

int main(int argc, char* args[])
{
	if (InitSDL())
	{
		//SDL_Delay(5000);
		
	}
	gameScreenManager = new GameScreenManager(gRenderer, SCREEN_LEVEL1);
	//CloseSDL();


	bool quit = false;

	while (!quit)
	{
		Render();
		quit = Update();
	}

	return 0;
}

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Games Engine Creation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

	   

		if (gWindow == NULL)
		{
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}

		
	}
	

	return true;
}

void CloseSDL() 
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();

	//Clear up the texture.


	//Release the renderer.
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;

	delete gameScreenManager;
	gameScreenManager = NULL;
	
}

bool Update()
{
	Uint32 newTime = SDL_GetTricks();
	SDL_Event e;

	SDL_PollEvent(&e);

	switch(e.type)
	{
		case SDL_QUIT:
		
			return true;
				break;

		default:break;
	}

	gameScreenManager->Update((float)(newTime - gOLDTime) / 1000.0f, e);
	return false;
	gOLDTime = newTime;
}

void Render()
{
	//Clear the screen.
	SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(gRenderer);

	//Update the screen.
	SDL_RenderPresent(gRenderer);

	gameScreenManager->Render();
}
