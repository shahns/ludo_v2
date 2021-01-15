/*
 * GameManager.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: vishwajit
 */

#include <GameManager.h>

#include "GameManager.h"
#include "Board.h"
#include "GoTPlayer.h"
#include "UIManager.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <vector>

//TODO remove these variables

bool allowHouseSpecialPowerUsage = false;
bool allowOwnSpecialPowerUsage = false;
bool isPlayerSelectionAllowedPower = false;

GameManager::GameManager() :
		UI() { // @suppress("Class members should be properly initialized")
	cout<<" [GM][const]: Entry"<<endl;
	noOfHouses = 4;
	//houses = NULL;
	isRunning = true;
	dieFace = 0;
	gameType = _UNDEFINED;
	gameFlags = FLAGS::DEFAULT;
	whoseChance = 0;
	isMovementAllowed = false;
	isDieThrowAllowed = true;
	//TODO why this string defination is required?
	moveInfoText = "Press 1, 2, 3, 4 to move your token";
	rollInfoText = "Press R to roll a die";
	rulesInfoText = "Press S to see rules";
	initUpdate();
	performOnBoarding();
	cout<<" [GM][const]: Exit"<<endl;
}
GameManager::~GameManager() {
}

//TODO get number of players from the screen

void GameManager::handleEvents() {
	cout<<" [GM][Hand_Events]: Entry"<<endl;
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		// User requests quit
		if (event.type == SDL_QUIT) {
			UI.clean();
			isRunning = false;
		}
		// User presses a key
		else if (event.type == SDL_KEYDOWN) {
			// Select surfaces based on key press
			switch (event.key.keysym.sym) {
				// roll die
				case SDLK_r:
				cout<< "[GAME_MANAGER]: AllowDieThrow: "
				<< isDieThrowAllowed << endl;
				if (isDieThrowAllowed &&
						gameFlags != FLAGS::ASK_TO_USE_HOUSE_POWER &&
						gameFlags != FLAGS::ASK_TO_USE_TOKEN_POWER) {
					gameFlags = FLAGS::ROLL_DIE;
					if (whoseChance != 0) {
						srand(rand() ^ time(NULL));
						dieFace = rand() % 6 + 1;
						whoseChance = validateTurn(whoseChance);
						setTurnText(whoseChance);
						isDieThrowAllowed = false;
						isMovementAllowed = true;
					} else {
						whoseChance = 0;
						isMovementAllowed = false;
					}
				} else {
					UI.showPopupMessage("Error!", movementError.c_str());
				}
				UI.showPopupMessage("WHoseCHance", std::to_string(whoseChance).c_str());
				break;

				case SDLK_s:
				UI.showRules(gameType);
				break;

				case SDLK_y:
				if (gameType == _GOT && !isMovementAllowed &&
						allowHouseSpecialPowerUsage) {
					_house turn =(_house) ((whoseChance)%4); //todo change 4 to no of houses

					if (dieFace != 6) {
						if (houses[turn]->isIsHpUsed()) {
							UI.showPopupMessage(
									"Error", powerAlreadyUsedError.c_str());
						} else {
							//todo turn or whose chance?
							//todo does both variables are really required?
							askToUsehousePower(turn);
							houses[turn]->setIsHpUsed(true);
						}
						isDieThrowAllowed = true;
						//std::string housePowerText = "";
						allowHouseSpecialPowerUsage = false;
						allowOwnSpecialPowerUsage = false;
						gameFlags = FLAGS::DEFAULT;
					} else {
						UI.showPopupMessage("Error", powerError.c_str());
						isDieThrowAllowed = true;
						//housePowerText = " ";
						allowHouseSpecialPowerUsage = false;
						allowOwnSpecialPowerUsage = false;
						gameFlags = FLAGS::DEFAULT;
					}
				} else {
				}
				break;
				case SDLK_n:
				if (gameType == _GOT && !isMovementAllowed &&
						allowHouseSpecialPowerUsage) {
					isDieThrowAllowed = true;
					allowHouseSpecialPowerUsage = false;
					allowOwnSpecialPowerUsage = false;
					gameFlags = FLAGS::DEFAULT;
				} else {
					UI.showPopupMessage("Error", invalidInputError.c_str());
				}
				break;
				case SDLK_t:
				if (dieFace != 6) {

					if (gameType == _GOT && !isMovementAllowed &&
							allowOwnSpecialPowerUsage) {
						isPlayerSelectionAllowedPower = true;
					} else {
						UI.showPopupMessage("Error",
								invalidInputError.c_str());
					}
				} else {
					UI.showPopupMessage("Error",
							powerCombinationError.c_str());
					isDieThrowAllowed = true;
					//housePowerText = "";
					allowHouseSpecialPowerUsage = false;
					allowOwnSpecialPowerUsage = false;
					gameFlags = FLAGS::DEFAULT;
				}
				break;
				case SDLK_p:
				whoseChance = (whoseChance+1)%4;
				if (gameType == _GOT) {
					allowHouseSpecialPowerUsage = false;
					allowOwnSpecialPowerUsage = false;
				}
				GameManager::setTurnText(whoseChance);
				gameFlags = FLAGS::DEFAULT;
				isDieThrowAllowed = true;
				break;
				case SDLK_1: processNumKey(0);
				break;
				case SDLK_2: processNumKey(1);
				break;
				case SDLK_3: processNumKey(2);
				break;
				case SDLK_4: processNumKey(3);
				break;
				case SDLK_6:
				dieFace = 6;
				break;
				default:
				break;
			}
		}
	}
	cout<<" [GM][Hand_Events]: Exit"<<endl;
}
void GameManager::processNumKey(uint8_t whicPlayer) {
	UI.showPopupMessage("WHoseCHance", std::to_string(whoseChance).c_str());
	cout<<" [GM][procc_num_key]: Entry"<<endl;
	if (!isDieThrowAllowed && gameFlags != FLAGS::ASK_TO_USE_HOUSE_POWER
			&& !allowOwnSpecialPowerUsage) {
		askToMoveToken (whicPlayer,whoseChance, false);
	} else if (isPlayerSelectionAllowedPower) {
		GoTPlayer * gt = (GoTPlayer*)((houses[whoseChance]->getHousePlayers())[whicPlayer]);
		if (gt->getPowerStatus()) {
			//whoseChance = 1;
			std::string text = "Extra Chance for Player ";
			UI.showPopupMessage("Pawn Special Power", text.c_str());
			gt->setPowerStatus(true);
		}
		else {
			UI.showPopupMessage("Error",
					"You have already used your special power.");
		}
		gameFlags = FLAGS::DEFAULT;
		allowOwnSpecialPowerUsage = false;
		allowHouseSpecialPowerUsage = false;
		isDieThrowAllowed = true;
		isPlayerSelectionAllowedPower = false;
		cout<< "[GAME_MANAGER] used special token power";
	}
	else {
		UI.showPopupMessage("Invalid Input",
				invalidInputError.c_str());
		cout << "[GAME_MANAGER] wrong combination"
		<< endl;
	}
	cout<<" [GM][procc_num_key]: Exit"<<endl;
	if (dieFace < 6) {
		whoseChance = (whoseChance+1)%noOfHouses;
	}


}
//Keynum = actual key -1
void GameManager::initUpdate() {
	cout<<" [GM][initUp]: Entry"<<endl;
	for (auto &h : houses) {
		for (uint8_t i = 0; i < noOfPlayers; i++) {
			Player* p = h->getPlayer(i);
			p->update();
		}
	}
	setTurnText(whoseChance);
	cout<<" [GM][initUp]: Exit"<<endl;
}
void GameManager::requestPlayerTextureUpdate() {
	cout<<" [GM][reqPl_Tex_Up]: Entry"<<endl;
	for (auto &h : houses) {
		for (auto &p : h->getHousePlayers()) {
			UI.requestPlayerTextureUpdate(h->getHouseType(), p->getPlayerNum(),
					p->getSrcRect(), p->getDestRect());
		}
	}
	cout<<" [GM][reqPl_Tex_Up]: Exit"<<endl;
}

