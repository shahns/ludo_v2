#ifndef GOTPLAYER_H_
#define GOTPLAYER_H_

#include "Common.h"
#include "Player.h"
class GoTPlayer : public Player
{
  public:
    GoTPlayer(int gpColor,uint8_t arrayIndex,uint8_t playerNum)
        : Player(gpColor,arrayIndex,playerNum)
    {
    	isPowerUsed = false;
    }

    /*!
        Getter function to get current status of token power
        @return status of the power usage
    */
    bool getPowerStatus();

    /*!
      Setter function for setting or updating token power status
      @param status value to set
  */
    void setPowerStatus(bool status);

    /*!
        performs housekeeping activities like power status when it is go to
       castle etc.
    */
    void doHouseKeeping();


  private:
//	uint8_t	 playerNumber; /* player number in house. Used to load appropriate texture*/
    bool isPowerUsed;   /**< traking token power usage status of the
                                     player*/
};
#endif
