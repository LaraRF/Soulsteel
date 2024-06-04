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
void enemies::draw() {

    DrawTexture(enemyTexture1, position.x, position.y, WHITE);


}

enemies::enemies(gameplay *scene) : _scene(scene){

}
