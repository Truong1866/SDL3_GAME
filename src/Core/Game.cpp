//
// Created by truong on 26/09/2026.
//
#include <iostream>
#include "Core/Game.hpp"

#include "Config/ConfigManager.hpp"
#include "Core/SystemManager.hpp"
#include "Systems/AnimationSystem.hpp"
#include "Systems/PhysicalSystem.hpp"
#include "Systems/PlayerStateSystem.hpp"
#include "Systems/RenderSystem.hpp"
#include "Core/PlayerFactory.hpp"
#include "Core/FileSystem.hpp"
#include "Systems/TransformSystem.hpp"

void Game::init() {

    Config::ConfigManager configManager;
    configManager.load("data/config");

    auto config = configManager.get();

    inputManager = InputManager();
    assetManager = AssetManager();

    auto &ctx = registry.ctx();

    ctx.emplace<AssetManager&>(assetManager);
    ctx.emplace<InputManager&>(inputManager);
    ctx.emplace<Config::AppConfig>(
        config
    );

    if (!state.init(registry)) return;

    systemManager.AddSystem<AnimationSystem>();
    systemManager.AddSystem<PhysicalSystem>();
    systemManager.AddSystem<RenderSystem>();
    systemManager.AddSystem<PlayerStateSystem>();
    systemManager.AddSystem<TransformSystem>();
    assetManager.loadTexture("Player", FileSystem::getPath("data/texture/body.png"), state.getRenderer());
    assetManager.loadTexture("tail", FileSystem::getPath("data/texture/tail.png"), state.getRenderer());
    assetManager.loadTexture("head", FileSystem::getPath("data/texture/head.png"), state.getRenderer());
    PlayerFactory::createPlayer(registry, assetManager,{50.0f, 60.0f});
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
    SDL_RenderClear(&state.getRenderer());
    systemManager.render(registry, state.getRenderer());
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