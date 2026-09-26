//
// Created by truong on 22/09/2026.
//
#pragma once
#include <unordered_map>
#include <string>
#include <SDL3/SDL.h>

class AssetManager {
private:
    std::unordered_map<std::string, SDL_Texture*> textures;

public:
    ~AssetManager();

    SDL_Texture* loadTexture(const std::string& id, const std::string& path, SDL_Renderer& renderer);
    SDL_Texture* getTexture(const std::string& id);

    void Clear();
};

