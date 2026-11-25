//
// Created by truong on 21/09/2026.
//

#pragma once
struct Sprite {
    SDL_Texture* texture = nullptr;
    SDL_FRect sourceRect{
        .x = 0,
        .y = 0,
        .w = 35,
        .h = 35
    };

    SDL_FPoint size{};
    int render_oder = 0;
};