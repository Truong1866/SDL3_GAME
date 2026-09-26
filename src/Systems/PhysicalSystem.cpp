//
// Created by truong on 22/09/2026.
//
#include "Systems/PhysicalSystem.h"
#include "Components/Transform.h"
#include "Components/Physical.h"
#include <entt/entt.hpp>
#include "Components/State.h"
#include "Components/Tag.h"


void PhysicalSystem::update(entt::registry &registry, uint64_t deltaTime) {
    auto& view = registry.view<PlayerTag, Physical, PlayerState, Transform>();

    for (auto& entity : view) {
        auto& physical = registry.get<Physical>(entity);
        auto& state = registry.get<PlayerState>(entity);
        auto& transform = registry.get<Transform>(entity);

        if (state.actionState == ActionState::Running) {
            transform.x += physical.speed * deltaTime;
            physical.speed += physical.acceleration * deltaTime;
            if (physical.speed > physical.maxSpeed) {
                physical.speed = physical.maxSpeed;
            }else if (physical.speed < -physical.maxSpeed) {
                physical.speed = -physical.maxSpeed;
            }
        }

        if (state.airState == AirState::Jumping) {
            transform.y += physical.jumpSpeed * deltaTime;
            physical.jumpSpeed += physical.acceleration * deltaTime;
            if (physical.jumpSpeed >= 0) {
                state.airState = AirState::Falling;
            }
        }
        if (state.airState == AirState::Falling) {
            transform.y += physical.jumpSpeed * deltaTime;
            if (transform.y >= 288) {
                transform.y = 288;
                state.airState = AirState::Grounded;
                physical.jumpSpeed = 0;
            }else physical.jumpSpeed += physical.acceleration * deltaTime;
        }
    }
}
