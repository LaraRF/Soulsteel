//
// Created by lrfri on 04.06.2024.
//

#include "enemies.h"
void enemies::update()  {

    /* Timer += Timer->GetTimeElapsed();
     int Random = (rand() % 4);
     if (Timer >= 2.0f)*/

    //movement
    if (IsKeyDown(KEY_G)) {
        position.y = position.y + stepsize;
    }
    if (IsKeyDown(KEY_T)) {
        position.y = position.y - stepsize;
    }
    if (IsKeyDown(KEY_F)) {
        position.x = position.x - stepsize;
    }
    if (IsKeyDown(KEY_H)) {
        position.x = position.x + stepsize;
    }//end movement code
}
void enemies::draw() {

    DrawTexture(enemyTexture1, position.x, position.y, WHITE);


}

enemies::enemies(gameplay *scene) : _scene(scene){

}
