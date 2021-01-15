/*
 * renderer.h
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#ifndef INCLUDE_RENDERER_H_
#define INCLUDE_RENDERER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Renderer {
public:
	/*!
	 Function to create a texture from a surface of an image
	 @param filename the filename of the image
	 @return returns the SDL_Texture of the image
	 */
	SDL_Texture *loadTexture(const char *filename);

	/*!
	 Function to draw a texture using Render_Copy
	 @param tex SDL_Texture to draw
	 @param src source SDL_Rect for texture tex
	 @param dest destination SDL_Rect for texture tex
	 @return returns the SDL_Texture of the image
	 */
	void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);

	/*!
	 Function to print text on screen
	 @param text text to be printed on the screen
	 @param font true type font to be used while printing, TTF_Font type
	 @param colour colour of the text to printed, SDL_Color type
	 @return returns the SDL_Texture of the text
	 */
	SDL_Texture *LoadTextureFromString(const char *text, TTF_Font *font,
			SDL_Color colour);
	SDL_Renderer *renderer; /**< A single static renderer on which
			 everything should be rendered*/
	Renderer();
	virtual ~Renderer();
};

#endif /* INCLUDE_RENDERER_H_ */
