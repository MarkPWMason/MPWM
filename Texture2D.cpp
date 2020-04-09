#include "Texture2D.h"
#include <SDL_image.h>
#include <string>
#include <iostream>
#include <SDL_main.h>
#include <SDL.h>

using namespace::std;

Texture2D::Texture2D(SDL_Renderer* renderer)
{
	
} 

Texture2D::~Texture2D()
{
	Free();

		mRenderer = NULL;
}

bool Texture2D::LoadFromFile(string path)
{
	Free();

	mWidth = pSurface->w;
	mHeight = pSurface->h;

	SDL_Texture* mTexture = NULL;

	//Load the Image.
	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface != NULL)
	{
		mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface);
		SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface-> format, 0, 0xFF, 0xFF));

		if (mTexture == NULL)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError() << endl;
			SDL_FreeSurface(pSurface);
		}
		else
		{
			cout << "Unable to create texture from surface. Error: " << IMG_GetError() << endl;
		}
		return mTexture != NULL ;
	}

	return true;
}

void Texture2D::Free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}

void Texture2D::Render(Vector2D newPosition, SDL_RendererFlip flip, double angle)
{
	//Set where to render the texture.
	SDL_Rect renderLocation = { 0, 0, mWidth, mHeight };

	//Render to screen.
	SDL_RenderCopyEx(mRenderer, mTexture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

	if (mRenderer != NULL)
	{
		
		if (mTexture == NULL)
		{
			mTexture == NULL;
		}

		//Initialise PNG loading
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{


			cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
			
		}
		else
		{
			cout << "Renderer could not initialise. Error: " << SDL_GetError();
			
		}
	}

}
