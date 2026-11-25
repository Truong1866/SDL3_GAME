//
// Created by truong on 11/21/26.
//

#pragma once
#include "entt/entity/entity.hpp"

enum class PartType {
    Body,
    Ears,
    Tail,
    Emote,
};

struct CharacterPart {
    PartType type;
    int renderOder;
};
