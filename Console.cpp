#pragma once
#include "DEF.h"
#include "Command.h"
#include "Header.h"

// Get the command 获取命令
int GetCommand(Settings settings, struct Fish_motion &myfish)
{
	int cmd = 0;
	MOUSEMSG m;

	if (GetAsyncKeyState(VK_UP) & 0x8000) { cmd |= CMD_UP; }									// Key Up       Up键
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) { cmd |= CMD_DOWN; }						// Key Down  Down键
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) { cmd |= CMD_LEFT; }							// Key Left     Left键
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { cmd |= CMD_RIGHT; }						// Key Right   Right键
	if (GetAsyncKeyState(87) & 0x8000) { cmd |= CMD_UP; }											// Key w         W键
	if (GetAsyncKeyState(83) & 0x8000) { cmd |= CMD_DOWN; }									// Key S         S键
	if (GetAsyncKeyState(65) & 0x8000) { cmd |= CMD_LEFT; }										// Key A          A键
	if (GetAsyncKeyState(68) & 0x8000) { cmd |= CMD_RIGHT; }									// Key D         D键

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { return CMD_QUIT; }						// Key Esc     Esc键
	if (GetAsyncKeyState(67) & 0x8000) { return CMD_CHEAT; }									// Key C         C
	if (GetAsyncKeyState(80) & 0x8000) { return CMD_SCREEN_SHOT; }						// Key P          P键
	if (GetAsyncKeyState(48) & 0x8000) { return CMD_SPEED_PAUSE; }						// Key 0         0键
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) { return CMD_SPEED_PAUSE; }		// Key space 空格键
	else if (GetAsyncKeyState(49) & 0x8000) { return CMD_SPEED_NORMAL; }			// Key 1         1键
	else if (GetAsyncKeyState(50) & 0x8000) { return CMD_SPEED_FAST; }					// Key 2         2键
	else if (GetAsyncKeyState(51) & 0x8000) { return CMD_SPEED_ULTRA; }				// Key 3         3键	


	if (MouseHit())
	{
		m = GetMouseMsg();

		if (m.uMsg == WM_LBUTTONUP)
		{
			if (480 < m.x && m.x < 605 && 728 < m.y && m.y < 748)
			{
				if (480 < m.x && m.x < 500)
					return CMD_SPEED_PAUSE;
				else if (515 < m.x && m.x < 535)
					return CMD_SPEED_NORMAL;
				else if (548 < m.x && m.x < 570)
					return CMD_SPEED_FAST;
				else if (580 < m.x && m.x < 605)
					return CMD_SPEED_ULTRA;
			}
			else if (824 < m.x && m.x < 1024 && 0 < m.y && m.y < 45)
			{
				if (824 < m.x && m.x < 874)
					return CMD_SETTINGS;
				else if (874 < m.x && m.x < 926)
					return CMD_GALLERY;
				else if (927 < m.x && m.x < 947)
					return CMD_NEW_GAME;
				else if (948 < m.x && m.x < 989 && m.y < 30)
					return CMD_SAVE;
				else if (989 < m.x && m.x < 1024 && m.y < 30)
					return CMD_OPTIONS;
			}		
		}
	}

	return cmd;
}

