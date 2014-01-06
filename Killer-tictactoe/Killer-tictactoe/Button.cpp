//
//  Button.cpp
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "Button.h"

Button::Button() {
    rendered = false;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = 0;
    dstRect.h = 0;
    texWidth = 0;
    texHeight = 0;
    buttonWidth = 200;
    buttonHeight = 200;
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
    dstRect.x = x;
    dstRect.y = y;
}

void Button::handleEvent(SDL_Event* e) {
    //if mouse event happened
    if (e->type == SDL_MOUSEBUTTONDOWN) {
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
        } else if (y > Position.y + buttonHeight) {
            inside = false;
        }
        
        if (!inside) {
            return;
        }
        //Mouse is inside button
        else {
            if (e->type == SDL_MOUSEBUTTONDOWN) {
                if (player == 1) {
                    if (!rendered) {
                        currentSprite = BUTTON_O;
                        player = 2;
                        rendered = true;
                        return;
                    }
                } else {
                    if (!rendered) {
                        currentSprite = BUTTON_X;
                        player = 1;
                        rendered = true;
                        return;
                    }
                }
            }
        }
    }
}
void Button::render(SDL_Renderer* ren) {
    if (currentSprite == BUTTON_O) {
        SDL_Surface* surf = IMG_Load("/Users/justincarr/Killer-tictactoe/Killer-tictactoe/textures/o.png");
        texture = SDL_CreateTextureFromSurface(ren, surf);
        SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
        SDL_RenderCopy(ren, texture, NULL, &dstRect);
        SDL_FreeSurface(surf);
        rendered = true;
        return;
    } else if(currentSprite == BUTTON_X){
        SDL_Surface* surf = IMG_Load("/Users/justincarr/Killer-tictactoe/Killer-tictactoe/textures/x.png");
        texture = SDL_CreateTextureFromSurface(ren, surf);
        SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
        SDL_RenderCopy(ren, texture, NULL, &dstRect);
        SDL_FreeSurface(surf);
        rendered = true;
        return;
    }
}