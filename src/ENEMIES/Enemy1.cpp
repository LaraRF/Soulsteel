//
// Created by sadeh on 13.06.2024.
//

#include "Enemy1.h"
#include <iostream>

Enemy1::Enemy1(gameplay *scene)
        : Enemy(scene,1, 1, true, false, false,
                12 * 32 + 16, 10 * 32 - 16, 11 * 32 - 16, 6 * 32 + 16) {
    idleTexture = assestmanagergraphics::getCharacterTexture("enemies", "teddy_idle_front");
    walkTexture = assestmanagergraphics::getCharacterTexture("enemies", "teddy_walk_front");
    attackTexture = assestmanagergraphics::getCharacterTexture("enemies", "teddy_attack_front");
    throwTexture = assestmanagergraphics::getCharacterTexture("enemies", "teddy_throw_front");
    bombTexture = assestmanagergraphics::getCharacterTexture("enemies", "teddy_bomb");
}

Texture2D Enemy1::getCurrentTexture() {
    std::string action = isThrowing ? "bomb_throw" : (currentAnimationState == Enemy::AnimationState::IDLE ? "walk" : "idle");
    std::string direction;
    switch(facing) {
        case Direction::Left: direction = "left"; break;
        case Direction::Right: direction = "right"; break;
        case Direction::Up: direction = "back"; break;
        case Direction::Down: direction = "front"; break;
    }
    std::string key = "teddy_" + action + "_" + direction;
    if (isThrowing && (facing == Direction::Left || facing == Direction::Right)) {
        key += "_body";  // For side bomb throws, we need the body animation
    }
    return assestmanagergraphics::getCharacterTexture("enemies", key);
}

void Enemy1::throwBomb() {
    if (!isThrowing) {
        isThrowing = true;
        bombAnimationTimer = 0.0f;
        bombPosition = position; // Adjust as needed
    }
}

Enemy1::~Enemy1() {
}

void Enemy1::update() {
    Enemy::update();
    updateAnimation();
    // Add logic to decide when to throw a bomb
    //for example when enemy is near character
}

void Enemy1::draw() {
    Texture2D texture = getCurrentTexture();
    DrawTextureRec(texture,
                   Rectangle{static_cast<float>(currentFrame * texture.width / FRAME_COUNT), 0.0f,
                             static_cast<float>(texture.width / FRAME_COUNT),
                             static_cast<float>(texture.height)},
                   Vector2{position.x - static_cast<float>(texture.width) / (2.0f * FRAME_COUNT),
                           position.y - static_cast<float>(texture.height) / 2.0f},
                   WHITE);

    if (isThrowing) {
        std::string bombKey = "teddy_bomb_throw_";
        bombKey += (facing == Direction::Left) ? "left" : "right";
        bombKey += "_bomb";
        Texture2D bombTexture = assestmanagergraphics::getCharacterTexture("enemies", bombKey);
        DrawTextureRec(bombTexture,
                       Rectangle{static_cast<float>(currentFrame * bombTexture.width / FRAME_COUNT), 0.0f,
                                 static_cast<float>(bombTexture.width / FRAME_COUNT),
                                 static_cast<float>(bombTexture.height)},
                       Vector2{bombPosition.x - static_cast<float>(bombTexture.width) / (2.0f * FRAME_COUNT),
                               bombPosition.y - static_cast<float>(bombTexture.height) / 2.0f},
                       WHITE);
    }
}



void Enemy1::drawBombThrow() {
    const AnimationInfo& bombAnim = animations["bomb"];
    DrawTextureRec(bombAnim.texture,
                   Rectangle{static_cast<float>(currentFrame * bombAnim.texture.width / bombAnim.frameCount), 0.0f,
                             static_cast<float>(bombAnim.texture.width / bombAnim.frameCount),
                             static_cast<float>(bombAnim.texture.height)},
                   Vector2{bombPosition.x - static_cast<float>(bombAnim.texture.width) / (2.0f * bombAnim.frameCount),
                           bombPosition.y - static_cast<float>(bombAnim.texture.height) / 2.0f},
                   WHITE);
}
void Enemy1::loadAnimations() {
    // Load animations for Enemy1 (Teddy)
    std::vector<std::string> actions = {"idle", "walk", "bomb_throw"};
    std::vector<std::string> directions = {"back", "front", "left", "right"};

    for (const auto& action : actions) {
        for (const auto& direction : directions) {
            std::string key = "teddy_" + action + "_" + direction;
            std::string actionName;
            if (action == "bomb_throw") {
                actionName = "Bomb throw";
            } else if (action == "idle") {
                actionName = "Idle";
            } else {
                actionName = "Walk";
            }

            std::string directionName = direction;
            if (direction == "left" || direction == "right") {
                directionName = "side " + direction;
            }

            std::string fileName = std::string("Character - Enemy - Teddy - ") + actionName + " " + directionName;

            if (action == "bomb_throw" && (direction == "left" || direction == "right")) {
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