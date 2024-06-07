//
// Created by lrfri on 05.06.2024.
//

#include "gameplayroom1.h"
#include "tileson.hpp"
#include "raymath.h"
#include "mainmenu.h"
#include "pausescreen.h"
#include "journal.h"
#include "ingameoptions.h"
#include "maincharacter.h"
#include "maincharactermodus.h"
#include "enemies.h"


void gameplayroom1::update() {
    maincharacter->update();
    enemies->update();

}

scene *gameplayroom1::evaluateSceneChange() {
    if (IsKeyPressed(KEY_M)) {
        return new mainmenu();
    } else if (IsKeyPressed(KEY_P)) {
        return new pausescreen();
    } else if (IsKeyPressed(KEY_J)) {
        return new journal();
    } else if (IsKeyPressed(KEY_O)) {
        return new ingameoptions();
    }
    else if(maincharacter->position.x == nextdoor.x && maincharacter->position.y == nextdoor.y){
            return new gameplayroom2();
    }else {
        return this;
    }

}

void gameplayroom1::draw() {
    ClearBackground(GRAY);

    //draws the map
    int tilesetCols = 1;
    int tileSize = 32;

    for (int y = 0; y < cols; y++) {
        for (int x = 0; x < rows; x++) {
            int data = tiles[y * rows + x];
            if (data < 0) continue;
            Rectangle src = {(float) (data % tilesetCols * tileSize), (float) (data / tilesetCols * tileSize),
                             (float) (tileSize), (float) (tileSize)};
            Rectangle dest = {(float) (x * tileSize), (float) (y * tileSize), (float) (tileSize), (float) (tileSize)};
//hier kann man "static_cast<float>" durch (float) ersetzen -> ist C, aber geht hier auch
            DrawTexturePro(tilesetgrass, src, dest, {}, 0, WHITE);
        }
    }

    maincharacter->draw();
    enemies->draw();

    DrawText("Press O to go to options.", 10, 400, 10, WHITE);
    DrawText("Press P to pause the game.", 10, 420, 10, WHITE);
    DrawText("Press M to go back to the main menu.", 10, 440, 10, WHITE);
    DrawText("Press J to open the journal.", 10, 460, 10, WHITE);


    DrawTexture(heart, 10, 20, WHITE);
    DrawTexture(heart, 50, 20, WHITE);
    DrawTexture(heart, 90, 20, WHITE);

}


void gameplayroom1::drawDebug() {

}

//gets the data from the map needed to draw it
gameplayroom1::gameplayroom1() {
    tson::Tileson tileson;
    auto map = tileson.parse("assets/graphics/tilesets/room1test.tmj");
    if (map->getStatus() != tson::ParseStatus::OK) {
        std::cout << map->getStatusMessage();
    }
    auto layer = map->getLayer("Kachelebene 1");

    for (int y = 0; y < layer->getSize().y; y++) {
        for (int x = 0; x < layer->getSize().x; x++) {
            tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
            tiles.back()--;
        }
    }
    rows = layer->getSize().x;
    cols = layer->getSize().y;

    maincharacter=new class maincharacter(this);
    enemies =new class enemies(this);



}


int gameplayroom1::getTileAt(float x, float y) {
    //catch out of bounds
    if (x < 0 || y < 0 || x >= mapWidth * 32 || y >= mapHeight * 32) {
        return 0;
    }
    int tileX = x / 32;
    int tileY = y / 32;
    return tiles[tileY * mapWidth + tileX];
}

bool gameplayroom1::touchesWall(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 0) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}


Rectangle gameplayroom1::getTouchedWall(Vector2 position, float radius) {
    //check all walls
    //on contact, note distance to wall
    //return wall with shortest distance
    float shortestDistance = 1000000;
    Rectangle closestWall{};
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) ==1) {
                Rectangle wall{static_cast<float>(x * 32), static_cast<float>(y * 32), 32, 32};
                Vector2 wallTouchPoint = Vector2Clamp(position, Vector2{wall.x, wall.y},
                                                      Vector2{wall.x + wall.width, wall.y + wall.height});
                float distance = Vector2Distance(position, wallTouchPoint);
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    closestWall = wall;
                }
            }
        }
    }
    return closestWall;
}