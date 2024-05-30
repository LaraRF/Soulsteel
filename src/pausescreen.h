//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_PAUSESCREEN_H
#define RAYLIBSTARTER_PAUSESCREEN_H

#include "raylib.h"
#include "globalstates.h"
#include "languagesettings.h"
#include "controlsettings.h"
#include "soundsettings.h"
#include <iostream>
#include "assestmanagergraphics.h"
#include "scene.h"

class pausescreen:public scene {
private:
    //Texture2D pausebutton = assestmanagergraphics::getTexture("userinterface/button_pause");


public:
    void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    //loads the necessary textures
    Texture2D pausebutton = assestmanagergraphics::getTexture("userinterface/button_pause");
    Texture2D title = assestmanagergraphics::getTexture("userinterface/title_3");

    //creates the box that will be used as a button
    Rectangle boxforpausebutton = {339,340,122,122};
};
#endif //RAYLIBSTARTER_PAUSESCREEN_H
