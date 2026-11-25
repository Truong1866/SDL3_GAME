//
// Created by truong on 11/23/26.
//

#pragma once
#include "Config/Config.hpp"
#include <filesystem>

namespace Config {
    class ConfigLoader {
        public:
        static WindowConfig loadWindow(const std::filesystem::path& path);

        static CharacterConfig loadCharacterConfig(const std::filesystem::path& path);

        static SpriteConfig loadSpriteConfig(const toml::table& table);

        static inline glm::vec2 loadVector(const auto table, const std::string name) {
            if (auto* arr = table["playerConfig"][name].as_array()) {
                if (arr->size() >= 2) {
                    float x = (*arr)[0].value_or(0.0f);
                    float y = (*arr)[1].value_or(0.0f);

                    glm::vec2 vec = glm::vec2(x, y);
                    return vec;
                }
            }
            return {0.0f, 0.0f};
        }

        static inline glm::ivec2 loadIVector(const auto table,
            const std::string fieldName, const std::string name) {
            if (auto* arr = table["playerConfig"][name].as_array()) {
                if (arr->size() >= 2) {
                    int x = (*arr)[0].value_or(0.0f);
                    int y = (*arr)[1].value_or(0.0f);

                    glm::vec2 vec = glm::vec2(x, y);
                    return vec;
                }
            }
            return {0, 0};
        }
    };
}

