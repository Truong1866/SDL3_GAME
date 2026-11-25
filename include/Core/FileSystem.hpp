//
// Created by truong on 16/09/2026.
//

#ifndef SDL3_GAME_FILESYSTEM_H
#define SDL3_GAME_FILESYSTEM_H

#endif //SDL3_GAME_FILESYSTEM_H
#pragma once
#include <SDL3/SDL.h>
#include <string>

namespace FileSystem {
    
    // Dùng inline để file header này có thể được include ở nhiều nơi
    inline const std::string& GetBasePath() {
        static std::string basePath = []() {
            const char* path = SDL_GetBasePath();
            return path ? std::string(path) : std::string("");
        }();
        return basePath;
    }

    // Hàm lấy đường dẫn data
    inline std::string getPath(const std::string& relativePath) {
        return GetBasePath() + relativePath;
    }
    
    // Bạn có thể thêm thoải mái hàng chục hàm khác vào đây
    // inline string GetSavePath() { ... }
    // inline bool FileExists(const string& path) { ... }
}
