//
// Created by lrfri on 14.05.2024.
//
#include "gameplay.h"
#include "tileson.hpp"
#include "raymath.h"
#include "mainmenu.h"
#include "pausescreen.h"
#include "journal.h"
#include "ingameoptions.h"
#include "maincharacter.h"
#include "maincharactermodus.h"
#include "ENEMIES/Enemy.h"
#include "ENEMIES/Enemy1.h"
#include "ENEMIES/Enemy2.h"


void gameplay::update() {
    themaincharacter->update();
    enemy1->update();
    enemy2->update();


    switch(room){
        case 1:
            if(themaincharacter->position.y <=(doorfromroom1to2)){
                room=2;
                reloadRoom();
                themaincharacter->position.y=startposroom1to2;
            }
            break;
        case 2:
            if(themaincharacter->position.y<=doorfromroom2to3){
                room=3;
                reloadRoom();
                themaincharacter->position.y=startposroom2to3;
            }
            if(themaincharacter->position.x>=doorfromroom2to4){
                room=4;
                reloadRoom();
                themaincharacter->position.x=startposroom2to4;
            }
            if(themaincharacter->position.y >=(doorfromroom2to1)){
                room=1;
                hasbeeninroom1before =true;
                reloadRoom();
                themaincharacter->position.y=startposroom2to1;
            }
            break;
        case 3:
            if(themaincharacter->position.y >=(doorfromroom3to2)){
                room=2;
                reloadRoom();
                themaincharacter->position.y=startposroom3to2;
            }
            break;
        case 4:
            if(themaincharacter->position.y<=doorfromroom4to5){
                room=5;
                reloadRoom();
                themaincharacter->position.y=startposroom4to5;
            }
            if(themaincharacter->position.x <=(doorfromroom4to2)){
                room=2;
                reloadRoom();
                themaincharacter->position.x=startposroom4to2;
            }
            break;
        case 5:
            if(themaincharacter->position.y <=doorfromroom5to6){
                room=6;
                reloadRoom();
                themaincharacter->position.y=startposroom5to6;
            }
            if(themaincharacter->position.y >=doorfromroom5to4){
                room=4;
                reloadRoom();
                themaincharacter->position.y =startposroom5to4;
            }
            break;
        case 6:
            if(themaincharacter->position.y >=doorfromroom6to5){
                room=5;
                reloadRoom();
                themaincharacter->position.y=startposroom6to5;
            }
            break;
    }

}

scene *gameplay::evaluateSceneChange() {
    if (IsKeyPressed(KEY_M)) {
        return new mainmenu();
    } else if (IsKeyPressed(KEY_P)) {
        return new pausescreen();
    } else if (IsKeyPressed(KEY_J)) {
        return new journal();
    } else if (IsKeyPressed(KEY_O)) {
        return new ingameoptions();
    } else {
        return this;
    }
}

void gameplay::draw() {
    ClearBackground(GRAY);

    //draws the map
    int tilesetCols = 1;
    int tileSize = 32;

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int data = tiles[y * mapWidth + x];
            if (data < 0) continue;
            Rectangle src = {(float) (data % tilesetCols * tileSize), (float) (data / tilesetCols * tileSize),
                             (float) (tileSize), (float) (tileSize)};
            Rectangle dest = {(float) (x * tileSize), (float) (y * tileSize), (float) (tileSize), (float) (tileSize)};
//hier kann man "static_cast<float>" durch (float) ersetzen -> ist C, aber geht hier auch
            DrawTexturePro(tilesetgrass, src, dest, {}, 0, WHITE);
        }
    }



    themaincharacter->draw();
    //if(room==1 && !hasbeeninroom1before){enemies->draw();} //drawt die Enemies nur in Level 1 und nur, wenn man zum ersten Mal im Raum ist
    if(room==2){enemy1->draw();} //drawt die Enemies nur in Level 1, aber die laufen da weiter, wo sie zuletzt waren (spawnen nicht immer am Start-Ort)


    DrawText("Press O to go to options.", 10, 400, 10, WHITE);
    DrawText("Press P to pause the game.", 10, 420, 10, WHITE);
    DrawText("Press M to go back to the main menu.", 10, 440, 10, WHITE);
    DrawText("Press J to open the journal.", 10, 460, 10, WHITE);


    DrawTexture(heart, 10, 20, WHITE);
    DrawTexture(heart, 50, 20, WHITE);
    DrawTexture(heart, 90, 20, WHITE);

    //DrawTexture(modeRobo, 800, 40, WHITE);
    //DrawTexture(modeSoul, 880, 40, WHITE);

    /*switch (languagestates) {
        case german:
            DrawText("Modus:", 840, 10, 20, BLACK);
            break;
        case english:
            DrawText("Mode:", 840, 10, 20, BLACK);
            break;
        default:
            break;
    }*/
    if (IsKeyDown(KEY_H)){
        this->drawDebug();
    }
}


