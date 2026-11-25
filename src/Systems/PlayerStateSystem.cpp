//
// Created by truong on 26/09/2026.
//
#include <entt/entt.hpp>
#include "Systems/PlayerStateSystem.hpp"
#include "Components/Physical.hpp"
#include "Components/State.hpp"
#include "Components/Transform.hpp"
#include "Core/InputManager.hpp"

void PlayerStateSystem::update(entt::registry& registry,const uint64_t deltaTime ) {
    auto& input = registry.ctx().get<InputManager&>();
    auto view = registry.view<PlayerState, Physical,LocalTransform>();

    for (auto& entity : view) {
        auto& state = registry.get<PlayerState>(entity);
        auto& physical = registry.get<Physical>(entity);
        auto& transform = registry.get<LocalTransform>(entity);

        if (state.isActionLocked) {
            state.actionTimer -= deltaTime;
            if (state.actionTimer <= 0) {
                state.isActionLocked = false;
                state.actionTimer = 0;
            } else {
                continue;
            }
        }

        if (state.airState == AirState::Grounded) {
            if (input.isKeyPressed(SDLK_SPACE)) {
                physical.velocity.y = -physical.jumpSpeed;
                state.airState = AirState::Jumping;
            }
        }

        if (input.isKeyHeld(SDLK_D)) {
            state.actionState = ActionState::Running;
            physical.acceleration.x = (physical.acceleration.x > 0) ? physical.acceleration.x : -physical.acceleration.x;
            transform.scale.x = 1.0f;
        }
        else if (input.isKeyHeld(SDLK_A)) {
            state.actionState = ActionState::Running;
            physical.acceleration.x = (physical.acceleration.x < 0) ? physical.acceleration.x : -physical.acceleration.x;
            transform.scale.x = -1.0f;
        }
        else {
            state.actionState = ActionState::Idle;
            physical.velocity.x = 0.0f;
        }
    }
}
