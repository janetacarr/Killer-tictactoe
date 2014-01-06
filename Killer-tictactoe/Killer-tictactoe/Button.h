//
//  Button.h
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Killer_tictactoe__Button__
#define __Killer_tictactoe__Button__

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
//Needed static constant to manage O or X states across buttons
static int player = 1;

enum buttonSprite {
    BUTTON_BLANK = 0,
    BUTTON_X = 1,
    BUTTON_O = 2
};

class Button {
public:
    //Constructor
    Button();
    //Deconstructor
    ~Button();
    
    void setPosition(int x, int y);
    //Handle mouse button click event on the button
    void handleEvent(SDL_Event* e);
    //Render's button state in the form of texture in the background, so Window's present method can push it to the front.
    void render(SDL_Renderer* ren);
    //Self explanatory, only to be either 1 or 2
    //void setPlayer(int in);
    buttonSprite getCurrentSprite();
private:
    bool rendered;
    //The button's destination on the renderer
    SDL_Rect dstRect;
    //Button texture width and height
    int texWidth, texHeight;
    
    int buttonWidth, buttonHeight;
    //Player states, either 1 or 2.
    //int player;
    //Coordinates the button, the upper left hand corner
    SDL_Point Position;
    //Buttn texture. Initially blank/null.
    SDL_Texture* texture;
    
    buttonSprite currentSprite;
};
#endif /* defined(__Killer_tictactoe__Button__) */
