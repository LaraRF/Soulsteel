//
// Created by lrfri on 28.05.2024.
//

#ifndef RAYLIBSTARTER_INGAMEOPTIONS_H
#define RAYLIBSTARTER_INGAMEOPTIONS_H

#include "raylib.h"
#include "globalstates.h"
#include <iostream>
#include "languagesettings.h"
#include "soundsettings.h"
#include "controlsettings.h"
#include "difficultysettings.h"

class ingameoptions {
public:
    int cursor=0;

    void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel);

    void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel);

    //creates the boxes that will be used as buttons
    //the marked version is used to outline the button that is currently selected
    Rectangle hitbox_flagDE = {50, 270, 150, 70};
    Rectangle hitbox_flagDE_marked = {40, 260, 170, 90};

    Rectangle hitbox_flagENG = {450, 270, 150, 70};
    Rectangle hitbox_flagENG_marked = {440, 260, 170, 90};

    Rectangle hitbox_close = {640, 360, 150, 70};
    Rectangle hitbox_close_marked = {630, 350, 170, 90};

    Rectangle hitbox_tastatur ={50, 90,150,70};
    Rectangle hitbox_tastatur_marked={40, 80, 170, 90};

    Rectangle hitbox_controller ={450,90,150,70};
    Rectangle hitbox_controller_marked={440,80,170,90};

    Rectangle hitbox_soundless ={50, 180,150,70};
    Rectangle hitbox_soundless_marked ={40, 170,170,90};

    Rectangle hitbox_soundmore ={450,180, 150,70};
    Rectangle hitbox_soundmore_marked ={440, 170,170,90};

    Rectangle hitbox_guided ={50,360,150,70};
    Rectangle hitbox_guided_marked ={40,350,170,90};

    Rectangle hitbox_exploration ={450,360,150,70};
    Rectangle hitbox_exploration_marked ={440,350,170,90};



    //loads all the necessary textures

    Texture2D flagDE = LoadTexture("assets/graphics/flag_DE_5.png");
    Texture2D flagENG = LoadTexture("assets/graphics/flag_ENG_2.png");
    Texture2D closeButton = LoadTexture("assets/graphics/button_close.png");
    Texture2D tastaturbutton = LoadTexture("assets/graphics/tastatur.png");
    Texture2D controllerbutton = LoadTexture("assets/graphics/controller.png");
    Texture2D soundlessbutton = LoadTexture("assets/graphics/soundless.png");
    Texture2D soundmorebutton = LoadTexture("assets/graphics/soundmore.png");

};


#endif //RAYLIBSTARTER_INGAMEOPTIONS_H
