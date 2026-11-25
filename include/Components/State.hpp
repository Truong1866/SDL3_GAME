//
// Created by truong on 26/09/2026.
//
#pragma once
enum class AirState {
    Grounded,
    Jumping,
    Falling
};

enum class ActionState {
    Idle,
    Running
};

struct PlayerState {
    AirState airState = AirState::Grounded;
    ActionState actionState = ActionState::Idle;

    bool isActionLocked = false;
    uint64_t actionTimer = 0;
};
