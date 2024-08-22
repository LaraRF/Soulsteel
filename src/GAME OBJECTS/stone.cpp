//
// Created by lrfri on 22.08.2024.
//

#include "stone.h"
#include "../gameplay.h"
#include "../assestmanagergraphics.h"

Stone::Stone(gameplay* scene, Vector2 initialPosition) : gameobjects(scene) {
    position = initialPosition;
    stoneTexture = assestmanagergraphics::getTexture("item/stone");
    size = 32;
}

void Stone::update() {
    //doesn't do anything frame by frame
}

void Stone::draw() {
    DrawTexture(stoneTexture, position.x, position.y, WHITE);
    //stone texture is still placeholder
}

bool Stone::tryMove(Vector2 direction) {
    if (_scene == nullptr) {
        std::cout << "Error: Stone's _scene is null" << std::endl;
        return false;
    }

    Vector2 newPosition = {
            position.x + direction.x * 32,
            position.y + direction.y * 32
    };

    Vector2 newTile = {std::floor(newPosition.x / 32), std::floor(newPosition.y / 32)};

    std::cout << "Attempting to move stone from (" << position.x << ", " << position.y
              << ") to (" << newPosition.x << ", " << newPosition.y << ")" << std::endl;

    // Add bounds checking
    if (newTile.x < 0 || newTile.x >= _scene->mapWidth || newTile.y < 0 || newTile.y >= _scene->mapHeight) {
        std::cout << "Stone move failed: Out of bounds" << std::endl;
        return false;
    }

    if (!_scene->touchesWall(newPosition, size) && !_scene->touchesStone(newTile)) {
        position = newPosition;
        std::cout << "Stone moved successfully" << std::endl;
        return true;
    }

    std::cout << "Stone move failed: Collision detected" << std::endl;
    return false;
}