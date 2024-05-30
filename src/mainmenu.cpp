//
// Created by lrfri on 14.05.2024.
//
#include "mainmenu.h"
#include "gameplay.h"
#include "optionen.h"


void mainmenu::update() {
    if(IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)){
        if(cursor == 2){
            cursor = 2; //makes it, so you can't go "more to the right" than last box
        }else{
            cursor++;
        }
    }

    if(IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)){
        if(cursor == 0){
            cursor = 0; //same here, but for other side of screen
        }else{
            cursor--;
        }
    }
}

scene *mainmenu::evaluateSceneChange() { //gives the buttons their functions
    if(IsKeyPressed(KEY_ENTER)) {
        switch(cursor){
            case 0:
                return new gameplay();
                break;
            case 1:
                return new optionen();
                break;
            case 2:
                CloseWindow();
        }
    }else{
        return this;}//return this = bleib bei dieser Szene (pointer auf sich selbst)

}

void mainmenu::draw() {
    DrawTexture(title, -65, 50, WHITE);


    switch(cursor){ //shows which box is selected by giving it a white outline
        case 0:
            DrawRectangleRec(hitbox_play_marked, WHITE);
            break;
        case 1:
            DrawRectangleRec(hitbox_settings_marked, WHITE);
            break;
        case 2:
            DrawRectangleRec(hitbox_close_marked, WHITE);
            break;
        default:
            break;
    }
    //draws the buttons
    DrawRectangleRec(hitbox_play, GRAY);
    DrawRectangleRec(hitbox_settings, GRAY);
    DrawRectangleRec(hitbox_close, GRAY);

    //draws the images on the buttons
    DrawTexture(buttonplay1, 130, 345, WHITE);
    DrawTexture(button1settings, 340, 320, WHITE);
    DrawTexture(button1close, 600, 340, WHITE);
}

void mainmenu::drawDebug() {

}

mainmenu::mainmenu() {

}
