//
// Created by truong on 26/09/2026.
//

#pragma once
#include <entt/entt.hpp>
#include "Core/SDL_State.h"
#include "Core/SystemManager.h"
#include "Core/AssetManager.h"
#include "Core/InputManager.h"

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
