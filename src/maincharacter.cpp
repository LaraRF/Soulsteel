//
// Created by lrfri on 20.05.2024.
//

#include "maincharacter.h"
#include "scene.h"

const float maincharacter::FRAME_DURATION = 0.1f;
const float maincharacter::DASH_ANIMATION_SPEED = 0.02f;

int maincharacter::attackPower = 2;

void maincharacter::attack(Enemy *target) {
    target->health -= Enemy::attackPower;

}

void calculateDamage(maincharacter &maincharacter, int damage) {
    maincharacter.health -= damage;
    if (maincharacter.health < 0) {
        maincharacter.health = 0;
    }
}

void maincharacter::collisionwall() {
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

void maincharacter::collisionenemies() {
    const std::vector<Enemy *> &enemies = _scene->getEnemies();

    for (int i = 0; i < enemies.size(); i++) {
        if (Collision::checkCollision(*this, *enemies[i])) {
            Rectangle enemyRect = enemies[i]->getCollisionRectangle();
            for (int j = 0; j < 4; j++) {
                Vector2 touchPoint = Vector2Clamp(position, {enemyRect.x, enemyRect.y},
                                                  {enemyRect.x + enemyRect.width, enemyRect.y + enemyRect.height});
                Vector2 pushForce = Vector2Subtract(position, touchPoint);
                float overlapDistance = size - Vector2Length(pushForce);
                if (overlapDistance <= 1) {
                    break;
                }
                pushForce = Vector2Normalize(pushForce);
                pushForce = Vector2Scale(pushForce, overlapDistance);
                position = Vector2Add(position, pushForce);
            }
        }
    }
}

void maincharacter::collisionbars() {
    if (!souldashactivated) {
        for (int i = 0; _scene->touchesBars(position, size) && i < 4; i++) {
            Rectangle touchedBars = _scene->getTouchedBars(position, size);
            Vector2 touchPoint = Vector2Clamp(position, {touchedBars.x, touchedBars.y},
                                              {touchedBars.x + touchedBars.width, touchedBars.y + touchedBars.height});
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
}

void maincharacter::collisionabyss() {
    if (_scene->touchesAbyss(position, size)) {
        if (currentmodus == robotmodus || (currentmodus == soulmodus && !souldashactivated)) {
            // Robot or non-dashing soul falls into abyss, soul using dash is fine
            //health--; // Lose one heart
            felldown = true;
            position = lastSafePosition; // Reset position

            //falling animation or something here

        }
    } else {
        updateLastSafePosition();
        felldown = false;
    }
}

void maincharacter::draw() {

    if (felldown) {
        DrawText("You fell into the abyss. You lost one life.", 10 * 15, 7 * 15, 20, RED);
    }
}

void maincharacter::drawsoul() {

    //draws current frame of soul animation
    Texture2D currentTexture = getCurrentTexture();

    DrawTextureRec(currentTexture, frameRec,
                   {position.x - frameRec.width / 2, position.y - frameRec.height / 2},
                   WHITE);

    if (souldustcanbeused()) {
        DrawText("Press L to use Soul Dust", position.x - 50, position.y - 40, 10, YELLOW);
    }

}

void maincharacter::drawrobot() {

    //DrawCircle(position.x, position.y, size,GRAY);
    DrawTexture(characterRobotTexture, position.x - 16, position.y - 32, WHITE);

}

//g
Rectangle maincharacter::getCollisionRectangle() const {
    return Rectangle{position.x - size / 2, position.y - size / 2, size, size};
}

Texture2D maincharacter::getCurrentTexture() {
    std::string state;
    switch (currentState) {
        case IDLE:
            state = "idle_";
            break;
        case WALKING:
            state = "walk_";
            break;
        case DASH:
            state = "dash_";
            break;
        case DUST:
            state = "dust_";
            break;
    }

    std::string direction;
    switch (currentDirection) {
        case BACK:
            direction = "back";
            break;
        case FRONT:
            direction = "front";
            break;
        case LEFT:
            direction = "left";
            break;
        case RIGHT:
            direction = "right";
            break;
    }

    return assestmanagergraphics::getTexture("characters/soul/" + state + direction);
}

int getHealth(const maincharacter &maincharacter) {
    return maincharacter.health;
}

maincharacter::maincharacter(gameplay *scene) : _scene(scene) {
    position = {32 * 12, 32 * 6};  // Set initial position
    currentState = IDLE;
    currentDirection = FRONT;
    currentFrame = 0;
    frameCounter = 0.0f;
    currentmodus = soulmodus;
    lookingdirection = south;

    // Set initial frame rectangle
    Texture2D currentTexture = getCurrentTexture();
    float frameWidth = static_cast<float>(currentTexture.width) / FRAME_COUNT;
    float frameHeight = static_cast<float>(currentTexture.height);
    frameRec = {0, 0, frameWidth, frameHeight};
}

void maincharacter::maincharacterwalking() {
    Vector2 movement = {0, 0};
    bool moved = false;

    if (IsKeyDown(KEY_S)) {
        movement.y = stepsize;
        lookingdirection = south;
        moved = true;
    }
    if (IsKeyDown(KEY_W)) {
        movement.y = -stepsize;
        lookingdirection = north;
        moved = true;
    }
    if (IsKeyDown(KEY_A)) {
        movement.x = -stepsize;
        lookingdirection = west;
        moved = true;
    }
    if (IsKeyDown(KEY_D)) {
        movement.x = stepsize;
        lookingdirection = east;
        moved = true;
    }

    if (moved) {
        Vector2 newPosition = {position.x + movement.x, position.y + movement.y};
        Vector2 currentTile = {std::floor(position.x / 32), std::floor(position.y / 32)};
        Vector2 newTile = {std::floor(newPosition.x / 32), std::floor(newPosition.y / 32)};

        bool canMove = true;
        if (_scene->touchesWall(newPosition, size) || _scene->isBlockAt(newTile) || _scene->isSwitchAt(newTile)) {
            canMove = false;
        } else if (currentTile.x != newTile.x || currentTile.y != newTile.y) {
            // Only check for stone collision if we're moving to a new tile
            if (_scene->touchesStone(newTile)) {
                if (currentmodus == robotmodus&& IsKeyDown(KEY_K)) {
                    Vector2 pushDirection = {newTile.x - currentTile.x, newTile.y - currentTile.y};
                    Stone* stone = _scene->getStoneAt(newTile);
                    if (stone != nullptr) {
                        //std::cout << "Attempting to push stone" << std::endl;
                        if (stone->tryMove(pushDirection)) {
                            //std::cout << "Stone pushed successfully" << std::endl;
                            // Move the character only if the stone was successfully pushed
                            position = newPosition;
                        } else {
                            //std::cout << "Failed to push stone" << std::endl;
                            canMove = false;
                        }
                    } else {
                        //std::cout << "Warning: Null stone detected at tile (" << newTile.x << ", " << newTile.y << ")" << std::endl;
                        canMove = false;
                    }
                } else {
                    //std::cout << "Cannot push stone in soul mode" << std::endl;
                    canMove = false;
                }
            } else {
                // If there's no stone, the character can move freely
                position = newPosition;
            }
        } else {
            // Moving within the same tile
            position = newPosition;
        }

        if (!canMove) {
            //std::cout << "Movement blocked" << std::endl;
        }
    }
}


void setAttackPower(int attack) {
    int attackPower = attack;
}

void maincharacter::souldash() {

    if (currentState != DASH) {
        // Start of new dash
        currentState = DASH;
        dashProgress = 0.0f;
        dashStartPosition = position;
        dashEndPosition = position;

        switch (lookingdirection) {
            case north:
                dashEndPosition.y -= DASH_DISTANCE;
                currentDirection = BACK;
                break;
            case east:
                dashEndPosition.x += DASH_DISTANCE;
                currentDirection = RIGHT;
                break;
            case south:
                dashEndPosition.y += DASH_DISTANCE;
                currentDirection = FRONT;
                break;
            case west:
                dashEndPosition.x -= DASH_DISTANCE;
                currentDirection = LEFT;
                break;
        }
    }

    dashProgress += DASH_ANIMATION_SPEED;
    currentFrame = static_cast<int>(dashProgress * DASH_FRAME_COUNT) % DASH_FRAME_COUNT;

    // Calculate new position
    Vector2 newPosition = Vector2Lerp(dashStartPosition, dashEndPosition, dashProgress);

    //checks wall collision
    if (!_scene->touchesWall(newPosition, size)) {
        position = newPosition;
    } else {
        currentState = IDLE;
        dashProgress = 1.0f; //ensures dah ends
    }


    /* Check if the new position is valid (not inside a wall)
    for (int i = 0; i <= stepsizesouldash; i++) {
        Vector2 checkPosition = Vector2Lerp(position, newPosition, (float)i / stepsizesouldash);
        if (_scene->touchesWall(checkPosition, size)) {
            // If we hit a wall, stop at the previous valid position
            newPosition = Vector2Lerp(position, newPosition, (float)(i-1) / stepsizesouldash);
            break;
        }
    }*/

    //position = newPosition;
    //updateDashAnimation(GetFrameTime());

    /*controlls speed of dash animation
    frameCounter += DASH_ANIMATION_SPEED;
    if (frameCounter >= 1.0f) {
        frameCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= FRAME_COUNT) {
            currentFrame = 0;
            currentState = IDLE;  // Ends dash after one full animation cycle
        }
    }*/
// Update the frame rectangle for drawing
    Texture2D currentTexture = getCurrentTexture();
    float frameWidth = static_cast<float>(currentTexture.width) / DASH_FRAME_COUNT;
    float frameHeight = static_cast<float>(currentTexture.height);
    frameRec = {currentFrame * frameWidth, 0, frameWidth, frameHeight};

    // End dash when animation completes
    if (dashProgress >= 1.0f) {
        currentState = IDLE;
    }
}

bool maincharacter::souldustcanbeused() const {
    return _scene->isAdjacentToFirebowl(position);
}

void maincharacter::souldust() {
    if (souldustcanbeused() && IsKeyPressed(KEY_L)) {
        auto [bowlX, bowlY] = _scene->getNearestFirebowlTile(position);
        if (bowlX != -1 && bowlY != -1 && !_scene->isFirebowlActivated(bowlX, bowlY)) {
            _scene->activateFirebowl(bowlX, bowlY);
        }
    }
}

void maincharacter::update() {
    Vector2 oldPosition = position;
    maincharacterwalking();

    //allows you to switch between soul and robot functions
    switch (currentmodus) {
        case soulmodus:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = robotmodus;
            }

            // soul dash
            if (IsKeyPressed(KEY_I) && currentState != DASH) {
                souldashactivated = true;
                souldash();
            } else if (currentState == DASH) {
                souldash();  // Continue the dash
            } else {
                souldashactivated = false;
            }
            //soul dust
            souldust();
            break;
        case robotmodus:
            //switch mode
            if (IsKeyPressed(KEY_SPACE)) {
                currentmodus = soulmodus;
            }
            if (IsKeyPressed(KEY_B)) {
                std::cout << "B key pressed in robot mode at position ("
                          << std::floor(position.x / 32) << ", " << std::floor(position.y / 32) << ")" << std::endl;
                if (_scene->isAdjacentToSwitch(position)) {
                    Vector2 characterTile = {std::floor(position.x / 32), std::floor(position.y / 32)};
                    _scene->toggleSwitchAt(characterTile);
                } else {
                    std::cout << "Not adjacent to any switch" << std::endl;
                }
            }

            //bomb throwing

            //space for more robot function
            break;
    }

    //checks if character is moving
    if (Vector2Equals(oldPosition, position) && currentState != DASH) {
        currentState = IDLE;
    } else if (currentState != DASH) {
        currentState = WALKING;
    }

    //update current direction based on movement
    if (IsKeyDown(KEY_W)) currentDirection = BACK;
    else if (IsKeyDown(KEY_S)) currentDirection = FRONT;
    else if (IsKeyDown(KEY_A)) currentDirection = LEFT;
    else if (IsKeyDown(KEY_D)) currentDirection = RIGHT;

//collisions
    collisionwall();
    collisionenemies();
    collisionbars();
    collisionabyss();
    updateLastSafePosition();

    //update animation
    //updateAnimation(GetFrameTime());
    //if (currentState == DASH) {
    // Dash animation is handled in souldash()
    //} else {
    updateAnimation(GetFrameTime());
    //}

}

void maincharacter::updateAnimation(float deltaTime) {
    frameCounter += deltaTime;
    if (frameCounter >= FRAME_DURATION) {
        frameCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= FRAME_COUNT) currentFrame = 0;
    }

    // Update frameRec based on current frame
    Texture2D currentTexture = getCurrentTexture();
    float frameWidth = static_cast<float>(currentTexture.width) / FRAME_COUNT;
    float frameHeight = static_cast<float>(currentTexture.height);
    frameRec = {currentFrame * frameWidth, 0, frameWidth, frameHeight};
}

void maincharacter::updateDashAnimation(float deltaTime) {
    frameCounter += deltaTime;
    if (frameCounter >= FRAME_DURATION) {
        frameCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= FRAME_COUNT) {
            currentFrame = 0;
            currentState = IDLE;  // End dash after one full animation cycle
        }
    }

    Texture2D currentTexture = getCurrentTexture();
    float frameWidth = static_cast<float>(currentTexture.width) / FRAME_COUNT;
    float frameHeight = static_cast<float>(currentTexture.height);
    frameRec = {currentFrame * frameWidth, 0, frameWidth, frameHeight};
}

void maincharacter::updateLastSafePosition() {
    if (!_scene->touchesAbyss(position, size)) {
        lastSafePosition = position;
    }
}


