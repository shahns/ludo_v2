#ifndef PLAYER_H_
#define PLAYER_H_

#include "Constants.h"
#include "Flags.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>

/*!
    Class that handles all player reladed functions.
*/
class Player
{
  public:
    /*!
        Constructor for class Player\n
        Auto-increments player id\n
        Automatically sets colour, texture, possible moves, intial positions and
       performs other initial required housekeeping.
    */
    Player(int pColor, const uint8_t arrayIndex, uint8_t PlayerNumber);

    /*!
        Destructor for player class
    */
    ~Player();

    /*!
        Function to update or set the rectangle in which to which to render the
       player's x poistion, y position, height and width of the texture.
    */
    void update();


    /*!
        Setter function to set the position index of the player
        @param places signed places to move
    */
    void incrPosIndex(int places, bool usingSpecialPower);

    /*!
        Getter function to return the playing status of the player
        @return boolean value
    */
    const bool isPlayingInGame() const;

    /*!
        Getter function to return current position index of the player
        @return boolean value
    */
    const int getPosIndex() const;

    /*!
		Getter function to return current position index of the player
		@return boolean value
	*/
    const int getPlayerColour() const;

    /*!
        Setter function to set current status of the player
        @param status current status
    */
    void setPlayerStatus(FLAGS status);

    /*!
        Getter function to get current x, y location of the player
        @return Point
    */
    const Point getPoint() const;

    /*!
        Setter function to set current point on screen
        @param x x coordinate
        @param y y coordinate
    */
    void setPoint(int x, int y);

	const SDL_Rect& getDestRect() const {
		return destRect;
	}

	const SDL_Rect& getSrcRect() const {
		return srcRect;
	}

uint8_t getPlayerNum() const {
		return playerNum;
	}

  private:
    uint8_t playerNum;
    static int nextID; /**< auto-increment for playerID */
    uint8_t poseArrayIndex;	/* index to x and y position data in array*/
    Point pt;
    int playerID;    /**< id for players; {1,16}, distrubuted sequentially */
    int playerColor; /**< color for players {R=1,G=2,B=3,Y=4} */
    int posIndex; /**< current postion index; current location on the board is
                     value of allPossibleMove at current value of posIndex */
    SDL_Rect srcRect, destRect;

  protected:
    FLAGS playerStatus; /**< current status of player */
};
#endif
