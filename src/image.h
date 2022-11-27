#pragma once
#include <iostream>
#include "game.h"

class Image : public Game{
    enum state{
        UP,
        Down,
        Left,
        Right
    };
    SDL_Surface * cur_surf = NULL;
    SDL_Surface * up_surf = load_png_on_surface("assets/up.bmp");
    SDL_Surface * down_surf = load_png_on_surface("assets/down.bmp");
    SDL_Surface * left_surf = load_png_on_surface("assets/left.bmp");
    SDL_Surface * right_surf = load_png_on_surface("assets/right.bmp");

public:
    Image();

    ~Image();
};
