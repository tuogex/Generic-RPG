//GLOBALS.H

#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <vector>

#include "file_reader.h"
#include "game_engine.h"
#include "timer.h"

extern SDL_Thread *consoleThread;

extern int mapLevel;
extern bool ifPortal;
extern bool wantPortal;

extern bool useKey;

extern bool devPortalSkip;

extern bool moveOn;

extern int MAP_WIDTH;
extern int MAP_HEIGHT;

extern int resizeX;
extern int resizeY;

extern int gameSaveInt;

extern int textureMap[150][113];
extern std::string tileTypeStr;
extern int heroTileType;

extern bool ifOrt;
extern bool ifOrtSetting;

extern bool fast;
extern int difficultyLevel;
extern bool devModeB;

extern bool difficultyFail;
extern bool graphicsFail;
extern bool devModeError;

extern bool initFail;

extern int zombAmt;
extern int skelAmt;
extern int ortAmt;
extern int ghostAmt;
extern const int healthPckNum;

extern Uint32 startTime;
extern Uint32 gameTime;

extern int controlMode;

extern int xp;
extern std::vector<bool> zombXp;
extern std::vector<bool> skelXp;
extern std::vector<bool> ortXp;
extern std::vector<bool> ghostXp;

/*
extern bool skelXp[];
extern bool ortXp[];
extern bool ghostXp[];
*/

extern bool boss1Xp;


extern std::vector<signed int> zombOffsetX;
extern std::vector<signed int> zombOffsetY;

extern signed int boss1OffsetX;
extern signed int boss1OffsetY;

extern std::vector<signed int> skelOffsetX;
extern std::vector<signed int> skelOffsetY;

extern std::vector<signed int> ortOffsetX;
extern std::vector<signed int> ortOffsetY;

extern std::vector<signed int> ghostOffsetX;
extern std::vector<signed int> ghostOffsetY;

extern int level;
extern int gameLevel;
extern int totalEnemyKills;
extern int previousLevelKills;
extern int gameLevelKillsNeeded;

extern std::vector<SDL_Rect> zombRect;
extern std::vector<SDL_Rect> skelRect;
extern std::vector<SDL_Rect> ortRect;
extern std::vector<SDL_Rect> ghostRect;
extern SDL_Rect boss1Rect;

extern int mapDetail[50][38];

extern SDL_Rect heroR;
extern bool heroSpawn;

extern const int FRAMES_PER_SECOND;
extern Timer fpsTime;
extern Timer update;
extern int totalGameFrames;
extern Timer totalGameTime;
extern int currentFps;
extern int heroUpdateTime;

extern Uint32 heroMoveTimerReset;
extern Uint32 mapOffsetTimer;

extern int heroX;
extern int heroY;

extern float heroHealth;
extern float heroHealthAdj;
extern float heroMaxHealth;
extern Uint32 heroHealthTimer;
extern Uint32 heroHealthTimerSub;
extern int heroHealthUpSpd;

extern bool heroTele;
extern bool heroTeleOnce;

extern float heroMagica;
extern float heroMagicaAdj;
extern bool heroMagicaWant;
extern float heroMaxMagica;
extern Uint32 heroMagicaTimer;
extern Uint32 heroMagicaTimerSub;
extern int heroMagicaUpSpd;

extern int swordType;

extern std::vector<bool> zombDead;
extern std::vector<bool> skelDead;
extern std::vector<bool> ortDead;
extern std::vector<bool> ghostDead;
extern bool boss1Dead;

extern std::vector<Uint32> zombRespawn;
extern std::vector<Uint32> skelRespawn;
extern std::vector<Uint32> ortRespawn;
extern std::vector<Uint32> ghostRespawn;

extern std::vector<unsigned int> zombHealth;
extern std::vector<unsigned int> skelHealth;
extern std::vector<unsigned int> ortHealth;
extern std::vector<unsigned int> ghostHealth;
extern unsigned int bossOneHealth;

extern int mapAmt;

extern int mapPickX;
extern int mapPickY;

extern unsigned int mapXAxis;
extern unsigned int mapYAxis;

extern SDL_Rect healthPckR[];
extern bool wantHealthPck;


