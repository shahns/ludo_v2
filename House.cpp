/*
 * House.cpp
 *
 *  Created on: Jan 31, 2019
 *      Author: vishwajit
 */

#include "House.h"

const std::string House::getStatusString() {
	std::string text = "";
	if (isHPUsed) {
		text += "\nHouse Power : Used";
	} else {
		text += "\nHouse Power: Available";
	}
	int i = 1;
	for (auto &p : players) {
		if (((GoTPlayer*) p)->getPowerStatus()) {
			text = " Token " + std::to_string(i) + " Power : Used";
		} else {
			text = " Token " + std::to_string(i) + " Power : Available";
		}
	}
	return text;
}
const std::string House::useHousePower(std::vector<House*> allHouses) {
	std::string popupText = "";
	switch (houseType) {
	case _HRED: {
		int i = 0;
		while (i < playerCount) {
			if (players[i]->getPosIndex() == 0) {
				players[i]->incrPosIndex(1, true);
				break;
			}
			i++;
		};
		popupText += "One token resurrected";
	}

		break;
	case _HBLUE: {
		for (auto &p : players)
			p->incrPosIndex(2, false);
		popupText += "Incremented all active tokens by 2 places";
	}

		break;
	case _HYELLOW: {
		srand(rand() ^ time(NULL));
		uint8_t houseKill = rand() % 3; //todo get no of houses and replace 3 by number-1
		uint8_t playerKill = rand() % playerCount;
		switch (houseKill) {
		case _HRED:
			allHouses[_HRED]->askToMovePlayer(playerKill, -58, false);
			popupText = " Player Red, Token " + std::to_string(playerKill + 1)
					+ " Sent to home";
			break;
		case _HBLUE:
			allHouses[_HBLUE]->askToMovePlayer(playerKill, -58, false);
			popupText = " Player Blue Token " + std::to_string(playerKill + 1)
					+ " Sent to home";
			break;
		case (_HGREEN - 1): //because yellow is 2 and green is 3!
			allHouses[_HGREEN]->askToMovePlayer(playerKill, -58, false);
			popupText = " Player Green, Token " + std::to_string(playerKill + 1)
					+ " Sent to home";
			break;
			//case _HGREEN:
		default:
			break;
		}
	}

		break;
	case _HGREEN: {
		for (auto &h : allHouses) {
			if (h->getHouseType() != _HGREEN) { //todo check colorrs and house number correspondence
				for (auto &p : h->getHousePlayers()) {
					p->incrPosIndex(-2, false);
				}
			}
		}
		popupText += "All other active token taken back by two places";
		break;
	}

	case _NOHOUSE:
	default:
		break;
	}
	return popupText;
}

bool House::isPowerUsageAllowed() {
	bool state = true;
	if (gameType == _GOT) {
		bool state = isHPUsed;
		for (auto &p : players) {
			state = state && ((GoTPlayer*) p)->getPowerStatus();
		}
	}
	return !state;
}

Point House::getPlayerPose(uint8_t whichPlayer) {
	return players[whichPlayer]->getPoint();
}
void House::askToMovePlayer(uint8_t playerNum, uint8_t dieFace,
		bool isSpecialMovement) {
	players[playerNum]->incrPosIndex(dieFace, isSpecialMovement);
}

const SDL_Rect& House::getPlayerSrcRect(uint8_t whichPlayer) {
	return players[whichPlayer]->getSrcRect();
}
const SDL_Rect& House::getPlayerDestRect(uint8_t whichPlayer) {
	return players[whichPlayer]->getDestRect();
}
House::House(uint8_t noOfPlayers, _house hType, GameType gameT) {
	// TODO Auto-generated constructor stub
	playerCount = noOfPlayers;
	houseType = hType;
	isHPUsed = false;
	stillPlaying = true;
	gameType = gameT;
	if (gameT == _GOT) {
		for (uint8_t i = 0; i < noOfPlayers; i++) {
			players.push_back(new GoTPlayer(houseType, ((4 * hType) + i), i));
		}
	} else {
		for (uint8_t i = 0; i < noOfPlayers; i++) {
			players.push_back(new Player(houseType, ((4 * hType) + i), i));
		}
	}
}

bool House::NorAllPlayers() {
	bool status = players[0]->isPlayingInGame();
	for (int i = 1; i < playerCount; i++) {
		status = status || players[i]->isPlayingInGame();
	}
	return !status;
}

House::~House() {
	// TODO Auto-generated destructor stub
}

