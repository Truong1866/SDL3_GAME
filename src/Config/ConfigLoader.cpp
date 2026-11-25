//
// Created by truong on 11/23/26.
//
#include "Config/ConfigLoader.hpp"
#include <toml++/toml.hpp>
#include <filesystem>

namespace Config {

    static WindowConfig loadWindow(const std::filesystem::path& path) {
        auto table = toml::parse_file(path.string());
        
        WindowConfig config;

        //[windowConfig]
        config.height = table["windowConfig"]["height"].value_or(config.height);
        config.width = table["windowConfig"]["width"].value_or(config.width);
        config.logH = table["windowConfig"]["logH"].value_or(config.logH);
        config.logW = table["windowConfig"]["logW"].value_or(config.logW);

        return config;
    }

    static CharacterConfig loadCharacterConfig(const std::filesystem::path& path) {
        auto table = toml::parse_file(path.string());

        CharacterConfig config;

        config.name = table["playerConfig"]["name"].value_or(config.name);
        config.scale = ConfigLoader::loadVector(table, "scale");

        SpriteConfig bodyConfig = ConfigLoader::loadSpriteConfig(*table["part"]["body"].as_table());
        config.parts.emplace(PartType::Body, bodyConfig);
        SpriteConfig earsConfig = ConfigLoader::loadSpriteConfig(*table["part"]["ears"].as_table());
        config.parts.emplace(PartType::Ears, earsConfig);
        SpriteConfig tailConfig = ConfigLoader::loadSpriteConfig(*table["part"]["tail"].as_table());
        config.parts.emplace(PartType::Tail, tailConfig);

        return config;
    }


    static SpriteConfig loadSpriteConfig(const toml::table& table) {
        SpriteConfig config;

        config.texturePath =
            table["texture"].value_or(config.texturePath);

        // source_size = [400, 400]
        if (auto size = table["source_size"].as_array()) {
            if (size->size() == 2) {
                config.frameSize.x = (*size)[0].value_or(64);
                config.frameSize.y = (*size)[1].value_or(64);
            }
        }

        // position = [0, 0]
        if (auto position = table["position"].as_array()) {
            if (position->size() == 2) {
                config.position.x = (*position)[0].value_or(0.0f);
                config.position.y = (*position)[1].value_or(0.0f);
            }
        }

        // pivot = [200, 200]
        if (auto pivot = table["pivot"].as_array()) {
            if (pivot->size() == 2) {
                config.pivot.x = (*pivot)[0].value_or(0.0f);
                config.pivot.y = (*pivot)[1].value_or(0.0f);
            }
        }

        config.column =
            table["column"].value_or(config.column);

        config.row =
            table["row"].value_or(config.row);

        config.frameDuration =
            table["duratian"].value_or(config.frameDuration);

        config.renderOrder =
            table["render_oder"].value_or(config.renderOrder);

        return config;
    }
}
