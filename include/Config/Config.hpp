//
// Created by truong on 11/23/26.
//

#pragma once
#include "toml++/impl/forward_declarations.hpp"
#include <glm/glm.hpp>
#include "Components/CharacterPart.hpp"

namespace Config {

    struct WindowConfig {
        int width = 1280;
        int height = 720;
        int logW = 1200;
        int logH = 800;
    };

    struct SpriteConfig {
        std::string texturePath;

        glm::ivec2 frameSize{64, 64};
        glm::vec2 displaySize{64.0f, 64.0f};

        glm::vec2 position{0.0f};
        glm::vec2 pivot{0.0f};

        int column = 1, row = 1;
        int frameDuration = 100;

        int renderOrder = 0;
    };

    struct CharacterConfig {
        std::string name;
        glm::vec2 scale{1.0f};

        std::unordered_map<PartType, SpriteConfig> parts;
    };

    struct AppConfig {
        WindowConfig windowConfig;
    };
}

