//
// Created by truong on 21/09/2026.
//

#pragma once
#include <SDL3/SDL_rect.h>

struct Transform {
    float x = 0.0f, y = 288.0f;
    bool flip = false;
};

struct Rotate{
    SDL_FPoint position = { 0.0f, 0.0f };
    float angle = 0.0f;
};

struct Scale{
    float scale = 1.0f;
};