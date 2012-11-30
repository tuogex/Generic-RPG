/****************************************

Developers: Jacob Hegna
Name: Generic RPG
DO NOT DISTRIBUTE WITHOUT WRITTTEN CONSENT
OF THE AUTHORS OF THE SOURCE CODE.

****************************************/


#include <windows.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <process.h>
#include <SDL/SDL_thread.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>

#include "headers/game_engine.h"
#include "headers/SDL_functions.h"
#include "headers/globals.h"
#include "headers/file_reader.h"
#include "headers/functions.h"
#include "headers/timer.h"
#include "headers/loadingScreens.h"

using namespace std;


void preLoop() {
/*
    bool failSkip = false;

    srand(time(NULL));

    bool lose = false;

    init();

    settingsFile();

    load_files();

if( devModeB ) {
    AllocConsole();

    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );
}

    bossOneHealth = 7500;
    boss1Rect.w = 175;
    boss1Rect.h = 175;

    for( int j = 0; j < zombAmt; j++ ) {
        zombRect[j].x = rand() % (480 + 240) + 800;
        zombRect[j].y = rand() % (317 + 240) + 600;
    }

    for( int t = 0; t < zombAmt; t++ ) {
        zombOffsetX[t] = rand() % (2400 + 0) - 800;
        zombOffsetY[t] = rand() % (1800 + 0) - 600;
    }

    for( int q = 0; q < skelAmt; q++ ) {
        skelRect[q].x = rand() % (480 + 240) - 800;
        skelRect[q].y = rand() % (317 + 240) - 600;
    }

    for( int w = 0; w < skelAmt; w++ ) {
        skelOffsetX[w] = rand() % (2400 + 0) - 800;
        skelOffsetY[w] = rand() % (1800 + 0) - 600;
    }

    for( int gh = 0; gh < ghostAmt; gh++ ) {
        ghostRect[gh].x = rand() % (600 + 200) + 800;
        ghostRect[gh].y = rand() % (360 + 200) - 600;

        ghostOffsetX[gh] = rand() % (2400 + 0) - 800;
        ghostOffsetY[gh] = rand() % (1800 + 0) - 600;

        SDL_SetAlpha( ghostSurf[gh], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    }

    SDL_SetAlpha( itemSlotSurf[0], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[1], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[2], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[3], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[4], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[5], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[6], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[7], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[8], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );

/*
    zombRect[0].x = rand() % 480 + 240;
    zombRect[0].y = rand() % 317 + 10;

    zombRect[1].x = rand() % 240 + 10;
    zombRect[1].y = rand() % 317 + 10;

    zombRect[2].x = ( rand() % 240 + 10 ) - 800;
    zombRect[2].y = ( rand() % 317 + 10 ) - 600;
*/

    ifstream file;
    file.open("settings\login data\ifLauncher");
    string test;
    file >> test;
    bool noLogin = false;
    if( test == "false") noLogin = true;
    else if(test == "true" ) noLogin = false;

    if( !devModeB) intro();

    Uint32 fpsReg = SDL_GetTicks();

    if( !ifNoSound ) Mix_PlayMusic( gameMusic, -1 );
    if( devModeB ) Mix_CloseAudio();
    if( ifNoSound ) Mix_CloseAudio();

    fpsTime.start();
    update.start();
    totalGameTime.start();

    mapOffsetXAmt = 0;
    mapOffsetYAmt = 0;

    //loadSave(gameSaveInt);
    hero.getLastHeroCord();


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

    screen = SDL_SetVideoMode( 805, 605, SCREEN_BPP, SDL_SWSURFACE );

}

