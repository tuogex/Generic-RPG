#include <string>
#include <sstream>
#include <math.h>
#include <fstream>
#include <stdio.h>
using namespace std;
#include "headers/game_engine.h"
#include "headers/globals.h"
#include "headers/SDL_functions.h"

void loadChars() {
    for( int j = 0; j < skelAmt; j++ ) {
        skelSurf[j] = load_image("images/RPG Sprites/skel/front.png");
        skelRect[j].w = 100;
        skelRect[j].h = 126;
    }
    for( int yy = 0; yy < ghostAmt; yy++ ) {
        ghostSurf[yy] = load_image("images/RPG Sprites/ghost/front.png");
        ghostRect[yy].w = 100;
        ghostRect[yy].h = 126;

        ghostHealth[yy] = 350;
    }


    for( int u = 0; u < zombAmt; u++ ) {
        zombHealth[u] = 500;
    }

    for( int y = 0; y < skelAmt; y++ ) {
        skelHealth[y] = 250;
    }


    for( int i = 0; i < zombAmt; i++ ) {
        zombSurf[i] = load_image("images/RPG Sprites/zombie/front.png");
        zombRect[i].w = 100;
        zombRect[i].h = 126;
    }
}

Actor::Actor() {
    hero.getLastHeroCord();
    float x = heroR.x;
    float y = heroR.y;
}

Actor::~Actor() {}

void Actor::miscMapItems() {

    portalX = ( (SCREEN_WIDTH /2 ) - 75) - mapOffsetXAmt;
    portalY = ((SCREEN_HEIGHT/2) - 75 ) - mapOffsetYAmt;

    bool levelOver = false;

    if( ( mapLevel == 4 ) && boss1Dead ) {
        levelOver = true;
    }

    if(mapLevel != 4 ) {
        if( totalEnemyKills > (mapLevel * 20) ) levelOver = true;
    }

    if( levelOver ) {


        apply_surface ( portalX, portalY, portalSurf, screen );


        //zombAmt = 5 + (mapLevel * 3);
        //skelAmt = 8 + (mapLevel * 2);
        //ghostAmt = 3 + (mapLevel * 2);

        //if( endLevelOnce ) {loadChars(); endLevelOnce = false; };

        levelOver = false;

        ifPortal = true;

        if( ( heroR.x >  portalX - 50 ) && ( heroR.x + heroR.w < portalX + 200 ) && wantPortal ) {

            if( ( heroR.y > portalY - 50 ) && ( heroR.y + heroR.h < portalY + 200 ) ) {
                mapLevel += 1;

                mapOffsetXAmt = 0;
                mapOffsetYAmt = 0;

                x = ( SCREEN_WIDTH / 2 ) - 50;
                y = (SCREEN_HEIGHT / 2) - 67;

                if( mapLevel == 2 ) {
                    water = load_image("images/other/level2/water.png");
                    grass = load_image("images/other/level2/grass.png");
                    road = load_image("images/other/level2/concrete.png");
                }

                if( mapLevel == 3 ) {
                    water = load_image("images/other/level3/water.png");
                    grass = load_image("images/other/level3/grass.png");
                    road = load_image("images/other/level3/concrete.png");
                }

                if( mapLevel == 4 ) {
                    water = load_image("images/other/level4/water.png");
                    grass = load_image("images/other/level4/grass.png");
                    road = load_image("images/other/level4/concrete.png");
                }

                for( int j = 0; j < zombAmt; j++ ) {
        zombRect[j].x = rand() % (480 + 240) + 800;
        zombRect[j].y = rand() % (317 + 240) + 600;
    }

    for( int t = 0; t < zombAmt; t++ ) {
        zombOffsetX[t] = -1000;
        zombOffsetY[t] = -1000;
    }

    for( int q = 0; q < skelAmt; q++ ) {
        skelRect[q].x = rand() % (480 + 240) - 800;
        skelRect[q].y = rand() % (317 + 240) - 600;
    }

    for( int w = 0; w < skelAmt; w++ ) {
        skelOffsetX[w] = 800;
        skelOffsetY[w] = 600;
    }

    for( int gh = 0; gh < ghostAmt; gh++ ) {
        ghostRect[gh].x = rand() % (600 + 200) + 800;
        ghostRect[gh].y = rand() % (360 + 200) - 600;

        ghostOffsetX[gh] = 1000;
        ghostOffsetY[gh] = -1000;
    }
            }

        }

    devPortalSkip = false;

    } else {
        ifPortal = false;
        endLevelOnce = true;
    }

}


void Actor::slashTime() {
    if( SDL_GetTicks() - attackTime > 100 ) {
        playerSlash = false;
    }
}

void Actor::getLastHeroCord() {
    ifstream xcord;
    ifstream ycord;

    switch(gameSaveInt) {
        case 1:
            xcord.open("saves/gameOne/player/PSLX");
            ycord.open("saves/gameOne/player/PSLY");
            break;

        case 2:
            xcord.open("saves/gameTwo/player/PSLX");
            ycord.open("saves/gameTwo/player/PSLY");
            break;

        case 3:
            xcord.open("saves/gameThree/player/PSLX");
            ycord.open("saves/gameThree/player/PSLY");
            break;

    }

    xcord >> x;
    xcord >> heroR.x;
    ycord >> y;
    ycord >> heroR.y;
}

