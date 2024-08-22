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
#include "GAME OBJECTS/stone.h"



class maincharacter;
class gameobjects;
class robot;
class Enemy;
class Enemy1;
class Enemy2;
class Enemy3;

struct ActivatedFirebowls {
    int x;
    int y;
    float animationTimer;
    int currentFrame;
    int room;
};
struct ActivatedFirebowl {
    int x;
    int y;
    int room;
};

    class gameplay : public scene {
    private:
        //std::vector<Enemy*> enemies;
        void clearEnemies();
        bool isAlive;

        //std::vector<std::pair<int, int>> activatedFirebowls;
        std::vector<ActivatedFirebowls> activeFirebowlAnimations;
        std::vector<ActivatedFirebowl> activatedFirebowls;
        float activatedFirebowlAnimationSpeed = 0.1f;


    public:

        void update() override;
        void doRoomSwitch();

        scene *evaluateSceneChange() override;

        void draw() override;
        void drawtextonscreen();
        void drawhealthhearts();
        void drawmaincharacter();


        void drawDebug() override;

        //loads the necessary textures
        Texture2D heart = assestmanagergraphics::getTexture("userinterface/heart_smaller");

        //loads the textures on the map (Kachelsatz)
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("tilesets/greyboxing1");
        Texture2D tileset_room1 = assestmanagergraphics::getTexture("tileset/level1");

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

        //soul dust
        Texture2D activatedFirebowlTexture=assestmanagergraphics::getTexture("item/souldust");
        bool isAdjacentToFirebowl(Vector2 pos) const;
        std::pair<int, int> getNearestFirebowlTile(Vector2 pos) const;
        void activateFirebowl(int x, int y);
        bool isFirebowlActivated(int x, int y) const;
        void drawActivatedFirebowls(float deltaTime);
        bool areAllFirebowlsActivatedInRoom(int roomNumber) const;
        bool showDoorIsLockedMessage = false;
        void deactivateFirebowls();

        //stones
        std::vector<Stone*> stones;
        void spawnStone(Vector2 position);
        void updateStones();
        void drawStones();
        std::map<int, std::vector<Stone*>> stonesInRooms;
        void spawnStone(int room, Vector2 position);
        bool touchesStone(Vector2 tilePosition) const;
        Stone* getStoneAt(Vector2 mapPosition) const;

        //collision functions
        int getTileAt(float x, float y) const;
        bool touchesWall(Vector2 pos, float size);
        bool touchesAbyss(Vector2 pos, float size);
        bool touchesBars(Vector2 pos, float size);
        Rectangle getTouchedBars(Vector2 position, float size); //radius replaced with size
        Rectangle getTouchedWall(Vector2 position, float size);
        Rectangle getTouchedAbyss(Vector2 position, float size);
        bool isTileYouCantPushStoneOnto(int tileID) const;

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

        void loadMap();
        void reloadRoom();

        //doors
        int doortextarea=32*4;
        int doorfromroom1to2=32*2;
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

        static const int fence0ID=0;
        static const int fence1ID=1;
        static const int barsID=2;
        static const int fence2ID=3;
        static const int fence3ID=4;
        static const int fence4ID=5;
        static const int fence5ID=6;
        static const int fence6ID=7;
        static const int fence7ID=8;
        static const int fence8ID=9;
        static const int fence9ID=10;
        static const int fence10ID=11;
        static const int fence11ID=12;
        static const int fence12ID=13;
        static const int fence13ID=14;
        static const int firebowlID =15;
        static const int pipe0ID =16;
        static const int pipe1ID =17;
        static const int pipe2ID =18;
        static const int pipe3ID =19;
        static const int pipe4ID =20;
        static const int pipe5ID =21;
        static const int pipe6ID =22;
        static const int pipe7ID =23;
        static const int pipe8ID =24;
        static const int pipe9ID =25;
        static const int tree0ID =26;
        static const int tree1ID =27;
        static const int tree2ID =28;
        static const int tree3ID =29;
        static const int tree4ID =30;
        static const int tree5ID =31;
        static const int tree6ID =32;
        static const int tree7ID =33;
        static const int tree8ID =34;
        static const int tree9ID =35;
        static const int tree10ID =36;
        static const int tree11ID =37;
        static const int grassID =38;
        static const int grassID0=39;
        static const int grassID1=40;
        static const int grassID2=41;
        static const int grassID3=42;
        static const int grassID4=43;
        static const int grassID5=44;
        static const int grassID6=45;
        static const int grassID7=46;
        static const int grassID8=47;
        static const int grassID9=48;
        static const int grassID10=49;
        static const int grassID11=50;
        static const int grassID12=51;
        static const int grassID13=52;
        static const int abyssID=53;
        static const int stonewallID0=54;
        static const int stonewallID1=55;
        static const int stonewallID2=56;
        static const int stonewallID3=57;
        static const int stonewallID4=58;
        static const int doorhingeID0=59;
        static const int doorID1=60;
        static const int doorID2=61;
        static const int doorID3=62;
        static const int doorhingeID1=63;
        static const int doorhingeID2=64;
        static const int doorID4=65;
        static const int doorID5=66;
        static const int doorID6=67;
        static const int doorhingeID3=68;
        //69-83 sind graue Wand oder so

        std::vector<int> fenceIDs = {fence0ID, fence1ID, fence2ID, fence3ID, fence4ID, fence5ID, fence6ID, fence7ID, fence8ID, fence9ID, fence10ID, fence11ID, fence12ID, fence13ID};
        std::vector<int> pipeIDs = {pipe0ID, pipe1ID, pipe2ID, pipe3ID, pipe4ID, pipe5ID, pipe6ID, pipe7ID, pipe8ID, pipe9ID};
        std::vector<int> treeIDs = {tree0ID, tree1ID, tree2ID, tree3ID, tree4ID, tree5ID, tree6ID, tree7ID, tree8ID, tree9ID, tree10ID, tree11ID};
        std::vector<int> doorIDs = {doorID1, doorID2, doorID3, doorID4, doorID5, doorID6};
        std::vector<int> doorhingeIDs = {doorhingeID0, doorhingeID1, doorhingeID2, doorhingeID3};
        std::vector<int> stonewallIDs ={stonewallID0, stonewallID1, stonewallID2, stonewallID3, stonewallID4,doorID1};

        std::vector<std::vector<int>> wallIDs = {pipeIDs, treeIDs, doorhingeIDs,stonewallIDs};

        ~gameplay() {
            std::cout << "Gameplay instance destroyed\n";
            for (auto& roomStones : stonesInRooms) {
                for (auto stone : roomStones.second) {
                    delete stone;
                }
            }
        }
    protected:
        std::vector<int>enemyID;

        void updateAllenemies();
    };

#endif //RAYLIBSTARTER_GAMEPLAY_H
