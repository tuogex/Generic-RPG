#include <SDL/SDL.h>

#include "headers/globals.h"
#include "headers/windowEvents.h"

Window::Window()
{
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE );

    if( screen == NULL ) {
        windowOk = false;
        return;
    } else {
        windowOk = true;
    }

    windowed = true;
}

void Window::toggle_fullscreen() {

    if( windowed ) {
        screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE | SDL_FULLSCREEN );
    }

}