/////////////////////////////////////
int main(int argc, char **argv) {
/////////////////////////////////////

    //preLoop();

    bool failSkip = false;

    srand(time(NULL));

    bool lose = false;

    init();

    settingsFile();

    load_files();

if( devModeB ) {
    AllocConsole();

    freopen( "CON", "wt", stdout );
    freopen( "CON", "wt", stderr );
}

    bossOneHealth = 7500;
    boss1Rect.w = 175;
    boss1Rect.h = 175;

    for( int j = 0; j < zombAmt; j++ ) {
        zombRect[j].x = rand() % (480 + 240) + 800;
        zombRect[j].y = rand() % (317 + 240) + 600;
    }

    for( int t = 0; t < zombAmt; t++ ) {
        zombOffsetX[t] = rand() % (2400 + 0) - 800;
        zombOffsetY[t] = rand() % (1800 + 0) - 600;
    }

    for( int q = 0; q < skelAmt; q++ ) {
        skelRect[q].x = rand() % (480 + 240) - 800;
        skelRect[q].y = rand() % (317 + 240) - 600;
    }

    for( int w = 0; w < skelAmt; w++ ) {
        skelOffsetX[w] = rand() % (2400 + 0) - 800;
        skelOffsetY[w] = rand() % (1800 + 0) - 600;
    }

    for( int gh = 0; gh < ghostAmt; gh++ ) {
        ghostRect[gh].x = rand() % (600 + 200) + 800;
        ghostRect[gh].y = rand() % (360 + 200) - 600;

        ghostOffsetX[gh] = rand() % (2400 + 0) - 800;
        ghostOffsetY[gh] = rand() % (1800 + 0) - 600;

        SDL_SetAlpha( ghostSurf[gh], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    }

    SDL_SetAlpha( itemSlotSurf[0], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[1], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[2], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[3], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[4], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[5], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[6], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[7], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );
    SDL_SetAlpha( itemSlotSurf[8], SDL_SRCALPHA, SDL_ALPHA_OPAQUE - 80 );


/*
    zombRect[0].x = rand() % 480 + 240;
    zombRect[0].y = rand() % 317 + 10;

    zombRect[1].x = rand() % 240 + 10;
    zombRect[1].y = rand() % 317 + 10;

    zombRect[2].x = ( rand() % 240 + 10 ) - 800;
    zombRect[2].y = ( rand() % 317 + 10 ) - 600;
*/

    ifstream file;
    file.open("settings\login data\ifLauncher");
    string test;
    file >> test;
    bool noLogin = false;
    if( test == "false") noLogin = true;
    else if(test == "true" ) noLogin = false;

    if( !devModeB) intro();

    Uint32 fpsReg = SDL_GetTicks();

    if( !ifNoSound ) Mix_PlayMusic( gameMusic, -1 );
    if( devModeB ) Mix_CloseAudio();
    if( ifNoSound ) Mix_CloseAudio();

    fpsTime.start();
    update.start();
    totalGameTime.start();

    mapOffsetXAmt = 0;
    mapOffsetYAmt = 0;

    //loadSave(gameSaveInt);
    hero.getLastHeroCord();


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

    screen = SDL_SetVideoMode( 805, 605, SCREEN_BPP, SDL_SWSURFACE );



    while(quit == false) {

        SDL_PollEvent(&event);

        moveOn = false;

        axisMath();
        SDL_FillRect(screen,NULL,0xFFFFFF);
        hero.slashTime();
        gameTime = SDL_GetTicks() - startTime;
        mapPicker();
        //imageMapRender();
        hero.miscMapItems();
        items();
        skeleton.mobs();
        hero.keyReg(event);
        movePlayer(event);
        hero.showHero();
        HUD();

        SDL_Flip(screen);
        frameCount++;
        totalGameFrames++;
        fpsCalc();


        if(event.type == SDL_QUIT ) quit = true;

        if( heroHealth <= 0 ) {
            quit = true;
            lose = true;
        } else {
            lose = false;
        }
        hero.slashTime();

    }

    saveGame(gameSaveInt);

    if( lose ) {
        //playerLose(event);
    }

    //if( !devModeB ) credits();

    //logFile();

    uninit();

    SDL_KillThread(consoleThread);

    system("clearMem.bat");

    return 0;
}

void imageMapRender() {
/*
    apply_surface( 0 - mapOffsetXAmt, 0 - mapOffsetYAmt, map11, screen );
    apply_surface( 0 - mapOffsetXAmt, -600 - mapOffsetYAmt, map11, screen);
    apply_surface( 0 - mapOffsetXAmt, 600 - mapOffsetYAmt, map11, screen);

    apply_surface( -800 - mapOffsetXAmt, 0 - mapOffsetYAmt, map11, screen );
    apply_surface( -800 - mapOffsetXAmt, -600 - mapOffsetYAmt, map11, screen);
    apply_surface( -800 - mapOffsetXAmt, 600 - mapOffsetYAmt, map11, screen);

    apply_surface( 800 - mapOffsetXAmt, 0 - mapOffsetYAmt, map11, screen );
    apply_surface( 800 - mapOffsetXAmt, -600 - mapOffsetYAmt, map11, screen);
    apply_surface( 800 - mapOffsetXAmt, 600 - mapOffsetYAmt, map11, screen);
*/

    apply_surface ( -800 - mapOffsetXAmt, -600 - mapOffsetYAmt, mapImage[mapLevel], screen );

}

int axisMath() {

if(fast) {
    switch(mapPickX) {
        case 0:
            mapXAxis = heroR.x;
            break;
        case 1:
            mapXAxis = SCREEN_WIDTH + heroR.x;
            break;
        case 2:
            mapXAxis = (2 * SCREEN_WIDTH) + heroR.x;
            break;
    }

    switch(mapPickY) {
        case 0:
            mapYAxis = heroR.y;
            break;
        case 1:
            mapYAxis = heroR.y + SCREEN_HEIGHT;
            break;
        case 2:
            mapYAxis = heroR.y + (SCREEN_HEIGHT * 2);
            break;
    }

    mapXAxis += mapOffsetXAmt;
    mapYAxis += mapOffsetYAmt;

    SDL_Delay(1);

}

}

void fpsCalc()
{
    currentFps = frameCount / (fpsTime.get_ticks() / 1000.f);
    if( ( fpsTime.get_ticks() / 1000.f ) > 1 ) {
        fpsTime.start();
        update.start();
        frameCount = 0;
    }
}

void mapPicker() {
if(!fast) {
    switch(mapPickY) {
        case 0:
            switch( mapPickX ) {
                case 2:
                    drawMap(fileReader20->map);
                    break;
                case 1:
                    drawMap(fileReader10->map);
                    break;
                case 0:
                    drawMap(fileReader00 -> map );
                    break;
                default:
                    apply_surface(0, 0, backbackground, screen );
                    break;
            }
        break;

        case 1:
            switch( mapPickX ) {
                case 2:
                    drawMap(errorFix->map);
                    break;
                case 1:
                    drawMap(fileReader11->map);
                    break;
                case 0:
                    drawMap(fileReader01 -> map );
                    break;
                default:
                    apply_surface(0, 0, backbackground, screen );
                    break;
            }
        break;

        case 2:
            switch( mapPickX ) {
                case 2:
                    drawMap(fileReader22->map);
                    break;
                case 1:
                    drawMap(fileReader12->map);
                    break;
                case 0:
                    drawMap(fileReader02 -> map );
                    break;
                default:
                    apply_surface(0, 0, backbackground, screen );
                    break;
            }
        break;

        default:
            apply_surface(0, 0, backbackground, screen );
        break;
    }
} else if(fast) {

    //drawMapFast1(0, 0, mainFileReader->map);

/*
    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT * 2, fileReader12->map);
    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT, fileReader11->map);
    drawMapFast1(SCREEN_WIDTH, 0, fileReader10->map);

    drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT, fileReader01->map);
    drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, fileReader02->map);
    drawMapFast1(SCREEN_WIDTH * 2, 0, fileReader00->map);

    drawMapFast1(0, SCREEN_HEIGHT, errorFix->map);
    drawMapFast1(0, SCREEN_HEIGHT * 2, fileReader22->map);
    drawMapFast1(0, 0, fileReader20->map);
*/
            //////////////////////////////////

    drawMapFast1(800, 600 * 2, fileReader12->map);
    drawMapFast1(800, 600, fileReader11->map);
    drawMapFast1(800, 0, fileReader10->map);

    drawMapFast1(800 * 2, 600, fileReader01->map);
    drawMapFast1(800 * 2, 600 * 2, fileReader02->map);
    drawMapFast1(800 * 2, 0, fileReader00->map);

    drawMapFast1(0, 600, errorFix->map);
    drawMapFast1(0, 600 * 2, fileReader22->map);
    drawMapFast1(0, 0, fileReader20->map);
            ///////////////////////////////
/*
    drawMapFast1(0, SCREEN_HEIGHT, fileReader12->map);
    drawMapFast1(0, 0, fileReader11->map);
    drawMapFast1(0, SCREEN_HEIGHT * -1, fileReader10->map);

    drawMapFast1(SCREEN_WIDTH, 0, fileReader01->map);
    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT, fileReader02->map);
    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT * -1, fileReader00->map);

    drawMapFast1(SCREEN_WIDTH * -1, 0, errorFix->map);
    drawMapFast1(SCREEN_WIDTH * -1, SCREEN_HEIGHT, fileReader22->map);
    drawMapFast1(SCREEN_WIDTH * -1, SCREEN_HEIGHT * -1, fileReader20->map);
    */
}

}


void HUD() {

        for( int i = 0; i < mapLevel; i++ ) {
            apply_surface(3 + i*23, SCREEN_HEIGHT - 85, levelTick, screen );
        }

        stringstream ss;
        ss << "fps:" <<  currentFps;
        string st;
        ss >> st;

        stringstream sd;
        sd << heroHealth;
        string healthString;
        sd >> healthString;

        stringstream xps;
        xps << xp;
        string xpStr;
        xps >> xpStr;

        stringstream lx;
        lx << level;
        string levelS;
        lx >> levelS;
/*
        stringstream qq;
        qq << heroMagica;
        string heroMagicaString;
        qq >> heroMagicaString;
*/
        stringstream xLocStrStr;
        string xLocStr;
        xLocStrStr << mapXAxis / 16;
        xLocStrStr >> xLocStr;

        stringstream yLocStrStr;
        string yLocStr;
        yLocStrStr << mapYAxis / 16;
        yLocStrStr >> yLocStr;
/*
        stringstream tileTypeStrStr;
        string tileTypeStr;
        switch(textureMap[(heroR.x + mapOffsetXAmt + (heroR.w / 2)) / 16][(heroR.y + mapOffsetYAmt + heroR.h) / 16] ) {
            case 0:
                tileTypeStrStr << "Grass";
                heroTileType = 0;
                break;
            case 1:
                tileTypeStrStr << "Road";
                heroTileType = 1;
                break;
            case 2:
                tileTypeStrStr << "Water";
                heroTileType = 2;
                break;
        }
        tileTypeStrStr >> tileTypeStr;

        */
/*
        stringstream tileTypeStrStr;
        string tileTypeStr;
        switch(textureMap[mapXAxis / 16][mapYAxis / 16] ) {
            case 0:
                tileTypeStrStr << "Grass";
                heroTileType = 0;
                break;
            case 1:
                tileTypeStrStr << "Road";
                heroTileType = 1;
                break;
            case 2:
                tileTypeStrStr << "Water";
                heroTileType = 2;
                break;
        }
        tileTypeStrStr >> tileTypeStr;

        */

        heroHealthAdj = 146 * (heroHealth/heroMaxHealth);
        heroMagicaAdj = 146 * (heroMagica/heroMaxMagica);

        xpAmt = TTF_RenderText_Solid( font, xpStr.c_str(), textColor );
        fpsDisplay = TTF_RenderText_Solid( font, st.c_str(), textColor );
        //healthDisplay = TTF_RenderText_Solid( font, healthString.c_str(), textColor );
        levelSh = TTF_RenderText_Solid( font, levelS.c_str(), textColor);
        //heroMagicaShow = TTF_RenderText_Solid(font, heroMagicaString.c_str(), textColor );
        playerXLocSurf = TTF_RenderText_Solid(font, xLocStr.c_str(), textColor);
        playerYLocSurf = TTF_RenderText_Solid(font, yLocStr.c_str(), textColor);
        tileType = TTF_RenderText_Solid(font, tileTypeStr.c_str(), textColor );


        apply_surface( SCREEN_WIDTH-70, 3, xpAmt, screen );
        //apply_surface( SCREEN_WIDTH - 60, SCREEN_HEIGHT - 35, healthDisplay, screen );
        apply_surface( 3, SCREEN_HEIGHT - 35, fpsDisplay, screen );
        if(!fast) apply_surface( 3, 3, quad, screen);
        apply_surface( SCREEN_WIDTH-70, 27, levelSh, screen);
        //apply_surface(SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60, heroMagicaShow, screen );
        //apply_surface(5, 5, playerXLocSurf, screen );
        //apply_surface(5, 30, playerYLocSurf, screen);
        //apply_surface(5, 55, tileType, screen );

        apply_surface( SCREEN_WIDTH - 155, SCREEN_HEIGHT - 35, heroHealthBarBack, screen );
        for( int ht = 0; ht < heroHealthAdj; ht++ ) {
            apply_surface( (SCREEN_WIDTH - 153) + ht, SCREEN_HEIGHT - 33, heroHealthBarTick, screen );
        }

        apply_surface( SCREEN_WIDTH - 155, SCREEN_HEIGHT - 70, heroHealthBarBack, screen );
        for( int mt = 0; mt < heroMagicaAdj; mt++ ) {
            apply_surface( (SCREEN_WIDTH - 153) + mt, SCREEN_HEIGHT - 68, heroMagicaBarTick, screen );
        }

        apply_surface( SCREEN_WIDTH - 75, 150, swordTypeSurf, screen);
        apply_surface( SCREEN_WIDTH - 80, 145, swordSquare, screen );
/*
        apply_surface( 100, SCREEN_HEIGHT - 50, itemSlotSurf[0], screen );
        apply_surface( 155, SCREEN_HEIGHT - 50, itemSlotSurf[1], screen );
        apply_surface( 210, SCREEN_HEIGHT - 50, itemSlotSurf[2], screen );
        apply_surface( 265, SCREEN_HEIGHT - 50, itemSlotSurf[3], screen );
        apply_surface( 320, SCREEN_HEIGHT - 50, itemSlotSurf[4], screen );
        apply_surface( 375, SCREEN_HEIGHT - 50, itemSlotSurf[5], screen );
*/
        for(int is = 0; is < 9; is++ ) {

            apply_surface(98+(55*is), SCREEN_HEIGHT - 52, itemSlotOutline, screen );

            switch(itemSlotItem[is])
            {
                case 0:
                    apply_surface(100 + (55*is), SCREEN_HEIGHT-50, itemSlotSurf[is], screen);
                    break;
                case 1:
                    apply_surface(100 + (55*is), SCREEN_HEIGHT-50, healthBall, screen );
                    break;
                case 2:
                    apply_surface(100 + (55*is), SCREEN_HEIGHT-50, magicaBall, screen );
                    break;
                default:
                    apply_surface(100 + (55*is), SCREEN_HEIGHT-50, itemSlotSurf[is], screen);
                    break;
            }
        }


}


void items() {
    for( int i = 0; i < healthPckNum; i++ ) {
        apply_surface( healthPckR[i].x - mapOffsetXAmt, healthPckR[i].y - mapOffsetYAmt, healthPck[i], screen );

        if( ( heroR.x + (heroR.w/2) )> (healthPckR[i].x - mapOffsetXAmt - 175) && (heroR.y  > (healthPckR[i].y -mapOffsetYAmt - 175))) {
            if( ( heroR.x + (heroR.w/2) < ((healthPckR[i].x + healthPckR[i].w + 175) - mapOffsetXAmt) ) ) {
                if( heroR.y < ((healthPckR[i].y + healthPckR[i].h + 175) - mapOffsetYAmt) ) {
                    if( wantHealthPck ) {
                        bool emptySlot = false;
                        int slotNum = 0;
                        while(!emptySlot) {
                            if(itemSlotItem[slotNum] == 0) {
                                emptySlot = true;
                                itemSlotItem[slotNum] = 1;
                                healthPck[i] = NULL;
                                healthPckR[i].w = 0;
                                healthPckR[i].h = 0;
                                healthPckR[i].x = 99999999;
                                healthPckR[i].y = 99999999;
                            } else {
                                slotNum++;
                            }
                            if( slotNum > 10) {
                                emptySlot = true;
                            }
                        }
                    }
                }
            }
        }
    }




    for( int sb = 0; sb < skelAmt; sb++ ) {
        if( skelDrop[sb] ) apply_surface(skelDeadCoord[sb].x - mapOffsetXAmt, skelDeadCoord[sb].y - mapOffsetYAmt, bagSurf, screen );

        if( ( heroR.x + (heroR.w/2) )> (skelDeadCoord[sb].x - mapOffsetXAmt - 50) && (heroR.y  > (skelDeadCoord[sb].y -mapOffsetYAmt - 50))) {
            if( ( heroR.x + (heroR.w/2) < ((skelDeadCoord[sb].x + skelDeadCoord[sb].w + 50) - mapOffsetXAmt) ) ) {
                if( heroR.y < ((skelDeadCoord[sb].y + skelDeadCoord[sb].h + 50) - mapOffsetYAmt) ) {
                    if( wantHealthPck ) {
                        bool emptySlot = false;
                        int slotNum = 0;
                        while(!emptySlot) {
                            if(itemSlotItem[slotNum] == 0) {
                                emptySlot = true;
                                itemSlotItem[slotNum] = 2;
                                skelDeadCoord[sb].x = 9999999;
                                skelDeadCoord[sb].y = -999999;
                            } else {
                                slotNum++;
                            }
                            if( slotNum > 10 ) {
                                emptySlot = true;
                            }
                        }
                    }
                }
            }
        }
    }

        //apply_surface( 150 - mapOffsetXAmt, 150 - mapOffsetYAmt, rareBagSurf, screen );

}

void Actor::mobs() {

if( !ifPortal ) {

if( mapLevel != 4 ) {

    if( mapLevel > 2 ) {
        for(int i = 0; i < zombAmt; i++ ) {
            bool zombXpCon = zombXp[i];
            bool zombDeadCon = zombDead[i];
            bool zombDropCon = zombDrop[i];
            zombie.moveMob( 0, zombRect[i], zombRespawn[i], zombDeadCon, zombHealth[i], zombHealthShow[i], zombXpCon, zombSurf[i], zombOffsetX[i], zombOffsetY[i], zombDropCon, zombDeadCoord[i] );
            zombXp[i] = zombXpCon;
            zombDead[i] = zombDeadCon;
            zombDrop[i] = zombDropCon;
        }
    }

    for(int j = 0; j < skelAmt; j++ ) {
        bool skelXpCon;
        skelXpCon = skelXp[j];
        bool skelDeadCon = skelDead[j];
        bool skelDropCon = skelDrop[j];
        skeleton.moveMob( 1, skelRect[j], skelRespawn[j], skelDeadCon, skelHealth[j], skelHealthShow[j], skelXpCon, skelSurf[j], skelOffsetX[j], skelOffsetY[j], skelDropCon, skelDeadCoord[j] );
        skelXp[j] = skelXpCon;
        skelDead[j] = skelDeadCon;
        skelDrop[j] = skelDropCon;
    }

if( mapLevel > 1 ) {
    for( int gh = 0; gh < ghostAmt; gh++ ) {
        bool ghostXpCon = ghostXp[gh];
        bool ghostDeadCon = ghostDead[gh];
        bool ghostDropCon = ghostDrop[gh];
        ghost.moveMob( 2, ghostRect[gh], ghostRespawn[gh], ghostDeadCon, ghostHealth[gh], ghostHealthShow[gh], ghostXpCon, ghostSurf[gh], ghostOffsetX[gh], ghostOffsetY[gh], ghostDropCon, ghostDeadCoord[gh] );
        ghostXp[gh] = ghostXpCon;
        ghostDead[gh] = ghostDeadCon;
        ghostDrop[gh] = ghostDropCon;
    }
}

}
}
    bool idk = true;

    if( mapLevel == 4 ) {
        bossOne.moveMob( 5, boss1Rect, ghostRespawn[1], boss1Dead, bossOneHealth, bossOneHealthSurf, boss1Xp, bossOneSurf, boss1OffsetX, boss1OffsetY, bossOneDrop, boss1DeadCoord );
        for( int mbo = 0; mbo < bossOneMiniAmt; mbo++) {

            bool bossOneMiniXpCon = bossOneMiniXp[mbo];
            bool bossOneMiniDeadCon = bossOneMiniDead[mbo];
            bool bossOneMiniDropCon = bossOneMiniDrop[mbo];
            if(!boss1Dead) bossOne.moveMob( 6, bossOneMiniRect[mbo], bossOneMiniRespawn[mbo],bossOneMiniDeadCon, bossOneMiniHealth[mbo], bossOneMiniHealthSurf[mbo], bossOneMiniXpCon, bossOneMiniSurf[mbo], bossOneMiniOffsetX[mbo], bossOneMiniOffsetY[mbo], bossOneMiniDropCon, bossOneMiniDeadCoord[mbo] );
            bossOneMiniDrop[mbo] = bossOneMiniDropCon;
            bossOneMiniDead[mbo] = bossOneMiniDeadCon;
            bossOneMiniXp[mbo] = bossOneMiniXpCon;
        }
    }

}


/////////////////////////////////////
void init() {
/////////////////////////////////////

    fileReader11 = new FileReader("Maps/maze11.txt");
    fileReader01 = new FileReader("Maps/maze01.txt");
    fileReader12 = new FileReader("Maps/maze12.txt");
    fileReader00 = new FileReader("Maps/maze00.txt");
    fileReader02 = new FileReader("Maps/maze02.txt");
    fileReader10 = new FileReader("Maps/maze10.txt");
    fileReader22 = new FileReader("Maps/maze22.txt");
    fileReader20 = new FileReader("Maps/maze20.txt");

    mainFileReader = new FileReader("Maps/Large Map/fullMap.txt");

    errorFix = new FileReader("Maps/maze21.txt");

    map = new SDL_Surface**[MAP_HEIGHT];

    for(int i = 0; i < MAP_HEIGHT; i++) {
        map[i] = new SDL_Surface*[MAP_WIDTH];
    }

    for(int i = 0; i < MAP_WIDTH; i++) {
        for(int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = NULL;
        }
    }

    SDL_Init(SDL_INIT_EVERYTHING);

    TTF_Init();

    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE );
    SDL_WM_SetCaption( "Generic RPG", NULL );
    SDL_WM_SetIcon(load_image("images/other/icon.bmp"), NULL);
}


