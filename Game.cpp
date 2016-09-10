#pragma once
#include "Command.h"
#include "DEF.h"
#include "Header.h"

// Game interface 游戏界面
int Game(struct Settings &settings, struct Fish_motion &myfish)
{	
	LinkList head;

	if(settings.record_mode == 0)
	{
		InitSetting(settings, 2);	 InitSetting(settings, 4);						// Initiate the setting 初始化设置
		IniMyFish(head, settings, myfish);											// Initiate my fish 初始化玩家操控的鱼
	}
	else
	{
		LoadRecord(settings, myfish);													// Load the record 读取存档
		InitSetting(settings, 2);																// Initiate the setting 初始化设置
		IniMyFish(head, settings, myfish);											// Initiate my fish 初始化玩家操控的鱼
	}

	StartBkMusic(settings, 1);															// Start the background music 开始播放背景音乐
	DisplayBackground(1);																// Display the game interface background 显示游戏界面背景
	DisplayGameInterface(0, 0);														// Display game interface 显示游戏界面
	DisplayWorkSpace(settings);														// Display the work space 显示工作区（时间）

	WorkSpace(settings, myfish, PAUSE); 										// Pause the game 暂停游戏
	Sleep(VICKY);

	while (true)
	{
		if (settings.game_speed == 0)
			WorkSpace(settings, myfish, PAUSE); 								// Pause the game 暂停游戏

		if (IfWin(head, settings, myfish))												// Judge if win 判断是否胜利
			Triumph(head,settings, myfish);											// Triumph 胜利
		else
			IfLevelUp(head);																	// Judge if level up 判定是否升级 

		RandomGenerateFish(head,settings);									// Random generate fish 随机生成鱼
		SynchroMyfish(head,myfish);													// Synchronize myfish 同步玩家的鱼
		TimeMeter(settings);																// Time meter 计时器

		DispatchCmd(GetCommand(settings,myfish),head,settings,myfish);
																										// Console board 控制台

		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		BeginBatchDraw();

		DisplayBackground(1);															// Display the game interface background 显示游戏界面背景
		Move(head, settings);																// Move 移动
		IfOut(head);																				// Judge whether if out 判断是否出界
		IfMeet(head, settings);																// If meet other fishs or pradate 判定是否出界或与鱼相遇和是否进行捕食

		DisplayMyFish(head);																// Display my fish 显示玩家的鱼
		DisplayGameInterface(settings.game_speed, settings.game_options);
																										// Display game interface 显示游戏界面
		DisplayWorkSpace(settings);													// Display the work space 显示工作区（时间）
		
		HpSleep(25);																			// Set a proper free time 设置合理时长的时间间隔
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		EndBatchDraw();
		FlushBatchDraw();
	}

	StopBkMusic();																			// End the background music 结束播放背景音乐
	return 1;
}

// Game over 游戏结束
int GameOver(LinkList &head, struct Settings &settings, struct Fish_motion &myfish)
{
	InitSetting(settings, 2);	 InitSetting(settings, 3); InitSetting(settings, 4);// Initiate the setting 初始化设置
	DeleteLinkList(head);																	// Delete the link list 删除链表
	DisplayBackground(8);
	WorkSpace(settings, myfish, RETURNTOMENU);						// Return to the main menu  返回主菜单
	return 1;
}

// Difficulty choice 难度选择
int Difficulty(int difficulty,struct Fish_motion &myfish)
{
	switch (difficulty)							// Set the difficulty    难度设定
	{
		case 0:	 break;
		case 1: myfish = { 0 , 8 , 160 , 120 , 6 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Easy    简单模式
		case 2: myfish = { 0 , 6 , 120 ,  90 , 4 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Normal 中等模式
		case 3: myfish = { 0 , 4 ,  96 ,  72   , 3 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Hard     困难模式	
		default: return -1;
	}

	return 1;
}