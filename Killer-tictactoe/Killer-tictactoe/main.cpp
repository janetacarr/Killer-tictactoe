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
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
int main(int argc, const char * argv[])
{
    Window win = Window("Killer Tic Tac Toe");
    //Figure out way to load texture from project directory, rather than full directory.
    SDL_Texture* texture = win.LoadImage("/Users/justincarr/Killer-tictactoe/Killer-tictactoe/textures/grid.png");
    
    //Game loop;
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        //Event Polling.
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            //If user presses any key
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
        win.Clear();
        
        
        win.Draw(texture, NULL, NULL);
        win.Present();
    }
    win.~Window();
}


