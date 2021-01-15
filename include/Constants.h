#pragma once
#include <string>
/*!
    all possible moves for individual players
*/

const int allXMoves[8][58] = {
    {64,  64,  128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512,
     512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704,
     640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384, 384, 384,
     320, 256, 192, 128, 64,  0,   0,   64,  128, 192, 256, 320, 384},//1-3
     
     {256, 64,  128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512,
     512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704,
     640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384, 384, 384,
     320, 256, 192, 128, 64,  0,   0,   64,  128, 192, 256, 320, 384}, //2-4
     
     {640, 512, 512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832,
     768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384,
     384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192, 256, 320,
     384, 384, 384, 384, 384, 384, 448, 448, 448, 448, 448, 448, 448},//5-7
     
     {832, 512, 512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832,
     768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384,
     384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192, 256, 320,
     384, 384, 384, 384, 384, 384, 448, 448, 448, 448, 448, 448, 448}, //6-8

     {832, 832, 768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384,
     384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192,
     256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512, 512, 512,
     576, 640, 704, 768, 832, 896, 896, 832, 768, 704, 640, 576, 512}, //9-10
         
    {640, 832, 768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384,
    384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192,
    256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512, 512, 512,
    576, 640, 704, 768, 832, 896, 896, 832, 768, 704, 640, 576, 512},//11-12
    
    {256, 384, 384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,
    128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512,
    512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704, 640, 576,
    512, 512, 512, 512, 512, 512, 448, 448, 448, 448, 448, 448, 448}, //13-16
    
    {64,  384, 384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,
    128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512,
    512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704, 640, 576,
    512, 512, 512, 512, 512, 512, 448, 448, 448, 448, 448, 448, 448} //14-15
};

    
const int allYMoves[8][58] = {
    
    {64,  384, 384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,
     128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512,
     512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704, 640, 576,
     512, 512, 512, 512, 512, 512, 448, 448, 448, 448, 448, 448, 448}, //1-2
     
     {256, 384, 384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,
     128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512,
     512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704, 640, 576,
     512, 512, 512, 512, 512, 512, 448, 448, 448, 448, 448, 448, 448}, //3-4
     
     {64,  64,  128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512,
     512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704,
     640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384, 384, 384,
     320, 256, 192, 128, 64,  0,   0,   64,  128, 192, 256, 320, 384}, //5-6
     
     {256, 64,  128, 192, 256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512,
     512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832, 768, 704,
     640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384, 384, 384,
     320, 256, 192, 128, 64,  0,   0,   64,  128, 192, 256, 320, 384}, //7-8
     
     {640, 512, 512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832,
     768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384,
     384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192, 256, 320,
     384, 384, 384, 384, 384, 384, 448, 448, 448, 448, 448, 448, 448}, //9-12
     
     {832, 512, 512, 512, 512, 512, 576, 640, 704, 768, 832, 896, 896, 896, 832,
     768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384, 384, 384,
     384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192, 256, 320,
     384, 384, 384, 384, 384, 384, 448, 448, 448, 448, 448, 448, 448},//10-11
     
     {832, 832, 768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384,
     384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192,
     256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512, 512, 512,
     576, 640, 704, 768, 832, 896, 896, 832, 768, 704, 640, 576, 512},//13-14
     
     {640, 832, 768, 704, 640, 576, 512, 512, 512, 512, 512, 512, 448, 384, 384,
     384, 384, 384, 384, 320, 256, 192, 128, 64,  0,   0,   0,   64,  128, 192,
     256, 320, 384, 384, 384, 384, 384, 384, 448, 512, 512, 512, 512, 512, 512,
     576, 640, 704, 768, 832, 896, 896, 832, 768, 704, 640, 576, 512} //15-16
    
};

const int moveMapX[16] = {0,1,0,1,2,3,2,3,4,4,5,5,6,7,7,6};
const int moveMapY[16] = {0,0,1,1,2,2,3,3,4,5,5,4,6,6,7,7};

const std::string GoTRules =
    "Game Rules\n------------------------\n1. All players start by "
    "rolling the die "
    "once.\n2. 6 is required on the die to get a pawn into the game. 6 "
    "also awards you a bonus turn. When 6 is rolled, player has the "
    "choice of getting a pawn out of the castle or moving the existing "
    "pawns in the game.\n3. At the start of each turn, roll the die "
    "and choose a pawn to move.\n4. When a player pawn reaches the "
    "place where another player pawn is there, the other players pawn "
    "is killed and sent back to their home castle.\n\n"
    "CONTROLS\n------------------------\nPress P to pass a "
    "turn.\nPress S to see this screen again.\nPress R to roll a "
    "die.\nPress T to use pawn power followed by 1, 2, 3, 4 (after "
    "your chance) \nPress 1,2,3,4 to select a "
    "pawn.\nPress Y to use house power (after your chance)\nPress N to "
    "refuse using "
    "power.\nPowers\n------------------------\nStarks:\n\tHouse "
    "Power: Resurrection - Gets a new pawn into the game.\n\tPawn "
    "Power: Other side of the wall - Power to choose the number on the "
    "opposite die face.\n\nTargaryens:\n\tHouse Power: Dothraki March "
    " - All active pawns move ahead 2 places.\n\tPawn Power: Speed of "
    "the Dragon - Pawn moves ahead by 2 times the number on the die "
    "face\n\nLannisters:\n\tHouse Power: Send Regards - Sends any 1 "
    "pawn of any opponent to the starting position.\n\tPawn Power: "
    "Golden chance - Awards 1 extra roll\n\nWhite Walkers:\n\tHouse "
    "Power: Attack on the kingdom - Each opponent pawn moves back by 2 "
    "places.\n\tPawn Power: Break the Wall - Advance pawn by 3 places";

const std::string traditionalRules =
    "Game Rules\n------------------------\n1. All players start by "
    "rolling the die "
    "once.\n2. 6 is required on the die to get a pawn into the game. 6 "
    "also awards you a bonus turn. When 6 is rolled, player has the "
    "choice of getting a pawn out of the castle or moving the existing "
    "pawns in the game.\n3. At the start of each turn, roll the die "
    "and choose a pawn to move.\n4. When a player pawn reaches the "
    "place where another player pawn is there, the other players pawn "
    "is killed and sent back to their home castle.\n\n"
    "CONTROLS\n------------------------\nPress P to pass a "
    "turn.\nPress S to see this screen again.\nPress R to roll a "
    "die.\nPress 1,2,3,4 to select a pawn.";

const std::string movementError =
    "Issue: Either pawn movement is pending or power usage "
    "is pending.\n----------------------------------------"
    "\nPossible Solutions:\nPress 1, 2, 3, 4 to move "
    "pawn\nPress Y to use power\nPress N to refuse using "
    "power\nPress T followed by pawn number to use pawn "
    "power";

const std::string powerError = "You can not combine House Power with "
                               "6. Use at next turn.";

const std::string powerAlreadyUsedError = "You have already used House Power. "
                                          "Press N to refuse it.";

const std::string invalidInputError = "Invalid input. Consumed.";

const std::string powerCombinationError = "You can not combine House Power with "
                                      "6. Use at next turn.";
