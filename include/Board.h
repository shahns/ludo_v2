/*
 * Board.h
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#ifndef INCLUDE_BOARD_H_
#define INCLUDE_BOARD_H_
#include <Common.h>
#include <Renderer.h>
#include <string>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
//#include <vector>

class Board {
public:
	/*!
	 Constructor with no input arguments\n
	 Initiates, loads board array and board textures
	 */
	Board(GameType,Renderer* renderer);

	/*!
	 Destructor for class Board
	 */
	~Board();
	/*!
	 Function to load a board layout array
	 */
	//void loadBoard(int arr[15][15]);
	/*!
	 Function to load a draw loaded layout array
	 */
	void drawBoard();

	/*!
	 Function to load board assets according to its type
	 */
	void loadAssets(GameType);

private:
	SDL_Rect src, dest; /**< SDL_Rect for texture location */
	SDL_Texture *boardLayout; /**< SDL_texture for board*/
	Renderer* renderer;
};

#endif /* INCLUDE_BOARD_H_ */
