#include <string>
#include <sstream>
#include <math.h>
#include <fstream>
#include <stdio.h>
using namespace std;
#include "headers/game_engine.h"
#include "headers/globals.h"
#include "headers/SDL_functions.h"

Actor::Actor() {
    hero.getLastHeroCord();
    int x = heroR.x;
    int y = heroR.y;
}

Actor::~Actor() {}

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


void Actor::move(int dx, int dy) {

    //if( heroTileType == 0 ) {
        x += ( dx + dx );
        y += ( dy + dy );
    //} else if( heroTileType == 1 ) {
        //x += ( dx * 3 );
        //y += ( dy * 3 );
    //} else if( heroTileType == 2 ) {
        //x += dx;
        //y += dy;
    //}

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
    if( x < 100 ) {
        x = 100;
        mapOffsetXAmt -= 2;
    }

    if( (x + heroR.w)> 700 ) {
        x = 700 - heroR.w;
        mapOffsetXAmt += 2;
    }

    if( y < 100 ) {
        y = 100;
        mapOffsetYAmt -= 2;
    }

    if( (y + heroR.h) > 500 ) {
        y = 500 - heroR.h;
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

    }

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

    //level = xp / 100;

gameLevelKillsNeeded = gameLevel * 3;

    level = sqrt(xp/50);
    if( totalEnemyKills - previousLevelKills > gameLevelKillsNeeded ) {
        gameLevel++;
        previousLevelKills = totalEnemyKills;
    }

    stringstream quadss;
    quadss << mapPickX << mapPickY;
    string quadst;
    quadss >> quadst;
    quad = TTF_RenderText_Solid( font, quadst.c_str(), textColor );
    SDL_Flip( screen );

}

void Actor::moveMob( int type, SDL_Rect& zomb, unsigned int& RespawnTimer, bool& ifDead, unsigned int& mobHealth, SDL_Surface *mobHealthShow, bool& ifXp, SDL_Surface *zombSurf, int respawnX, int respawnY ) {
if(fast){
    zomb.x -= mapOffsetXAmt;
    zomb.y -= mapOffsetYAmt;
}

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
                mobHealth = 300;
        }
        zomb.w = 100;
        zomb.h = 126;
        zomb.x = rand() % ( rand() % 240 + 10 ) + respawnX;
        zomb.y = rand() % ( rand() % 317 + 10 ) + respawnY;
    }

    if( zombie.zombHitDetect(type, zomb.x, zomb.y, zomb) && !ifDead ) ifDead = false;
    else  mobHealth -= 25;

    if( mobHealth <= 0 ) {
        ifDead = true;
        totalEnemyKills += 1;
    }

    stringstream ss;
    ss << mobHealth;
    string healthString;
    ss >> healthString;


    mobHealthShow = TTF_RenderText_Solid(font, healthString.c_str(), whiteTextColor );

    if( !ifDead ){
        apply_surface( zomb.x, zomb.y, zombSurf, screen );
        apply_surface(zomb.x + 30, zomb.y - 40, mobHealthShow, screen );

        /*
        apply_surface( zomb.x - mapOffsetXAmt, zomb.y - mapOffsetYAmt, zombSurf, screen );
        apply_surface(zomb.x + 30 - mapOffsetXAmt, zomb.y - 40 - mapOffsetYAmt, mobHealthShow, screen );
        */
    }

    if( ifDead ) {
        zomb.w = 0;
        zomb.h = 0;
        if( !ifXp ) {
            xp += 50;
            ifXp = true;
            RespawnTimer = SDL_GetTicks();
        }
    }


    signed int zombAcc1 = rand() % 650 - 650;

    switch( type ) {
        case 0:
            if( heroR.x > zomb.x ) {
                zomb.x++;
            } else if( heroR.x < ( zomb.x + zombAcc1 ) ) {
                zomb.x--;
            }

            if( heroR.y > zomb.y ) {
                zomb.y++;
            } else if( heroR.y < ( zomb.y + zombAcc1) ) {
                zomb.y--;
            }
            break;

        case 1:
            if( heroR.x > zomb.x ) zomb.x += 2;
            else if( heroR.x < ( zomb.x + zombAcc1 ) ) zomb.x-= 2;

            if( heroR.y > zomb.y ) zomb.y += 2;
            else if( heroR.y < ( zomb.y + zombAcc1) ) zomb.y -= 2;
            break;

        case 2:
            if( heroR.x > zomb.x ) zomb.x += 2;
            else if( heroR.x < ( zomb.x + zombAcc1 ) ) zomb.x-= 2;

            if( heroR.y > zomb.y ) zomb.y += 2;
            else if( heroR.y < ( zomb.y + zombAcc1) ) zomb.y -= 2;
            break;
    }
if(fast) {
    zomb.x += mapOffsetXAmt;
    zomb.y += mapOffsetYAmt;
}

}


