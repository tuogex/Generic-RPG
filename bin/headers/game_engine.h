//GAME_ENGINE.H
#include <SDL/SDL.h>

#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

class Actor {
private:
    int x, y;

    int portalX, portalY;

public:
    Actor();
    ~Actor();
    void move(int dx, int dy);
    void moveMob( int type, SDL_Rect& zomb, unsigned int& RespawnTimer, bool& ifDead, unsigned int& mobHealth, SDL_Surface *mobHealthShow, bool& ifXp, SDL_Surface *zombSurf, int respawnX, int respawnY );
    bool zombHitDetect( int type, int x, int y, SDL_Rect locate);
    void slashTime();
    void mobs();
    void getLastHeroCord();
    void getMobCoord();
    void keyReg(SDL_Event event);
    void showHero();
    void miscMapItems();
};

void saveGame(int location);
void loadSave(int location);

#endif