void Actor::showHero() {

        switch( charPos ) {
        case 1:/*
            if( ( totalGameTime.get_ticks() - heroUpdateTime < 500 ) && keyDown ) {
                if(!playerSlash) apply_surface( x, y, heroFront, screen );s
                else apply_surface(x, y, heroSlashFront, screen );
            } else if( keyDown ) {
                apply_surface(x, y, heroAnimateTest, screen);
                if( totalGameTime.get_ticks() - heroUpdateTime > 1000 ) {
                    heroUpdateTime = totalGameTime.get_ticks();
                }
            } else if( !keyDown ) {
                apply_surface(x, y, heroFront, screen );
            }*/
            if(!playerSlash) apply_surface( x, y, heroFront, screen );
            else apply_surface(x, y, heroSlashFront, screen );

            break;
        case 2:
            if(!playerSlash) apply_surface( x, y, heroBack, screen );
            else apply_surface(x, y, heroSlashBack, screen );
            break;
        case 3:
            if( !playerSlash ) apply_surface( x, y, heroLeft, screen );
            else apply_surface( x - 24, y, heroSlashLeft, screen );
            break;
        case 4:
            if( !playerSlash ) apply_surface( x, y, heroRight, screen );
            else apply_surface( x, y, heroSlashRight, screen );
            break;
    }
/*
    apply_surface(heroR.x - 20, heroR.y - 6, load_image("Images/Other/magicaAttackDrop/1.png"), screen);
        apply_surface(heroR.x - 70, heroR.y - 56, load_image("Images/Other/magicaAttackDrop/2.png"), screen);
            apply_surface(heroR.x - 105, heroR.y - 86, load_image("Images/Other/magicaAttackDrop/3.png"), screen);
*/
    int i;

    if( magicaAttackDropTimer.get_ticks() > 1 ) i = 1;
    if( magicaAttackDropTimer.get_ticks() > 100 ) i = 2;
    if( magicaAttackDropTimer.get_ticks() > 200 ) i = 3;
    if( magicaAttackDropTimer.get_ticks() > 300 ) { i = 0; magicaAttackDropTimer.pause(); }

    std::stringstream magicaAttackDropSS;
    magicaAttackDropSS << "Images/Other/magicaAttackDrop/" << i << ".png";
    std::string j;
    magicaAttackDropSS >> j;
    apply_surface(heroR.x - (20 + ((i-1)*45)), heroR.y - (6 + (40 * (i-1))), load_image(j.c_str()), screen);
}



