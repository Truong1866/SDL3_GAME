//
// Created by truong on 26/09/2026.
//
#include "Systems/PlayerStateSystem.h"
#include <entt/entt.hpp>
#include "Components/Physical.h"
#include "Components/State.h"
#include "Components/Tag.h"
#include "Core/InputManager.h"

void PlayerStateSystem::update(entt::registry& registry,const uint64_t deltaTime ) {
    auto& input = registry.ctx().get<InputManager&>();
    auto view = registry.view<PlayerState, Physical>();

    for (auto& entity : view) {
        auto& state = registry.get<PlayerState>(entity);
        auto& physical = registry.get<Physical>(entity);

        if (state.isActionLocked) {
            state.actionTimer -= deltaTime;
            if (state.actionTimer <= 0.0f) {
                state.isActionLocked = false;
                state.actionTimer = 0.0f;
            } else {
                continue;
            }
        }

        if (state.airState == AirState::Grounded) {
            if (input.isKeyPressed(SDLK_SPACE)) {
                physical.jumpSpeed = -physical.maxJumpSpeed;
                state.airState = AirState::Jumping;
            }
        }else {
            if (physical.jumpSpeed < 0) state.airState = AirState::Jumping;
            else state.airState = AirState::Falling;
        }

        if (input.isKeyHeld(SDLK_D)) {
            state.actionState = ActionState::Running;
            physical.acceleration = (physical.acceleration > 0) ? physical.acceleration : -physical.acceleration;
        }
        else if (input.isKeyHeld(SDLK_A)) {
            state.actionState = ActionState::Running;
            physical.acceleration = (physical.acceleration < 0) ? physical.acceleration : -physical.acceleration;
        }
        else {
            state.actionState = ActionState::Idle;
            physical.speed = 0.0f;
        }
    }
}
