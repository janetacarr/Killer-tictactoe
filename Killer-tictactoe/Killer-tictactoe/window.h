//
//  window.h
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#ifndef __Killer_tictactoe__window__
#define __Killer_tictactoe__window__

#include <iostream>
#include "SDL2/SDL.h"


class Window {
public:
    //Constructor
    Window(std::string, int width = 600, int height = 600);
    //Deconstructor
    ~Window();
    //Draw function just a wrapper around the SDL_RenderCopy
    void Draw(SDL_Texture* tex, SDL_Rect *srcRect, SDL_Rect *dstRect);
    //Clear function is a wrapper for RenderClear
    void Clear();
    //Present is also a wrapper for RenderPresent function
    void Present();
    //Box represents the current window size
    void Box();
    SDL_Texture* LoadImage(const std::string &file);
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Rect mBox;
};
#endif /* defined(__Killer_tictactoe__window__) */