void Actor::move(int dx, int dy) {

    //if( heroTileType == 0 ) {
        //x += ( dx + dx );
        //y += ( dy + dy );
    //} else if( heroTileType == 1 ) {
        //x += ( dx * 3 );
        //y += ( dy * 3 );
    //} else if( heroTileType == 2 ) {
        //x += dx;
        //y += dy;

    int preX = x;
    int preY = y;

    x += dx * 2;
    y += dy * 2;

    //top
    for( int ts = 1; ts <= 8; ts++ ) {
        if(wallDetectArr[((mapOffsetXAmt+(x + (10*ts) + 10)) + 800)/16][((mapOffsetYAmt+(y - 8)) + 600)/16] == 3) {
            //y -= dy * 2;
            y = preY;
        }
    }

    //bottom
    for( int bs = 1; bs <= 8; bs++ ) {
        if(wallDetectArr[((mapOffsetXAmt+(x + (10*bs) + 10)) + 800)/16][((mapOffsetYAmt+(y + heroR.h)) + 600)/16] == 3) {
            //y -= dy * 2;
            y = preY;
        }
    }

    //left side
    for(int ls = 1; ls <= 9; ls++ ) {
        if(wallDetectArr[((mapOffsetXAmt+(x + 15)) + 800)/16][((mapOffsetYAmt+(y + (14 * ls))) + 600)/16] == 3) {
            //x -= dx * 2;
            x = preX;
        }
    }

    //right side
    for(int rs = 1; rs <= 9; rs++ ) {
        if(wallDetectArr[((mapOffsetXAmt+((x + heroR.w) - 15)) + 800)/16][((mapOffsetYAmt+(y + (rs * 14))) + 600)/16] == 3) {
            //x -= dx * 2;
            x = preX;
        }
    }


    if(!heroSpawn) {
        x = (SCREEN_WIDTH/2) - 63;
        y = (SCREEN_HEIGHT/2) - 63;
        heroSpawn = true;
    }

    if( heroTele && ( heroMagica >= 60 ) ) {
        x = rand() % 800 - 0;
        y = rand() % 600 - 0;
        heroMagica -= 60;
        heroTele = false;
        heroTeleOnce = true;
    }

    heroR.x = x;
    heroR.y = y;

if(fast) {
    if( x < 325 ) {
        x = 325;
        mapOffsetXAmt -= 2;
    }

    if( (x + heroR.w) > (SCREEN_WIDTH - 325) ) {
        x = (SCREEN_WIDTH - 325) - heroR.w;
        mapOffsetXAmt += 2;
    }

    if( y < 212 ) {
        y = 212;
        mapOffsetYAmt -= 2;
    }

    if( (y + heroR.h) > (SCREEN_HEIGHT - 212) ) {
        y = (SCREEN_HEIGHT - 212) - heroR.h;
        mapOffsetYAmt += 2;
    }
}

    if( !heroSpawn ) {
        heroR.x = (SCREEN_WIDTH / 2);
        heroSpawn = true;
    }

    if( ( heroMagicaWant && heroMagica > 0 ) && (heroHealth < heroMaxHealth) ) {
        heroMagica--;
        heroHealth++;
    }
    if( heroMagica <= 0 ) heroMagica = 0;
    if( heroHealth > heroMaxHealth ) heroHealth = heroMaxHealth;

    if( magicAttackUse && heroMagica > 10 ) {
        heroMagica -= 13;
        magicAttack = true;
        apply_surface((heroR.x + (heroR.w/2)) - 265, (heroR.y + (heroR.h)) - 265, magicaAttackSprite, screen );

        SDL_SetAlpha(magicaAttackSprite, SDL_SRCALPHA, SDL_ALPHA_OPAQUE - magicaAlphaAmt );

        if(magicaAlphaAmtUp) {
            if(magicaAlphaAmt < 240 ) {
                magicaAlphaAmt += 7;
            } else {
                magicaAlphaAmtUp = false;
            }
        } else {
            if(magicaAlphaAmt > 30 ) {
                magicaAlphaAmt -= 7;
            } else {
                magicaAlphaAmtUp = true;
            }
        }

    } else {
        magicAttack = false;
    }

/*
    switch(difficultyLevel) {

        case 0:
            heroMaxMagica = 1000;
            heroMaxHealth = 1000;
        break;

        case 1:
            if( level < 4 ) heroMaxMagica = 250 + level*25;
            else heroMaxMagica = 350 + (level * 20);
            heroMaxHealth = 500 + (level * 20);
        break;

        case 2:
            if( level < 4 ) heroMaxMagica = 200 + level*20;
            else heroMaxMagica = 350 + (level * 20);
            heroMaxHealth = 400 + (level * 20);
        break;

    }*/

    if( level < 4 ) heroMaxMagica = 250 + level*25;
    else heroMaxMagica = 350 + (level * 20);
    heroMaxHealth = 500 + (level * 20);

    if(heroMagica > heroMaxMagica) heroMagica = heroMaxMagica;

    heroMagicaUpSpd = 200;

    if( heroMagicaTimer >= heroMagicaUpSpd ) {
        if( heroMagica < heroMaxMagica ) {
            heroMagica++;
        }
        heroMagicaTimerSub = SDL_GetTicks();
    }
    heroMagicaTimer = SDL_GetTicks() - heroMagicaTimerSub;

    if( heroHealthTimer >= heroHealthUpSpd ) {
        if( heroHealth < heroMaxHealth ) {
            heroHealth++;
        }
        heroHealthTimerSub = SDL_GetTicks();
    }
    heroHealthTimer = SDL_GetTicks() - heroHealthTimerSub;
/*
    switch( charPos ) {
        case 1:
        /*
            if( ( totalGameTime.get_ticks() - heroUpdateTime < 500 ) && keyDown ) {
                if(!playerSlash) apply_surface( x, y, heroFront, screen );
                else apply_surface(x, y, heroSlashFront, screen );
            } else if( keyDown ) {
                apply_surface(x, y, heroAnimateTest, screen);
                if( totalGameTime.get_ticks() - heroUpdateTime > 1000 ) {
                    heroUpdateTime = totalGameTime.get_ticks();
                }
            } else if( !keyDown ) {
                apply_surface(x, y, heroFront, screen );
            }
            if(!playerSlash) apply_surface( x, y, heroFront, screen );
            else apply_surface(x, y, heroSlashFront, screen );
            break;
        case 2:
            if(!playerSlash) apply_surface( x, y, heroBack, screen );
            else apply_surface(x, y, heroSlashBack, screen );
            break;
        case 3:
            if( !playerSlash ) apply_surface( x, y, heroLeft, screen );
            else apply_surface( x - 24, y, heroSlashLeft, screen );
            break;
        case 4:
            if( !playerSlash ) apply_surface( x, y, heroRight, screen );
            else apply_surface( x, y, heroSlashRight, screen );
            break;
    }
*/
    if( (x + 50) > 800 ) {
        mapPickX++;
        x = 0;
        mapOffsetXAmt += 800;

        for(int i = 0; i < zombAmt; i++ ) {
            zombRect[i].x -= 800;
        }

        for(int q= 0; q < skelAmt; q++ ) {
            skelRect[q].x -= 800;
        }
    }
    if( (y + 40) > 600 ) {
       mapPickY--;
       mapOffsetYAmt-=600;
       y = 0;

       for(int j = 0; j < zombAmt; j++ ) {
            zombRect[j].y -= 600;
       }
       for(int w = 0; w < skelAmt; w++ ) {
            skelRect[w].y -= 600;
       }

    }
    if( y < 0 ) {
        mapPickY++;
        y = 550;
        mapOffsetYAmt+=600;

        for( int k = 0; k < zombAmt; k++ ) {
          zombRect[k].y += 600;
        }
        for( int e = 0; e < skelAmt; e++ ) {
          skelRect[e].y += 600;
        }
    }
    if( (x + 50) < 0 ) {
        mapPickX--;
        x = 750;
        mapOffsetXAmt -= 800;

        for(int h = 0; h < zombAmt; h++ ) {
            zombRect[h].x += 800;
        }
        for(int r = 0; r < skelAmt; r++ ) {
            skelRect[r].x += 800;
        }
    }

    level = xp / 400;

    gameLevelKillsNeeded = gameLevel * 3;

    //level = (100)/(1+(999 * (pow(.990832, xp) ) ) );


    if( totalEnemyKills - previousLevelKills > gameLevelKillsNeeded ) {
        gameLevel++;
        previousLevelKills = totalEnemyKills;
    }

    stringstream quadss;
    quadss << mapPickX << mapPickY;
    string quadst;
    quadss >> quadst;
    quad = TTF_RenderText_Solid( font, quadst.c_str(), textColor );
    //SDL_Flip( screen );

}

