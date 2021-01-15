#include <GoTPlayer.h>

bool GoTPlayer::getPowerStatus() { return isPowerUsed; }

void GoTPlayer::setPowerStatus(bool status)
{
    isPowerUsed = status;
}

void GoTPlayer::doHouseKeeping()
{
    if (Player::playerStatus == FLAGS::PLAYER_AT_CASTLE) {
    	isPowerUsed = true;
    }
}

