//
// Created by truong on 26/09/2026.
//
#include <entt/entt.hpp>
#include "Core/Game.h"
#include <iostream>
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
    PlayerFactory::createPlayer(registry, assetManager);
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
    SDL_RenderClear(&state.getRenderer());
    SDL_RenderPresent(&state.getRenderer());
}

bool Game::isRunning() const{
    return running;
}

void Game::cleanUp() {
    std::cout << "\n=== Cleaning up resources ===" << std::endl;

    // 1. Clear all entities from registry
    std::cout << "Clearing entities..." << std::endl;
    registry.clear();

    // 2. Destroy all GPU textures
    std::cout << "Clearing textures..." << std::endl;
    assetManager.Clear();

    // 3. Cleanup SDL (window, renderer, etc.)
    std::cout << "Cleaning up SDL..." << std::endl;
    state.cleanup();

    std::cout << "✓ All resources cleaned up" << std::endl;
    std::cout << "============================\n" << std::endl;
}