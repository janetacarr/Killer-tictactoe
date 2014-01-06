//
//  main.cpp
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//
/**
 *@authur Justin A. Carr
 */
#include <iostream>
#include "window.h"
#include "Button.h"
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
Button buttons[9];
void initButtons() {
    buttons[0] = Button();
    buttons[0].setPosition(0, 0);
    
    buttons[1] = Button();
    buttons[1].setPosition(200, 0);
    
    buttons[2] = Button();
    buttons[2].setPosition(400, 0);
    
    buttons[3] = Button();
    buttons[3].setPosition(0, 200);
    
    buttons[4] = Button();
    buttons[4].setPosition(200, 200);
    
    buttons[5] = Button();
    buttons[5].setPosition(400, 200);
    
    buttons[6] = Button();
    buttons[6].setPosition(0, 400);
    
    buttons[7] = Button();
    buttons[7].setPosition(200, 400);
    
    buttons[8] = Button();
    buttons[8].setPosition(400, 400);
}

bool checkWinner() {
    
}
int main(int argc, const char * argv[])
{
    Window win = Window("Killer Tic Tac Toe");
    //Figure out way to load texture from project directory, rather than full directory.
    SDL_Texture* texture = win.LoadImage("/Users/justincarr/Killer-tictactoe/Killer-tictactoe/textures/grid.png");
    initButtons();

    //Game loop;

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        //Event Polling.
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            
            for (int i = 0; i < 9; i++) {
                buttons[i].handleEvent(&e);
            }
            //if the user presses anykey
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
            }
        }
        //Clear renderer
        //win.Clear();
        //Draw background
        win.Draw(texture, NULL, NULL);
        //Render all clicked button textures
        
        for (int i = 0; i < 9; i++) {
            buttons[i].render(win.getRenderer());
        }
        
        //Bring everything in the back to the front.
        win.Present();
    }
    win.~Window();
}


