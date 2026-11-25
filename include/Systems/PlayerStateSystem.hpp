//
// Created by truong on 26/09/2026.
//
#pragma once
#include <entt/entt.hpp>
#include "Systems/ISystem.hpp"

class PlayerStateSystem : public ISystem {
public:
    void update(entt::registry& registry, uint64_t deltaTime) override;
};
