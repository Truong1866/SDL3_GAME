//
// Created by truong on 11/24/26.
//
#include <glm/glm.hpp>
#include "Systems/TransformSystem.hpp"

#include "Components/ChildrenList.hpp"
#include "Components/Parent.hpp"
#include "Components/Transform.hpp"
#include "Core/Matrix.hpp"

void TransformSystem::update(entt::registry &registry, uint64_t deltaTime) {
    auto view = registry.view<LocalTransform, WorldTransform>(entt::exclude<Parent>);
    for (entt::entity root : view) {
        updateEntity(registry, root, glm::mat3{1.0f});
    }
}

void TransformSystem::updateEntity(entt::registry &registry, entt::entity entity, const glm::mat3 &parentWorld) {
    if (!registry.valid(entity)) return;

    const auto& local = registry.get<LocalTransform>(entity);
    auto& world = registry.get<WorldTransform>(entity);

    world.matrix = parentWorld * createTransformMatrix(local);

    if (!registry.all_of<ChildrenList>(entity)) return;
    const auto& parts = registry.get<ChildrenList>(entity);

    for (entt::entity child : parts.children) {
        if (!registry.valid(child))
            continue;
        updateEntity(registry, child, world.matrix);
    }
}