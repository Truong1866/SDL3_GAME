//
// Created by truong on 21/09/2026.
//

#pragma once
#include <entt/entt.hpp>
#include "Systems/ISystem.h"

class AnimationSystem : public ISystem{
public:
    void update(entt::registry& registry, uint64_t deltaTime) override;
};
