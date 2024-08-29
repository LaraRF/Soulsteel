//
// Created by sadeh on 13.06.2024.
//

#include "Enemy2.h"

Enemy2::Enemy2(gameplay *scene)
        : Enemy(scene,2, 2, false, true, false,
                6.0f * 32.0f - 16.0f, 8 * 32 + 16, 8 * 32 - 16, 6 * 32 + 16) {
    loadAnimations();
}

void Enemy2::update() {
    Enemy::update();
    updateAnimation();
}

void Enemy2::draw() {
    Texture2D texture = getCurrentTexture();
    DrawTextureRec(texture,
                   Rectangle{static_cast<float>(currentFrame * texture.width / FRAME_COUNT), 0.0f,
                             static_cast<float>(texture.width / FRAME_COUNT),
                             static_cast<float>(texture.height)},
                   Vector2{position.x - static_cast<float>(texture.width) / (2.0f * FRAME_COUNT),
                           position.y - static_cast<float>(texture.height) / 2.0f},
                   WHITE);
}

void Enemy2::loadAnimations() {
    // Implement animation loading for Enemy2 (Spider)
    // Similar to Enemy1's loadAnimations, but with Spider-specific animations
    std::vector<std::string> actions = {"idle", "walk", "ranged"};
    std::vector<std::string> directions = {"back", "front", "left", "right"};

    for (const auto& action : actions) {
        for (const auto& direction : directions) {
            std::string key = "spider_" + action + "_" + direction;
            std::string actionName;
            if (action == "ranged") {
                actionName = "Ranged";
            } else if (action == "idle") {
                actionName = "Idle";
            } else {
                actionName = "Walk";
            }

            std::string directionName = direction;
            if (direction == "left" || direction == "right") {
                directionName = "side " + direction;
            }

            std::string fileName = std::string("Character - Enemy - Spider - ") + actionName + " " + directionName;

            if (action == "ranged" && (direction == "left" || direction == "right")) { //change states for spider ranged
                animations[key + "_body"] = {FRAME_COUNT, FRAME_DURATION,
                                             assestmanagergraphics::getCharacterTexture("enemies", fileName + " - body - animated")};
                animations[key + "_bomb"] = {FRAME_COUNT, FRAME_DURATION,
                                             assestmanagergraphics::getCharacterTexture("enemies", fileName + " - bomb - animated")};
            } else {
                animations[key] = {FRAME_COUNT, FRAME_DURATION,
                                   assestmanagergraphics::getCharacterTexture("enemies", fileName + " - animated")};
            }
        }
    }
}


Texture2D Enemy2::getCurrentTexture() {
    std::string action = isAttacking ? "ranged" : (currentAnimationState == Enemy::AnimationState::IDLE ? "walk" : "idle");
    std::string direction;
    switch(facing) {
        case Direction::Left: direction = "left"; break;
        case Direction::Right: direction = "right"; break;
        case Direction::Up: direction = "back"; break;
        case Direction::Down: direction = "front"; break;
    }
    std::string key = "teddy_" + action + "_" + direction;
    if (isAttacking && (facing == Direction::Left || facing == Direction::Right)) {

    }
    return assestmanagergraphics::getCharacterTexture("enemies", key);
}

Enemy2::~Enemy2() {
    }