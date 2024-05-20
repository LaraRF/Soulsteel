//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"


void maincharacter::update() {

   if (IsKeyPressed(KEY_S)||IsKeyDown(KEY_S)) {
        characterposition.y = characterposition.y+5.0f;
    }
    if (IsKeyPressed(KEY_W)||IsKeyDown(KEY_W)) {
        characterposition.y = characterposition.y-5.0f;
    }
    if (IsKeyPressed(KEY_A)||IsKeyDown(KEY_A)) {
        characterposition.x = characterposition.x-5.0f;
    }
    if (IsKeyPressed(KEY_D)||IsKeyDown(KEY_D)) {
        characterposition.x = characterposition.x+5.0f;
    }

}

void maincharacter::draw() {

    DrawRectangle(characterposition.x, characterposition.y, 32,32, BLACK);

}
