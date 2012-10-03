#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H

#include <string>
#include <SDL\SDL.h>

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
SDL_Surface *load_image(std::string filename);

#endif
