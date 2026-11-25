//
// Created by truong on 11/24/26.
//

#pragma once

#include "Config.hpp"
#include "ConfigLoader.hpp"

namespace Config {

    class ConfigManager {
    public:
        void load(const std::filesystem::path& directory);

        const AppConfig& get() const noexcept {
            return m_config;
        }

        static bool loadCharacterConfigs(const std::filesystem::path& directory);

        const CharacterConfig* getCharacter(
            const std::string& name
        ) const;

    private:
        AppConfig m_config;
        std::unordered_map<std::string, CharacterConfig> characters;
    };

}
