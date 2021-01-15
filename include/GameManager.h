/*
 * GameManager.h
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#ifndef INCLUDE_GAMEMANAGER_H_
#define INCLUDE_GAMEMANAGER_H_
#include "UIManager.h"
#include "Common.h"
#include "Flags.h"
#include "House.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include <vector>

class GameManager {
public:
	/*!
	 Constructor for class GameManager\n
	 Performs initialization for game related requirements.
	 */
	GameManager();
	/*!
	 Destructor for class GameManager\n
	 */
	~GameManager();

	/*!
	 Handles various events during program life time for e.g. SDL_QUIT,
	 SDL_KEYDOWN
	 */
	void handleEvents();

	/*!
	 Sets game for first turn
	 */
	void initUpdate();
	void requestPlayerTextureUpdate();
	std::string showGoTStatus();

	/*!
	 Render_Copies various textures to renderer and Render_Presents the
	 renderer
	 */
	void gameStatusUpdate();

	/*!
	 Getter function to return the running status of game
	 @return boolean value
	 */
	bool running() {
		return isRunning;
	}

	/*!
	 Calculates if perticular player and in turn perticular house is playing
	 game or not and updates flags accordingly
	 */
	void playerStatusUpdate();

	/*!
	 Validates and sets and keeps track of next and current turn of the
	 player and check if game is won
	 @param x current turn
	 @return int validated current turn

	 */
	const int validateTurn(int turn)const;

	/*!
	 Setter function for setting game type
	 @param gameType type of the current game {"Traditional", "GoT"}
	 */
	void setGameType(GameType type) {
		gameType = type;
	}

	/*!
	 Getter function to get game type
	 @return type of the game
	 */
	GameType getGameType() {
		return gameType;
	}

	/*!
	 Setter function for setting or updating turn text
	 @param turn house number of the player who will play current turn
	 */
	void setTurnText(int turn) {
		turnText = "Turn: Player " + std::to_string(turn);
	}



	/*!
	 Setter function to set movement status
	 @param status movement status
	 */
	void setIsMovementAllowed(bool status) {
		isMovementAllowed = status;
	}

	/*!
	 Getter function to get game type at the start of the game and show
	 background on onboarding screen
	 @return int 0 if selection is made\n 1 if error while displaying the
	 pop-up\n 2 if no selection made
	 */
	void performOnBoarding();

	/*!
	 Function for using house specific powers (only for GoT Version)
	 @param house house number of the player
	 */
	void askToUsehousePower(_house houseType);

	/*!
	 Setter function to set house power status of player
	 @param &playerVector movement status
	 @param powerStatus movement status
	 */
	void setAllHousePowers(std::vector<GoTPlayer *> &playerVector,
			bool powerStatus);
private:
	uint8_t noOfPlayers;
	std::vector<House*> houses;
	//std::vector<std::vector<Player *>> playerVector;
	//uint8_t Number_of_Players;
	// game
	bool isRunning; /**< programme running status*/
	// SDL_Window *window; /**< SDL_Window for program */
	FLAGS gameFlags; /**< enum GUIFLAGS */

	// GameManager Related
	GameType gameType; /**< type of the game normal, GoT */
	std::string turnText; /**< player turn*/
	std::string tokenToMoveText = "Type Token Number to move"; /**< info text token to move*/
	std::string moveInfoText; /**< info text displayed for current turn*/
	std::string rollInfoText; /**< info text displayed to roll die*/
	std::string rulesInfoText; /**< info text displayed to show rules*/
	int dieFace; /**< randomly generated value upon die roll*/
	/*static*/
	int whoseChance; /**< tracking current turn*/
	bool isMovementAllowed; /**< traking current movement status*/
	bool isDieThrowAllowed; /**< traking current die roll status*/
	UIManager UI;
	uint8_t noOfHouses;
	//TODO write explanation
	void processNumKey(uint8_t);
	/*!
	 asks to move token on the screen and updates token position using player
	 class
	 @param playerNum token number to be moved
	 @param &playerVector vector consisting all players
	 @param movement is movement allowed for current situation
	 */
	void askToMoveToken(uint8_t playerNum, uint8_t whichHouse,
			bool isSpecialMove);

	/*!
	 Function to implement kill logic
	 @param myColor color number of the house
	 @param myNewPosIndex updated position index
	 */
	void killEnemy(uint8_t whichHouse, uint8_t whichPlayer);

};

#endif /* INCLUDE_GAMEMANAGER_H_ */
