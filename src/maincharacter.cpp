//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"
#include "scene.h"


void maincharacter::update() {


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
    switch (currentmode) {
        case soul:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmode = robot;
            }

            //movement
            switch (souldashactivated) {
                case 0:
                    if (IsKeyDown(KEY_S)) {
                        position.y = position.y + stepsize;
                    }
                    if (IsKeyDown(KEY_W)) {
                        position.y = position.y - stepsize;
                    }
                    if (IsKeyDown(KEY_A)) {
                        position.x = position.x - stepsize;
                    }
                    if (IsKeyDown(KEY_D)) {
                        position.x = position.x + stepsize;
                    }
                    break;
                case 1:
                    if (IsKeyDown(KEY_S)) {
                        position.y = position.y + (stepsize + stepzisesouldash);
                    }
                    if (IsKeyDown(KEY_W)) {
                        position.y = position.y - (stepsize + stepzisesouldash);
                    }
                    if (IsKeyDown(KEY_A)) {
                        position.x = position.x - (stepsize + stepzisesouldash);
                    }
                    if (IsKeyDown(KEY_D)) {
                        position.x = position.x + (stepsize + stepzisesouldash);
                    }
            }
            //end of movement code
            //space for more soul functions
            break;
        case robot:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmode = soul;
            }

            //movement
            if (IsKeyDown(KEY_S)) {
                position.y = position.y + stepsize;
            }
            if (IsKeyDown(KEY_W)) {
                position.y = position.y - stepsize;
            }
            if (IsKeyDown(KEY_A)) {
                position.x = position.x - stepsize;
            }
            if (IsKeyDown(KEY_D)) {
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

void maincharacter::draw() {

    //draws soul or robot, depending on which is chosen
    switch (currentmode) {
        case soul:
            DrawCircle(position.x, position.y, size,PINK);
            DrawTexture(characterSoulTexture, position.x-16, position.y-24, WHITE);
            if (souldashactivated) {
                DrawText("Souldash activated", 10, 10, 10, WHITE);
            } else if (!souldashactivated) {
                DrawText("Souldash deactivated", 10, 10, 10, WHITE);
            }
            break;
        case robot:
            //DrawCircle(position.x, position.y, size,GRAY);
            DrawTexture(characterRobotTexture, position.x-16, position.y-24, WHITE);
            break;
        default: std::cout << "help";
    }
}

maincharacter::maincharacter(gameplay *scene) : _scene(scene) {

}
