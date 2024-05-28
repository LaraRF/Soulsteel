//
// Created by lrfri on 14.05.2024.
//
#include "gameplay.h"
#include "tileson.hpp"

void gameplay::update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates,
                      controlmodes &controlmodes,difficultylevel &difficultylevel) {
    //lets you switch between different screens
    if (IsKeyPressed(KEY_M)) {
        globalstates = menu;
    }
    if (IsKeyPressed(KEY_P)) {
        globalstates = pausieren;
    }
    if (IsKeyPressed(KEY_J)) {
        globalstates = hauptjournal;
    }
    if (IsKeyPressed(KEY_O)) {
        globalstates= ingameoptions;
    }
}

void gameplay::draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel) {
    ClearBackground(GRAY);

    //draws the map
    int tilesetCols = 1;
    int tileSize = 32;

    for (int y = 0; y < cols; y++){
        for (int x = 0; x < rows; x++){
            int data = tiles[y*rows + x];
            if (data < 0) continue;
            Rectangle src = {(float)(data % tilesetCols * tileSize), (float)(data / tilesetCols * tileSize), (float)(tileSize), (float)(tileSize)};
            Rectangle dest = {(float)(x * tileSize), (float)(y * tileSize), (float)(tileSize), (float)(tileSize)};
//hier kann man "static_cast<float>" durch (float) ersetzen -> ist C, aber geht hier auch
            DrawTexturePro(tilesetgrass, src, dest, {}, 0, WHITE);
        }
    }

    //draws text depending on chosen language
    switch (languagestates) {
        case german:
            DrawText("Drücke O, um zu den Optionen zu kommen.", 10, 350, 30, BLACK);
            DrawText("Drücke P, um das Spiel zu pausieren.", 10, 400, 30, BLACK);
            DrawText("Drücke M, um zurück zum Menü zu kommen.", 10, 450, 30, BLACK);
            DrawText("Drücke J, um das Journal zu öffnen.", 10, 500, 30, BLACK);
            break;
        case english:
            DrawText("Press O to go to options.", 10, 350, 30, BLACK);
            DrawText("Press P to pause the game.", 10, 400, 30, BLACK);
            DrawText("Press M to go back to the main menu.", 10, 450, 30, BLACK);
            DrawText("Press J to open the journal.", 10, 500, 30, BLACK);
            break;
    }

    DrawTexture(heart, 10, 10, WHITE);
    DrawTexture(heart, 100, 10, WHITE);
    DrawTexture(heart, 190, 10, WHITE);

    //DrawTexture(modeRobo, 800, 40, WHITE);
    //DrawTexture(modeSoul, 880, 40, WHITE);

    /*switch (languagestates) {
        case german:
            DrawText("Modus:", 840, 10, 20, BLACK);
            break;
        case english:
            DrawText("Mode:", 840, 10, 20, BLACK);
            break;
        default:
            break;
    }*/
}

//gets the data from the map needed to draw it
gameplay::gameplay() {
    tson::Tileson tileson;
    auto map = tileson.parse("assets/graphics/tilesets/grassmap_actualsize.tmj");
    if (map->getStatus() != tson::ParseStatus::OK) {
        std::cout << map->getStatusMessage();
    }
    auto layer = map->getLayer("Kachelebene 1");

    for (int y = 0; y < layer->getSize().y; y++) {
        for (int x = 0; x < layer->getSize().x; x++) {
            tiles.push_back(layer->getData()[y * layer->getSize().x + x]);
            tiles.back()--;
        }
    }
    rows = layer->getSize().x;
    cols = layer->getSize().y;
}
