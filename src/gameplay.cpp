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
#include "ENEMIES/Enemy3.h"
#include "GAME OBJECTS/gameobjects.h"
#include "GAME OBJECTS/robot.h"
#include "maincharactermodus.h"
#include "maincharacter.h"
#include "Wall.h"

void gameplay::update() {

    themaincharacter->update();
    therobot->update();


    for (int i = 0; i < enemies.size(); i++) {
        enemies[i]->update();
    }
    for (int i = 0; i < gameobjects.size(); i++) {
        gameobjects[i]->update();
    }

    if (IsKeyPressed(KEY_SPACE)) {
        switch (currentmodus) {
            case soulmodus:
                if (soulcantakeover()) {
                    currentmodus = robotmodus;
                    soulhasntchangedformsyet = false;
                    soulleavesrobot = false;
                    soulentersrobot = true;
                }
                break;
            case robotmodus:
                currentmodus = soulmodus;
                soulleavesrobot = true;
                soulentersrobot = false;
                break;
        }
    }

    switch (room) {
        case 1:
            if (themaincharacter->position.y <= (doorfromroom1to2)) {
                room = 2;
                if (currentmodus == soulmodus) {
                    soulisinroom = 2;
                } else { robotisinroom = 2; }
                reloadRoom();
                themaincharacter->position.y = startposroom1to2;
            }
            break;
        case 2:
            if (themaincharacter->position.y <= doorfromroom2to3) {
                room = 3;
                if (currentmodus == soulmodus) {
                    soulisinroom = 3;
                } else { robotisinroom = 3; }
                reloadRoom();
                themaincharacter->position.y = startposroom2to3;
            }
            if (themaincharacter->position.x >= doorfromroom2to4) {
                room = 4;
                if (currentmodus == soulmodus) {
                    soulisinroom = 4;
                } else { robotisinroom = 4; }
                reloadRoom();
                themaincharacter->position.x = startposroom2to4;
            }
            if (themaincharacter->position.y >= (doorfromroom2to1)) {
                room = 1;
                if (currentmodus == soulmodus) {
                    soulisinroom = 1;
                } else { robotisinroom = 1; }
                hasbeeninroom1before = true;
                reloadRoom();
                themaincharacter->position.y = startposroom2to1;
            }
            break;
        case 3:
            if (themaincharacter->position.y >= (doorfromroom3to2)) {
                room = 2;
                if (currentmodus == soulmodus) {
                    soulisinroom = 2;
                } else { robotisinroom = 2; }
                reloadRoom();
                themaincharacter->position.y = startposroom3to2;
            }
            break;
        case 4:
            if (themaincharacter->position.y <= doorfromroom4to5) {
                room = 5;
                if (currentmodus == soulmodus) {
                    soulisinroom = 5;
                } else { robotisinroom = 5; }
                reloadRoom();
                themaincharacter->position.y = startposroom4to5;
            }
            if (themaincharacter->position.x <= (doorfromroom4to2)) {
                room = 2;
                if (currentmodus == soulmodus) {
                    soulisinroom = 2;
                } else { robotisinroom = 2; }
                reloadRoom();
                themaincharacter->position.x = startposroom4to2;
            }
            break;
        case 5:
            if (themaincharacter->position.y <= doorfromroom5to6) {
                room = 6;
                if (currentmodus == soulmodus) {
                    soulisinroom = 6;
                } else { robotisinroom = 6; }
                reloadRoom();
                themaincharacter->position.y = startposroom5to6;
            }
            if (themaincharacter->position.y >= doorfromroom5to4) {
                room = 4;
                if (currentmodus == soulmodus) {
                    soulisinroom = 4;
                } else { robotisinroom = 4; }
                reloadRoom();
                themaincharacter->position.y = startposroom5to4;
            }
            break;
        case 6:
            if (themaincharacter->position.y >= doorfromroom6to5) {
                room = 5;
                if (currentmodus == soulmodus) {
                    soulisinroom = 6;
                } else { robotisinroom = 6; }
                reloadRoom();
                themaincharacter->position.y = startposroom6to5;
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
    }
    return this;
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

        for (Enemy *enemy: enemies) {
            enemy->draw();
        }

    }
    switch (currentmodus) {
        case soulmodus:
            themaincharacter->drawsoul();
            break;
        case robotmodus:
            themaincharacter->drawrobot();
            break;
    }

    if (room == 1) {
        if (robotisinroom == 1) {
            therobot->draw();
        }
    }
    if (room == 2) {
        if (robotisinroom == 2) {
            therobot->draw();
        }
    }
    if (room == 3) {
        if (robotisinroom == 3) {
            therobot->draw();
        }
    }
    if (room == 4) {
        if (robotisinroom == 4) {
            therobot->draw();
        }
    }
    if (room == 5) {
        if (robotisinroom == 5) {
            therobot->draw();
        }
    }
    if (room == 6) {
        if (robotisinroom == 6) {
            therobot->draw();
        }
    }
    //if(room==1 && !hasbeeninroom1before){enemies->draw();} //drawt die Enemies nur in Level 1 und nur, wenn man zum ersten Mal im Raum ist
    //if(room==1){enemy1->draw();} //drawt die Enemies nur in Level 1, aber die laufen da weiter, wo sie zuletzt waren (spawnen nicht immer am Start-Ort)

    /*for (int i = 0; i < enemies.size(); i++){
        enemies[i]->draw();}*/


    for (int i = 0; i < gameobjects.size(); i++) {
        gameobjects[i]->draw();
    }

    if (soulleavesrobot || soulhasntchangedformsyet) {
        therobot->position = {themaincharacter->position.x, themaincharacter->position.y};
        soulleavesrobot = false;
        soulhasntchangedformsyet = false;
    }


    DrawText("Press O to go to options.", 10, 400, 10, WHITE);
    DrawText("Press P to pause the game.", 10, 420, 10, WHITE);
    DrawText("Press M to go back to the main menu.", 10, 440, 10, WHITE);
    DrawText("Press J to open the journal.", 10, 460, 10, WHITE);


    DrawTexture(heart, 10, 20, WHITE);
    DrawTexture(heart, 50, 20, WHITE);
    DrawTexture(heart, 90, 20, WHITE);


    if (IsKeyDown(KEY_H)) {
        this->drawDebug();
    }
}


