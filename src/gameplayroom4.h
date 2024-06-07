//
// Created by lrfri on 07.06.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAYROOM4_H
#define RAYLIBSTARTER_GAMEPLAYROOM4_H


#include <vector>
#include "raylib.h"
#include "assestmanagergraphics.h"
#include "scene.h"

class maincharacter;
class enemies;

class gameplayroom4 : public scene{
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
    Vector2 nextdoor {21*32+16, 16};
    Vector2 lastdoor {24*32+16,3*32+16 };
    gameplayroom4();
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

#endif //RAYLIBSTARTER_GAMEPLAYROOM4_H
