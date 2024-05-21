//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"


void maincharacter::update(languagestates &languagestates, maincharactermodus &maincharactermodus) {

   switch(maincharactermodus){
       case soul:
           if(IsKeyPressed(KEY_SPACE)){
               maincharactermodus=robot;
           }
           break;
       case robot:
           if(IsKeyPressed(KEY_SPACE)){
               maincharactermodus=soul;
           }
           break;
   }



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

void maincharacter::draw(languagestates &languagestates, maincharactermodus &maincharactermodus) {

    switch(maincharactermodus){
        case soul:
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, PINK);
            break;
        case robot:
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, BLACK);
            break;
    }



}
