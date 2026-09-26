//
// Created by truong on 22/09/2026.
//

#include "Core/InputManager.h"
#include <SDL3/SDL.h>
#include <unordered_map>

void InputManager::update() {
    previousKeys = currentKeys;
}

void InputManager::handleEvents(const SDL_Event &event) {
    if (event.type == SDL_EVENT_KEY_DOWN) {
        currentKeys[event.key.key] = true;
    }
    else if (event.type == SDL_EVENT_KEY_UP) {
        currentKeys[event.key.key] = false;
    }
}

bool InputManager::isKeyPressed(const SDL_Keycode key) {
    return currentKeys[key] && !previousKeys[key];
}

bool InputManager::isKeyHeld(const SDL_Keycode key) {
    return currentKeys[key];
}