/////////////////////////////////////
void uninit() {
/////////////////////////////////////
    for(int i = 0; i < MAP_HEIGHT; i++) {
        delete[] *map[i];
    }
    delete[] *map;
}


/////////////////////////////////////
void load_files() {
/////////////////////////////////////

    ifstream textureMapFile;
    textureMapFile.open("Maps\Large Map\fullMap.txt");
    for(int v = 0; v < 113; v++ ) {
        for(int b = 0; b > 150; v++ ) {
            textureMapFile >> textureMap[b][v];
        }
    }

    font = TTF_OpenFont( "images/other/Arial.ttf", 28 );

    largeFont = TTF_OpenFont( "images/other/Arial.ttf", 72 );

    introMusic = Mix_LoadMUS( "audio/intro.ogg" );

    gameMusic = Mix_LoadMUS( "audio/gameMusic.ogg" );

    slash = Mix_LoadWAV( "audio/slash.wav" );

    introTitle = load_image( "images/Other/title.png" );

    instruct = load_image("images/Other/instructions.png");

    introBackground = load_image( "images/Other/introBackground.jpg" );

    creditsImage = load_image( "images/Other/credits.png" );

    youLoseText = TTF_RenderText_Solid(largeFont, "You Lose!", whiteTextColor );

    heroAnimateTest = load_image("images/RPG Sprites/hero/animationTestImage.png");
    heroFront = load_image( "images/RPG Sprites/hero/mainFront.png" );
    heroBack = load_image( "images/RPG Sprites/hero/mainBack.png" );
    heroLeft = load_image( "images/RPG Sprites/hero/mainLeft.png" );
    heroRight = load_image( "images/RPG Sprites/hero/mainRight.png" );
    heroSlashRight = load_image("images/RPG Sprites/hero/slashRight.png");
    heroSlashLeft = load_image("images/RPG Sprites/hero/slashLeft.png" );
    heroSlashFront = load_image("images/RPG Sprites/hero/slashFront.png" );
    heroSlashBack = load_image("images/RPG Sprites/hero/slashBack.png");
    heroR.w = 100;
    heroR.h = 126;

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


    mobHealthBar = load_image("images/other/mobHealthBar.png");
    mobHealthBarTick = load_image("images/other/mobHealthBarTick.png");


    /*
    zombSurf[0] = load_image( "images/RPG Sprites/zombie/front.png" );
    zombRect[0].w = 100;
    zombRect[0].h = 126;

    zombSurf[1] = load_image( "images/RPG Sprites/zombie/front.png");
    zombRect[1].w = 100;
    zombRect[1].h = 126;

    zombSurf[2] = load_image("images/RPG Sprites/zombie/front.png" );
    zombRect[2].w = 100;
    zombRect[2].h = 100;
    */

    for( int hp = 0; hp < healthPckNum; hp++ ) {
        healthPck[hp] = load_image("images/items/health.png");
        healthPckR[hp].x = ( rand() % 2400 + 0 ) - 800;
        healthPckR[hp].y = ( rand() % 2400 + 0 ) - 600;
        healthPckR[hp].h = 50;
        healthPckR[hp].w = 50;
    }

    grass = load_image( "Images/Other/level1/grass4.png" );
    road = load_image( "Images/Other/level1/concrete2.png" );
    water = load_image( "Images/Other/level1/water.png" );

    backbackground = load_image( "images/Other/backbackground.png" );
    levelTick = load_image("images/HUD/levelTick.png");

    mapImage[1] = load_image("images/maps/1.png");
    mapImage[2] = load_image("images/maps/2.png");
    mapImage[3] = load_image("images/maps/3.png");



    portalSurf = load_image("images/Items/portal.png");

    bossOneSurf = load_image("images/RPG sprites/bosses/bossOne.png");


    for(int boms = 0; boms < bossOneMiniAmt; boms++ ) {
        bossOneMiniSurf[boms] = load_image("images/RPG sprites/bosses/bossOneMini.png");
        bossOneMiniHealth[boms] = 100;
        bossOneMiniRect[boms].w = 35;
        bossOneMiniRect[boms].h = 35;
        bossOneMiniRect[boms].x = (rand() % 800 + 35);
        bossOneMiniRect[boms].y = (rand() % 600 + 35);
        bossOneMiniOffsetX[boms] = rand() % (2400 + 0) - 800;
        bossOneMiniOffsetY[boms] = rand() % (1800 + 0) - 600;
    }

    heroHealthBarBack = load_image("images/HUD/healthBack.png");
    heroHealthBarTick = load_image("images/HUD/healthTick.png");
    heroMagicaBarTick = load_image("images/HUD/magicaTick.png");

    swordTypeSurf = load_image("images/items/sword1.png");
    swordSquare = load_image("images/items/swordSquare.png");

    bagSurf = load_image("images/items/bag.png");
    rareBagSurf = load_image("images/items/rareBag.png");

    introSelectRect = load_image("images/HUD/introSelect.png");

    zombHitSound = Mix_LoadWAV("Audio/zombhit.wav");

    itemSlotSurf[0] = load_image("images/HUD/itemSlots/1.png");
    itemSlotSurf[1] = load_image("images/HUD/itemSlots/2.png");
    itemSlotSurf[2] = load_image("images/HUD/itemSlots/3.png");
    itemSlotSurf[3] = load_image("images/HUD/itemSlots/4.png");
    itemSlotSurf[4] = load_image("images/HUD/itemSlots/5.png");
    itemSlotSurf[5] = load_image("images/HUD/itemSlots/6.png");
    itemSlotSurf[6] = load_image("images/HUD/itemSlots/7.png");
    itemSlotSurf[7] = load_image("images/HUD/itemSlots/8.png");
    itemSlotSurf[8] = load_image("images/HUD/itemSlots/9.png");

    itemSlotOutline = load_image("images/HUD/itemSlots/outline.png");

    healthBall = load_image("images/HUD/itemSlots/healthBall.png");
    magicaBall = load_image("images/HUD/itemSlots/magicaBall.png");

    magicaAttackSprite = load_image("images/other/magicaAttackSprite.png");
}

