#include "headers/globals.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <iostream>
#include <string>
#include <SDL/SDL_Thread.h>
#include <vector>

SDL_Thread *consoleThread = NULL;

int mapLevel = 1;
bool ifPortal;
bool wantPortal;

bool useKey;

bool devPortalSkip;

bool moveOn;

int MAP_WIDTH;
int MAP_HEIGHT;

int resizeX;
int resizeY;

int gameSaveInt;

int textureMap[150][113];
std::string tileTypeStr;
int heroTileType;

bool fast;
int difficultyLevel;
bool devModeB;

bool difficultyFail= false;
bool graphicsFail= false;
bool devModeError;

bool initFail= false;
int zombAmt = 8;
int skelAmt = 5;
int ortAmt = 30;
int ghostAmt = 3;
const int healthPckNum = 3;

bool ifOrt;
bool ifOrtSetting;

bool ifNoSound;

Uint32 startTime;
Uint32 gameTime;

int controlMode = 0;

const int FRAMES_PER_SECOND = 60;
Timer fpsTime;
Timer update;
Timer totalGameTime;
int totalGameFrames;
int currentFps;
int heroUpdateTime;

Uint32 heroMoveTimerReset = 0;
Uint32 mapOffsetTimer = 0;

int xp;
std::vector<bool> zombXp(zombAmt);
std::vector<bool> skelXp(skelAmt);
std::vector<bool> ortXp(ortAmt);
std::vector<bool> ghostXp(ghostAmt);
/*
bool skelXp[skelAmt];
bool ortXp[ortAmt];
bool ghostXp[ghostAmt];
*/

bool boss1Xp;

std::vector<signed int> zombOffsetX(zombAmt);
std::vector<signed int> zombOffsetY(zombAmt);

signed int boss1OffsetX;
signed int boss1OffsetY;

std::vector<signed int> skelOffsetX(skelAmt);
std::vector<signed int> skelOffsetY(skelAmt);

std::vector<signed int> ortOffsetX(ortAmt);
std::vector<signed int> ortOffsetY(ortAmt);

std::vector<signed int> ghostOffsetX(ghostAmt);
std::vector<signed int> ghostOffsetY(ghostAmt);


int level = 1;
int gameLevel = 1;
int totalEnemyKills = 0;
int previousLevelKills = 0;
int gameLevelKillsNeeded = 0;

std::vector<SDL_Rect> zombRect(zombAmt);
std::vector<SDL_Rect> skelRect(skelAmt);
std::vector<SDL_Rect> ortRect(ortAmt);
std::vector<SDL_Rect> ghostRect(ghostAmt);
SDL_Rect boss1Rect;

int mapDetail[50][38];

SDL_Rect heroR;
bool heroSpawn;

float heroHealth;
float heroHealthAdj;
float heroMaxHealth;
Uint32 heroHealthTimer = SDL_GetTicks();
Uint32 heroHealthTimerSub = 0;
int heroHealthUpSpd;

float heroMagica;
float heroMagicaAdj;
bool heroMagicaWant;
float heroMaxMagica;
Uint32 heroMagicaTimer = SDL_GetTicks();
Uint32 heroMagicaTimerSub = 0;
int heroMagicaUpSpd;

bool heroTele;
bool heroTeleOnce;

int swordType = 0;

std::vector<bool> zombDead(zombAmt);
std::vector<bool> skelDead(skelAmt);
std::vector<bool> ortDead(ortAmt);
std::vector<bool> ghostDead(ghostAmt);
bool boss1Dead;

std::vector<Uint32> zombRespawn(zombAmt);
std::vector<Uint32> skelRespawn(skelAmt);
std::vector<Uint32> ortRespawn(ortAmt);
std::vector<Uint32> ghostRespawn(ghostAmt);

std::vector<unsigned int> zombHealth(zombAmt);
std::vector<unsigned int> skelHealth(skelAmt);
std::vector<unsigned int> ortHealth(ortAmt);
std::vector<unsigned int> ghostHealth(ghostAmt);
unsigned int bossOneHealth;

int mapAmt = 3;

int mapPickX = 1;
int mapPickY = 1;

unsigned int mapXAxis;
unsigned int mapYAxis;

SDL_Rect healthPckR[healthPckNum];
bool wantHealthPck = false;


