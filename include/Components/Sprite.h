//
// Created by truong on 21/09/2026.
//

#pragma once
#include <SDL3/SDL.h>
struct Sprite {
    SDL_Texture* texture;
    SDL_FRect rect{
        0,
        0,
        35,
        35
    };
    float width = 35;
    float height = 35;
};