void gameplay::drawDebug() {
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            if (getTileAt(x * 32.0, y * 32.0) == 1) {
                DrawRectangleLines(x * 32, y * 32, 32, 32, RED);
            }
        }
    }
}

//gets the data from the map needed to draw it
gameplay::gameplay() {
    tson::Tileson tileson;
    themaincharacter = new class maincharacter(this);
    therobot = new robot(this);
    //gameobjects.push_back(new robot(this));
    //gameobjects.push_back(new robot(this, {11 * 32, 5 * 32}));


    reloadRoom();
}

void gameplay::reloadRoom() {
    tson::Tileson tileson;
    tiles.clear();
    enemies.clear();

    switch (room) {
        case 1: {
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
        case 2: {
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


            //custom enemies
            if (std::find(enemyID.begin(), enemyID.end(), 201) == enemyID.end()) {


                Enemy1 *enemy1 = new Enemy1(this);
                enemy1->controltype = Path;
                enemy1->id = 201;
                enemy1->position.x = 5 * 32;
                enemy1->position.y = 4 * 32;
                enemy1->stopleft = 5 * 32; //creates new stop points for Enemy1 instance enemy1
                enemy1->stopdown = 4 * 32;
                enemy1->stopright = 10 * 32;
                enemy1->stopup = 3 * 32 + 16;
                enemy1->calculatePathAsRectangle();
                enemies.push_back(enemy1);

                if (enemy1->health == 0) {
                    enemyID.push_back(enemy1->id);
                }
            }

            if (std::find(enemyID.begin(), enemyID.end(), 202) == enemyID.end()) {

                Enemy2 *enemy2 = new Enemy2(this);
                enemy2->controltype = Random;
                enemy2->id = 202;
                enemy2->position.x = 22 * 32 + 16;
                enemy2->position.y = 8 * 32;
                enemy2->stopleft = 11 * 32; //creates new stop points for Enemy1 instance enemy1
                enemy2->stopdown = 6 * 32;
                enemy2->stopright = 8 * 32;
                enemy2->stopup = 3 * 32 + 16;
                enemies.push_back(enemy2);

                if (enemy2->health == 0) {
                    enemyID.push_back(enemy2->id);
                }
            }

            if (std::find(enemyID.begin(), enemyID.end(), 203) == enemyID.end()) {

                Enemy3 *enemy3 = new Enemy3(this);
                enemy3->controltype = Path;
                enemy3->id = 203;
                enemy3->position.x = 12 * 32;
                enemy3->position.y = 9 * 32;
                enemies.push_back(enemy3);


                float polygons = 180;
                for (int i = 0; i < polygons; i++) {
                    float angle = (float) i * PI * 2 / polygons;    //walks in circle
                    enemy3->path.push_back({cos(angle) * 64 + 12 * 32, sin(angle) * 64 + 7 * 32});
                }

                if (enemy3->health == 0) {
                    enemyID.push_back(enemy3->id);
                }
            }




            //creates enemies for room 2
            /*enemies.push_back((new Enemy1(this)));
                    //creates enemies with diffrent stop points


            enemies.push_back((new Enemy2(this)));
            enemies.push_back((new Enemy3(this)));



            gameplay scene; //implements gameplay instance

            Enemy1 enemy1(&scene); //creates Enemy1 instance
            enemy1.controltype = Path; // sets control type

            Enemy2 enemy2(&scene);
            enemy2.controltype = Random;

            Enemy3 enemy3(&scene);
            enemy3.controltype = Path;*/



        }
            break;

        case 3: {
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
        case 4: {
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
        case 5: {
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
        case 6: {
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

bool gameplay::soulcantakeover() {
    if (CheckCollisionPointCircle({themaincharacter->position.x, themaincharacter->position.y},
                                  {therobot->position.x, therobot->position.y}, takeoverradius)) {
        return true;
    } else {
        return false;
    }
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

const std::vector<Enemy *> &gameplay::getEnemies() const {
    return enemies;
}

void gameplay::clearEnemies() {
    for (Enemy *enemy: enemies) {
        delete enemy;
    }
    enemies.clear();
}


