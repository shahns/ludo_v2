#ifndef GOTPLAYER_H_
#define GOTPLAYER_H_

#include "Common.h"
#include "Flags.h"
#include "Token.h"
class GoTToken : public Token
{
  public:
    GoTToken(int gpColor, uint8_t arrayIndex, uint8_t playerNum)
        : Token(gpColor, arrayIndex, playerNum)
    {
        isPowerUsed = false;
    }

    /*!
     Getter function to get current status of token power
     @return status of the power usage
     */
    bool getOwnPowerUsedStatus();

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

    /*!
     allows GOTPlayer to use own special power
     @param number on die face
     @param current chance
     @return effects of power usage on game
     */
    ownPowerReturn useOwnPower(uint8_t dieFace, uint8_t whoseChace);

  private:
    bool isPowerUsed = false; /**< traking token power usage status of the
     player*/
};

#endif
