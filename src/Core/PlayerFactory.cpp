//
// Created by truong on 23/09/2026.
//
#include "Core/PlayerFactory.hpp"
#include "Components/Animation.hpp"
#include "Components/Physical.hpp"
#include "Components/Sprite.hpp"
#include "Components/Tag.hpp"
#include "Components/Transform.hpp"
#include "Core/AssetManager.hpp"
#include "Components/State.hpp"
#include "Components/CharacterPart.hpp"
#include "Components/Parent.hpp"
#include "Components/ChildrenList.hpp"

entt::entity PlayerFactory::createPlayer(entt::registry &registry, AssetManager &assetManager, const glm::vec2 position) {
    auto player = registry.create();
    registry.emplace<PlayerTag>(player);
    registry.emplace<Physical>(player);
    registry.emplace<WorldTransform>(player);
    registry.emplace<LocalTransform>(player, LocalTransform(position));
    registry.emplace<PlayerState>(player);
    registry.emplace<Sprite>(player,
        Sprite{
        .texture = assetManager.getTexture("player"),
        .sourceRect = {0,0,400,400},
        .size = {400, 400}
    });

    //-----------------------------------tail------------------------------------//

    auto tail = registry.create();

    registry.emplace<Parent>(tail, player);
    registry.emplace<CharacterPart>(tail, PartType::Tail , 0);
    registry.emplace<WorldTransform>(tail);
    registry.emplace<LocalTransform>(tail,
        LocalTransform {
        .position = {-35.0f, 10.0f}
        }
        );

    registry.emplace<Sprite>(tail,
        Sprite{
            .texture = assetManager.getTexture("tail"),
            .sourceRect = {0,0,340,360},
            .size = {340 * 5, 360}
        }
    );

    registry.emplace<Animation>(tail);

    //-----------------------------------head------------------------------------//

    auto head = registry.create();
    registry.emplace<Parent>(head, player);
    registry.emplace<CharacterPart>(head, PartType::Ears , 0);
    registry.emplace<WorldTransform>(head);
    registry.emplace<LocalTransform>(head,
        LocalTransform{
        .position = {0.0f, -35.0f}
        }
        );

    registry.emplace<Sprite>(head,
        Sprite{
        .texture = assetManager.getTexture("head"),
        .sourceRect = {0,0,350,200},
        .size = {350 * 5, 200}
    });

    registry.emplace<Animation>(head);

    registry.get<ChildrenList>(player).children.push_back(tail);
    registry.get<ChildrenList>(player).children.push_back(head);

    return player;
}
