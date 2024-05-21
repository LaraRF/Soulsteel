//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_OPTIONEN_H
#define RAYLIBSTARTER_OPTIONEN_H

#include "raylib.h"
#include "globalstates.h"
#include <iostream>
#include "languagesettings.h"
#include "soundsettings.h"
#include "controlsettings.h"

class optionen {
public:
    int cursor=0;

    void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    //creates the boxes that will be used as buttons
    //the marked version is used to outline the button that is currently selected
    Rectangle hitbox_flagDE = {200, 340, 150, 90};
    Rectangle hitbox_flagDE_marked = {190, 330, 170, 110};

    Rectangle hitbox_flagENG = {600, 340, 150, 90};
    Rectangle hitbox_flagENG_marked = {590, 330, 170, 110};

    Rectangle hitbox_close = {770, 440, 150, 90};
    Rectangle hitbox_close_marked = {760, 430, 170, 110};

    Rectangle hitbox_tastatur ={200, 100,150,90};
    Rectangle hitbox_tastatur_marked={190, 90, 170, 110};

    Rectangle hitbox_controller ={600,100,150,90};
    Rectangle hitbox_controller_marked={590,90,170,110};

    Rectangle hitbox_soundless ={200, 220,150,90};
    Rectangle hitbox_soundless_marked ={190, 210,170,110};

    Rectangle hitbox_soundmore ={600,220, 150,90};
    Rectangle hitbox_soundmore_marked ={590, 210,170,110};


    //loads all the necessary textures

    Texture2D flagDE = LoadTexture("assets/graphics/flag_DE_5.png");
    Texture2D flagENG = LoadTexture("assets/graphics/flag_ENG_2.png");
    Texture2D closeButton = LoadTexture("assets/graphics/button_close.png");
    Texture2D tastaturbutton = LoadTexture("assets/graphics/tastatur.png");
    Texture2D controllerbutton = LoadTexture("assets/graphics/controller.png");
    Texture2D soundlessbutton = LoadTexture("assets/graphics/soundless.png");
    Texture2D soundmorebutton = LoadTexture("assets/graphics/soundmore.png");

};


#endif //RAYLIBSTARTER_OPTIONEN_H
