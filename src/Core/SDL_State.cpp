//
// Created by truong on 16/09/2026.
//
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "Core/SDL_State.hpp"

#include "Config/Config.hpp"
#include "entt/entity/registry.hpp"

SDL_State::SDL_State() {
    window = nullptr;
    renderer = nullptr;
    width = height = logH = logW = 0;
}

SDL_State::~SDL_State() {
    cleanup();
}

bool SDL_State::init(entt::registry& registry) {
    const auto& windowConfig = registry.ctx().get<Config::AppConfig>().windowConfig;
    width = windowConfig.width;
    height = windowConfig.height;
    logW = windowConfig.logW;
    logH = windowConfig.logH;

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "SDL3 could not initialize!", nullptr);
        cleanup();
        return false;
    }

    window = SDL_CreateWindow("SDL3 Demo", width, height, SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Could not create window!", nullptr);
        cleanup();
        return false;
    }

    renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", "Could not create renderer!", nullptr);
        cleanup();
        return false;
    }

    SDL_SetRenderLogicalPresentation(renderer, logW, logH, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    return true;
}

void SDL_State::cleanup() {
    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }
    SDL_Quit();
}

SDL_Window* SDL_State::getWindow() const {
    return window;
}

SDL_Renderer &SDL_State::getRenderer() const {
    return *renderer;
}

resolution SDL_State::getResolution() const {
    return resolution{
        .width = width,
        .height = height,
    };
}

resolution SDL_State::getLogSize() const {
    return resolution{
        .width = logW,
        .height = logH,
    };
}


