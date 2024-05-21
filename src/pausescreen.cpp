//
// Created by lrfri on 14.05.2024.
//
#include "pausescreen.h"
#include <iostream>
#include "raylib.h"

void pausescreen::update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes) {
    //pressing P gets you back to gameplay screen
    if(IsKeyPressed(KEY_P)){
        globalstates =gameplayscreen;
    }
}

void pausescreen::draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes) {
    //draws the background and textures
    ClearBackground(DARKGRAY);
    DrawRectangleRec(boxforpausebutton, GRAY);
    DrawTexture(pausebutton, 398,398, WHITE);
    DrawTexture(title, 30,50,WHITE);

    //draws the text depending on which language is selected
    switch(languagestates){
        case german:
            DrawText("Das Spiel ist pausiert. Drücke P erneut, um zurück zum Spiel zu gelangen.",
                     12,300, 25, WHITE);
            break;
        case english:
            DrawText("The game is paused. Press P again to get back to the game.",
                     10,300,30,WHITE);

    }

}