extern FileReader *fileReader11;
extern FileReader *fileReader01;
extern FileReader *fileReader12;
extern FileReader *fileReader00;
extern FileReader *fileReader02;
extern FileReader *fileReader10;
extern FileReader *fileReader20;
extern FileReader *fileReader21;
extern FileReader *fileReader22;

extern FileReader *mainFileReader;

extern SDL_Rect scrollRect;

extern int mapOffsetXAmt;
extern int mapOffsetYAmt;

extern FileReader *errorFix;


extern int fpsCounter;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern const int SCREEN_BPP;

extern TTF_Font *font;
extern TTF_Font *largeFont;
extern SDL_Color textColor;
extern SDL_Color whiteTextColor;

extern SDL_Surface *screen;
extern SDL_Surface ***map;
extern SDL_Surface *FPS;
extern SDL_Surface *introMessage;
extern SDL_Surface *instruct;
extern SDL_Surface *introTitle;
extern SDL_Surface *introBackground;
extern SDL_Surface *pressStart;
extern SDL_Surface *creditsImage;
extern SDL_Surface *youLoseText;
extern SDL_Surface *healthDisplay;
extern SDL_Surface *heroFront;
extern SDL_Surface *heroAnimateTest;
extern SDL_Surface *heroBack;
extern SDL_Surface *heroLeft;
extern SDL_Surface *heroRight;
extern SDL_Surface *heroSlashRight;
extern SDL_Surface *heroSlashLeft;
extern SDL_Surface *heroSlashFront;
extern SDL_Surface *heroSlashBack;
extern SDL_Surface *zombBack;
extern SDL_Surface *zombLeft;
extern SDL_Surface *zombRight;
extern SDL_Surface *backbackground;
extern SDL_Surface *fpsDisplay;
extern SDL_Surface *tileType;
extern SDL_Surface *playerXLocSurf;
extern SDL_Surface *playerYLocSurf;
extern SDL_Surface *grass;
extern SDL_Surface *road;
extern SDL_Surface *water;
extern SDL_Surface *quad;
extern SDL_Surface *xpAmt;
extern SDL_Surface *levelSh;
extern SDL_Surface *levelTick;

extern SDL_Surface *portalSurf;

extern std::vector<SDL_Surface*> zombHealthShow;
extern std::vector<SDL_Surface*> skelHealthShow;
extern std::vector<SDL_Surface*> ortHealthShow;
extern std::vector<SDL_Surface*> ghostHealthShow;

extern std::vector<SDL_Surface*> zombSurf;
extern std::vector<SDL_Surface*> skelSurf;
extern std::vector<SDL_Surface*> ortSurf;
extern std::vector<SDL_Surface*> ghostSurf;

extern SDL_Surface *mapImage[];

extern SDL_Surface *healthPck[];

extern SDL_Surface *heroMagicaShow;

extern SDL_Surface *heroHealthBarBack;
extern SDL_Surface *heroHealthBarTick;
extern SDL_Surface *heroMagicaBarTick;


extern SDL_Surface *mobHealthBar;
extern SDL_Surface *mobHealthBarTick;


extern SDL_Surface *bossOneSurf;
extern SDL_Surface *bossOneHealthSurf;

extern SDL_Surface *swordTypeSurf;
extern SDL_Surface *swordSquare;

extern SDL_Surface *bagSurf;
extern SDL_Surface *rareBagSurf;

extern SDL_Rect zombHitSquare;

extern bool playerSlash;
extern Uint32 attackTime;
extern bool playSlash;
extern bool spaceClick;

extern int zombSpawnX;
extern int zombSpawnY;

extern int zomb2SpawnX;
extern int zomb2SpawnY;

extern SDL_Event event;

extern Mix_Music *introMusic;
extern Mix_Music *gameMusic;

extern Mix_Chunk *slash;

extern Actor hero;
extern Actor zombie;
extern Actor skeleton;
extern Actor ortman;
extern Actor ghost;

extern Actor bossOne;

extern bool ifOrt;

extern bool ifNoSound;

extern int charPos;

extern int spawnX;
extern int spawnY;

extern bool quit;
extern bool pause;

extern int mouseDesX;
extern int mouseDesY;

extern bool playerUp;
extern bool playerDown;
extern bool playerRight;
extern bool playerLeft;
extern bool keyDown;

extern int frameCount;

#endif
