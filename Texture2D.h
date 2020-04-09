#pragma once
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H

#include <string>
#include <iostream>
#include "Commons.h"
#include <SDL_main.h>
#include <SDL.h>

using namespace::std;


class Texture2D
{

public:
	Texture2D(SDL_Renderer* renderer);
	~Texture2D();

	void Free();
	void Render(Vector2D newPosition, SDL_RendererFlip flip, double angle = 0.0f);
	bool LoadFromFile(string path);

	int GetWidth() { return mWidth; }
	int GetHeight() { return mHeight; }

private:
	SDL_Renderer* mRenderer;
	SDL_Texture* mTexture;

	SDL_Surface* pSurface;

	int mWidth;
	int mHeight;
};







#endif // !_TEXTURE2D_H

