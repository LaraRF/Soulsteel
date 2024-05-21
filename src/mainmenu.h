//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_MAINMENU_H
#define RAYLIBSTARTER_MAINMENU_H

#include "raylib.h"
#include "globalstates.h"
#include "languagesettings.h"
#include "controlsettings.h"
#include "soundsettings.h"

class mainmenu {
public:
    int cursor = 0;

    void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    //creates the boxes that will be used as buttons; marked boxes are to create an outline that shows which button is selected
    Rectangle hitbox_play = {100, 350, 150, 90};
    Rectangle hitbox_play_marked = {90, 340, 170, 110};

    Rectangle hitbox_settings = {400, 350, 150, 90};
    Rectangle hitbox_settings_marked = {390, 340, 170, 110};

    Rectangle hitbox_close = {700, 350, 150, 90};
    Rectangle hitbox_close_marked = {690, 340, 170, 110};

    //loads the necessary textures
    Texture2D title = LoadTexture("assets/graphics/title_3.png");
    Texture2D button1play = LoadTexture("assets/graphics/button_play.png");
    Texture2D button1settings = LoadTexture("assets/graphics/button_settings.png");
    Texture2D button1close = LoadTexture("assets/graphics/button_close.png");
};



#endif //RAYLIBSTARTER_MAINMENU_H
