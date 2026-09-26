//
// Created by truong on 23/09/2026.
//
#pragma once
#include <entt/entt.hpp>
#include "Core/AssetManager.h"

class PlayerFactory {
public:
    entt::entity createPlayer(entt::registry &registry, AssetManager &assetManager);
};
