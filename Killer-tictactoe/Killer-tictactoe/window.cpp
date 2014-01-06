//
//  window.cpp
//  Killer-tictactoe
//
//  Created by Justin Carr on 2014-01-04.
//  Copyright (c) 2014 Justin Carr. All rights reserved.
//

#include "window.h"
#include "SDL2_image/SDL_image.h"
#include "SDL2_ttf/SDL_ttf.h"

Window::Window(std::string title, int width , int height) {
    //Initialize SDL sub systems
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        throw std::runtime_error("SDL init failed");
    }
    if (TTF_Init() == -1) {
        throw std::runtime_error("TTR init failed");
    }
    
    //Setup our window size
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = width;
    mBox.h = height;
    //Create the window
    mWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN);
    //Make sure it was created alright
    if (mWindow == nullptr) {
        throw std::runtime_error("Failed to create window");
    }
    //Create the renderer
    mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (mRenderer == nullptr) {
        throw std::runtime_error("Failed to create renderer.");
    }
    
}
Window::~Window() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    IMG_Quit();
    SDL_Quit();
}
SDL_Texture* Window::LoadImage(const std::string &file) {
    SDL_Texture *tex = nullptr;
    tex = IMG_LoadTexture(mRenderer, file.c_str());
    if (tex == nullptr) {
        throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
    }
    return tex;
}
SDL_Renderer* Window::getRenderer() {
    return mRenderer;
}
//Broken, Reneders full texture to full renderer.
void Window::Draw(SDL_Texture* tex, SDL_Rect *srcRect, SDL_Rect *dstRect) {
    
    if (dstRect == nullptr) {
        SDL_RenderCopy(mRenderer, tex, NULL, NULL);
    } else 
        SDL_RenderCopy(mRenderer, tex, NULL, dstRect);
}
void Window::Clear() {
    SDL_RenderClear(mRenderer);
}
void Window::Present() {
    SDL_RenderPresent(mRenderer);
}

