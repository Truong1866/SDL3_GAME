//
// Created by truong on 16/09/2026.
//

#ifndef SDL3_GAME_SDL_STATE_H
#define SDL3_GAME_SDL_STATE_H
#include "entt/entity/registry.hpp"

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

        bool init(entt::registry& registry);
        void cleanup();
        SDL_Window* getWindow() const;
        SDL_Renderer &getRenderer() const;
        resolution getResolution() const;
        resolution getLogSize() const;
};