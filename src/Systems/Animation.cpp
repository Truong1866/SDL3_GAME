//
// Created by truong on 22/09/2026.
//
#include <entt/entt.hpp>
#include "Systems/AnimationSystem.hpp"
#include "Components/Animation.hpp"
#include "Components/Sprite.hpp"

void AnimationSystem::update(entt::registry& reg,const uint64_t deltaTime) {
    auto view = reg.view<Animation, Sprite>();

    for (auto& entity : view) {
        auto& sprite = view.get<Sprite>(entity);
        auto& animation = view.get<Animation>(entity);
        animation.currentTime += deltaTime;

        if (animation.currentTime >= animation.duration) {
            animation.currentTime -= animation.duration;
            animation.currentFrame = (animation.currentFrame++) % animation.frameCount;
        }

        sprite.sourceRect.x =
            static_cast<float>(animation.currentFrame) * sprite.sourceRect.w;
    }
}