FileReader *fileReader11 = NULL;
FileReader *fileReader01 = NULL;
FileReader *fileReader12 = NULL;
FileReader *fileReader00 = NULL;
FileReader *fileReader02 = NULL;
FileReader *fileReader10 = NULL;
FileReader *fileReader20 = NULL;
FileReader *fileReader21 = NULL;
FileReader *fileReader22 = NULL;

FileReader *mainFileReader = NULL;

SDL_Rect scrollRect;

int mapOffsetXAmt;
int mapOffsetYAmt;


FileReader *errorFix;

int fpsCounter;

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

TTF_Font *font = NULL;
TTF_Font *largeFont = NULL;
SDL_Color textColor = { 0, 0, 0 };
SDL_Color whiteTextColor = { 255, 255, 255 };

SDL_Surface *screen = NULL;
SDL_Surface *FPS = NULL;
SDL_Surface ***map;
SDL_Surface *introMessage = NULL;
SDL_Surface *instruct = NULL;
SDL_Surface *introTitle = NULL;
SDL_Surface *introBackground = NULL;
SDL_Surface *pressStart = NULL;
SDL_Surface *creditsImage = NULL;
SDL_Surface *youLoseText = NULL;
SDL_Surface *healthDisplay = NULL;
SDL_Surface *heroFront = NULL;
SDL_Surface *heroAnimateTest = NULL;
SDL_Surface *heroBack = NULL;
SDL_Surface *heroLeft = NULL;
SDL_Surface *heroRight = NULL;
SDL_Surface *heroSlashRight = NULL;
SDL_Surface *heroSlashLeft = NULL;
SDL_Surface *heroSlashFront = NULL;
SDL_Surface *heroSlashBack = NULL;
SDL_Surface *zombBack = NULL;
SDL_Surface *zombLeft = NULL;
SDL_Surface *zombRight = NULL;
SDL_Surface *backbackground = NULL;
SDL_Surface *fpsDisplay = NULL;
SDL_Surface *tileType = NULL;
SDL_Surface *playerXLocSurf = NULL;
SDL_Surface *playerYLocSurf = NULL;
SDL_Surface *grass = NULL;
SDL_Surface *road = NULL;
SDL_Surface *water = NULL;
SDL_Surface *quad = NULL;
SDL_Surface *xpAmt = NULL;
SDL_Surface *levelSh = NULL;
SDL_Surface *levelTick = NULL;

SDL_Surface *portalSurf = NULL;

std::vector<SDL_Surface*> zombHealthShow(zombAmt);
std::vector<SDL_Surface*> skelHealthShow(zombAmt);
std::vector<SDL_Surface*> ortHealthShow(ortAmt);
std::vector<SDL_Surface*> ghostHealthShow(ghostAmt);

std::vector<SDL_Surface*> zombSurf(zombAmt);
std::vector<SDL_Surface*> skelSurf(skelAmt);
std::vector<SDL_Surface*> ortSurf(ortAmt);
std::vector<SDL_Surface*> ghostSurf(ghostAmt);

SDL_Surface *bossOneSurf = NULL;
SDL_Surface *bossOneHealthSurf = NULL;

SDL_Surface *mapImage[5];

SDL_Surface *heroMagicaShow = NULL;

SDL_Surface *heroHealthBarBack = NULL;
SDL_Surface *heroHealthBarTick = NULL;
SDL_Surface *heroMagicaBarTick = NULL;

SDL_Surface *mobHealthBar = NULL;
SDL_Surface *mobHealthBarTick = NULL;

SDL_Surface *swordTypeSurf = NULL;
SDL_Surface *swordSquare = NULL;

SDL_Surface *bagSurf = NULL;
SDL_Surface *rareBagSurf = NULL;

SDL_Rect zombHitSquare;

bool playerSlash = false;
Uint32 attackTime;
bool playSlash = false;
bool spaceClick;

int zombSpawnX;
int zombSpawnY;

int zomb2SpawnX;
int zomb2SpawnY;

SDL_Event event;

bool quit = false;
bool pause = false;

int mouseDesX = 100;
int mouseDesY = 100;

Mix_Music *introMusic = NULL;
Mix_Music *gameMusic = NULL;

Mix_Chunk *slash = NULL;

int charPos = 1;

bool playerUp;
bool playerDown;
bool playerRight;
bool playerLeft;
bool keyDown;

bool healthPackUsed[healthPckNum];
SDL_Surface *healthPck[healthPckNum];

Actor hero;
Actor zombie;
Actor skeleton;
Actor ortman;
Actor ghost;

Actor bossOne;

int frameCount = 0;
