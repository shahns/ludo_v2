#include <GameManager.h>
#include <Player.h>
#include <UIManager.h>

#include "Flags.h"
#include <iostream>

int Player::nextID = 0;

//GameManager *gm = new GameManager();

Player::Player(int pColor, const uint8_t arrayIndex, uint8_t PlayerNumber){
	poseArrayIndex = arrayIndex;
	playerNum = PlayerNumber;
    playerID = ++nextID;
    posIndex = 0;
    playerStatus = FLAGS::PLAYER_AT_HOME;
    //TODO instead of texture what if we hold an enum
    playerColor = pColor;
    //std::copy(&pMoves[0][0], &pMoves[0][0] + 2 * 58, &allPossibleMoves[0][0]);
    pt.x = allXMoves[moveMapX[poseArrayIndex]][posIndex];
    pt.y = allYMoves[moveMapY[poseArrayIndex]][posIndex];
    srcRect = {0, 0, 64, 64}; // x,y,w,h
    destRect = {pt.x, pt.y,
                    srcRect.w, srcRect.h};
}

void Player::update()
{
	//cout<<"pt.x"<<pt.x<<"\tpt.y"<<pt.y<<endl;
    srcRect = {0, 0, 64, 64}; // x,y,w,h
    destRect = {pt.x, pt.y,
                srcRect.w, srcRect.h};
}

void Player::incrPosIndex(int places, bool usingSpecialPower)
{
    if (posIndex == 0 && !(places == 6) && !usingSpecialPower) {
        cout << "[PLAYER_MANAGER] Need a 6 to get token out. Passing turn "
                     "to next player"
                  << endl;
    } else {
        posIndex = posIndex + places;
        if (posIndex >= 57) {
            posIndex = 57;
            pt.x = allXMoves[moveMapX[poseArrayIndex]][posIndex];
            pt.y = allYMoves[moveMapY[poseArrayIndex]][posIndex];
            playerStatus = FLAGS::PLAYER_AT_CASTLE;
        }
        if (posIndex <= 0) {
            posIndex = 0;
            pt.x = allXMoves[moveMapX[poseArrayIndex]][posIndex];
            pt.y = allYMoves[moveMapY[poseArrayIndex]][posIndex];
            playerStatus = FLAGS::PLAYER_AT_HOME;
        }
        srcRect = {0, 0, 64, 64}; // x,y,w,h

        pt.x = allXMoves[moveMapX[poseArrayIndex]][posIndex];
        pt.y = allYMoves[moveMapY[poseArrayIndex]][posIndex];
        destRect = {pt.x, pt.y, srcRect.w, srcRect.h};
    }
}

const bool Player::isPlayingInGame() const
{
    if (playerStatus == FLAGS::PLAYER_IS_PLAYING ||
        playerStatus == FLAGS::PLAYER_AT_HOME) {
        return true;
    }
    return false;
}

const int Player::getPosIndex() const { return posIndex; }
const int Player::getPlayerColour() const { return playerColor; }
void Player::setPlayerStatus(FLAGS status) { playerStatus = status; }

const Point Player::getPoint() const { return pt; }

void Player::setPoint(int x, int y)
{
    pt.x = x;
    pt.y = y;
}
