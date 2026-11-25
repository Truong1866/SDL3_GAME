//
// Created by truong on 11/21/26.
//

#pragma once
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Components/Transform.hpp"

inline Matrix3 createTransformMatrix(const LocalTransform& transform) {
    float c = std::cos(transform.rotation);
    float s = std::sin(transform.rotation);

    Matrix3 T(
        glm::vec3(1, 0, 0),
        glm::vec3(0, 1, 0),
        glm::vec3(transform.position, 1)
        );

    Matrix3 R(
        glm::vec3(c, s, 0),
        glm::vec3(-s, c, 0),
        glm::vec3(0, 0, 1)
        );
    Matrix3 S(
        glm::vec3(transform.scale.x, 0, 0),
        glm::vec3(0, transform.scale.y, 0),
        glm::vec3(0, 0, 1)
    );

    Matrix3 P(1.0f);
    P[2] = glm::vec3(
        transform.pivot.x,
        transform.pivot.y,
        1.0f
    );

    Matrix3 NP(1.0f);
    NP[2] = glm::vec3(
        -transform.pivot.x,
        -transform.pivot.y,
        1.0f
    );

    return T * P * R * S * NP;
}

struct TransformResult {
    glm::vec2 position;
    glm::vec2 scale;
    float rotation;
};

inline TransformResult decomposeTransform(const glm::mat3& m) {
    return {
        .position = {
            m[2][0],
            m[2][1]
        },
        .scale = {
            glm::length(glm::vec2(m[0][0], m[0][1])),
            glm::length(glm::vec2(m[1][0], m[1][1]))
            },
        .rotation = std::atan2(m[0][1], m[0][0])
    };
}