//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAY_H
#define RAYLIBSTARTER_GAMEPLAY_H

#include <vector>
#include "raylib.h"
#include "assestmanagergraphics.h"
#include "scene.h"

    class gameplay:public scene {
    public:

        void update() override;

        scene *evaluateSceneChange() override;

        void draw() override;

        void drawDebug() override;

        //loads the necessary textures
        Texture2D heart = assestmanagergraphics::getTexture("userinterface/heart_smaller");
        //Texture2D modeRobo = LoadTexture("assets/graphics/robot_anuki_3.png");
        //Texture2D modeSoul = LoadTexture("assets/graphics/soul_destiny_3.png");

        //loads the textures on the map (Kachelsatz)
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("userinterface/grasses");


        //attributes necessary for using the map
        std::vector<int> tiles;
        int rows;
        int cols;
        gameplay();
        bool touchesWall(Vector2 pos, float size);
        bool touchesWall(Vector2 pos);

        Vector2 touchWallPosition(Vector2 pos, Vector2 size);
        Rectangle getWallAt(Vector2 pos);
        int getTileAt(float x, float y);
        Rectangle getTouchedWall(Vector2 position, float radius);

        std::vector<int> tileMap;
        int mapWidth = 25;
        int mapHeight = 15;
    };




#endif //RAYLIBSTARTER_GAMEPLAY_H
