//
// Created by lrfri on 22.08.2024.
//

#include "stone.h"
#include "../gameplay.h"
#include "../assestmanagergraphics.h"

Stone::Stone(gameplay* scene, Vector2 initialPosition) : gameobjects(scene) {
    mapPosition = initialPosition;
    position = {mapPosition.x, mapPosition.y};
    size = 32;
    stoneTexture = assestmanagergraphics::getTexture("item/stone");
}

void Stone::update() {
    //doesn't do anything frame by frame
}

void Stone::draw() {
    DrawTexture(stoneTexture, position.x, position.y, WHITE);
    //stone texture is still placeholder
}

bool Stone::tryMove(Vector2 direction) {
    Vector2 newMapPosition = {
            mapPosition.x + direction.x * 32,
            mapPosition.y + direction.y * 32
    };

    // Check if the new position is valid (not occupied by a wall or another stone)
    if (!_scene->touchesWall(newMapPosition, size) &&
        !_scene->touchesStone({newMapPosition.x / 32, newMapPosition.y / 32})) {
        mapPosition = newMapPosition;
        position = mapPosition;
        return true;
    }
    return false;
}