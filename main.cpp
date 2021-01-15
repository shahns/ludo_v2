#include "GameManager.h"

GameManager *game = nullptr;
int main(int argc, char *argv[])
{
    const int FPS = 1;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new GameManager();
    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->playerStatusUpdate();
        game->handleEvents();
        game->gameStatusUpdate();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
        //cout<<"stuck in main";
        //while(1);
    }

    return 0;
}
