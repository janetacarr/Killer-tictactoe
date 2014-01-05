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
    SDL_Texture* texture = win.LoadImage("/Users/justincarr/grid.png");
    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = 600;
    dstRect.h = 600;
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
        
        
        win.Draw(texture, NULL, dstRect);
        win.Present();
    }
    win.~Window();
}