void Actor::moveMob( int type, SDL_Rect& zomb, unsigned int& RespawnTimer, bool& ifDead, unsigned int& mobHealth, SDL_Surface *mobHealthShow, bool& ifXp, SDL_Surface *zombSurf, int respawnX, int respawnY, bool& mobDrop, SDL_Rect& deadCoord ) {
if(fast){
    zomb.x -= mapOffsetXAmt;
    zomb.y -= mapOffsetYAmt;
}

if( type != 5 ) {
    if( ( SDL_GetTicks() - RespawnTimer >= 3000) && ifDead ) {
        ifDead = false;
        ifXp = false;
        switch(type) {
            case 0:
                mobHealth = 500;
                break;
            case 1:
                mobHealth = 250;
                break;
            case 2:
                mobHealth = 350;
                break;
            case 6:
                mobHealth = 100;
                break;
        }
        zomb.w = 100;
        zomb.h = 126;
        zomb.x = rand() % ( rand() % 240 + 10 ) + respawnX;
        zomb.y = rand() % ( rand() % 317 + 10 ) + respawnY;
    }
}

    if( zombie.zombHitDetect(type, zomb.x, zomb.y, zomb) && !ifDead ) ifDead = false;
    else  { mobHealth -= 25; }

if( type != 2 ) {
    if(magicAttack) {
        if( ( zomb.x - heroR.x < 250 ) && (zomb.x - heroR.x > -250) ) {
            if( ( zomb.y - heroR.y < 250 ) && (zomb.y - heroR.y > -250) ) {
                mobHealth -= 50;
            }
        }
    }
}

    if( mobHealth <= 0 ) {
        ifDead = true;
        totalEnemyKills += 1;
        deadCoord.x = zomb.x + mapOffsetXAmt;
        deadCoord.y = zomb.y + mapOffsetYAmt;
        int dropChance = rand() % 8+1;
        switch(dropChance) {
            case 1:
                mobDrop = true;
                break;
            case 2:
                mobDrop = false;
                break;
        }
    }
/*
    stringstream ss;
    ss << mobHealth;
    string healthString;
    ss >> healthString;


    mobHealthShow = TTF_RenderText_Solid(font, healthString.c_str(), whiteTextColor );
*/


    float maxMobHealth;
    switch(type) {
        case 0:
            maxMobHealth = 500.f;
            break;
        case 1:
            maxMobHealth = 250.f;
            break;
        case 2:
            maxMobHealth = 350.f;
            break;
        case 5:
            maxMobHealth = 7500.f;
            break;
        case 6:
            maxMobHealth = 100.f;
            break;
    }

    float mobHealthFlt = mobHealth;
    float mobHealthAdj = 96.f * (mobHealthFlt/maxMobHealth);

    if( !ifDead ){
        apply_surface( zomb.x, zomb.y, zombSurf, screen );
        //apply_surface(zomb.x + 30, zomb.y - 40, mobHealthShow, screen );

    if(type != 6) {
        apply_surface( zomb.x, zomb.y - 35, mobHealthBar, screen );

        for( int mh = 0; mh < mobHealthAdj; mh++ ) {
            apply_surface( zomb.x + 2 + mh, zomb.y - 33, mobHealthBarTick, screen );
        }
    }

        /*
        apply_surface( zomb.x - mapOffsetXAmt, zomb.y - mapOffsetYAmt, zombSurf, screen );
        apply_surface(zomb.x + 30 - mapOffsetXAmt, zomb.y - 40 - mapOffsetYAmt, mobHealthShow, screen );
        */
    }

if(type != 5 && type != 6) {
    if( ifDead ) {
        zomb.w = 0;
        zomb.h = 0;
        if( !ifXp ) {
            xp += 50;
            ifXp = true;
            RespawnTimer = SDL_GetTicks();
        }
    }
} else if( type == 5 ) {
    if(ifDead) {
        if(!ifXp) {
            xp += 1000;
            ifXp = true;
            zomb.w = 0;
            zomb.h = 0;
        }
    }
}

    signed int zombAcc1 = rand() % 200 + 50;

    //int zombAcc1 = 50;

    SDL_Rect zombAcc;
    zombAcc.w = (zombAcc1 * 2);
    zombAcc.h = (zombAcc1 * 2);
    zombAcc.x = (zomb.x + 50) - zombAcc1;
    zombAcc.y = (zomb.y + 63) - zombAcc1;

    switch( type ) {
        case 0:
            if( (heroR.x + 50) > (zombAcc.x + zombAcc.w)) {
                zomb.x++;
            }
            else if( (heroR.x + 50) < zombAcc.x) zomb.x--;

            if( ( heroR.y + 63) > (zombAcc.y + zombAcc.h)) zomb.y++;
            else if( (heroR.y + 63) < zombAcc.y ) zomb.y--;
        break;

        case 1:
            if( (heroR.x + 50) > (zombAcc.x + zombAcc.w)) zomb.x+=2;
            else if( (heroR.x + 50) < zombAcc.x) zomb.x-=2;

            if( ( heroR.y + 63) > (zombAcc.y + zombAcc.h)) zomb.y+=2;
            else if( (heroR.y + 63) < zombAcc.y ) zomb.y-=2;
        break;

        case 2:
            if( (heroR.x + 50) > (zombAcc.x + zombAcc.w)) zomb.x+=1;
            else if( (heroR.x + 50) < zombAcc.x) zomb.x-=1;

            if( ( heroR.y + 63) > (zombAcc.y + zombAcc.h)) zomb.y+=1;
            else if( (heroR.y + 63) < zombAcc.y ) zomb.y-=1;
        break;

        case 5:
            if( (heroR.x + 50) > (zombAcc.x + zombAcc.w)) zomb.x+=2;
            else if( (heroR.x + 50) < zombAcc.x) zomb.x-=2;

            if( ( heroR.y + 63) > (zombAcc.y + zombAcc.h)) zomb.y+=2;
            else if( (heroR.y + 63) < zombAcc.y ) zomb.y-=2;
        break;

        case 6:
            if( (heroR.x + 50) > (zombAcc.x + zombAcc.w)) zomb.x+=3;
            else if( (heroR.x + 50) < zombAcc.x) zomb.x-=3;

            if( ( heroR.y + 63) > (zombAcc.y + zombAcc.h)) zomb.y+=3;
            else if( (heroR.y + 63) < zombAcc.y ) zomb.y-=3;
        break;
    }

    if(fast) {
        zomb.x += mapOffsetXAmt;
        zomb.y += mapOffsetYAmt;
    }

}


