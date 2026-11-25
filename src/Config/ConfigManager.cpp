//
// Created by truong on 11/24/26.
//
#include "Config/ConfigManager.hpp"

#include <iostream>

#include "Config/ConfigValidator.hpp"

namespace Config {
    void ConfigManager::load(const std::filesystem::path& directory) {
        AppConfig config;

        config.windowConfig = ConfigLoader::loadWindow(directory / "engine/window.toml");

        if (loadCharacterConfigs(directory / "character")) {
            return;
        }

        ConfigValidator::validate(config);
        m_config = config;
    }

    bool ConfigManager::loadCharacterConfigs(const std::filesystem::path &directory) {
        for (const auto& file : std::filesystem::directory_iterator(directory)) {
            try {
                ConfigLoader::loadCharacterConfig(file);
            }
            catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                return false;
            }
        }
        return true;
    }

    const CharacterConfig *ConfigManager::getCharacter(const std::string &name) const {
        if (characters.contains(name)) {
            return &characters.at(name);
        }
        return nullptr;
    }
}
