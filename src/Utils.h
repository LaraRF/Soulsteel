//
// Created by sadeh on 10.07.2024.
//

#ifndef RAYLIBSTARTER_UTILS_H
#define RAYLIBSTARTER_UTILS_H

#include "maincharacter.h"
#include "ENEMIES/Enemy.h"
#include "Wall.h"

bool checkCollision(const maincharacter& maincharacter, const Enemy& enemy);
bool checkCollision(const maincharacter& maincharacter, const Wall& wall);

#endif //RAYLIBSTARTER_UTILS_H