bool Actor::zombHitDetect( int type, int x, int y, SDL_Rect locate ) {
    hero.slashTime();
    if( playerSlash ) {
        if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
            if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                return false;
        }
    }

    switch(type) {
        case 0:
            if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
                if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                    heroHealth -= 3;
            }
        break;

        case 1:
            if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
                if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                    heroHealth -= 1;
            }
        break;

        case 2:
            if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
                if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                    heroHealth -= 2;
            }
        break;

        case 5:
            if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
                if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                    heroHealth -= 4;
            }
        break;

        case 6:
            if( ( (heroR.x + 50) > x ) && ((heroR.y + 63)> y) ) {
                if( ( ( heroR.x + 50 ) < x + locate.w )  && ( ( heroR.y + 63 ) < y + locate.h ) )
                    heroHealth -= 1;
            }
        break;
    }
    return true;
}

void Actor::getMobCoord() {
    ifstream saveFileZXL[zombAmt];
    ifstream saveFileZYL[zombAmt];

    ifstream saveFileSXL[skelAmt];
    ifstream saveFileSYL[skelAmt];

    ifstream saveFileSOX[skelAmt];
    ifstream saveFileSOY[skelAmt];

    switch(gameSaveInt) {
        case 1:

            saveFileSXL[0].open("saves/gameOne/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameOne/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameOne/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameOne/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameOne/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameOne/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameOne/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameOne/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameOne/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameOne/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameOne/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameOne/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameOne/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameOne/mobs/zomb/ZYL2");

            break;

        case 2:

            saveFileSXL[0].open("saves/gameTwo/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameTwo/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameTwo/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameTwo/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameTwo/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameTwo/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameTwo/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameTwo/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameTwo/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameTwo/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameTwo/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameTwo/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameTwo/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameTwo/mobs/zomb/ZYL2");

            break;

        case 3:

            saveFileSXL[0].open("saves/gameThree/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameThree/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameThree/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameThree/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameThree/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameThree/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameThree/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameThree/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameThree/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameThree/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameThree/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameThree/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameThree/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameThree/mobs/zomb/ZYL2");

            break;
    }

    for(int i; i < skelAmt; i++) {
        saveFileSXL[i] >> skelRect[i].x;
        saveFileSYL[i] >> skelRect[i].y;
        saveFileSOX[i] >> skelOffsetX[i];
        saveFileSOY[i] >> skelOffsetY[i];
    }

    for(int i = 0; i < skelAmt; i++) {
        saveFileSXL[i].close();
        saveFileSYL[i].close();
        saveFileSOX[i].close();
        saveFileSOY[i].close();
    }

}


