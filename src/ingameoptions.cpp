//
// Created by lrfri on 28.05.2024.
//

#include "ingameoptions.h"
#include "raylib.h"
#include "languagesettings.h"
#include "gameplay.h"

void ingameoptions::update() {
//allows navigation through the menu by using WASD keys
    switch (cursor) {
        case 0:
            if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 1:
            if (IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 7;
            }
            break;
        case 2:
            if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 3:
            if (IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 5;
            }
            break;
        case 4:
            if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 5:
            if (IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 3;
            } else if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 6:
            if (IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 7:
            if (IsKeyPressed(KEY_W)|| IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_S)|| IsKeyPressed(KEY_RIGHT)|| IsKeyPressed(KEY_DOWN)) {
                cursor++;
            } else if (IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)) {
                cursor--;
            }
            break;
        case 8:
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_UP)|| IsKeyPressed(KEY_LEFT)) {
                cursor--;
                break;
            }
    }
}

scene *ingameoptions::evaluateSceneChange() {
    if (IsKeyPressed(KEY_ENTER)) {
        switch (cursor) {
            case 0:
                //control =tastatur
                break;
            case 1:
                //control =controller
                break;
            case 2:
                //sound =less
                break;
            case 3:
                //sound =more
                break;
            case 4:
                //languagestates=german;
                break;
            case 5:
                //languagestates=english;
                break;
            case 6:
                //difficultylevel =guided;
                break;
            case 7:
                //difficultylevel =exploration;
                break;
            case 8:
                return new gameplay();
                break;
            default:
                break;
        }
    } else if (IsKeyPressed(KEY_O)) {
        return new gameplay();
    } else {
        return this;
    }
}

void ingameoptions::draw() {
//shows which button is selected by giving it a white outline
    switch (cursor) {
        case 0:
            DrawRectangleRec(hitbox_tastatur_marked, WHITE);
            break;
        case 1:
            DrawRectangleRec(hitbox_controller_marked, WHITE);
            break;
        case 2:
            DrawRectangleRec(hitbox_soundless_marked, WHITE);
            break;
        case 3:
            DrawRectangleRec(hitbox_soundmore_marked, WHITE);
            break;
        case 4:
            DrawRectangleRec(hitbox_flagDE_marked, WHITE);
            break;
        case 5:
            DrawRectangleRec(hitbox_flagENG_marked, WHITE);
            break;
        case 6:
            DrawRectangleRec(hitbox_guided_marked, WHITE);
            break;
        case 7:
            DrawRectangleRec(hitbox_exploration_marked, WHITE);
            break;
        case 8:
            DrawRectangleRec(hitbox_close_marked, WHITE);
            break;
        default:
            break;
    }

    //draws the buttons
    /*switch(languagestates){
        case german:
            DrawRectangleRec(hitbox_flagDE, PINK);
            DrawRectangleRec(hitbox_flagENG, GRAY);
            break;
        case english:
            DrawRectangleRec(hitbox_flagDE, GRAY);
            DrawRectangleRec(hitbox_flagENG, PINK);
    }

    DrawRectangleRec(hitbox_close, GRAY);

    switch(controlmodes){
        case tastaturmode:
            DrawRectangleRec(hitbox_tastatur, PINK);
            DrawRectangleRec(hitbox_controller, GRAY);
            break;
        case controllermode:
            DrawRectangleRec(hitbox_tastatur, GRAY);
            DrawRectangleRec(hitbox_controller, PINK);
    }
    //Switch missing and maybe not needed?, because we don't have sound settings yet
    DrawRectangleRec(hitbox_soundless, GRAY);
    DrawRectangleRec(hitbox_soundmore, GRAY);

    switch(difficultylevel){
        case guided:
            DrawRectangleRec(hitbox_guided, PINK);
            DrawRectangleRec(hitbox_exploration, GRAY);
            break;
        case exploration:
            DrawRectangleRec(hitbox_guided, GRAY);
            DrawRectangleRec(hitbox_exploration, PINK);
    }

    //draws the images on the buttons
    DrawTexture(flagDE, 75, 275, WHITE);
    DrawTexture(flagENG, 475, 275, WHITE);
    DrawTexture(closeButton, 680, 360, WHITE);
    DrawTexture(tastaturbutton, 75, 95, WHITE);
    DrawTexture(controllerbutton, 475, 95, WHITE);
    DrawTexture(soundlessbutton, 75, 185, WHITE);
    DrawTexture(soundmorebutton, 475, 185, WHITE);
    DrawText("G", 105,375, 50, BLACK);
    DrawText("E", 515,375, 50, BLACK);

    //draws the text depending on the selected language
    switch (languagestates) {
        case german:
            DrawText("Einstellungen", 170, 23, 50, WHITE);
            DrawText("Steuerung", 250, 115, 30, WHITE);
            DrawText("Ton", 250, 195, 30, WHITE);
            DrawText("Sprache", 250, 295, 30, WHITE);
            DrawText("Spielmodus", 250, 390, 30, WHITE);
            break;
        case english:
            DrawText("Settings", 170, 23, 50, WHITE);
            DrawText("Control", 250, 115, 30, WHITE);
            DrawText("Sound", 250, 195, 30, WHITE);
            DrawText("Language", 250, 295, 30, WHITE);
            DrawText("Game mode", 250, 390, 30, WHITE);
            break;
        default:
            break;
    }*/
}

void ingameoptions::drawDebug() {

}

