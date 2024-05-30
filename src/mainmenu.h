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
#include "scene.h"
#include "assestmanagergraphics.h"

class mainmenu: public scene {
private:
    Texture2D buttonplay1 = assestmanagergraphics::getTexture("userinterface/button_play_1");
    Texture2D button1settings = assestmanagergraphics::getTexture("userinterface/button_settings");
    Texture2D button1close = assestmanagergraphics::getTexture("userinterface/button_close");
    Texture2D title = assestmanagergraphics::getTexture("userinterface/title_3");

public:

    int cursor = 0;

    mainmenu();

    void update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    void draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes);

    void update() override;

    scene *evaluateSceneChange() override;

    void draw() override;

    void drawDebug() override;

    //creates the boxes that will be used as buttons; marked boxes are to create an outline that shows which button is selected
    Rectangle hitbox_play = {90, 330, 150, 90};
    Rectangle hitbox_play_marked = {80, 320, 170, 110};

    Rectangle hitbox_settings = {325, 330, 150, 90};
    Rectangle hitbox_settings_marked = {315, 320, 170, 110};

    Rectangle hitbox_close = {560, 330, 150, 90};
    Rectangle hitbox_close_marked = {550, 320, 170, 110};

    //loads the necessary textures
   /* Texture2D title = LoadTexture("assets/graphics/title_3.png");
    Texture2D button1play = LoadTexture("assets/graphics/button_play.png");
    Texture2D button1settings = LoadTexture("assets/graphics/button_settings.png");
    Texture2D button1close = LoadTexture("assets/graphics/button_close.png");*/
};



#endif //RAYLIBSTARTER_MAINMENU_H
