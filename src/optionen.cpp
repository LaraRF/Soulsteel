//
// Created by lrfri on 14.05.2024.
//
#include "optionen.h"
#include "raylib.h"
#include "mainmenu.h"

void optionen::update() {
//allows navigation through the menu by using WASD keys
    switch (cursor) {
        case 0:
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 1:
            if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 7;
            }
            break;
        case 2:
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 3:
            if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 5;
            }
            break;
        case 4:
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 5:
            if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                cursor--;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor = cursor + 3;
            } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 6:
            if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT)) {
                cursor++;
            } else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN)) {
                cursor = cursor + 2;
            }
            break;
        case 7:
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP)) {
                cursor = cursor - 2;
            } else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_RIGHT) ||
                       IsKeyPressed(KEY_DOWN)) {
                cursor++;
            } else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT)) {
                cursor--;
            }
            break;
        case 8:
            if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_LEFT)) {
                cursor--;
                break;
            }
    }
}

scene *optionen::evaluateSceneChange() {
    if (IsKeyPressed(KEY_M)) {
                return new mainmenu();

    } else {
        return this;
    }
}

void optionen::draw() {
DrawText("Controls", 300,40,50,WHITE);
DrawText("Movement:", 50,120,25,WHITE);
DrawText("W: Move up\nA: Move left\nS: Move down\nD: Move right", 200,120, 20,WHITE);
DrawText("Abilities:", 50, 280, 25, WHITE);
DrawText("I: Soul dash (move through bars and over abyss)\nL: Soul Dust (light up fire bowls)\nK: some robot function\nJ: some robot function", 200, 280, 20,WHITE);
DrawText("Press M to go back to main menu", 50, 440, 20,WHITE);
}

void optionen::drawDebug() {

}
