//GLOBALS.H

#ifndef GLOBALS_H
#define GLOBALS_H

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string>

#include "file_reader.h"
#include "game_engine.h"
#include "timer.h"

extern SDL_Thread *axisMathThread;
extern SDL_Thread *mapLoader;

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

extern const int zombAmt;
extern const int skelAmt;
extern const int ortAmt;
extern const int ghostAmt;

extern Uint32 startTime;
extern Uint32 gameTime;

extern int controlMode;

extern int xp;
extern bool zombXp[];
extern bool skelXp[];
extern bool ortXp[];
extern bool ghostXp[];

extern signed int zombOffsetX[];
extern signed int zombOffsetY[];

extern signed int skelOffsetX[];
extern signed int skelOffsetY[];

extern signed int ortOffsetX[];
extern signed int ortOffsetY[];

extern signed int ghostOffsetX[];
extern signed int ghostOffsetY[];

extern int level;
extern int gameLevel;
extern int totalEnemyKills;
extern int previousLevelKills;
extern int gameLevelKillsNeeded;

extern SDL_Rect zombRect[];
extern SDL_Rect skelRect[];
extern SDL_Rect ortRect[];
extern SDL_Rect ghostRect[];

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

extern int heroX;
extern int heroY;

extern int heroHealth;
extern int heroMaxHealth;
extern Uint32 heroHealthTimer;
extern Uint32 heroHealthTimerSub;
extern int heroHealthUpSpd;

extern bool heroTele;
extern bool heroTeleOnce;

extern signed int heroMagica;
extern bool heroMagicaWant;
extern int heroMaxMagica;
extern Uint32 heroMagicaTimer;
extern Uint32 heroMagicaTimerSub;
extern int heroMagicaUpSpd;

extern int swordType;

extern bool zombDead[];
extern bool skelDead[];
extern bool ortDead[];
extern bool ghostDead[];

extern Uint32 zombRespawn[];
extern Uint32 skelRespawn[];
extern Uint32 ortRespawn[];
extern Uint32 ghostRespawn[];

extern unsigned int zombHealth[];
extern unsigned int skelHealth[];
extern unsigned int ortHealth[];
extern unsigned int ghostHealth[];

extern unsigned int zomb1Health;
extern unsigned int zomb2Health;
extern unsigned int zomb3Health;

extern int mapAmt;

extern int mapPickX;
extern int mapPickY;

extern unsigned int mapXAxis;
extern unsigned int mapYAxis;

extern SDL_Rect healthPckR;
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
extern SDL_Surface *healthPck;
extern SDL_Surface *levelTick;

extern SDL_Surface *zombHealthShow[];
extern SDL_Surface *skelHealthShow[];
extern SDL_Surface *ortHealthShow[];
extern SDL_Surface *ghostHealthShow[];

extern SDL_Surface *zombSurf[];
extern SDL_Surface *skelSurf[];
extern SDL_Surface *ortSurf[];
extern SDL_Surface *ghostSurf[];

extern SDL_Surface *heroMagicaShow;

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
