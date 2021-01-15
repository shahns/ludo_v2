/*! \file */
#pragma once
/*!
    This is a enum class for flags used in the program
*/
#include <ostream>
enum class FLAGS : int {
    ROLL_DIE,               /**< GUI flag for rolling a die*/
    UPDATE_GAME_TYPE,       /**< GUI flag for player name*/
    ASK_TO_USE_HOUSE_POWER, /**< GUI flag for asking user to use house power*/
    ASK_TO_USE_TOKEN_POWER, /**< GUI flag for asking user to use token power*/
    DEFAULT,                /**< Default Value*/
    GAME_WON,               /**< Flag to be set after game wone*/
    PLAYER_AT_HOME,         /**< player status flag for player at home*/
    PLAYER_IS_PLAYING,      /**< player status flag for player playing*/
    PLAYER_AT_CASTLE        /**< player status flag for player at castle*/
};

struct Point {
    int x, y;
    /*!
       overloaded equality operator
   */
    bool operator==(const Point &p) const { return (x == p.x && y == p.y); }

    /*!
	overloaded << operator for pretty printing
	*/
    friend std::ostream &operator<<(std::ostream &os, const Point p)
    {
        os << p.x << ',' << p.y;
        return os;
    }
};
