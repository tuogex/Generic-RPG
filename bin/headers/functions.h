#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL\SDL.h>
#include <string>

void init();

void uninit();

void fpsCalc();

bool settingsFile();

void logFile();

void load_files();

int axisMath();

void imageMapRender();

void keyReg(SDL_Event event);

void drawMapFast(int offsetX, int offsetY, int **intMap );
void drawMapFast1(int offsetX, int offsetY, int **intMap );
void drawMap(int **intMap );

void HUD();

void movePlayer(SDL_Event event);

void playerLose( SDL_Event event );

void mapPicker();

void items();

SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

#endif
