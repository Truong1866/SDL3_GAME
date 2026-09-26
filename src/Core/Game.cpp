//
// Created by truong on 26/09/2026.
//
#include <entt/entt.hpp>
#include "Core/Game.h"
#include "Core/SystemManager.h"
#include "Systems/AnimationSystem.h"
#include "Systems/PhysicalSystem.h"
#include "Systems/PlayerStateSystem.h"
#include "Systems/RenderSystem.h"
#include "Core/PlayerFactory.h"
#include "Core/FileSystem.h"

void Game::init() {
    state.setResolution(800, 600);
    state.setLogSize(640, 320);
    if (!state.init()) return;
    systemManager.AddSystem<AnimationSystem>();
    systemManager.AddSystem<PhysicalSystem>();
    systemManager.AddSystem<RenderSystem>();
    systemManager.AddSystem<PlayerStateSystem>();
    assetManager.loadTexture("Player", FileSystem::getPath("data/texture/idle.png"), state.getRenderer());
    PlayerFactory player;
    player.createPlayer(registry, assetManager);
    registry.ctx().emplace<InputManager&>(inputManager);
    registry.ctx().emplace<AssetManager&>(assetManager);
}

void Game::update(const uint64_t deltaTime) {
    systemManager.update(registry, deltaTime);
}

void Game::input() {
    SDL_Event event;
    inputManager.update();
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;
        }
        inputManager.handleEvents(event);
    }
}

void Game::render() {
    systemManager.render(registry, state.getRenderer());
}

bool Game::isRunning() const{
    return running;
}