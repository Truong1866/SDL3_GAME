//
// Created by truong on 22/09/2026.
//
#include "Systems/PhysicalSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/State.hpp"
#include "Components/Tag.hpp"
#include "Components/Transform.hpp"


void PhysicalSystem::update(entt::registry &registry, const uint64_t dt) {
    auto view = registry.view<PlayerTag, Physical, PlayerState, LocalTransform>();

    float deltaTime = dt / 1000.0f;

    for (auto& entity : view) {
        auto& physical = registry.get<Physical>(entity);
        auto& state = registry.get<PlayerState>(entity);
        auto& transform = registry.get<LocalTransform>(entity);

        if (state.actionState == ActionState::Running) {
            transform.position.x += physical.velocity.x;
            physical.velocity.x += physical.acceleration.x * deltaTime;
            if (physical.velocity.x > physical.maxSpeed) {
                physical.velocity.x = physical.maxSpeed;
            }else if (physical.velocity.x < -physical.maxSpeed) {
                physical.velocity.x = -physical.maxSpeed;
            }
        }

        if (state.airState == AirState::Jumping) {
            transform.position.y += physical.velocity.y;
            physical.velocity.y += physical.gravity * deltaTime;
            if (physical.velocity.y >= 0) {
                state.airState = AirState::Falling;
            }
        }
        else if (state.airState == AirState::Falling) {
            transform.position.y += physical.velocity.y;
            if (transform.position.y + physical.velocity.y >= 900) {
                transform.position.y = 0;
                state.airState = AirState::Grounded;
                physical.jumpSpeed = 0;
            }else physical.jumpSpeed += physical.gravity * deltaTime;
        }
    }
}
