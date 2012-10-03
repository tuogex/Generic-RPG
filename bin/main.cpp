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

#include "headers/game_engine.h"
#include "headers/SDL_functions.h"
#include "headers/globals.h"
#include "headers/file_reader.h"
#include "headers/functions.h"
#include "headers/timer.h"
#include "headers/windowEvents.h"



using namespace std;

/////////////////////////////////////
int main(int argc, char **argv) {
/////////////////////////////////////

    bool failSkip = false;

    srand(time(NULL));

    //if( !loginTest() ) return 0;

    bool lose;

    init();

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

    for( int qx = 0; qx < ortAmt; qx++ ) {
        ortRect[qx].x = rand() % (480 + 240) - 800;
        ortRect[qx].y = rand() % (317 + 240) + 600;
    }

    for( int wx = 0; wx < ortAmt; wx++ ) {
        ortOffsetX[wx] = 1000;
        ortOffsetY[wx] = 1000;
    }

/*
    zombRect[0].x = rand() % 480 + 240;
    zombRect[0].y = rand() % 317 + 10;

    zombRect[1].x = rand() % 240 + 10;
    zombRect[1].y = rand() % 317 + 10;

    zombRect[2].x = ( rand() % 240 + 10 ) - 800;
    zombRect[2].y = ( rand() % 317 + 10 ) - 600;
*/
    load_files();

    if(!settingsFile()) return -1;

    if( !devModeB) intro();
    if( !devModeB) instructScreen(event);

    apply_surface( 0, 0, introBackground, screen );
    SDL_Flip(screen);

    Uint32 fpsReg = SDL_GetTicks();

    if( devModeB == false ) Mix_PlayMusic( gameMusic, -1 );

    fpsTime.start();
    update.start();

    while(quit == false) {

        SDL_PollEvent(&event);
        axisMath();
        SDL_FillRect(screen,NULL,0xFFFFFF);
        hero.slashTime();
        gameTime = SDL_GetTicks() - startTime;
        HUD();
        mapPicker();
        HUD();
        skeleton.mobs();
        items();
        keyReg(event);
        movePlayer(event);
        HUD();

        SDL_Flip(screen);
        frameCount++;
        fpsCalc();

        if( heroHealth <= 0 ) {
            quit = true;
            lose = true;
        } else {
            lose = false;
        }
        hero.slashTime();
    }

    ofstream arrayFile;
    arrayFile.open("textureMap.txt");

    for(int i = 1; i < 150; i++ ) {
        for(int j = 1; j < 113; j++) {
            arrayFile << textureMap[i][j];
        }
        arrayFile << endl;
    }

    arrayFile.close();

    if( lose ) playerLose(event);

    if( !devModeB ) credits();

    logFile();

    uninit();

    return 0;
}

void axisMath() {
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


    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT * 2, fileReader12->map);
    drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT, fileReader11->map);
    drawMapFast1(SCREEN_WIDTH, 0, fileReader10->map);

    drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT, fileReader01->map);
    drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, fileReader02->map);
    drawMapFast1(SCREEN_WIDTH * 2, 0, fileReader00->map);

    drawMapFast1(0, SCREEN_HEIGHT, errorFix->map);
    drawMapFast1(0, SCREEN_HEIGHT * 2, fileReader22->map);
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

        stringstream qq;
        qq << heroMagica;
        string heroMagicaString;
        qq >> heroMagicaString;

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

        xpAmt = TTF_RenderText_Solid( font, xpStr.c_str(), textColor );
        fpsDisplay = TTF_RenderText_Solid( font, st.c_str(), textColor );
        healthDisplay = TTF_RenderText_Solid( font, healthString.c_str(), textColor );
        levelSh = TTF_RenderText_Solid( font, levelS.c_str(), textColor);
        heroMagicaShow = TTF_RenderText_Solid(font, heroMagicaString.c_str(), textColor );
        playerXLocSurf = TTF_RenderText_Solid(font, xLocStr.c_str(), textColor);
        playerYLocSurf = TTF_RenderText_Solid(font, yLocStr.c_str(), textColor);
        tileType = TTF_RenderText_Solid(font, tileTypeStr.c_str(), textColor );


        apply_surface( SCREEN_WIDTH-70, 3, xpAmt, screen );
        apply_surface( SCREEN_WIDTH - 60, SCREEN_HEIGHT - 35, healthDisplay, screen );
        apply_surface( 3, SCREEN_HEIGHT - 35, fpsDisplay, screen );
        if(!fast) apply_surface( 3, 3, quad, screen);
        apply_surface( SCREEN_WIDTH-70, 27, levelSh, screen);
        apply_surface(SCREEN_WIDTH - 60, SCREEN_HEIGHT - 60, heroMagicaShow, screen );
        apply_surface(5, 5, playerXLocSurf, screen );
        apply_surface(5, 30, playerYLocSurf, screen);
        //apply_surface(5, 55, tileType, screen );


}


