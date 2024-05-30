//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"
#include "scene.h"


void maincharacter::update(languagestates &languagestates, maincharactermodus &maincharactermodus,
                           difficultylevel &difficultylevel) {

    //souldash

    if (IsKeyPressed(KEY_I)) {
        souldash++;
    }
    if (souldash % 2) {
        souldashactivated = true;
    } else {
        souldashactivated = false;
    }

    //allows you to switch between soul and robot functions
    switch (maincharactermodus) {
        case soul:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                maincharactermodus = robot;
            }

            //movement
            switch (souldashactivated) {
                case 0:
                    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) {
                        position.y = position.y + stepsize;
                    }
                    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
                        position.y = position.y - stepsize;
                    }
                    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
                        position.x = position.x - stepsize;
                    }
                    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
                        position.x = position.x + stepsize;
                    }
                    break;
                case 1:
                    if (IsKeyPressed(KEY_S) || IsKeyDown(KEY_S)) {
                        position.y = position.y + (stepsize + stepzisesouldash);
                    }
                    if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
                        position.y = position.y - (stepsize + stepzisesouldash);
                    }
                    if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
                        position.x = position.x - (stepsize + stepzisesouldash);
                    }
                    if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
                        position.x = position.x + (stepsize + stepzisesouldash);
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
                position.y = position.y + stepsize;
            }
            if (IsKeyPressed(KEY_W) || IsKeyDown(KEY_W)) {
                position.y = position.y - stepsize;
            }
            if (IsKeyPressed(KEY_A) || IsKeyDown(KEY_A)) {
                position.x = position.x - stepsize;
            }
            if (IsKeyPressed(KEY_D) || IsKeyDown(KEY_D)) {
                position.x = position.x + stepsize;
            }//end movement code
            //space for more robot function
            break;
    }

    for (int i = 0; _scene->touchesWall(position, size) && i < 4; i++) {
        Rectangle touchedWall = _scene->getTouchedWall(position, size);
        Vector2 touchPoint = Vector2Clamp(position, {touchedWall.x, touchedWall.y},
                                          {touchedWall.x + touchedWall.width, touchedWall.y + touchedWall.height});
        Vector2 pushForce = Vector2Subtract(position, touchPoint);
        float overlapDistance = size - Vector2Length(pushForce);
        if (overlapDistance <= 0) {
            break;
        }
        pushForce = Vector2Normalize(pushForce);
        pushForce = Vector2Scale(pushForce, overlapDistance);
        position = Vector2Add(position, pushForce);
    }
}

void maincharacter::draw(languagestates &languagestates, maincharactermodus &maincharactermodus,
                         difficultylevel &difficultylevel) {

    //draws soul or robot, depending on which is chosen
    switch (maincharactermodus) {
        case soul:
            if (souldashactivated) {
                DrawText("Souldash activated", 10, 10, 10, WHITE);
            } else if (!souldashactivated) {
                DrawText("Souldash deactivated", 10, 10, 10, WHITE);
            }

            DrawTexture(characterSoulTexture, 32, 32, WHITE);
            break;
        case robot:
            DrawTexture(characterRobotTexture, 32, 32, WHITE);
            break;
    }
}

maincharacter::maincharacter(gameplay *scene) : _scene(scene) {

}
