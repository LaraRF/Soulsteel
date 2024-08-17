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
#include "maincharacter.h"
#include "Wall.h"



class maincharacter;
class gameobjects;
class robot;
class Enemy;
class Enemy1;
class Enemy2;
class Enemy3;


    class gameplay : public scene {
    private:
        //std::vector<Enemy*> enemies;
        void clearEnemies();
        bool isAlive;

        std::vector<std::pair<int, int>> activatedFirebowls;


    public:

        void update() override;
        void doRoomSwitch();

        scene *evaluateSceneChange() override;

        void draw() override;
        void drawtextonscreen();
        void drawhealthhearts();
        void drawmaincharacter();


        void drawDebug() override;

        void activateFirebowl(int x, int y);
        bool isFirebowlActivated(int x, int y) const;
        void drawActivatedFirebowls();

        //loads the necessary textures
        Texture2D heart = assestmanagergraphics::getTexture("userinterface/heart_smaller");

        //loads the textures on the map (Kachelsatz)
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("tilesets/greyboxing1");

        Texture2D activatedFirebowlTexture=assestmanagergraphics::getTexture("item/souldust");
        bool isAdjacentToFirebowl(Vector2 pos) const;
        std::pair<int, int> getNearestFirebowlTile(Vector2 pos) const;

        //attributes necessary for using the map
        std::vector<int> tiles;
        int mapWidth = 25;
        int mapHeight = 15;

        gameplay();

        maincharactermodus currentmodus = soulmodus;

        //stuff to handle character switch and when to show inactive robot
        bool soulleavesrobot=false;
        bool soulentersrobot=false;
        bool soulhasntchangedformsyet=true;
        bool soulcantakeover();
        int takeoverradius =40;

        //collision functions
        int getTileAt(float x, float y) const;
        bool touchesWall(Vector2 pos, float size);
        bool touchesAbyss(Vector2 pos, float size);
        bool touchesBars(Vector2 pos, float size);
        Rectangle getTouchedBars(Vector2 position, float size); //radius replaced with size
        Rectangle getTouchedWall(Vector2 position, float size);
        Rectangle getTouchedAbyss(Vector2 position, float size);

        Vector2 touchWallPosition(Vector2 pos, Vector2 size);
        Rectangle getWallAt(Vector2 pos);
        std::vector<Wall*> walls;

        //lets different entities spawn
        const std::vector<Enemy*>& getEnemies() const;
        maincharacter *themaincharacter;
        std::vector<Enemy*> enemies;
        std::vector<gameobjects*> gameobjects;
        robot *therobot;

        //room switch things
        int room=1;
        int robotisinroom=1;
        int soulisinroom=1;
        bool hasbeeninroom1before =false;

        void reloadRoom();

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

        static const int grassID=0;
        static const int wallID=1;
        static const int abyssID=3;
        static const int firebowlID =9;
        static const int barsID=10;

    protected:
        std::vector<int>enemyID;

        void updateAllenemies();
    };

#endif //RAYLIBSTARTER_GAMEPLAY_H