/////////////////////////////////////
void Actor::keyReg(SDL_Event event) {
/////////////////////////////////////

    //int x = 0, y = 0;

/*
    if(event.type == SDL_VIDEORESIZE ) {

            if( event.resize.w < 500 ) {
                event.resize.w = 500;
            }

            if( event.resize.h < 360 ) {
                event.resize.h = 360;
            }


            screen = SDL_SetVideoMode(event.resize.w, event.resize.h, SCREEN_BPP, SDL_SWSURFACE | SDL_RESIZABLE);

            x += (event.resize.w - SCREEN_WIDTH);
            y += (event.resize.h - SCREEN_HEIGHT);

            SCREEN_WIDTH = event.resize.w;
            SCREEN_HEIGHT = event.resize.h;
    }*/

    if(event.type == SDL_KEYDOWN) {

        keyDown = true;

        switch( event.key.keysym.sym ) {
        case SDLK_w:
            if(controlMode == 0) playerUp = true;
            if(controlMode == 0)charPos = 2;
            break;
        case SDLK_s:
            if(controlMode == 0) playerDown = true;
            if(controlMode == 0) charPos = 1;
            break;
        case SDLK_a:
            if(controlMode == 0) playerLeft = true;
            if(controlMode == 0) charPos = 3;
            break;
        case SDLK_d:
            if(controlMode == 0) playerRight = true;
            if(controlMode == 0) charPos = 4;
            break;
        case SDLK_q:
            heroMagicaWant = true;
            break;
        case SDLK_F5:
            screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_FULLSCREEN );
            break;
        case SDLK_F11:
            saveGame(gameSaveInt);
            break;
        case SDLK_SPACE:
            if(controlMode == 0 ) playerSlash = true;
            while(!spaceClick) {
                attackTime = SDL_GetTicks();
                spaceClick = true;
            }
            break;
        case SDLK_F1:
            controlMode = 0;
            break;
        case SDLK_F2:
            controlMode = 1;
            break;
        //case SDLK_CAPSLOCK:
            //if(!heroTeleOnce) heroTele = true;
            //break;
        case SDLK_e:
            wantHealthPck = true;
            wantPortal = true;
            useKey = true;
            break;

        case SDLK_f:
            magicAttackUse = true;
            break;

        case SDLK_1:
            switch(itemSlotItem[0]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[0] = 0;

            break;

        case SDLK_2:
            switch(itemSlotItem[1]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[1] = 0;

            break;

        case SDLK_3:
            switch(itemSlotItem[2]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[2] = 0;

            break;

        case SDLK_4:
            switch(itemSlotItem[3]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[3] = 0;

            break;

        case SDLK_5:
            switch(itemSlotItem[4]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[4] = 0;

            break;

        case SDLK_6:
            switch(itemSlotItem[5]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[5] = 0;

            break;

        case SDLK_7:
            switch(itemSlotItem[6]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[6] = 0;

            break;

        case SDLK_8:
            switch(itemSlotItem[7]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[7] = 0;

            break;

        case SDLK_9:
            switch(itemSlotItem[8]) {
                case 1:
                    heroHealth += 100;
                    break;
                case 2:
                    heroMagica += 50;
                    break;
            }

            itemSlotItem[8] = 0;

            break;

        default:
            break;
        }


    }

    if(event.type == SDL_KEYUP) {

        keyDown = false;

        switch( event.key.keysym.sym ) {
        case SDLK_w:
            playerUp = false;
            break;
        case SDLK_s:
            playerDown = false;
            break;
        case SDLK_a:
            playerLeft = false;
            break;
        case SDLK_d:
            playerRight = false;
            break;
        case SDLK_F5:
            screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_FULLSCREEN );
            break;
        case SDLK_q:
            heroMagicaWant = false;
            break;
        case SDLK_e:
            wantHealthPck = false;
            wantPortal = false;
            useKey = false;
            break;

        case SDLK_f:
            magicAttackUse = false;
            break;

        case SDLK_SPACE:
            spaceClick = false;
            playerSlash = false;
            playSlash = false;
            break;
        case SDLK_RETURN:
            devPortalSkip = true;
            break;
        default:
            break;
        }


    }

    //x = event.motion.x;
    //y = event.motion.y;

    if( event.type == SDL_MOUSEBUTTONDOWN ) {
        if( (event.button.button == SDL_BUTTON_LEFT) && controlMode == 1 ) {
            playerSlash = true;
            while(!spaceClick) {
                    attackTime = SDL_GetTicks();
                    spaceClick = true;
            }
        }
        if( (event.button.button == SDL_BUTTON_RIGHT) && controlMode == 1 ) {
            mouseDesX = x;
            mouseDesY = y;
        }
    }
    if( event.type == SDL_MOUSEBUTTONUP ) {
        if( event.button.button == SDL_BUTTON_LEFT ) {
            spaceClick = false;
            playerSlash = false;
            playSlash = false;
        }
    }

    if(event.type == SDL_QUIT) {
        quit = true;
    }
}




//////////////////////////////////
void movePlayer( SDL_Event event ) {
//////////////////////////////////
    int xVel = 0;
    int yVel = 0;
if(controlMode == 0) {
    if( playerDown ) {
        yVel = 1;
    } else if( !playerDown ) {
        yVel = 0;
    }

    if( playerUp ) {
        yVel = -1;
    }

    if( playerRight ) {
        xVel = 1;
    }

    if( playerLeft ) {
        xVel = -1;

    }
}
if(controlMode == 1) {
    if( (heroR.x + 50) < mouseDesX ) xVel++;
    else if((heroR.x + 50) > mouseDesX ) xVel--;

    if( (heroR.y + 63) < mouseDesY ) yVel++;
    else if((heroR.y + 63) > mouseDesY ) yVel--;
}

if( !ifNoSound ) {
    if( !playSlash && playerSlash && !devModeB ) { Mix_PlayChannel( -1, slash, 0 ); playSlash = true; }
}

    hero.slashTime();
    hero.move( xVel, yVel );
}


/////////////////////////////////////
void drawMap( int **intMap ) {
/////////////////////////////////////

    for(int i = 0; i < MAP_WIDTH; i++) {
        for(int j = 0; j < MAP_HEIGHT; j++) {
            switch(intMap[j][i]) {
            case 0:
                apply_surface( (i * 16 ), ( j * 16 ), grass, screen );
                break;
            case 1:
                apply_surface( (i * 16 ), ( j * 16 ), road, screen );
                break;
            case 2:
                apply_surface( (i * 16 ), ( j * 16 ), water, screen );
                break;
            default:
                break;
            }
        }
    }
}

/////////////////////////////////////
void drawMapFast( int offsetX, int offsetY, int **intMap ) {
/////////////////////////////////////

    for(int i = 0; i < MAP_WIDTH; i++) {
        for(int j = 0; j < MAP_HEIGHT; j++) {
            switch(intMap[j][i]) {
            case 2:
                if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                        if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                            apply_surface( ((i * 16 ) - mapOffsetXAmt) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, water, screen );
                         }
                    }
                }

                //textureMap[i + offsetX][j + offsetY] = 2;
                break;
            case 1:
                if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                        if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( ((i * 16 ) - mapOffsetXAmt ) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, road, screen );
                        }
                    }
                }

                    //textureMap[i + offsetX][j + offsetY] = 1;
                break;
            case 0:
                if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 800 ) {
                        if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( ((i * 16 ) - mapOffsetXAmt) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, grass, screen );
                            }
                        }
                    }

                //textureMap[i + offsetX][j + offsetY] = 0;
                break;
            default:
                break;
            }
        }
    }


}


/////////////////////////////////////
void drawMapFast1( int offsetX, int offsetY, int **intMap ) {
/////////////////////////////////////

    for(int i = 0; i < MAP_WIDTH; i++) {
        for(int j = 0; j < MAP_HEIGHT; j++) {
            switch(intMap[j][i]) {
            case 2:
                //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                        //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( (((((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH) + resizeX), ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, water, screen );
                         //}
                    //}
                //}

                //textureMap[j + (offsetX / 16)][i + (offsetY / 16)] = 2;
                break;
            case 1:
                //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                        //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( (((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH+ resizeX, ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, road, screen );
                        //}
                    //}
                //}

                    //textureMap[j + (offsetX / 16)][i + (offsetY / 16)] = 1;
                break;
            case 0:
                //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 800 ) {
                        //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( (((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH + resizeX, ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, grass, screen );
                        //}
                    //}
                //}

                //textureMap[i + offsetX][j + offsetY] = 0;
                break;
            default:
                break;
            }
        }
    }

}


