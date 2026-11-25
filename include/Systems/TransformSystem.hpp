//
// Created by truong on 11/24/26.
//

#pragma once
#include <glm/fwd.hpp>
#include "ISystem.hpp"

class TransformSystem : public ISystem {
public:
    void update(entt::registry &registry, uint64_t deltaTime) override;

    void updateEntity(
    entt::registry& registry,
    entt::entity entity,
    const glm::mat3& parentWorld
    );
};
