//
// Created by truong on 21/09/2026.
//

#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>

class InputManager {
private:
    std::unordered_map<SDL_Keycode, bool> currentKeys;
    std::unordered_map<SDL_Keycode, bool> previousKeys;

public:
    void update();

    void handleEvents(const SDL_Event &event);
    bool isKeyPressed(SDL_Keycode key);
    bool isKeyHeld(SDL_Keycode key);
};