/*
 * renderer.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#include <Renderer.h>

Renderer::Renderer() {
	// TODO Auto-generated constructor stub
renderer = nullptr;
}

Renderer::~Renderer() {
	// TODO Auto-generated destructor stub
}

SDL_Texture *Renderer::loadTexture(const char *texture) {
	SDL_Surface *tempSurface = IMG_Load(texture);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer,
			tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}

void Renderer::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(renderer, tex, &src, &dest);
}

SDL_Texture *Renderer::LoadTextureFromString(const char *text, TTF_Font *font,
		SDL_Color colour) {
	SDL_Surface *tempsurface = TTF_RenderText_Solid(font, text, colour);
	SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer,
			tempsurface);
	SDL_FreeSurface(tempsurface);
	return tex;
}