void saveGame(int location) {

    ofstream newGame;
    switch(location) {
        case 1:
            newGame.open("settings/saves/one");
        break;

        case 2:
            newGame.open("settings/saves/two");
        break;

        case 3:
            newGame.open("settings/saves/three");
        break;
    }

    newGame << "5";
    newGame.close();

    ofstream saveFileMOX;
    ofstream saveFileMOY;
    ofstream saveFilePXL;
    ofstream saveFilePYL;
    ofstream saveFileHH;
    ofstream saveFileTK;
    ofstream saveFilePXP;
    ofstream saveFileGL;
    ofstream saveFileHL;
    ofstream saveFileHM;
    ofstream saveFileMPX;
    ofstream saveFileMPY;
    ofstream saveFileML;

    ofstream saveItemSlots[9];

    ofstream saveFileZXL[zombAmt];
    ofstream saveFileZYL[zombAmt];

    ofstream saveFileSXL[skelAmt];
    ofstream saveFileSYL[skelAmt];

    ofstream saveFileSOX[skelAmt];
    ofstream saveFileSOY[skelAmt];

    saveFileSYL[0].open("saves/gameOne/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameOne/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameOne/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameOne/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameOne/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameOne/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameOne/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameOne/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameOne/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameOne/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameOne/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameOne/mobs/zomb/ZYL2");
/*
    stringstream sfss;
    stringstream SYLss;
    stringstream SOXss;
    stringstream SOYss;
    stringstream ZXLss;
    stringstream ZYLss;

    for( int qq = 0; qq < skelAmt; qq++ ) {
        sfss << "saves/" << location << "mobs/skel/SXL" << qq;
        SYLss << "saves/" << location << "mobs/skel/SYL" << qq;
        SOXss << "saves/" << location << "mobs/skel/SOX" << qq;
        SOYss << "saves/" << location << "mobs/skel/SOY" << qq;

        saveFileSXL[qq].open(sfss.str().c_str());
        saveFileSYL[qq].open(SYLss.str().c_str());
        saveFileSOX[qq].open(SOXss.str().c_str());
        saveFileSOY[qq].open(SOYss.str().c_str());
    }
*/
    switch(location) {
        case 1:

        if( location == 666 ) {
        remove("saves/gameOne/game/mapOffsetX");
        remove("saves/gameOne/game/mapOffsetY");
        remove("saves/gameOne/player/PSLX");
        remove("saves/gameOne/player/PSLY");
        remove("saves/gameOne/player/hh");
        remove("saves/gameOne/player/tk");
        remove("saves/gameOne/player/PXP");
        remove("saves/gameOne/game/gl");
        remove("saves/gameOne/player/hl");
        remove("saves/gameOne/player/hm");
        remove("saves/gameOne/game/MPX");
        remove("saves/gameOne/game/MPY");
        }

            saveFileMOX.open("saves/gameOne/game/mapOffsetX");
            saveFileMOY.open("saves/gameOne/game/mapOffsetY");
            saveFilePXL.open("saves/gameOne/player/PSLX");
            saveFilePYL.open("saves/gameOne/player/PSLY");
            saveFileHH.open("saves/gameOne/player/hh");
            saveFileTK.open("saves/gameOne/player/tk");
            saveFilePXP.open("saves/gameOne/player/PXP");
            saveFileGL.open("saves/gameOne/game/gl");
            saveFileHL.open("saves/gameOne/player/hl");
            saveFileHM.open("saves/gameOne/player/hm");
            saveFileMPX.open("saves/gameOne/game/MPX");
            saveFileMPY.open("saves/gameOne/game/MPY");
            saveFileML.open("saves/gameOne/game/ML");

            saveFileSXL[0].open("saves/gameOne/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameOne/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameOne/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameOne/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameOne/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameOne/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameOne/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameOne/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameOne/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameOne/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameOne/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameOne/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameOne/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameOne/mobs/zomb/ZYL2");

            saveItemSlots[0].open("saves/gameOne/game/itemSlot1");
            saveItemSlots[1].open("saves/gameOne/game/itemSlot2");
            saveItemSlots[2].open("saves/gameOne/game/itemSlot3");
            saveItemSlots[3].open("saves/gameOne/game/itemSlot4");
            saveItemSlots[4].open("saves/gameOne/game/itemSlot5");
            saveItemSlots[5].open("saves/gameOne/game/itemSlot6");
            saveItemSlots[6].open("saves/gameOne/game/itemSlot7");
            saveItemSlots[7].open("saves/gameOne/game/itemSlot8");
            saveItemSlots[8].open("saves/gameOne/game/itemSlot9");

            break;

        case 2:

        if( location == 666 ) {
        remove("saves/gameTwo/game/mapOffsetX");
        remove("saves/gameTwo/game/mapOffsetY");
        remove("saves/gameTwo/player/PSLX");
        remove("saves/gameTwo/player/PSLY");
        remove("saves/gameTwo/player/hh");
        remove("saves/gameTwo/player/tk");
        remove("saves/gameTwo/player/PXP");
        remove("saves/gameTwo/game/gl");
        remove("saves/gameTwo/player/hl");
        remove("saves/gameTwo/player/hm");
        remove("saves/gameTwo/game/MPX");
        remove("saves/gameTwo/game/MPY");
        }

            saveFileMOX.open("saves/gameTwo/game/mapOffsetX");
            saveFileMOY.open("saves/gameTwo/game/mapOffsetY");
            saveFilePXL.open("saves/gameTwo/player/PSLX");
            saveFilePYL.open("saves/gameTwo/player/PSLY");
            saveFileHH.open("saves/gameTwo/player/hh");
            saveFileTK.open("saves/gameTwo/player/tk");
            saveFilePXP.open("saves/gameTwo/player/PXP");
            saveFileGL.open("saves/gameTwo/game/gl");
            saveFileHL.open("saves/gameTwo/player/hl");
            saveFileHM.open("saves/gameTwo/player/hm");
            saveFileMPX.open("saves/gameTwo/game/MPX");
            saveFileMPY.open("saves/gameTwo/game/MPY");
            saveFileML.open("saves/gameTwo/game/ML");

            saveFileSXL[0].open("saves/gameTwo/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameTwo/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameTwo/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameTwo/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameTwo/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameTwo/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameTwo/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameTwo/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameTwo/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameTwo/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameTwo/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameTwo/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameTwo/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameTwo/mobs/zomb/ZYL2");

            saveItemSlots[0].open("saves/gameTwo/game/itemSlot1");
            saveItemSlots[1].open("saves/gameTwo/game/itemSlot2");
            saveItemSlots[2].open("saves/gameTwo/game/itemSlot3");
            saveItemSlots[3].open("saves/gameTwo/game/itemSlot4");
            saveItemSlots[4].open("saves/gameTwo/game/itemSlot5");
            saveItemSlots[5].open("saves/gameTwo/game/itemSlot6");
            saveItemSlots[6].open("saves/gameTwo/game/itemSlot7");
            saveItemSlots[7].open("saves/gameTwo/game/itemSlot8");
            saveItemSlots[8].open("saves/gameTwo/game/itemSlot9");

            break;

        case 3:

        if( location == 666 ) {
        remove("saves/gameThree/game/mapOffsetX");
        remove("saves/gameThree/game/mapOffsetY");
        remove("saves/gameThree/player/PSLX");
        remove("saves/gameThree/player/PSLY");
        remove("saves/gameThree/player/hh");
        remove("saves/gameThree/player/tk");
        remove("saves/gameThree/player/PXP");
        remove("saves/gameThree/game/gl");
        remove("saves/gameThree/player/hl");
        remove("saves/gameThree/player/hm");
        remove("saves/gameThree/game/MPX");
        remove("saves/gameThree/game/MPY");
        }

            saveFileMOX.open("saves/gameThree/game/mapOffsetX");
            saveFileMOY.open("saves/gameThree/game/mapOffsetY");
            saveFilePXL.open("saves/gameThree/player/PSLX");
            saveFilePYL.open("saves/gameThree/player/PSLY");
            saveFileHH.open("saves/gameThree/player/hh");
            saveFileTK.open("saves/gameThree/player/tk");
            saveFilePXP.open("saves/gameThree/player/PXP");
            saveFileGL.open("saves/gameThree/game/gl");
            saveFileHL.open("saves/gameThree/player/hl");
            saveFileHM.open("saves/gameThree/player/hm");
            saveFileMPX.open("saves/gameThree/game/MPX");
            saveFileMPY.open("saves/gameThree/game/MPY");
            saveFileML.open("saves/gameThree/game/ML");

            saveFileSXL[0].open("saves/gameThree/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameThree/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameThree/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameThree/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameThree/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameThree/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameThree/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameThree/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameThree/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameThree/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameThree/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameThree/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameThree/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameThree/mobs/zomb/ZYL2");

            saveItemSlots[0].open("saves/gameThree/game/itemSlot1");
            saveItemSlots[1].open("saves/gameThree/game/itemSlot2");
            saveItemSlots[2].open("saves/gameThree/game/itemSlot3");
            saveItemSlots[3].open("saves/gameThree/game/itemSlot4");
            saveItemSlots[4].open("saves/gameThree/game/itemSlot5");
            saveItemSlots[5].open("saves/gameThree/game/itemSlot6");
            saveItemSlots[6].open("saves/gameThree/game/itemSlot7");
            saveItemSlots[7].open("saves/gameThree/game/itemSlot8");
            saveItemSlots[8].open("saves/gameThree/game/itemSlot9");

            break;
    }

    saveFileMOX << mapOffsetXAmt;
    saveFileMOY << mapOffsetYAmt;
    saveFilePXL << heroR.x;
    saveFilePYL << heroR.y;
    saveFileHH << heroHealth;
    saveFileTK << totalEnemyKills;
    saveFileHL << level;
    saveFilePXP << xp;
    saveFileGL << gameLevel;
    saveFileMPX << mapPickX;
    saveFileMPY << mapPickY;
    saveFileML << mapLevel;

    for(int is = 0; is < 9; is++ ) {
        saveItemSlots[is] << itemSlotItem[is];
    }

    for(int q = 0; q < skelAmt; q++) {
        saveFileSXL[q] << skelRect[q].x;
        saveFileSYL[q] << skelRect[q].y;
        saveFileSOX[q] << skelOffsetX[q];
        saveFileSOY[q] << skelOffsetY[q];
    }

    saveFileML.close();
    saveFileMOX.close();
    saveFileMOX.close();
    saveFileMOX.close();
    saveFileMOX.close();
    saveFileHH.close();
    saveFileMPX.close();
    saveFileMPY.close();
    saveFileHM.close();

    for(int w = 0; w < skelAmt; w++) {
        saveFileSXL[w].close();
        saveFileSYL[w].close();
        saveFileSOX[w].close();
        saveFileSOY[w].close();
    }


}

