#include <SDL3/SDL.h>
#include "Core/Game.h"

int main() {
    Game game;
    game.init();
    uint64_t prevTime = SDL_GetTicks();
    while (game.isRunning()) {
        uint64_t nowTime = SDL_GetTicks();
        uint64_t deltaTime = nowTime - prevTime;
        game.input();
        game.update(deltaTime);
        game.render();
        prevTime = nowTime;
    }
    return 0;
}