std::string GameManager::showGoTStatus() {
	cout<<" [GM][show_GOT_Stat]: Entry"<<endl;
	std::string text = "";
	for (uint8_t i = 0; i < 4; i++) { //todo 4 is hardcoded
		text += "\nPlayer " + std::to_string(i + 1);
		text += houses[i]->getStatusString();
	}
	cout<<" [GM][show_GOT_Stat]: Exit"<<endl;
	return text;
}
void GameManager::gameStatusUpdate() {
	cout<<" [GM][gameStat_UP]: Entry"<<endl;
	UI.renderClear();
	UI.drawBoard();
	std::string askHPString = "";
	if (gameFlags == FLAGS::ASK_TO_USE_HOUSE_POWER) {
		askHPString = "Use House Power?";
	}

	requestPlayerTextureUpdate();
	std::string gotStatusText = "";
	if (gameType == _GOT) {
		gotStatusText = showGoTStatus();
	}
	UI.statusUpdate(gameType, gotStatusText, askHPString, turnText,
			moveInfoText, rollInfoText, rulesInfoText);

	switch (gameFlags) {
		case FLAGS::ROLL_DIE:
		UI.setTexture(_DIEFACE, dieFace);
		break;
		case FLAGS::ASK_TO_USE_HOUSE_POWER:
		allowHouseSpecialPowerUsage = true;
		break;
		case FLAGS::ASK_TO_USE_TOKEN_POWER:
		allowOwnSpecialPowerUsage = true;
		break;
		case FLAGS::DEFAULT:
		allowHouseSpecialPowerUsage = false;
		allowOwnSpecialPowerUsage = false;
		break;
		default:
		break;
	}
	UI.renderPresentTexture();
	cout<<" [GM][gameStat_UP]: Exit"<<endl;
}
void GameManager::playerStatusUpdate() {
	cout<<" [GM][Pl_Stat_UP]: Entry"<<endl;
	if (gameType == _GOT) {
		for (auto &h : houses) {
			for (uint8_t i = 0; i < noOfPlayers; i++) {
				Player* p = h->getPlayer(i);
				//todo check any other way apart from typecasting
				//to access derived class method from parent class
				((GoTPlayer*) p)->doHouseKeeping();
			}
		}
	}
	uint8_t activeHouses = 0;
	for (int i = 0; i < noOfHouses; i++) {
		if(!(houses[i]->NorAllPlayers())) {
			activeHouses++;
		}
	}
	if ((activeHouses) == 1) {
		UI.showPopupMessage("Congratulations!!!",
				"Congratulations!!! Game Finished. Game will be "
				"closed on clicking ok! ");
		UI.clean();
		isRunning = false;
	}
	cout<<" [GM][Pl_Stat_UP]: Exit"<<endl;
}