// Dispatch command order 分发控制命令
int DispatchCmd(int cmd, LinkList head, struct Settings &settings, struct Fish_motion &myfish)
{
	if (cmd == CMD_NULL)											// Stay 保持静止
	{
		MyFishStay(head, settings);
		return 1;
	}
	else
	{
		if (cmd & CMD_UP)												// GoUp 向上 1
			MyFishMoveUp(head, settings);	
		if (cmd & CMD_DOWN)										// GoDown 向下 2 
			MyFishMoveDown(head, settings);
		if (cmd & CMD_LEFT)											// GoLeft 向左 3		
			MyFishMoveLeft(head, settings);
		if (cmd & CMD_RIGHT)										// GoRight 向右 4 
			MyFishMoveRight(head, settings);
	}
		

	if (cmd == CMD_SPEED_PAUSE)							// Pause 暂停
		settings.game_speed = 0;
	else if( cmd == CMD_SPEED_NORMAL)				// Normal speed 1×倍速运行
		settings.game_speed = 1;
	else if (cmd == CMD_SPEED_FAST)						// Fast speed 2×倍速运行
		settings.game_speed = 2;
	else if (cmd == CMD_SPEED_ULTRA)					// Ultra speed 3×倍速运行
		settings.game_speed = 3;

	if (cmd == CMD_QUIT)											// Quit the game 退出游戏	
		Quit();
	else if (cmd == CMD_SETTINGS)							// Options setting 设定选项
	{
		EndBatchDraw(); FlushBatchDraw();

		SetOptionsMode(settings,0, 3, 0);						// Game_speed = 0  Game_options = 3 暂停 游戏界面按钮为设定
		WorkSpace(settings, myfish, GAMESETTINGS);	// Game settings 游戏设定选单

		DisplayBackground(1);
		DisplayGameInterface(settings.game_speed, settings.game_options);
		DisplayWorkSpace(settings);

		SetOptionsMode(settings, 1, 0, 0);						// Game_speed = 1  Game_options = 0 1×倍速 游戏界面按钮为无
	}
	else if (cmd == CMD_GALLERY)							// Gallery 相册
	{
		EndBatchDraw(); FlushBatchDraw();

		SetOptionsMode(settings, 0, 2, 0);						// Game_speed = 0  Game_options = 2 暂停 游戏界面按钮为相册  
		DisplayGameInterface(settings.game_speed, settings.game_options);
		DisplayWorkSpace(settings);
		WorkSpace(settings, myfish, GALLERY);			// Gallery 相册

		SetOptionsMode(settings, 1, 0, 0);						// Game_speed = 1  Game_options = 0 1×倍速 游戏界面按钮为无
	}
	else if (cmd == CMD_NEW_GAME)						// New game 新游戏
	{
		EndBatchDraw(); FlushBatchDraw();

		SetOptionsMode(settings, 0, 4, 0);						// Game_speed = 0  Game_options = 2 暂停 游戏界面按钮为新游戏  
		DisplayGameInterface(settings.game_speed, settings.game_options);
		Sleep(VICKY);
		
		InitSetting(settings, 2);
		Game(settings, myfish);
	}
	else if (cmd == CMD_SAVE)									// Save 存储游戏
	{
		EndBatchDraw(); FlushBatchDraw();
		SetOptionsMode(settings, 0, 5, 0);						// Game_speed = 0  Game_options = 5 暂停 游戏界面按钮为存储  
		DisplayGameInterface(settings.game_speed, settings.game_options);
		Sleep(VICKY);
		SaveRecord(settings, myfish);
		SetOptionsMode(settings, 1, 0, 0);						// Game_speed = 1  Game_options = 0 1×倍速 游戏界面按钮为无
	}	
	else if (cmd == CMD_OPTIONS)							// Options 选项	
	{
		EndBatchDraw(); FlushBatchDraw();

		SetOptionsMode(settings, 0, 1, 0);						// Game_speed = 0  Game_options = 1 暂停 游戏界面按钮为选项
		WorkSpace(settings,myfish,OPTIONSMENU);	// Options menu 选项菜单
		SetOptionsMode(settings, 1, 0, 0);						// Game_speed = 1  Game_options = 0 1×倍速 游戏界面按钮为无
	}
	else if(cmd == CMD_SCREEN_SHOT)					// Screenshot 截屏
		ScreenShot(1, settings);
	else if (cmd == CMD_CHEAT)									// GoldFinger 金手指作弊器					
	{
		EndBatchDraw(); FlushBatchDraw();
		Goldfinger(head, settings);
	}				

	return 1;
}

// Quit the game 退出游戏
int Quit(void)
{
	HWND ifexit = GetHWnd();

	if ((MessageBoxA(ifexit, "是否退出当前游戏？", "退出游戏", MB_YESNO | MB_ICONQUESTION)) == 6)
		exit(0);    // Exit this program 退出游戏

	return 1;
}