void items() {
    apply_surface( healthPckR.x - mapOffsetXAmt, healthPckR.y - mapOffsetYAmt, healthPck, screen );

    if( ( heroR.x + (heroR.w/2) )> (healthPckR.x - mapOffsetXAmt - 175) && (heroR.y  > (healthPckR.y -mapOffsetYAmt - 175))) {
        if( ( heroR.x + (heroR.w/2) < ((healthPckR.x + healthPckR.w + 175) - mapOffsetXAmt) ) ) {
            if( heroR.y < ((healthPckR.y + healthPckR.h + 175) - mapOffsetYAmt) ) {
                if( wantHealthPck ) {
                    heroHealth += 150;
                    healthPck = NULL;
                    healthPckR.w = 0;
                    healthPckR.h = 0;
                    healthPckR.x = 99999999;
                    healthPckR.y = 99999999;
                }
            }
        }
    }
}

void Actor::mobs() {
    for(int i = 0; i < zombAmt; i++ ) {
        zombie.moveMob( 0, zombRect[i], zombRespawn[i], zombDead[i], zombHealth[i], zombHealthShow[i], zombXp[i], zombSurf[i], zombOffsetX[i], zombOffsetY[i] );
    }

    for(int j = 0; j < skelAmt; j++ ) {
        skeleton.moveMob( 1, skelRect[j], skelRespawn[j], skelDead[j], skelHealth[j], skelHealthShow[j], skelXp[j], skelSurf[j], skelOffsetX[j], skelOffsetY[j] );
    }

    if(ifOrt) {
        for(int k = 0; k < ortAmt; k++ ) {
            ortman.moveMob( 1, ortRect[k], ortRespawn[k], ortDead[k], ortHealth[k], ortHealthShow[k], ortXp[k], ortSurf[k], ortOffsetX[k], ortOffsetY[k] );
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

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    SDL_WM_SetCaption( "Generic RPG", NULL );
    SDL_WM_SetIcon(load_image("images/icon.bmp"), NULL);
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

    font = TTF_OpenFont( "arial.ttf", 28 );

    largeFont = TTF_OpenFont( "arial.ttf", 72 );

    introMusic = Mix_LoadMUS( "audio/intro.ogg" );

    gameMusic = Mix_LoadMUS( "audio/gameMusic.ogg" );

    slash = Mix_LoadWAV( "audio/slash.wav" );

    introTitle = load_image( "images/title.png" );

    instruct = load_image("images/instructions.png");

    introBackground = load_image( "images/introBackground.jpg" );

    creditsImage = load_image( "images/credits.png" );

    youLoseText = TTF_RenderText_Solid(largeFont, "You Lose!", whiteTextColor );

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

    for( int i = 0; i < zombAmt; i++ ) {
        zombSurf[i] = load_image("images/RPG Sprites/zombie/front.png");
        zombRect[i].w = 100;
        zombRect[i].h = 126;
    }
    for( int j = 0; j < skelAmt; j++ ) {
        skelSurf[j] = load_image("images/RPG Sprites/skel/front.png");
        skelRect[j].w = 100;
        skelRect[j].h = 126;
    }

    for( int xy = 0; xy < ortAmt; xy++ ) {
        ortSurf[xy] = load_image("images/RPG Sprites/ort/front.png");
        ortRect[xy].w = 100;
        ortRect[xy].h = 126;
    }

    for( int u = 0; u < zombAmt; u++ ) {
        zombHealth[u] = 500;
    }

    for( int y = 0; y < skelAmt; y++ ) {
        skelHealth[y] = 250;
    }

    for( int yx = 0; yx < ortAmt; yx++ ) {
        ortHealth[yx] = 250;
    }


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

    healthPck = load_image("images/items/health.png");
    healthPckR.x = 500;
    healthPckR.y = 500;
    healthPckR.h = 50;
    healthPckR.w = 50;

    grass = load_image( "Images/grass4.png" );
    road = load_image( "Images/concrete2.png" );
    water = load_image( "Images/water.png" );

    backbackground = load_image( "images/backbackground.png" );
}

/////////////////////////////////////
void keyReg(SDL_Event event) {
/////////////////////////////////////

    int x = 0, y = 0;
    if(event.type == SDL_KEYDOWN) {
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
        case SDLK_CAPSLOCK:
            if(!heroTeleOnce) heroTele = true;
            break;
        case SDLK_c:
            wantHealthPck = true;
            break;
        default:
            break;
        }
        if(event.type == SDL_KEYDOWN ) {
            if((event.key.keysym.sym == SDLK_o))
                ifOrt = true;
        }


    }

    if(event.type == SDL_KEYUP) {
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
            heroTeleOnce = false;
            heroTele = false;
            break;
        case SDLK_c:
            wantHealthPck = false;
            break;
        case SDLK_SPACE:
            spaceClick = false;
            playerSlash = false;
            playSlash = false;
            break;
        default:
            break;
        }


    }

    x = event.motion.x;
    y = event.motion.y;

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
    if( !playSlash && playerSlash && !devModeB ) { Mix_PlayChannel( -1, slash, 0 ); playSlash = true; }

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
                //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                        //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                            apply_surface( ((i * 16 ) - mapOffsetXAmt) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, water, screen );
                         //}
                    //}
                //}

                //textureMap[i + offsetX][j + offsetY] = 2;
                break;
            case 1:
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                        //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 810 ) {
                            //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                                //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( ((i * 16 ) - mapOffsetXAmt ) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, road, screen );
                            //}
                        //}
                    //}

                    //textureMap[i + offsetX][j + offsetY] = 1;
                break;
            case 0:
                //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) >= -10 ) {
                    //if( ( ((i * 16 ) - mapOffsetXAmt) - offsetX ) <= 800 ) {
                        //if( ( (( j * 16 ) - mapOffsetYAmt) ) >= -100 ) {
                            //if( (( j * 16 ) - mapOffsetYAmt) <= 1500 )
                                apply_surface( ((i * 16 ) - mapOffsetXAmt) - offsetX, (( j * 16 ) - mapOffsetYAmt) - offsetY, grass, screen );
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
                            apply_surface( (((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH, ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, water, screen );
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
                                apply_surface( (((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH, ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, road, screen );
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
                                apply_surface( (((i * 16 ) - mapOffsetXAmt) - offsetX) + SCREEN_WIDTH, ((( j * 16 ) - mapOffsetYAmt) - offsetY) + SCREEN_HEIGHT, grass, screen );
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


/////////////////////////////////////
int intro() {
/////////////////////////////////////

/*
    Mix_PlayMusic( introMusic, -1 );

    introMessage = TTF_RenderText_Solid( font, "Sub-Par Game Dev presents...", whiteTextColor );

    pressStart = TTF_RenderText_Solid( font, "Press 'Enter'", whiteTextColor );



    SDL_Flip(screen);

    Uint32 timer = SDL_GetTicks();

    bool endIntro = false;

	while( ( endIntro == false ) && ( quit == false ) )
	{
		if( SDL_PollEvent( &event ) )
		{

			if( event.type == SDL_KEYDOWN )
			{

                if( event.key.keysym.sym == SDLK_ESCAPE )
				{

                    quit = true;
                }


                endIntro = true;
			}

			if( event.type == SDL_QUIT )
			{

                quit = true;
            }
		}

		timer = SDL_GetTicks();


		if( timer > 3000 )
		{

            endIntro = true;
        }
	}

    apply_surface( 0, 0, introBackground, screen );

    apply_surface( 145, 30, introTitle, screen );

    apply_surface( 235, 300, pressStart, screen );

    SDL_Flip(screen);

    bool enter = false;

    while( ( enter == false ) && ( quit == false ) ) {
        while( SDL_PollEvent( &event ) ) {
            if( event.type == SDL_KEYDOWN ) {
                if( event.key.keysym.sym == SDLK_RETURN ) {
                    enter = true;
                }
            }
        }
    }
*/
}

void instructScreen( SDL_Event event ) {

    bool instructQuit = false;

    while( !quit && !instructQuit ) {
        SDL_PollEvent(&event);
        apply_surface( 0, 0, instruct, screen );
        SDL_Flip(screen);
        if(event.type == SDL_QUIT) quit = true;

        if(event.type == SDL_KEYDOWN ) instructQuit = true;
        if( event.type == SDL_MOUSEBUTTONDOWN ) instructQuit = true;
    }

}

/////////////////////////////////////
void credits() {
/////////////////////////////////////

    apply_surface( 0, 0, creditsImage, screen );
    SDL_Flip( screen );

    bool quit2 = false;

    while( quit2 == false ) {
        while( SDL_PollEvent( &event ) ) {
            if( event.type == SDL_KEYDOWN ) {
                    quit2 = true;
            }

            if( event.type == SDL_QUIT ) {
                quit = true;
                quit2 = true;
            }
        }
    }

}


void playerLose( SDL_Event event ) {
    SDL_FillRect(screen,NULL,0x000000);
    apply_surface( 230, 200, youLoseText, screen );
    SDL_Flip(screen);
    SDL_Delay(500);

    /*
    bool quit2;
    apply_surface( 0, 0, introBackground, screen );
    apply_surface( 230, 200, youLoseText, screen );
    SDL_Flip(screen);
    while( !quit2 ) {
        while( SDL_PollEvent(&event) ) {
            if( event.type == SDL_KEYDOWN ) quit2 = true;
            if( event.type == SDL_QUIT ) quit2 = true;
            if( event.type == SDL_MOUSEBUTTONDOWN ) quit2 = true;
        }
    }
    */
}


bool settingsFile() {
    ifstream graphics;
    graphics.open("settings/graphics");
    string graphicsStr;
    graphics >> graphicsStr;
    if( graphicsStr == "high" ) fast = true;
    else if(graphicsStr == "low" ) fast = false;
    else {
        graphicsFail = true;
        return false;
    }

    ifstream difficulty;
    difficulty.open("settings/difficulty");
    string difficultyStr;
    difficulty >> difficultyStr;
    if( difficultyStr == "easy" ) {
        heroHealth = 1000;
        heroMaxHealth = 1000;
        heroHealthUpSpd = 500;

        heroMagica = 1000;
        heroMaxMagica = 1000;
        heroMagicaUpSpd = 200;

        difficultyLevel = 0;
    } else if( difficultyStr == "medium" ) {

        heroHealth = 500;
        heroMaxHealth = 500;
        heroHealthUpSpd = 400;

        heroMagica = 250;
        heroMaxMagica = 250;
        heroMagicaUpSpd = 200;

        difficultyLevel = 1;
    } else if( difficultyStr == "hard" ) {

        heroHealth = 400;
        heroMaxHealth = 400;
        heroHealthUpSpd = 375;

        heroMagica = 200;
        heroMaxMagica = 200;
        heroMagicaUpSpd = 200;

        difficultyLevel = 2;
    } else{
        difficultyFail = true;
        return false;
    }

    ifstream devMode;
    devMode.open("settings/development-mode");
    string devModeStr;
    devMode >> devModeStr;
    if( devModeStr == "yes" ) {
        devModeB = true;
    } else if( devModeStr == "no" ) {
        devModeB = false;
    } else {
        devModeError = true;
        return false;
    }

    return true;
}

void logFile() {
    ofstream myfile;
    myfile.open("log.txt");
    myfile << "Total time spent in game: " << SDL_GetTicks() / 1000 << " seconds" << endl;
    myfile << "Average fps: " << ( frameCount / ( (SDL_GetTicks() - startTime) / 1000 ) ) << endl;
    myfile << "Total frames: " << frameCount << endl << endl;

    myfile << "Difficulty: ";
    switch(difficultyLevel) {
        case 0:
            myfile << "easy" << endl;
            break;
        case 1:
            myfile << "medium" << endl;
            break;
        case 2:
            myfile << "hard" << endl;
            break;
        default:
            myfile << "NULL" << endl;
            break;
    }

    myfile << "Graphics level: ";
    if(fast) myfile << "high" << endl;
    else if(!fast) myfile << "low" << endl;
    else myfile << "NULL";

    myfile << endl;

    myfile << "SDL Init: ";
    if( initFail ) myfile << "FAILED" << endl;
    else myfile << "SUCCEDED" << endl << endl;

    myfile << "Development Mode Loader: ";
    if( !devModeError ) myfile << "SUCCEDED" << endl;
    else myfile<< "FAILED" << endl;

    myfile << "Graphics setting loader: ";
    if( graphicsFail ) myfile << "FAILED" << endl;
    else myfile << "SUCCEDED" << endl;

    myfile << "Difficulty setting loader: ";
    if( difficultyFail ) myfile << "FAILED" << endl;
    else myfile << "SUCCEDED" << endl;

    ofstream reset;
    reset.open("settings\login data\ifLogin");
    reset << "";

    myfile.close();

}


bool loginTest() {

    ifstream file;
    file.open("settings\login data\ifLogin");
    string test;
    file >> test;
    if( test == "011110010110010101110011")
    return true;
}
