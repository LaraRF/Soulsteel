//
// Created by sweet on 29.05.2024.
//

#ifndef RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H
#define RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H


#include <map>
#include "raylib.h"
#include <string>

class assestmanagergraphics {
public:
    static void init();
    static Texture2D getTexture(std::string name);
private:
    static bool m_texturesLoaded;
    static std::map<std::string, Texture2D> m_textures;
};


#endif //RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H
