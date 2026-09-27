//
// Created by truong on 23/09/2026.
//
#include "Core/PlayerFactory.h"
#include <entt/entt.hpp>
#include "Components/Animation.h"
#include "Components/Physical.h"
#include "Components/Sprite.h"
#include "Components/Tag.h"
#include "Components/Transform.h"
#include "Core/AssetManager.h"

entt::entity PlayerFactory::createPlayer(entt::registry &registry, AssetManager &assetManager) {
    auto player = registry.create();
    registry.emplace<PlayerTag>(player);
    registry.emplace<Animation>(player, 1, 8, 0.0f, 1000.0f/30, true);
    registry.emplace<Physical>(player);
    registry.emplace<Transform>(player);
    registry.emplace<Rotate>(player);

    Sprite sprite;
    sprite.texture = assetManager.getTexture("Player");
    sprite.width = 32;
    sprite.height = 32;
    registry.emplace<Sprite>(player, sprite);
    return player;
}
