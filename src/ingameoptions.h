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
    Rectangle hitbox_flagDE = {200, 310, 150, 70};
    Rectangle hitbox_flagDE_marked = {190, 300, 170, 90};

    Rectangle hitbox_flagENG = {600, 310, 150, 70};
    Rectangle hitbox_flagENG_marked = {590, 300, 170, 90};

    Rectangle hitbox_close = {790, 460, 150, 70};
    Rectangle hitbox_close_marked = {780, 450, 170, 90};

    Rectangle hitbox_tastatur ={200, 90,150,70};
    Rectangle hitbox_tastatur_marked={190, 80, 170, 90};

    Rectangle hitbox_controller ={600,90,150,70};
    Rectangle hitbox_controller_marked={590,80,170,90};

    Rectangle hitbox_soundless ={200, 200,150,70};
    Rectangle hitbox_soundless_marked ={190, 190,170,90};

    Rectangle hitbox_soundmore ={600,200, 150,70};
    Rectangle hitbox_soundmore_marked ={590, 190,170,90};

    Rectangle hitbox_guided ={200,420,150,70};
    Rectangle hitbox_guided_marked ={190,410,170,90};

    Rectangle hitbox_exploration ={600,420,150,70};
    Rectangle hitbox_exploration_marked ={590,410,170,90};



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
