#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include "Constants.h"
#include <string>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
//#include <vector>

typedef enum _House{_HRED,_HBLUE,_HYELLOW,_HGREEN,_NOHOUSE=-1}_house; // add other
typedef enum _GameType{_TRADITIONAL,_GOT,_UNDEFINED=-1}GameType;
typedef enum _texType{_ONBOARDING,_DIEFACE}texType;
#define cout std::cout
#define endl std::endl
#define cin std::cin
#endif
