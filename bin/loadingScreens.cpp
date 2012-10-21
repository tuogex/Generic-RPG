#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <sstream>
#include <fstream>

#include "headers/game_engine.h"
#include "headers/SDL_functions.h"
#include "headers/globals.h"
#include "headers/file_reader.h"
#include "headers/functions.h"
#include "headers/timer.h"
#include "headers/loadingScreens.h"

using namespace std;

/////////////////////////////////////
int intro() {
/////////////////////////////////////

    screen = SDL_SetVideoMode( 800, 600, SCREEN_BPP, SDL_SWSURFACE );

    if( !ifNoSound) Mix_PlayMusic( introMusic, -1 );

    introMessage = TTF_RenderText_Solid( font, "Sub-Par Game Dev presents...", whiteTextColor );

    pressStart = TTF_RenderText_Solid( font, "Press 'Enter'", textColor );



    SDL_Flip(screen);

    Uint32 timer = SDL_GetTicks();

    bool endIntro = false;

    int xSlow;
    int ySlow;

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
                if(event.key.keysym.sym == SDLK_RETURN) {
                    endIntro = true;
                }


                endIntro = true;
			}

			if( event.type == SDL_QUIT )
			{

                quit = true;
			}
		}


        drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT * 2, fileReader12->map);
        drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT, fileReader11->map);
        drawMapFast1(SCREEN_WIDTH, 0, fileReader10->map);

        drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT, fileReader01->map);
        drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, fileReader02->map);
        drawMapFast1(SCREEN_WIDTH * 2, 0, fileReader00->map);

        drawMapFast1(0, SCREEN_HEIGHT, errorFix->map);
        drawMapFast1(0, SCREEN_HEIGHT * 2, fileReader22->map);
        drawMapFast1(0, 0, fileReader20->map);


        //imageMapRender();

        if(xSlow == 0) {
            mapOffsetXAmt--;
            mapOffsetYAmt++;
            xSlow = 1;
        } else {
            xSlow = 0;
        }

        apply_surface( 0, 0, introBackground, screen );

        apply_surface( 165, 30, TTF_RenderText_Solid( largeFont , "Generic RPG", textColor), screen );

        apply_surface( 295, 300, pressStart, screen );

        SDL_Flip(screen);
	}

	int x = mapOffsetYAmt;
if(!quit) {
	for( int i = 0; i <= x; i++ ) {


        drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT * 2, fileReader12->map);
        drawMapFast1(SCREEN_WIDTH, SCREEN_HEIGHT, fileReader11->map);
        drawMapFast1(SCREEN_WIDTH, 0, fileReader10->map);

        drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT, fileReader01->map);
        drawMapFast1(SCREEN_WIDTH * 2, SCREEN_HEIGHT * 2, fileReader02->map);
        drawMapFast1(SCREEN_WIDTH * 2, 0, fileReader00->map);

        drawMapFast1(0, SCREEN_HEIGHT, errorFix->map);
        drawMapFast1(0, SCREEN_HEIGHT * 2, fileReader22->map);
        drawMapFast1(0, 0, fileReader20->map);


        //imageMapRender();

        mapOffsetXAmt++;
        mapOffsetYAmt--;

        SDL_Flip(screen);
	}
}

}






/////////////////////////////////////
void credits() {
/////////////////////////////////////

    screen = SDL_SetVideoMode( 800, 600, SCREEN_BPP, SDL_SWSURFACE );

    saveGame(gameSaveInt);

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

    screen = SDL_SetVideoMode( 800, 600, SCREEN_BPP, SDL_SWSURFACE );

    SDL_FillRect(screen,NULL,0x000000);

    ofstream saveNum;
    switch(gameSaveInt) {
        case 1:
            saveNum.open("settings/saves/one");
        break;

        case 2:
            saveNum.open("settings/saves/two");
        break;

        case 3:
            saveNum.open("settings/saves/three");
        break;
    }

    saveNum << "0";
    saveNum.close();

    SDL_Surface *finalLevel = NULL;
    SDL_Surface *timeSurvived = NULL;

    stringstream levelss;
    levelss << "Final.level-" << gameLevel;
    string levels;
    levelss >> levels;

    stringstream timess;
    timess << "Time.survived-" << totalGameTime.get_ticks() / 1000;
    string times;
    timess >> times;

    finalLevel = TTF_RenderText_Solid(font, levels.c_str(), whiteTextColor);
    timeSurvived = TTF_RenderText_Solid(font, times.c_str(), whiteTextColor );


    apply_surface( 230, 200, youLoseText, screen );
    apply_surface(290,300, finalLevel, screen );
    apply_surface(290, 350, timeSurvived, screen );
    SDL_Flip(screen);
    SDL_Delay(1000);

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
        ifNoSound = true;
    } else if( devModeStr == "no" ) {
        devModeB = false;
    } else {
        devModeError = true;
        return false;
    }

    ifstream ifOrti;
    ifOrti.open("settings/13centurycalamity");
    string ifOrts;
    ifOrti >> ifOrts;
    if(ifOrts == "1" ) {
        ifOrtSetting = true;
    } else if(ifOrts == "0") {
        ifOrtSetting = false;
    } else {
        return false;
    }

    ifstream musicPreference;
    musicPreference.open("settings/musicPref");
    string musicString;
    musicPreference >> musicString;
    if( musicString == "1") {
        ifNoSound = false;
    } else if( musicString == "2" ) {
        ifNoSound = true;
    }

    ifstream xWin;
    xWin.open("settings/xWinSize");
    xWin >> SCREEN_WIDTH;

    ifstream yWin;
    yWin.open("settings/yWinSize");
    yWin >> SCREEN_HEIGHT;

    ifstream gameSave;
    gameSave.open("settings/saveGame");
    gameSave >> gameSaveInt;

    return true;
}


void logFile() {
    ofstream myfile;
    myfile.open("log.txt");
    myfile << "Total time spent in game: " << totalGameTime.get_ticks() / 1000 << " seconds" << endl;
    myfile << "Average fps: " << ( totalGameFrames / ( (totalGameTime.get_ticks()) / 1000 ) ) << endl;
    myfile << "Total frames: " << totalGameFrames << endl << endl;

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
