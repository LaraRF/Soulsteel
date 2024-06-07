//
// Created by lrfri on 14.05.2024.
//
#include "pausescreen.h"
#include <iostream>
#include "raylib.h"
#include "gameplayroom1.h"

void pausescreen::update() {

}

scene *pausescreen::evaluateSceneChange() {
    if (IsKeyPressed(KEY_P)) {
        return new gameplayroom1();
    } else {
        return this;
    }
}

void pausescreen::draw() {
//draws the background and textures
    ClearBackground(DARKGRAY);
    DrawRectangleRec(boxforpausebutton, GRAY);
    DrawTexture(pausebutton, 337, 338, WHITE);
    DrawTexture(title, -70, 50, WHITE);

    //draws the text depending on which language is selected


    DrawText("The game is paused. Press P again to get back to the game.",
             75, 300, 20, WHITE);


}

void pausescreen::drawDebug() {

}
