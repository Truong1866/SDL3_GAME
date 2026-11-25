//
// Created by truong on 22/09/2026.
//
#include <entt/entt.hpp>
#include "Systems/RenderSystem.hpp"
#include "Components/Sprite.hpp"
#include "Components/Transform.hpp"
#include "Core/Matrix.hpp"

void RenderSystem::render(entt::registry& reg, SDL_Renderer &render) {
    auto view = reg.view<WorldTransform, Sprite>();
    for (auto& entity : view) {
        auto& world = view.get<WorldTransform>(entity);
        auto& sprite = view.get<Sprite>(entity);

        auto transform = decomposeTransform(world.matrix);

        SDL_FRect dstRect{
            transform.position.x,
            transform.position.y,
            sprite.sourceRect.w * transform.scale.x,
            sprite.sourceRect.h * transform.scale.y
        };

        SDL_FPoint center{
            sprite.sourceRect.w * 0.5f,
            sprite.sourceRect.h * 0.5f
        };

        SDL_RenderTextureRotated(
            &render,
            sprite.texture,
            &sprite.sourceRect,
            &dstRect,
            glm::degrees(transform.rotation),
            &center,
            SDL_FLIP_NONE
        );
    }
}
