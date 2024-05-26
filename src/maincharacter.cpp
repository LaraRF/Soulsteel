//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"


void maincharacter::update(languagestates &languagestates, maincharactermodus &maincharactermodus) {

    //allows you to switch between soul and robot by pressing space bar
    switch (maincharactermodus) {
        case soul:
            if (IsKeyPressed(KEY_SPACE)) {
                maincharactermodus = robot;
            }
            break;
        case robot:
            if (IsKeyPressed(KEY_SPACE)) {
                maincharactermodus = soul;
            }
            break;
    }

    //gives character movement, 4 directions, using arrow keys

        if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) {
            characterposition.y = characterposition.y + stepsize;
        }
        if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
            characterposition.y = characterposition.y - stepsize;
        }
        if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
            characterposition.x = characterposition.x - stepsize;
        }
        if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
            characterposition.x = characterposition.x + stepsize;
        }

        //different skills for soul and robot
        //using IJKL keys, but can easily be changed
        switch (maincharactermodus) {
            case soul:
                //dash

                //light

                //dust

                break;
            case robot:

                //melee attack

                //ranged attack

                //heavy lifting

                //bomb

                break;
        }
    }


void maincharacter::draw(languagestates &languagestates, maincharactermodus &maincharactermodus) {

    //draws soul or robot, depending on which is chosen
    switch(maincharactermodus){
        case soul:
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, PINK);
            break;
        case robot:
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, BLACK);
            break;
    }



}
