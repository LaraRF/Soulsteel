//
// Created by lrfri on 14.05.2024.
//
#include "optionen.h"
#include "globalstates.h"
#include "raylib.h"
#include "languagesettings.h"

void optionen::update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes) {

    switch (cursor) {
        case 0:
            if (IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 1:
            if (IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 5;
            }
            break;
        case 2:
            if (IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 3:
            if (IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 3;
            }
            break;
        case 4:
            if (IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            }
            break;
        case 5:
            if (IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_DOWN)) {
                cursor++;
            }
            break;
        case 6:
            if (IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_UP)) {
                cursor--;
                break;
                default:
                    break;
            }
    }
    if(IsKeyPressed(KEY_ENTER)){
        switch(cursor){
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
                languagestates=german;
                break;
            case 5:
                languagestates=english;
                break;
            case 6:
                globalstates=menu;
                break;
            default:
                break;
        }
    }
}

void optionen::draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes) {

    switch (cursor) { //shows which box is selected by giving it a white outline
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
            DrawRectangleRec(hitbox_close_marked, WHITE);
            break;
        default:
            break;
    }

    DrawRectangleRec(hitbox_flagDE, GRAY);
    DrawRectangleRec(hitbox_flagENG, GRAY);
    DrawRectangleRec(hitbox_close, GRAY);

    DrawRectangleRec(hitbox_tastatur, GRAY);
    DrawRectangleRec(hitbox_controller, GRAY);

    DrawRectangleRec(hitbox_soundless, GRAY);
    DrawRectangleRec(hitbox_soundmore, GRAY);

    DrawTexture(flagDE, 225, 355, WHITE);
    DrawTexture(flagENG, 625, 355, WHITE);
    DrawTexture(closeButton, 810, 450, WHITE);
    DrawTexture(tastaturbutton, 225, 115, WHITE);
    DrawTexture(controllerbutton, 625, 115, WHITE);
    DrawTexture(soundlessbutton, 225, 235, WHITE);
    DrawTexture(soundmorebutton, 625, 235, WHITE);

    switch (languagestates) {
        case german:
            DrawText("Einstellungen", 320, 23, 50, WHITE);
            DrawText("Steuerung", 400, 125, 30, WHITE);
            DrawText("Ton", 400, 235, 30, WHITE);
            DrawText("Sprache", 400, 365, 30, WHITE);
            break;
        case english:
            DrawText("Settings", 380, 23, 50, WHITE);
            DrawText("Control", 400, 125, 30, WHITE);
            DrawText("Sound", 400, 235, 30, WHITE);
            DrawText("Language", 400, 365, 30, WHITE);
            break;
        default:
            break;
    }
}