void loadSave(int position) {

    ifstream saveFileMOX;
    ifstream saveFileMOY;
    ifstream saveFilePXL;
    ifstream saveFilePYL;
    ifstream saveFileHH;
    ifstream saveFileTK;
    ifstream saveFilePXP;
    ifstream saveFileGL;
    ifstream saveFileHL;
    ifstream saveFileHM;
    ifstream saveFileMPX;
    ifstream saveFileMPY;
    ifstream saveFileML;
    //ifstream saveItemSlots[9];

    ifstream saveFileZXL[zombAmt];
    ifstream saveFileZYL[zombAmt];

    ifstream saveFileSXL[skelAmt];
    ifstream saveFileSYL[skelAmt];

    ifstream saveFileSOX[skelAmt];
    ifstream saveFileSOY[skelAmt];

    switch(position) {
        case 1:
            saveFileMOX.open("saves/gameOne/game/mapOffsetX");
            saveFileMOY.open("saves/gameOne/game/mapOffsetY");
            saveFilePXL.open("saves/gameOne/player/PSLX");
            saveFilePYL.open("saves/gameOne/player/PSLY");
            saveFileHH.open("saves/gameOne/player/hh");
            saveFileTK.open("saves/gameOne/player/tk");
            saveFilePXP.open("saves/gameOne/player/PXP");
            saveFileGL.open("saves/gameOne/game/gl");
            saveFileHL.open("saves/gameOne/player/hl");
            saveFileHM.open("saves/gameOne/player/hm");
            saveFileMPX.open("saves/gameOne/game/MPX");
            saveFileMPY.open("saves/gameOne/game/MPY");
            saveFileML.open("saves/gameOne/game/ML");

            saveFileSXL[0].open("saves/gameOne/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameOne/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameOne/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameOne/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameOne/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameOne/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameOne/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameOne/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameOne/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameOne/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameOne/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameOne/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameOne/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameOne/mobs/zomb/ZYL2");
/*
            saveItemSlots[0].open("saves/gameOne/game/itemSlot1");
            saveItemSlots[1].open("saves/gameOne/game/itemSlot2");
            saveItemSlots[2].open("saves/gameOne/game/itemSlot3");
            saveItemSlots[3].open("saves/gameOne/game/itemSlot4");
            saveItemSlots[4].open("saves/gameOne/game/itemSlot5");
            saveItemSlots[5].open("saves/gameOne/game/itemSlot6");
            saveItemSlots[6].open("saves/gameOne/game/itemSlot7");
            saveItemSlots[7].open("saves/gameOne/game/itemSlot8");
            saveItemSlots[8].open("saves/gameOne/game/itemSlot9");
            */

            break;

        case 2:
            saveFileMOX.open("saves/gameTwo/game/mapOffsetX");
            saveFileMOY.open("saves/gameTwo/game/mapOffsetY");
            saveFilePXL.open("saves/gameTwo/player/PSLX");
            saveFilePYL.open("saves/gameTwo/player/PSLY");
            saveFileHH.open("saves/gameTwo/player/hh");
            saveFileTK.open("saves/gameTwo/player/tk");
            saveFilePXP.open("saves/gameTwo/player/PXP");
            saveFileGL.open("saves/gameTwo/game/gl");
            saveFileHL.open("saves/gameTwo/player/hl");
            saveFileHM.open("saves/gameTwo/player/hm");
            saveFileMPX.open("saves/gameTwo/game/MPX");
            saveFileMPY.open("saves/gameTwo/game/MPY");
            saveFileML.open("saves/gameTwo/game/ML");

            saveFileSXL[0].open("saves/gameTwo/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameTwo/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameTwo/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameTwo/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameTwo/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameTwo/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameTwo/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameTwo/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameTwo/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameTwo/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameTwo/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameTwo/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameTwo/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameTwo/mobs/zomb/ZYL2");
/*
            saveItemSlots[0].open("saves/gameTwo/game/itemSlot1");
            saveItemSlots[1].open("saves/gameTwo/game/itemSlot2");
            saveItemSlots[2].open("saves/gameTwo/game/itemSlot3");
            saveItemSlots[3].open("saves/gameTwo/game/itemSlot4");
            saveItemSlots[4].open("saves/gameTwo/game/itemSlot5");
            saveItemSlots[5].open("saves/gameTwo/game/itemSlot6");
            saveItemSlots[6].open("saves/gameTwo/game/itemSlot7");
            saveItemSlots[7].open("saves/gameTwo/game/itemSlot8");
            saveItemSlots[8].open("saves/gameTwo/game/itemSlot9");*/

            break;

        case 3:
            saveFileMOX.open("saves/gameThree/game/mapOffsetX");
            saveFileMOY.open("saves/gameThree/game/mapOffsetY");
            saveFilePXL.open("saves/gameThree/player/PSLX");
            saveFilePYL.open("saves/gameThree/player/PSLY");
            saveFileHH.open("saves/gameThree/player/hh");
            saveFileTK.open("saves/gameThree/player/tk");
            saveFilePXP.open("saves/gameThree/player/PXP");
            saveFileGL.open("saves/gameThree/game/gl");
            saveFileHL.open("saves/gameThree/player/hl");
            saveFileHM.open("saves/gameThree/player/hm");
            saveFileMPX.open("saves/gameThree/game/MPX");
            saveFileMPY.open("saves/gameThree/game/MPY");
            saveFileML.open("saves/gameThree/game/ML");

            saveFileSXL[0].open("saves/gameThree/mobs/skel/SXL0");
            saveFileSXL[1].open("saves/gameThree/mobs/skel/SXL1");

            saveFileSYL[0].open("saves/gameThree/mobs/skel/SYL0");
            saveFileSYL[1].open("saves/gameThree/mobs/skel/SYL1");

            saveFileSOX[0].open("saves/gameThree/mobs/skel/SOX0");
            saveFileSOX[1].open("saves/gameThree/mobs/skel/SOX1");

            saveFileSOY[0].open("saves/gameThree/mobs/skel/SOY0");
            saveFileSOY[1].open("saves/gameThree/mobs/skel/SOY1");

            saveFileZXL[0].open("saves/gameThree/mobs/zomb/ZXL0");
            saveFileZXL[1].open("saves/gameThree/mobs/zomb/ZXL1");
            saveFileZXL[2].open("saves/gameThree/mobs/zomb/ZXL2");

            saveFileZYL[0].open("saves/gameThree/mobs/zomb/ZYL0");
            saveFileZYL[1].open("saves/gameThree/mobs/zomb/ZYL1");
            saveFileZYL[2].open("saves/gameThree/mobs/zomb/ZYL2");
/*
            saveItemSlots[0].open("saves/gameThree/game/itemSlot1");
            saveItemSlots[1].open("saves/gameThree/game/itemSlot2");
            saveItemSlots[2].open("saves/gameThree/game/itemSlot3");
            saveItemSlots[3].open("saves/gameThree/game/itemSlot4");
            saveItemSlots[4].open("saves/gameThree/game/itemSlot5");
            saveItemSlots[5].open("saves/gameThree/game/itemSlot6");
            saveItemSlots[6].open("saves/gameThree/game/itemSlot7");
            saveItemSlots[7].open("saves/gameThree/game/itemSlot8");
            saveItemSlots[8].open("saves/gameThree/game/itemSlot9");*/

            break;
    }

    if(saveFileGL) {
       heroSpawn = true;
    }

    saveFileHH >> heroHealth;
    saveFileMOX >> mapOffsetXAmt;
    saveFileMOY >> mapOffsetYAmt;
    saveFilePXL >> heroR.x;
    saveFilePYL >> heroR.y;
    saveFileTK >> totalEnemyKills;
    saveFileHL >> level;
    saveFilePXP >> xp;
    saveFileGL >> gameLevel;
    saveFileHM >> heroMagica;
    saveFileMPX >> mapPickX;
    saveFileMPY >> mapPickY;
    saveFileML >> mapLevel;

    for(int i; i < skelAmt; i++) {
        saveFileSXL[i] >> skelRect[i].x;
        saveFileSYL[i] >> skelRect[i].y;
        saveFileSOX[i] >> skelOffsetX[i];
        saveFileSOY[i] >> skelOffsetY[i];
    }

    for(int is = 0; is < 9; is++) {
        //saveItemSlots[is] >> itemSlotItem[is];
    }


    saveFileML.close();
    saveFileMOX.close();
    saveFileMOY.close();
    saveFileMPX.close();
    saveFileMPY.close();
    saveFileHM.close();
    saveFilePXL.close();
    saveFilePYL.close();

    for(int j = 0; j < skelAmt; j++) {
        saveFileSXL[j].close();
        saveFileSYL[j].close();
        saveFileSOX[j].close();
        saveFileSOY[j].close();
    }
}
