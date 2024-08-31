//
// Created by sadeh on 13.06.2024.
//

#include "Enemy1.h"
#include <iostream>
#include <regex>

Enemy1::Enemy1(gameplay *scene)
        : Enemy(scene,1, 1, true, false, false,
                12 * 32 + 16, 10 * 32 - 16, 11 * 32 - 16, 6 * 32 + 16) {
    loadAnimations();
}

Texture2D Enemy1::getCurrentTexture() {
    std::string action = isThrowing ? "bomb_throw" : (currentAnimationState == Enemy::AnimationState::IDLE ? "idle" : "walk");
    std::string direction;
    switch(facing) {
        case Direction::Left: direction = "side_left"; break;
        case Direction::Right: direction = "side_right"; break;
        case Direction::Up: direction = "back"; break;
        case Direction::Down: direction = "front"; break;
    }
    std::string key = "teddy_" + action + "_" + direction;

    if (animations.find(key) == animations.end()) {
        std::cout << "Warning: Animation not found for key: " << key << std::endl;
        // Return a default texture or the first available texture
        return animations.begin()->second.texture;
    }

    if (isThrowing && (facing == Direction::Left || facing == Direction::Right)) {
        return animations[key + "_body"].texture;
    }
    return animations[key].texture;
}

void Enemy1::drawBombThrow() {
    std::string bombKey = "teddy_bomb_throw_side_" + std::string(facing == Direction::Left ? "left" : "right") + "_bomb";
    const AnimationInfo& bombAnim = animations[bombKey];
    Rectangle sourceRec = {
            static_cast<float>(currentFrame * bombAnim.texture.width / bombAnim.frameCount), 0.0f,
            static_cast<float>(bombAnim.texture.width / bombAnim.frameCount),
            static_cast<float>(bombAnim.texture.height)
    };
    Vector2 position = {
            bombPosition.x - static_cast<float>(bombAnim.texture.width) / (2.0f * bombAnim.frameCount),
            bombPosition.y - static_cast<float>(bombAnim.texture.height) / 2.0f
    };
    DrawTextureRec(bombAnim.texture, sourceRec, position, WHITE);
}

std::string Enemy1::toLowerCase(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
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
    Rectangle sourceRec = {
            static_cast<float>(currentFrame * texture.width / FRAME_COUNT), 0.0f,
            static_cast<float>(texture.width / FRAME_COUNT),
            static_cast<float>(texture.height)
    };
    Vector2 position = {
            this->position.x - static_cast<float>(texture.width) / (2.0f * FRAME_COUNT),
            this->position.y - static_cast<float>(texture.height) / 2.0f
    };
    DrawTextureRec(texture, sourceRec, position, WHITE);

    if (isThrowing) {
        drawBombThrow();
    }
    if(IsKeyDown(KEY_H)){
        DrawRectangleRec(getCollisionRectangle(),RED);
    }
}

void Enemy1::loadAnimations() {
    std::vector<std::string> actions = {"Idle", "Walk", "Bomb throw"};
    std::vector<std::string> directions = {"back", "front", "side left", "side right"};

    for (const auto& action : actions) {
        for (const auto& direction : directions) {
            std::string fileName = "Character - Enemy - Teddy - " + action + " " + direction;
            std::string key = "teddy_" + toLowerCase(action) + "_" + toLowerCase(direction);
            key = std::regex_replace(key, std::regex("\\s+"), "_");

            if (action == "Bomb throw" && (direction == "side left" || direction == "side right")) {
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

