//
// Created by truong on 22/09/2026.
//
#pragma once
#include <entt/entt.hpp>
#include "Systems/ISystem.h"

class PhysicalSystem : public ISystem{
public:
    void update(entt::registry &registry ,uint64_t deltaTime) override;
};
