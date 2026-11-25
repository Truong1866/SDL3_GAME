//
// Created by truong on 26/09/2026.
//
#pragma once
#include <SDL3/SDL_render.h>
#include "Core/InputManager.hpp"
#include <entt/entt.hpp>

class ISystem {
public:
    virtual ~ISystem()  = default;

    // Computer data of component.
    virtual void update(entt::registry &registry, uint64_t deltaTime){};

    // Use for render for user see.
    virtual void render(entt::registry &registry, SDL_Renderer &render){};
};
