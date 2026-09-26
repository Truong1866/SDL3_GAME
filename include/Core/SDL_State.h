//
// Created by truong on 16/09/2026.
//

#ifndef SDL3_GAME_SDL_STATE_H
#define SDL3_GAME_SDL_STATE_H

#endif //SDL3_GAME_SDL_STATE_H
#pragma once
#include <SDL3/SDL.h>

struct resolution {
    int width, height;
};

class SDL_State {
private: SDL_Window *window;
         SDL_Renderer *renderer;
         int width, height, logW, logH;

public: SDL_State();
        ~SDL_State();
        bool init();
        void cleanup();
        void setResolution(int W, int H);
        void setLogSize(int W, int H);
        SDL_Window* getWindow() const;
        SDL_Renderer &getRenderer() const;
        resolution getResolution();
        resolution getLogSize();
};