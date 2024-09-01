//
// Created by lrfri on 14.05.2024.
//
#include "mainmenu.h"
#include "gameplay.h"
#include "optionen.h"
#include "gamechoicescreen.h"


void mainmenu::update() {
    if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
        if (cursor == 2) {
            cursor = 2; //makes it, so you can't go "more to the right" than last box
        } else {
            cursor++;
        }
    }

    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
        if (cursor == 0) {
            cursor = 0; //same here, but for other side of screen
        } else {
            cursor--;
        }
    }
}

scene *mainmenu::evaluateSceneChange() { //gives the buttons their functions
    if (IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                return new gamechoicescreen(reinterpret_cast<gameplay *>(this));
                break;
            case 1:
                return new optionen();
                break;
            case 2:
                CloseWindow();
                return nullptr;
        }
    } else {
        return this;
    }//return this = stay on this screen (points to itself)
}

void mainmenu::draw() {
    DrawTexture(title, -65, 50, WHITE);


    switch (cursor) { //shows which box is selected by giving it a white outline
        case 0:
            DrawTexture(start_selected, 90,330,WHITE);
            DrawTexture(settings, 325, 330, WHITE);
            DrawTexture(close, 560, 330, WHITE);
            break;
        case 1:
            DrawTexture(start, 90, 330, WHITE);
            DrawTexture(settings_selected,325,330, WHITE);
            DrawTexture(close, 560, 330, WHITE);
            break;
        case 2:
            DrawTexture(start, 90, 330, WHITE);
            DrawTexture(settings, 325, 330, WHITE);
            DrawTexture(close_selected,560,330, WHITE);
            break;
        default:
            break;
    }
    //draws the buttons
    /*DrawRectangleRec(hitbox_play, GRAY);
    DrawRectangleRec(hitbox_settings, GRAY);
    DrawRectangleRec(hitbox_close, GRAY);*/

    /*DrawTexture(start, 90, 330, WHITE);
    DrawTexture(settings, 325, 330, WHITE);
    DrawTexture(close, 560, 330, WHITE);*/
}

void mainmenu::drawDebug() {

}


