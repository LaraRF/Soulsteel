//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAY_H
#define RAYLIBSTARTER_GAMEPLAY_H

#include <vector>
#include "raylib.h"
#include "assestmanagergraphics.h"
#include "scene.h"
#include "ENEMIES/Enemy.h"
#include "GAME OBJECTS/gameobjects.h"
#include "maincharactermodus.h"


class maincharacter;
class gameobjects;
class robot;
class Enemy;
class Enemy1;
class Enemy2;


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
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("tilesets/greyboxing1");


        //attributes necessary for using the map
        std::vector<int> tiles;
        //int rows;
        //int cols;
        gameplay();
        bool touchesWall(Vector2 pos, float size);
        bool touchesWall(Vector2 pos);
        bool touchesBars(Vector2 pos, float size);
        Rectangle getTouchedBars(Vector2 position, float radius);

        Vector2 touchWallPosition(Vector2 pos, Vector2 size);
        Rectangle getWallAt(Vector2 pos);
        int getTileAt(float x, float y);
        Rectangle getTouchedWall(Vector2 position, float radius);

        //std::vector<int> tileMap;
        int mapWidth = 25;
        int mapHeight = 15;

        maincharacter *themaincharacter;
        std::vector<Enemy*> enemies;
        std::vector<gameobjects*> gameobjects;
        robot *therobot;

        int room=1;
        bool hasbeeninroom1before =false;

        //doors
        int doorfromroom1to2=32;
        int startposroom1to2=14*32+16;
        int doorfromroom2to1=14*32+20;
        int startposroom2to1=2*32+16;
        int doorfromroom2to3=2*32;
        int startposroom2to3=14*32+16;
        int doorfromroom3to2=14*32+20;
        int startposroom3to2=2*32+16;
        int doorfromroom2to4=24*32+16;
        int startposroom2to4=16;
        int doorfromroom4to2=16;
        int startposroom4to2=24*32+16;
        int doorfromroom4to5=16;
        int startposroom4to5=14*32+16;
        int doorfromroom5to4=14*32+20;
        int startposroom5to4=20;
        int doorfromroom5to6=2*32;
        int startposroom5to6=14*32+16;
        int doorfromroom6to5=14*32+20;
        int startposroom6to5=2*32+16;

        bool robotswitched1to2 =false;
        bool robotswitched2to1 =false;
        bool robotswitched2to3 =false;
        bool robotswitched3to2 =false;
        bool robotswitched2to4 =false;
        bool robotswitched4to2 =false;
        bool robotswitched4to5 =false;
        bool robotswitched5to4 =false;
        bool robotswitched5to6 =false;
        bool robotswitched6to5 =false;
        bool maincharacterswitched1to2 =false;
        bool maincharacterswitched2to1 =false;
        bool maincharacterswitched2to3 =false;
        bool maincharacterswitched3to2 =false;
        bool maincharacterswitched2to4 =false;
        bool maincharacterswitched4to2 =false;
        bool maincharacterswitched4to5 =false;
        bool maincharacterswitched5to4 =false;
        bool maincharacterswitched5to6 =false;
        bool maincharacterswitched6to5 =false;



        maincharactermodus currentmodus =soulmodus;


        void reloadRoom();

        bool touchesNextDoor(Vector2 pos, float size);
    };




#endif //RAYLIBSTARTER_GAMEPLAY_H
