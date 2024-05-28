//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"


void maincharacter::update(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel) {

    //souldash

    if(IsKeyPressed(KEY_I)){
        souldash++;
    }
    if(souldash %2){
        souldashactivated=true;
    }else{
        souldashactivated=false;
    }

    //allows you to switch between soul and robot functions
    switch (maincharactermodus) {
        case soul:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                maincharactermodus = robot;}

                //movement
                switch(souldashactivated) {
                    case 0:
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
                        break;
                    case 1:
                        if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) {
                            characterposition.y = characterposition.y + (stepsize+stepzisesouldash);
                        }
                        if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
                            characterposition.y = characterposition.y - (stepsize+stepzisesouldash);
                        }
                        if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
                            characterposition.x = characterposition.x - (stepsize+stepzisesouldash);
                        }
                        if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
                            characterposition.x = characterposition.x + (stepsize+stepzisesouldash);
                        }
                }
            //end of movement code
            //space for more soul functions
            break;
        case robot:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                maincharactermodus = soul;
            }

            //movement
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
            }//end movement code
            //space for more robot function
            break;
    }
}





void maincharacter::draw(languagestates &languagestates, maincharactermodus &maincharactermodus, difficultylevel &difficultylevel) {

    //draws soul or robot, depending on which is chosen
    switch(maincharactermodus){
        case soul:
            if(souldashactivated){
                DrawText("Souldash activated", 10,10, 10,WHITE);
            }else if (!souldashactivated) {
                DrawText("Souldash deactivated", 10,10, 10,WHITE);
            }
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, PINK);
            break;
        case robot:
            DrawRectangle(characterposition.x, characterposition.y, 32, 32, BLACK);
            break;
    }





}
