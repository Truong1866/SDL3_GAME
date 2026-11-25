//
// Created by truong on 22/09/2026.
//
#pragma once
#include <SDL3/SDL_render.h>
#include <entt/entt.hpp>
#include "Systems/ISystem.hpp"

class RenderSystem : public ISystem {
public:
    void render(entt::registry& reg, SDL_Renderer &render) override;
};
