//
// Created by lrfri on 14.05.2024.
//
#include "journal.h"
#include "globalstates.h"
#include "raylib.h"
#include "languagesettings.h"

void journal::update(globalstates &globalstates, languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel) {

    //navigating the journal by using arrow keys
    if(IsKeyPressed(KEY_D)|| IsKeyPressed(KEY_RIGHT)){
        if(cursor == 2){
            cursor = 2; //ends with last box, does not come back on the other side of the screen
        }else{
            cursor++;
        }
    }

    if(IsKeyPressed(KEY_A)|| IsKeyPressed(KEY_LEFT)){
        if(cursor == 0){
            cursor = 0; //same here: you can't go more the side if you're already on the last box
        }else{
            cursor--;
        }
    }

    //gives the buttons their functions
    if(IsKeyPressed(KEY_ENTER)) {
        switch(cursor){
            case 0:
                //no journal content yet
                break;
            case 1:
                //no journal content yet
                break;
            case 2:
                globalstates = gameplayscreen;
        }
    }
    //pressing J gets you back to the game play screen
    if(IsKeyPressed(KEY_J)){
        globalstates=gameplayscreen;
    }
}

void journal::draw(languagestates &languagestates, soundstates &soundstates, controlmodes &controlmodes,difficultylevel &difficultylevel) {

    DrawTexture(journalbackground, 5,5,WHITE);

    switch(cursor){ //shows which box is selected by giving it a white outline
        case 0:
            DrawRectangleRec(journalpage1_marked, WHITE);
            break;
        case 1:
            DrawRectangleRec(journalpage2_marked, WHITE);
            break;
        case 2:
            DrawRectangleRec(hitbox_close_marked, WHITE);
            break;
        default:
            break;
    }


    DrawRectangleRec(journalpage1, GRAY);
    DrawRectangleRec(journalpage2, GRAY);
    DrawRectangleRec(hitbox_close, GRAY);

    DrawTexture(closeButton, 825,450,WHITE);

    //shows the text depending on which language is chosen
    switch(languagestates) {
        case german:
            DrawText("Journal Inhalt TBD", 50, 15, 30, BLACK);
            DrawText("Journal Inhalt TBD", 575, 15, 30, BLACK);
            DrawText("Hier wird es mal ein Journal\nmit verschiedenen\nSeiten geben.", 60, 200, 20, BLACK);
            DrawText("Aktuell passiert\nauf diesen beiden\nSeiten noch nichts.", 610, 200, 20, BLACK);


            break;
        case english:
            DrawText("Journal content TBD", 45, 15, 30, BLACK);
            DrawText("Journal content TBD", 570, 15, 30, BLACK);
            DrawText("Eventually here\nwill be a journal\nwith different pages.", 60, 200, 20, BLACK);
            DrawText("At this time\nnothing happens on\nthese two pages.", 610, 200, 20, BLACK);
            break;
        default:
            break;
    }
}
