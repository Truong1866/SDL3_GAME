//
// Created by truong on 21/09/2026.
//

#pragma once
#include <glm/glm.hpp>

using Matrix3 = glm::mat3;

struct LocalTransform {
    glm::vec2 position{0,0};
    float rotation = 0.0f;
    glm::vec2 scale{1, 1};
    glm::vec2 pivot{0, 0};
};

struct WorldTransform {
    Matrix3 matrix{1.0f};
};