/*
 * House.h
 *
 *  Created on: Jan 31, 2019
 *      Author: vishwajit
 */

#ifndef HOUSE_H_
#define HOUSE_H_

#include "Player.h"
#include "GoTPlayer.h"
#include <vector>
#include "Common.h"
//todo craeate house enum {home,playing,completed} and ponder on its use
class House {
	GameType gameType;
	_house houseType;
	uint8_t playerCount;
	bool isHPUsed;
	std::vector<Player*> players;
	bool stillPlaying;
	//create an enum
public:
	const SDL_Rect& getPlayerSrcRect(uint8_t whichPlayer);
	const SDL_Rect& getPlayerDestRect(uint8_t whichPlayer);
	const std::string getStatusString();
	const std::string useHousePower(std::vector<House*> allHouses);
	bool isPowerUsageAllowed();
	void askToMovePlayer(uint8_t playerNum,uint8_t dieFace,bool isSpecialMovement);
	bool NorAllPlayers();
	House(uint8_t noOfPlayers, _house hType,GameType gameT);
	virtual ~House();

	const std::vector<Player*>& getHousePlayers() const {
		return players;
	}

	Player* getPlayer(uint8_t whichplayer) const {
		return players[whichplayer];
	}
	Point getPlayerPose(uint8_t whichPlayer);
	void setHousePlayers(const std::vector<Player*>& housePlayers) {
		this->players = housePlayers;
	}
	bool isIsHpUsed() const {
		return isHPUsed;
	}

	void setIsHpUsed(bool isHpUsed) {
		isHPUsed = isHpUsed;
	}

	bool isStillPlaying() const {
		return stillPlaying;
	}

	void setStillPlaying(bool isStillPlaying) {
		this->stillPlaying = isStillPlaying;
	}

	uint8_t getNoOfPlayers() const {
		return playerCount;
	}

	void setNoOfPlayers(uint8_t noOfPlayers) {
		this->playerCount = noOfPlayers;
	}

	_house getHouseType() const {
		return houseType;
	}

	void setHouseType(_house houseType) {
		this->houseType = houseType;
	}
};

#endif /* HOUSE_H_ */
