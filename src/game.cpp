#include "game.h"

void Game::initializer(){
    /*
        This function Initializes the window and prints the error if
        Initlization of SDL Goes Wrong

        Note use of Conditional Operators is used
    */

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL Could not be initialized, \nError"<< SDL_GetError()<< std::endl;
    }
    else{
        std::cout << "SDL initialized Successfully";
    }
}

void Game::make_window(const char * window_name){
    /* This function makes a window object named window and put's it's memory
        address inside the window pointer private variable we have declared
    */
    window = SDL_CreateWindow(window_name,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN // TO FORCE OPENGL as BackEnd in SDL
    );
    if (window == NULL) {
        std::cout << "Window Could not be initialized \nError " << SDL_GetError() << std::endl;
    }
    else{
        // Creation of a surface object..!
        //surface = make_surface();
        //SDL_FillRect(surface , NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ));
        //SDL_UpdateWindowSurface(window);
        std::cout << "Window is Initialized" << std::endl;
    }
}

void Game::event_handeling(){
    // event Object... note it's a event OBJECT and not a pointer
    SDL_Event event;
    bool quit = false;

    while(!quit){
        while(SDL_PollEvent(&event)){
            // event object's ENUM type is used..
            if(event.type == SDL_QUIT) quit = true;
        }
    }
}

SDL_Surface * Game::make_surface(){
    // Returns a surface object with white background..! over the window which is private
    // But in the scope of Game class
    SDL_Surface * surf= SDL_GetWindowSurface(window);
    return surf;
}


Game::Game(const char * name){
    /* CONSTRUCTOR
        initialization of window + surface + event Handeling
        Initializing SDL with OpenGL
    */

    initializer();
    make_window(name);
    //event_handeling();
}

Game::~Game(){
    /* Destructor
        Destorys the current window
        Deletes all surface objects as well as
        any data in memory is freed here
    */
    SDL_FreeSurface(surface);
    SDL_DestroyWindow( window );
    SDL_Quit();
}

SDL_Surface * Game::load_png_on_surface(const char * path_to_bmp){
    /*
        When an path is provided
        This function loads the bmp image and
        returns a surface object pointer after allocation
    */
    SDL_Surface * surf = NULL;
    surf = SDL_LoadBMP(path_to_bmp);
    if(surf == NULL){
        std::cout << "Error Loading the image " << path_to_bmp << "Error \n"<< SDL_GetError() << std::endl;
    }
    else{
        std::cout <<std::endl <<  "Image Loaded Successfully : " << path_to_bmp << std::endl;
        return surf;
    }
    return NULL;
}
Game::Game(){
    make_window("Event Handeling Bitch");
}