/*
void Actor::moveZomb() {


    if( ( SDL_GetTicks() - zomb1RespawnTimer >= 3000) && zomb1Dead ) {
        zomb1Dead = false;
        zomb1Xp = false;
        zomb1.w = 100;
        zomb1.h = 126;
        zomb1.x = rand() % ( rand() % 240 + 10 ) + 800;
        zomb1.y = rand() % 317 + 10;
    }
    if( ( SDL_GetTicks() - zomb2RespawnTimer >= 2500) && zomb2Dead ) {
        zomb2Dead = false;
        zomb2Xp = false;
        zomb2.w = 100;
        zomb2.h = 126;
        zomb2.x = ( rand() % 240 + 10 ) + 800;
        zomb2.y = ( rand() % 317 + 10 ) + 600;
    }
    if( ( SDL_GetTicks() - zomb3RespawnTimer >= 2000 ) && zomb3Dead ) {
        zomb3Dead = false;
        zomb3Xp = false;
        zomb3.w = 100;
        zomb3.h = 126;
        zomb3.x = ( rand() % 240 + 10 ) - 800;
        zomb3.y = ( rand() % 317 + 10 ) - 600;
    }

    if( zombie.zombHitDetect(zomb1.x, zomb1.y, zomb1) && !zomb1Dead ) zomb1Dead = false;
    else zomb1Dead = true;

    if( zombHitDetect(zomb2.x, zomb2.y, zomb2) && !zomb2Dead ) zomb2Dead = false;
    else zomb2Dead = true;

    if( zombHitDetect(zomb3.x, zomb3.y, zomb3) && !zomb3Dead ) zomb3Dead = false;
    else zomb3Dead = true;

    if( !zomb1Dead ) apply_surface( zomb1.x, zomb1.y, zombFront, screen );
    if( !zomb2Dead ) apply_surface( zomb2.x, zomb2.y, zomb2Front, screen );
    if( !zomb3Dead ) apply_surface( zomb3.x, zomb3.y, zomb2Front, screen );

    if( zomb1Dead ) {
        zomb1.w = 0;
        zomb1.h = 0;
        if( !zomb1Xp ) {
            xp += 50;
            zomb1Xp = true;
            zomb1RespawnTimer = SDL_GetTicks();
        }
    }
    if( zomb2Dead ) {
        zomb2.w = 0;
        zomb2.h = 0;
        if( !zomb2Xp ) {
            xp += 50;
            zomb2Xp = true;
            zomb2RespawnTimer = SDL_GetTicks();
        }
    }

    if( zomb3Dead ) {
        zomb3.w = 0;
        zomb3.h = 0;
        if( !zomb3Xp ) {
            xp += 50;
            zomb3Xp = true;
            zomb3RespawnTimer = SDL_GetTicks();
        }
    }

    signed int zombAcc1 = rand() % 400 - 400;
    signed int zombAcc2 = rand() % 400 - 400;
    signed int zombAcc3 = rand() % 400 - 400;


    if( heroR.x > zomb1.x ) zomb1.x++;
    else if( heroR.x < ( zomb1.x + zombAcc1 ) ) zomb1.x--;

    if( heroR.y > zomb1.y ) zomb1.y++;
    else if( heroR.y < ( zomb1.y + zombAcc1) ) zomb1.y--;

    if( heroR.x > zomb2.x ) zomb2.x++;
    else if( heroR.x < ( zomb2.x + zombAcc2 ) ) zomb2.x--;

    if( heroR.y > zomb2.y ) zomb2.y++;
    else if( heroR.y < ( zomb2.y + zombAcc2 ) ) zomb2.y--;

    if( heroR.x > zomb3.x ) zomb3.x++;
    else if( heroR.x < ( zomb3.x + zombAcc3 ) ) zomb3.x--;

    if( heroR.y > zomb3.y ) zomb3.y++;
    else if( heroR.y < ( zomb3.y + zombAcc3 ) ) zomb3.y--;
}
*/
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
                    heroHealth -= 2;
            }
        break;

        case 1:
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

    ofstream saveFileZXL[zombAmt];
    ofstream saveFileZYL[zombAmt];

    ofstream saveFileSXL[skelAmt];
    ofstream saveFileSYL[skelAmt];

    ofstream saveFileSOX[skelAmt];
    ofstream saveFileSOY[skelAmt];

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

    for(int q = 0; q < skelAmt; q++) {
        saveFileSXL[q] << skelRect[q].x;
        saveFileSYL[q] << skelRect[q].y;
        saveFileSOX[q] << skelOffsetX[q];
        saveFileSOY[q] << skelOffsetY[q];
    }

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

    ifstream newGame;
    int newGameCheck;
    switch(position) {
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

    newGame >> newGameCheck;
    if( !newGameCheck == 0 ) {

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

    for(int i; i < skelAmt; i++) {
        saveFileSXL[i] >> skelRect[i].x;
        saveFileSYL[i] >> skelRect[i].y;
        saveFileSOX[i] >> skelOffsetX[i];
        saveFileSOY[i] >> skelOffsetY[i];
    }


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
}
