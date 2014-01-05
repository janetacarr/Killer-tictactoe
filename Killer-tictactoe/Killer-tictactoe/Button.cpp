//
//  Button.cpp
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "Button.h"

Button::Button() {
    texWidth = 0;
    texHeight = 0;
    buttonWidth = 200;
    buttonHeight = 200;
    player = 1;
    Position.x = 0;
    Position.y = 0;
    texture = NULL;
    currentSprite = BUTTON_BLANK;
}

Button::~Button() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
    
}
void Button::setPosition(int x, int y) {
    Position.x = x;
    Position.y = y;
}

void Button::handleEvent(SDL_Event* e) {
    //if mouse event happened
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        //Get the mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);
        
        //Check if mouse is in button
        bool inside = true;
        
        //Mouse is left the button
        if (x < Position.x) {
            inside = false;
        } else if (x > Position.x + buttonWidth) {
            inside = false;
        } else if ( y < Position.y) {
            inside = false;
        } else if (y < Position.y + buttonHeight) {
            inside = false;
        }
        
        if (!inside) {
            currentSprite = BUTTON_BLANK;
        }
        //Mouse is inside button
        else {
            if (e->type == SDL_MOUSEBUTTONDOWN) {
                if (player == 1) {
                    currentSprite = BUTTON_O;
                } else {
                    currentSprite = BUTTON_X;
                }
            }
        }
    }
}