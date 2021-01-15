#include "GoTToken.h"
bool GoTToken::getOwnPowerUsedStatus() { return isPowerUsed; }

void GoTToken::setPowerStatus(bool status) { isPowerUsed = status; }

void GoTToken::doHouseKeeping()
{
    if (Token::playerStatus == FLAGS::PLAYER_AT_CASTLE) {
        isPowerUsed = true;
    }
}

ownPowerReturn GoTToken::useOwnPower(uint8_t dieFace, uint8_t whoseChace)
{
    ownPowerReturn ownPower;
    ownPower.body = "Can not take player out. Chance Wasted!";
    ownPower.whoseChance = whoseChace;
    switch (Token::getPlayerColour()) {
    case _HRED:
        isPowerUsed = true;
        ownPower.whoseChance = 0;
        ownPower.body = "Extra Chance for Player 1";
        break;
    case _HBLUE:
        if (Token::getPosIndex() != 0) {
            Token::incrPosIndex(3, false);
            isPowerUsed = true;
            ownPower.whoseChance = 2;
            ownPower.body = "Token moved ahead by 3 places";
        }
        break;
    case _HYELLOW:
        if (Token::getPosIndex() != 0) {
            Token::incrPosIndex(dieFace, false);
            isPowerUsed = true;
            ownPower.whoseChance = 3;
            ownPower.body =
                "Token moved ahead by " + std::to_string(dieFace) + " places";
        }
        break;
    case _HGREEN:
        if (Token::getPosIndex() != 0) {
            Token::incrPosIndex(std::abs(7 - (2 * dieFace)), false);
            isPowerUsed = true;
            ownPower.whoseChance = 0;
            ownPower.body = "Token moved ahead by " +
                            std::to_string(std::abs(7 - (2 * dieFace))) +
                            " places";
        }
        break;
    default:
        ownPower.body = "Something went wrong. Repeating chance";
        break;
    }
    return ownPower;
}
