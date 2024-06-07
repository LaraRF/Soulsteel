//
// Created by lrfri on 05.06.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAYROOM1_H
#define RAYLIBSTARTER_GAMEPLAYROOM1_H

#include <vector>
#include "raylib.h"
#include "assestmanagergraphics.h"
#include "scene.h"
#include "gameplayroom2.h"


class maincharacter;
class enemies;

class gameplayroom1 : public scene{
public:

    void update() override;

    scene *evaluateSceneChange() override;

    void draw() override;

    void drawDebug() override;

    //loads the necessary textures
    Texture2D heart = assestmanagergraphics::getTexture("userinterface/heart_smaller");

    //loads the textures on the map (Kachelsatz)
    Texture2D tilesetgrass = assestmanagergraphics::getTexture("tilesets/grassesfour");


    //attributes necessary for using the map
    std::vector<int> tiles;
    int rows;
    int cols;
    Vector2 nextdoor {24*32+16, 8*32+16};
    gameplayroom1();
    bool touchesWall(Vector2 pos, float size);
    bool touchesWall(Vector2 pos);

    Vector2 touchWallPosition(Vector2 pos, Vector2 size);
    Rectangle getWallAt(Vector2 pos);
    int getTileAt(float x, float y);
    Rectangle getTouchedWall(Vector2 position, float radius);

    //std::vector<int> tileMap;
    int mapWidth = 25;
    int mapHeight = 15;

    maincharacter *maincharacter;
    enemies *enemies;
};


#endif //RAYLIBSTARTER_GAMEPLAYROOM1_H
