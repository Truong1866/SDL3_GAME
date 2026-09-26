//
// Created by truong on 22/09/2026.
//

#include "Systems/RenderSystem.h"
#include <entt/entt.hpp>
#include "Components/Sprite.h"
#include "Components/Transform.h"

void RenderSystem::render(entt::registry& reg, SDL_Renderer *render) {
    auto view = reg.view<Transform, Sprite, Rotate>();
    for (auto entity : view) {
        auto& transform = view.get<Transform>(entity);
        auto& sprite = view.get<Sprite>(entity);
        auto& rotate = view.get<Rotate>(entity);

        SDL_FRect dstRect= {
            transform.x,
            transform.y,
            sprite.width,
            sprite.height
        };
        if (dstRect.x < 0 || dstRect.x > 800 || dstRect.y < 0 || dstRect.y > 600) {
            continue;
        }

        SDL_RenderTextureRotated(
            render,
            sprite.texture,
            &sprite.rect,
            &dstRect,
            rotate.angle,
            &rotate.position,
            (transform.flip) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    }
}
