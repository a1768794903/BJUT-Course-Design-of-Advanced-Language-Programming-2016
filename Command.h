#pragma once
#define CMD_NULL						0

#define CMD_UP								1
#define CMD_DOWN						2
#define CMD_LEFT							4
#define CMD_RIGHT						8

#define CMD_QUIT							16
#define CMD_SPEED_PAUSE		32
#define CMD_SPEED_NORMAL	64
#define CMD_SPEED_FAST			128
#define CMD_SPEED_ULTRA		256

#define CMD_SETTINGS				512
#define CMD_GALLERY					1024
#define CMD_SAVE						2048
#define CMD_OPTIONS					4096
#define CMD_CHEAT						8192
#define CMD_SCREEN_SHOT		16384
#define CMD_NEW_GAME				32768

#define PAUSE								100
#define MENU									101
#define RETURNTOMENU				102
#define CHANGESETTING				103
#define GALLERY							104
#define OPTIONSMENU					105
#define GAMESETTINGS				106
#define HELP									107
#define CREDITS							108
#define ACCOMPLISHMENT			109
#define EXITTOMAINMENU			110
#define EXITGAME							111
#define CANNOTSAVE					112

// Cheat Code 作弊代码
enum CHEAT
{
	CHEAT_SPEEDUP,            // Speed up 加速
	CHEAT_SPEEDDOWN,      // Speed down 减速
	CHEAT_INVISIBLE,            // Invisible , become transparent 透明
	CHEAT_POINTS,                // Add points 加分
	CHEAT_STRINGER            // Stringer 彩蛋
};