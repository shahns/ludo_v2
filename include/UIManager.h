/*
 * UIManager.h
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#ifndef INCLUDE_UIMANAGER_H_
#define INCLUDE_UIMANAGER_H_

#include "Board.h"

//TODO Remove dependency of PLAYER.h
#include <GoTPlayer.h>
#include "Player.h"
#include <Common.h>
#include <Renderer.h>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
class UIManager {
public:
	void renderPresentTexture();
	void renderClear();
	void renderNewTexture(texType tex);
	GameType onboarding();

	/*!
	 Performs initial housekeeping for game related requirements and creates
	 window for program
	 @param title title of the window
	 @param xpos x coordinate for window
	 @param ypos y coordinate for window
	 @param width width of the window
	 @param height height of the window
	 @param fullscreen whether to create fullscreen window
	 */
	void init(const char *title, int xpos, int ypos, int width, int height,
			bool fullscreen);
	/*!
	 Function to show pop-ups during the game
	 @param title title text of the popup
	 @param body body text of the popup
	 */
	void showPopupMessage(const char *title, const char *body);

	/*!
	 Function to display (pop-up) rules for the current game
	 */
	void showRules(GameType game);

	/*!
	 Function to create a renderCopy of the player that is to be displayed
	 */
	void requestPlayerTextureUpdate(_house whichhouse, uint8_t whichplayer,
			SDL_Rect srcRect, SDL_Rect DestRect);

	/*!
	 Destroys window, renderer and quits the game
	 */
	void clean();

	/*!
	 Function used to get pointer to texture by passing specific flags
	 @param textType texture flag
	 @return returns pointer to texture
	 */
	SDL_Texture *giveBackTexture(texType tex);

	/*!
	 Setter function for setting perticualr file or image to texture determined
	 by texType flag
	 @param texType flag to determine type of the texture
	 @param dieFace value on dieFace, optional paramater, if not entered
	 texture will be set for on boarding screen
	 */
	void setTexture(texType tex, int dieFace = 0);

	void drawBoard();
	void createBoard(GameType gameType);
	void statusUpdate(GameType gameType, std::string gotStatusText,
			std::string askHPTxt, std::string turnText,std::string moveInfoText,std::string rollInfoText,std::string rulesInfoText);
	UIManager();
	virtual ~UIManager();
private:
	Board *board;
	SDL_Texture *onBoardingBackground; /**< SDL_Texture for onBoarding Screen*/
	SDL_Texture *dieTexture; /**< SDL_Texture for die*/
	Renderer renderer;
	SDL_Window *window; /**< SDL_Window for program */
	TTF_Font *font; /**< font for text */
	SDL_Color textColor; /**< text color for text */
	SDL_Texture *gameTypeTexture; /**< SDL_Texture for text */
};

#endif /* INCLUDE_UIMANAGER_H_ */
