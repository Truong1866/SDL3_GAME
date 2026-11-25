//
// Created by truong on 26/09/2026.
//
#pragma once
#include <vector>
#include <memory>
#include "Systems/ISystem.hpp"

class SystemManager {
private:
    std::vector<std::unique_ptr<ISystem>> systems;

public:
    // Thêm System vào cuối hàng đợi
    template<typename T, typename... Args>
    void AddSystem(Args&&... args) {
        systems.push_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    void update(entt::registry& registry, const uint64_t deltaTime) {
        for (auto& sys : systems) {
            sys->update(registry, deltaTime);
        }
    }

    void render(entt::registry& registry, SDL_Renderer& renderer) {
        for (auto& sys : systems) {
            sys->render(registry, renderer);
        }
    }
};