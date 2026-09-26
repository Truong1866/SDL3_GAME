//
// Created by truong on 22/09/2026.
//
#include <Systems/AnimationSystem.h>
#include <entt/entt.hpp>
#include <Components/Animation.h>
#include <Components/Sprite.h>

void AnimationSystem::update(entt::registry& reg,const uint64_t deltaTime) {
    auto view = reg.view<Animation, Sprite>();

    for (auto& entity : view) {
        auto& sprite = view.get<Sprite>(entity);
        auto& animation = view.get<Animation>(entity);
        animation.currentTime += deltaTime;

        if (animation.currentTime >= animation.duration) {
            animation.currentTime -= animation.duration;
            animation.currentFrame = (animation.currentFrame +1 ) % animation.frameCount;
        }

        sprite.rect.x = static_cast<float>(animation.currentFrame) * sprite.width;
        sprite.rect.y = sprite.height;
        sprite.rect.w = sprite.width;
        sprite.rect.h = sprite.height;
    }
}