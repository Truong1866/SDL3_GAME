//
// Created by truong on 26/09/2026.
//

#pragma once
#include "Core/SDL_State.hpp"
#include "Core/SystemManager.hpp"
#include "Core/AssetManager.hpp"
#include "Core/InputManager.hpp"

class Game {
private:
    entt::registry registry;
    AssetManager assetManager;
    SystemManager systemManager;
    InputManager inputManager;
    SDL_State state;
    bool running = true;

public:
    void init();
    void update(uint64_t deltaTime);
    void input();
    void render();
    bool isRunning() const;
    void cleanUp();
};