void gameplay::drawDebug() {
    for (int y = 0; y < mapHeight; y++){
        for (int x = 0; x < mapWidth; x++){
            if (getTileAt(x * 32.0,y * 32.0) == 1){
                DrawRectangleLines(x * 32, y * 32, 32, 32, RED);
            }
        }
    }
}

//gets the data from the map needed to draw it
gameplay::gameplay() {
    tson::Tileson tileson;
    themaincharacter = new maincharacter(this);
    enemy1 = new Enemy1(this);
    enemy2 = new Enemy2(this);

    reloadRoom();

}

void gameplay::reloadRoom() {
    tson::Tileson tileson;
    tiles.clear();
    switch (room) {
        case 1:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room1test_greyboxing1.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
            }
            break;
        case 2:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room2test_greyboxing1.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
            }
            break;
        case 3:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room3test_greyboxing1.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 4:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room4test.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 5:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room5test_greyboxing1.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
        case 6:
        {
            auto map = tileson.parse("assets/graphics/tilesets/room5test.tmj");
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
            mapWidth = layer->getSize().x;
            mapHeight = layer->getSize().y;
        }
            break;
    }
}

int gameplay::getTileAt(float x, float y) {
    //catch out of bounds
    if (x < 0 || y < 0 || x >= mapWidth * 32 || y >= mapHeight * 32) {
        return 0;
    }
    int tileX = x / 32;
    int tileY = y / 32;
    return tiles[tileY * mapWidth + tileX];
}

bool gameplay::touchesWall(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if ((getTileAt(x * 32, y * 32) == 1)) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}
bool gameplay::touchesNextDoor(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 3) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}

Rectangle gameplay::getTouchedWall(Vector2 position, float radius) {
    //check all walls
    //on contact, note distance to wall
    //return wall with shortest distance
    float shortestDistance = 1000000;
    Rectangle closestWall{};
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 1) {
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

bool gameplay::touchesBars(Vector2 pos, float size) {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if ((getTileAt(x * 32, y * 32) == 10)) {
                if (CheckCollisionCircleRec(pos, size,
                                            Rectangle{(float) x * 32, (float) y * 32, (float) 32, (float) 32})) {
                    return true;
                }
            }
        }
    }
    return false;
}

Rectangle gameplay::getTouchedBars(Vector2 position, float radius) {
    //check all walls
    //on contact, note distance to wall
    //return wall with shortest distance
    float shortestDistance = 1000000;
    Rectangle closestBar{};
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32, y * 32) == 10) {
                Rectangle bars{static_cast<float>(x * 32), static_cast<float>(y * 32), 32, 32};
                Vector2 wallTouchPoint = Vector2Clamp(position, Vector2{bars.x, bars.y},
                                                      Vector2{bars.x + bars.width, bars.y + bars.height});
                float distance = Vector2Distance(position, wallTouchPoint);
                if (distance < shortestDistance) {
                    shortestDistance = distance;
                    closestBar = bars;
                }
            }
        }
    }
    return closestBar;
}


