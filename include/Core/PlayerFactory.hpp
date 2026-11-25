//
// Created by truong on 23/09/2026.
//
#pragma once
#include <entt/entt.hpp>
#include <glm/vec2.hpp>

#include "Core/AssetManager.hpp"

class PlayerFactory {
public:
    static entt::entity createPlayer(entt::registry &registry, AssetManager &assetManager, glm::vec2 position);
};
