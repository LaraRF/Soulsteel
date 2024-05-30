//
// Created by sweet on 29.05.2024.
//

#ifndef RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H
#define RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H


#include <map>
#include "raylib.h"

class assestmanagergraphics {
public:
    static void init();
    static Texture2D getTexture(const char *name);
private:
    static bool m_texturesLoaded;
    static std::map<const char*, Texture2D> m_textures;
};


#endif //RAYLIBSTARTER_ASSESTMANAGERGRAPHICS_H
