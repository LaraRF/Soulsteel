//
// Created by sweet on 29.05.2024.
//
#include <iostream>
#include "assestmanagergraphics.h"

bool assestmanagergraphics::m_texturesLoaded = false;
std::map<std::string, Texture2D> assestmanagergraphics::m_textures;

void assestmanagergraphics::init() {
    if (m_texturesLoaded) {
        TraceLog(LOG_ERROR, "assetmanagergraphics::init() called more than once");
        return;
    }
    m_texturesLoaded = true;
    m_textures["ERROR"] = LoadTexture("assets/graphics/ERROR.png");
    m_textures["tilesets/level1"] = LoadTexture("assets/graphics/tilesets/tilesets/level1.png");
    //placeholder menu
    m_textures["background/background_blue"] = LoadTexture("assets/graphics/backgrounds/background_blue.png");
    m_textures["userinterface/button_close"] = LoadTexture("assets/graphics/userinterface/button_close.png");
    m_textures["userinterface/button_pause"] = LoadTexture("assets/graphics/userinterface/button_pause.png");
    m_textures["userinterface/button_play"] = LoadTexture("assets/graphics/userinterface/button_play.png");
    m_textures["userinterface/button_play_1"] = LoadTexture("assets/graphics/userinterface/button_play_1.png");
    m_textures["userinterface/button_settings"] = LoadTexture("assets/graphics/userinterface/button_settings.png");
    m_textures["userinterface/controller"] = LoadTexture("assets/graphics/userinterface/controller.png");
    m_textures["userinterface/flag_DE_5"] = LoadTexture("assets/graphics/userinterface/flag_DE_5.png");
    m_textures["userinterface/flag_ENG_2"] = LoadTexture("assets/graphics/userinterface/flag_ENG_2.png");
    m_textures["userinterface/grasses"] = LoadTexture("assets/graphics/userinterface/grasses.png");
    m_textures["tilesets/grassesfour"] = LoadTexture("assets/graphics/tilesets/grassesfour.png");
    m_textures["tilesets/greyboxing1"] = LoadTexture("assets/graphics/tilesets/tileset_greyboxing_room1.png");
    m_textures["userinterface/heart"] = LoadTexture("assets/graphics/userinterface/heart.png");
    m_textures["userinterface/heart_smaller"] = LoadTexture("assets/graphics/userinterface/heart_smaller.png");
    m_textures["userinterface/journal_background"] = LoadTexture("assets/graphics/userinterface/journal_background.png");
    m_textures["userinterface/journal_background_newsize"] = LoadTexture("assets/graphics/userinterface/journal_background_newsize.png");
    m_textures["userinterface/robot_anuki_3"] = LoadTexture("assets/graphics/userinterface/robot_anuki_3.png");
    m_textures["userinterface/soul_destiny_3"] = LoadTexture("assets/graphics/userinterface/soul_destiny_3.png");
    m_textures["userinterface/soundless"] = LoadTexture("assets/graphics/userinterface/soundless.png");
    m_textures["userinterface/soundmore"] = LoadTexture("assets/graphics/userinterface/soundmore.png");
    m_textures["userinterface/tastatur"] = LoadTexture("assets/graphics/userinterface/tastatur.png");
    m_textures["userinterface/testimage"] = LoadTexture("assets/graphics/userinterface/testimage.png");
    m_textures["userinterface/tile_pink"] = LoadTexture("assets/graphics/userinterface/tile_pink.png");
    m_textures["userinterface/title_3"] = LoadTexture("assets/graphics/userinterface/title_3.png");
    m_textures["userinterface/title_4"] = LoadTexture("assets/graphics/userinterface/title_4.png");
    //placeholder character
    m_textures["characters/soul/Soul_front"] = LoadTexture("assets/graphics/characters/soul/Soul_front.png");
    m_textures["characters/robot/Robot_front"] = LoadTexture("assets/graphics/characters/robot/Robot_front.png");
    //enemies
    m_textures["characters/enemies/enemy_1"] = LoadTexture("assets/graphics/characters/enemies/enemy_1.png");
    m_textures["characters/enemies/enemy_2"] = LoadTexture("assets/graphics/characters/enemies/enemy_2.png");

    for (auto &texture: m_textures) {
        if (!IsTextureReady(texture.second)) {
            TraceLog(LOG_WARNING, "assetmanagergraphics::init() failed to load texture: %s", texture.first.c_str());
        }
    }
}

Texture2D assestmanagergraphics::getTexture(std::string name) { //call this texture on consturction of a new object,
    //not every frame, check if the texture exists in map
    if (m_textures.find(name) != m_textures.end()) {
        return m_textures[name];
}
    TraceLog(LOG_WARNING, "assetmanagergraphics::getTexture() called with unknown texture name: %s", name.c_str());
    return m_textures["ERROR"];

}