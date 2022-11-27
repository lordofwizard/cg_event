#include "image.h"

Image::Image(){
    SDL_Event event;
    bool quit = false;


    while(!quit){
        while(SDL_PollEvent(&event)){
            // event object's ENUM type is used..
            if(event.type == SDL_QUIT) quit = true;
            else if( event.type == SDL_KEYDOWN ){
                switch( event.key.keysym.sym )
                            {
                                case SDLK_UP:
                                cur_surf = up_surf;
                                std::cout << "Up Pressed" << std::endl;
                                break;

                                case SDLK_DOWN:
                                cur_surf = down_surf;
                                break;

                                case SDLK_LEFT:
                                cur_surf = left_surf;
                                break;

                                case SDLK_RIGHT:
                                cur_surf = right_surf;
                                break;

                                default:
                                cur_surf = up_surf;
                                break;
                            }
            }
        SDL_BlitSurface(cur_surf, NULL, surface, NULL);
        SDL_UpdateWindowSurface(window);
        }
    }
    //SDL_FreeSurface(cur_surf);
}
Image::~Image(){
    SDL_FreeSurface(up_surf);
    SDL_FreeSurface(right_surf);
    SDL_FreeSurface(left_surf);
    SDL_FreeSurface(down_surf);
    SDL_FreeSurface(cur_surf);

}
