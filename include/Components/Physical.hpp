//
// Created by truong on 21/09/2026.
//
#pragma once
#include <glm/glm.hpp>

struct Physical {
    glm::vec2 velocity{0.0f};
    glm::vec2 acceleration{0.0f};

    float maxSpeed{0.6f};
    float gravity{0.1f};
    float jumpSpeed{0.3f};
};