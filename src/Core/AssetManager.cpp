//
// Created by truong on 22/09/2026.
//

#include "Core/AssetManager.h"
#include <unordered_map>
#include <string>
#include <SDL3/SDL.h>
#include <iostream>
#include <ranges>
#include <SDL3_image/SDL_image.h>

AssetManager::~AssetManager() {
    Clear();
}

SDL_Texture* AssetManager::loadTexture(const std::string& id, const std::string& path, SDL_Renderer& renderer) {
    if (textures.contains(id)) {
        return textures[id];
    }

    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << "Could not load texture from " << path << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(&renderer, surface);
    SDL_DestroySurface(surface);
    textures[id] = texture;
    return texture;
}

SDL_Texture* AssetManager::getTexture(const std::string& id) {
    if (textures.contains(id)) {
        return textures[id];
    }
    else std::cerr << "Warning (W) : Cannot find texture id: " << id << std::endl;
    return nullptr;
}

void AssetManager::Clear() {
    for (auto &val: textures | std::views::values) {
        SDL_DestroyTexture(val);
    }
    textures.clear();
}