const int GameManager::validateTurn(int turn) const {
	cout<<" [GM][val_turn]: Entry"<<endl;
	for (int i = turn; i < turn + noOfHouses; i++) {
		if (houses[i % 4]->isStillPlaying())
		cout<<" [GM][val_turn]: Exit"<<endl;
		return i % 4;
	}
	cout<< "[GAME_MANAGER] Game is finished"<<endl;
	cout<<" [GM][val_turn]: Exit"<<endl;
	return -1;
}

void GameManager::askToMoveToken(uint8_t playerNum, uint8_t whichHouse,
		bool isSpecialMove) {
	cout<<" [GM][ask_MV_tok]: Entry"<<endl;
	//todo this if condition check can be improved
	if (gameType == _GOT) {
		if (houses[whichHouse]->isPowerUsageAllowed()) {
			allowHouseSpecialPowerUsage = true;
			allowOwnSpecialPowerUsage = true;
		}
	}
	houses[whichHouse]->askToMovePlayer(playerNum, dieFace, isSpecialMove);
	isMovementAllowed = false;
	if (gameType == _TRADITIONAL) {
		isDieThrowAllowed = true;
		//cout<< houses[whichHouse]->getPosIndex() << endl;
	}
	killEnemy(whichHouse, playerNum);
	cout<<" [GM][ask_MV_tok]: Exit"<<endl;
}

//todo change playercolor mechanism
void GameManager::killEnemy(uint8_t whichHouse, uint8_t whichPlayer) {
	cout<<" [GM][kill_Enemy]: Entry"<<endl;
	Point newPoint = houses[whichHouse]->getPlayerPose(whichPlayer);
	for (auto &h : houses) {
		if (h->getHouseType() != whichHouse) {
			for (uint8_t i = 0; i < noOfPlayers; i++) {
				Player* p = h->getPlayer(i);
				if (p->getPoint() == newPoint && !(p->getPosIndex() == 1)) {
					p->incrPosIndex(-58, false);

				}

			}
		}
	}
	cout<<" [GM][kill_Enemy]: Exit"<<endl;
}

void GameManager::askToUsehousePower(_house houseType) {
	cout<<" [GM][ask_use_HP]: Entry"<<endl;
	std::string popuptext = houses[houseType]->useHousePower(houses);
	UI.showPopupMessage("House Power Used", popuptext.c_str());
	cout<<" [GM][ask_use_HP]: Exit"<<endl;
}

void GameManager::performOnBoarding() {
	cout<<" [GM][perf_onBoard]: Entry"<<endl;
	GameType isCorrectGameType = _UNDEFINED;
	while (isCorrectGameType == _UNDEFINED) {
		isCorrectGameType = UI.onboarding();
	}
	setGameType(isCorrectGameType);
	UI.showRules(gameType);
	UI.createBoard(gameType);
//todo change this to dynamical limit
	for (int i = 0; i < noOfHouses; i++) {
		houses.push_back(new House(4, (_house) i, gameType));
	}
	cout<<" [GM][perf_onBoard]: Exit"<<endl;
}

