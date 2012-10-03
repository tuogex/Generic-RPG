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

void axisMath();

void keyReg(SDL_Event event);

void drawMapFast(int offsetX, int offsetY, int **intMap );
void drawMapFast1(int offsetX, int offsetY, int **intMap );
void drawMap(int **intMap );

void HUD();

bool loginTest();

void logFile();

void movePlayer(SDL_Event event);

void playerLose( SDL_Event event );

void mapPicker();

void instructScreen(SDL_Event event);

int settings(int item);

void credits();
int intro();

void writeFile();

void items();

SDL_Surface *load_image( std::string filename );

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );

#endif
