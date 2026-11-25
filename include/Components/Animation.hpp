//
// Created by truong on 21/09/2026.
//

#pragma once
struct Animation {
    int currentFrame;
    int frameCount;
    uint64_t currentTime;
    uint64_t duration;
    bool isLoop;
};
