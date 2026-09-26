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
    registry.emplace<Animation>(player, 1, 8, 0.0, 1000.0/30, true);
    registry.emplace<Physical>(player);
    registry.emplace<Sprite>(player, assetManager.getTexture("Player"));
    registry.emplace<Transform>(player);
    registry.emplace<Rotate>(player);
    return player;
}
