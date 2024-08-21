//
// Created by lrfri on 21.08.2024.
//

#ifndef RAYLIBSTARTER_GAMECHOICESCREEN_H
#define RAYLIBSTARTER_GAMECHOICESCREEN_H
#include "scene.h"
#include "assestmanagergraphics.h"
#include <iostream>
#include "gameplay.h"
class gamechoicescreen: public scene {
public:
    gamechoicescreen(gameplay* existingGameplay) : scene(), gameplayInstance(existingGameplay) {
        std::cout << "Game choice screen created\n";
    }

    ~gamechoicescreen() {
        std::cout << "Game choice screen destroyed\n";
    }

    int cursor=0;

    void update() override;

    scene *evaluateSceneChange() override;

    void draw() override;

    void drawDebug() override;

    gameplay *gameplayInstance;

    Texture2D title = assestmanagergraphics::getTexture("userinterface/title_3");

    //creates the boxes that will be used as buttons; marked boxes are to create an outline that shows which button is selected
    Rectangle hitbox_newgame = {120, 330, 200, 90};
    Rectangle hitbox_newgame_marked = {110, 320, 220, 110};

    Rectangle hitbox_continue = {460, 330, 200, 90};
    Rectangle hitbox_continue_marked = {450, 320, 220, 110};
};


#endif //RAYLIBSTARTER_GAMECHOICESCREEN_H
