#pragma once 
#include "DEF.h"
#include "Header.h"

// Menu 主菜单
int Menu(Settings &settings)
{
	char ch;
	MOUSEMSG m = GetMouseMsg();
	RankList list[50];
	static int trigger = 0;
	struct Fish_motion myfish = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 };
	
	if (trigger == 0)
	{
		InitSetting(settings, 1);												// Initiate the setting 初始化设置
		StartBkMusic(settings, 2);										// Start the background music for menu 播放主菜单背景音乐
	}

	LoadMouseCursor(settings.switch_mouse);				// Change the mouse cursor 改变鼠标光标
	++trigger;																		// Add trigger 计步器递增
	DisplayBackground(2);												// Display the menu interface 显示菜单界面
	OuttextScript(1);															// Outtext the menu scripts 打印菜单文本

	while (true)
	{
		if (_kbhit()) { ch = _getch(); if(ch == 27) Quit(); }		// Quit the game 退出游戏
	
		while (MouseHit())
		{
			m = GetMouseMsg();

			if (LMARGIN < m.x && m.x < LMARGIN + 130 && 280 < m.y && m.y < 620)
			{
				// Click the buttons 点击按钮效果
				if (m.uMsg == WM_LBUTTONUP)
				{
					// Start game and choose the mode 开始游戏并选择困难模式
					if (LMARGIN < m.x && m.x < LMARGIN + 130 && 280 < m.y && m.y < 310)
					{
						OuttextChoice(2, 1);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音
						Category(settings, myfish);							// Category directory 分类（难度）目录
					}

					// Load previous record 读取之前存档
					else if (LMARGIN < m.x && m.x < LMARGIN + 130 && 330 < m.y && m.y < 360)
					{
						OuttextChoice(2, 2);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音

						if (settings.record_mode == 1)
							Game(settings, myfish);							// Enter the game 进入游戏
					}

					// Display help information 显示帮助信息
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 380 < m.y && m.y < 410)
					{
						OuttextChoice(2, 3);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音
						DisplayBackground(5);								// Display background for help 显示帮助背景
						WorkSpace(settings, myfish, RETURNTOMENU);		// Return to the main menu  返回主菜单
					}

					// Display the ranking list 显示排行榜
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 430 < m.y && m.y < 460)
					{
						OuttextChoice(2, 4);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音
						InitRankingList(list);										// Initiate a ranking list 初始化排行榜
						LoadRankingList(list);									// Load a ranking list from files 从文件中读取排行榜
						DisplayRankingList(list);								// Display ranking list 显示排行榜
						WorkSpace(settings, myfish, RETURNTOMENU);		// Return to the main menu  返回主菜单
					}

					// Change setting 更改设置
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 480 < m.y && m.y < 510)
					{
						OuttextChoice(2, 5);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音
						WorkSpace(settings, myfish, CHANGESETTING);		// Change the setting 更改设置
					}

					// Exit 退出游戏
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 580 < m.y && m.y < 610)
					{
						OuttextChoice(2, 6);									// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);								// Play the click sound 播放点击声音
						Quit();															// Quit the game 退出游戏
					}

					// Display the scripts for menu interface 显示菜单界面文本
					else
						OuttextScript(1);							
					
					Sleep(20);									// Sleep for 20ms 睡眠20毫秒
				}
				// Stress the buttons 按钮效果（加强）
				else
				{
					if (LMARGIN - 5 < m.x && m.x < LMARGIN + 120 && 280 < m.y && m.y < 310)
						OuttextChoice(1, 1);
					else if (LMARGIN - 5 < m.x && m.x < LMARGIN + 120 && 330 < m.y && m.y < 360)
						OuttextChoice(1, 2);
					else if (LMARGIN - 5 < m.x && m.x < LMARGIN + 70 && 380 < m.y && m.y < 410)
						OuttextChoice(1, 3);
					else if (LMARGIN - 5 < m.x && m.x < LMARGIN + 70 && 430 < m.y && m.y < 460)
						OuttextChoice(1, 4);
					else if (LMARGIN - 5 < m.x && m.x < LMARGIN + 70 && 480 < m.y && m.y < 510)
						OuttextChoice(1, 5);
					else if (LMARGIN - 5 < m.x && m.x < LMARGIN + 70 && 580 < m.y && m.y < 610)
						OuttextChoice(1, 6);
					else
						OuttextScript(1);							// Display the scripts for menu interface 显示菜单界面文本
				}
			}		
		}		
	}

	StopBkMusic(); // Stop the background music for menu 结束主菜单背景音乐

	return 1;
}

// Category directory 分类（难度）目录
int Category(Settings &settings, struct Fish_motion &myfish)
{
	char ch;
	MOUSEMSG m = GetMouseMsg();

	DisplayBackground(4);						// Display the category interface 显示难度选择界面
	OuttextScript(2);									// Display the scripts for category interface 显示难度选择界面文本

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();										// Keyboard hit  点击键盘

			if( ch ==27)											// Esc  Esc键
					Menu(settings);							// Menu 主菜单
		}

		while (MouseHit())
		{
			m = GetMouseMsg();

			if (LMARGIN - 5 < m.x && m.x < LMARGIN + 135  && 395 < m.y && m.y < 655)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					if (LMARGIN < m.x && m.x < LMARGIN + 70 && 400 < m.y && m.y < 430)
					{
						OuttextScript(2);							// Display the scripts for category interface 显示难度选择界面文本
						OuttextChoice(2, 7);					// Display the scripts for the choice 显示选项文本
						SoundEffect(settings, 2);				// Play the click sound 播放点击声音
						settings.difficulty = 1;					// Set the difficulty as easy 设置游戏难度为简单
						settings.remain_time = 180;		// Set the remain time as 180s 设置游戏时间为180秒
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 450 < m.y && m.y < 480)
					{
						OuttextScript(2);							// Display the scripts for category interface 显示难度选择界面文本
						OuttextChoice(2, 8);					// Display the scripts for the choice 显示选项文本	
						SoundEffect(settings, 2);				// Play the click sound 播放点击声音
						settings.difficulty = 2;					// Set the difficulty as normal 设置游戏难度为中等
						settings.remain_time = 150;		// Set the remain time as 150s 设置游戏时间为150秒
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 500 < m.y && m.y < 530)
					{
						OuttextScript(2);							// Display the scripts for category interface 显示难度选择界面文本
						OuttextChoice(2, 9);					// Display the scripts for the choice 显示选项文本	
						SoundEffect(settings, 2);				// Play the click sound 播放点击声音
						settings.difficulty = 3;					// Set the difficulty as hard 设置游戏难度为困难
						settings.remain_time = 120;		// Set the remain time as 120s 设置游戏时间为120秒
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 130 && 570 < m.y && m.y < 600)
					{
						OuttextChoice(2, 10);					// Display the scripts for the choice 显示选项文本	
						SoundEffect(settings, 2);				// Play the click sound 播放点击声音
						settings.record_mode = 0;
						Game(settings, myfish);				// Start the game 开始新游戏
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 < m.y && m.y < 650)
					{
						OuttextChoice(2, 11);					// Display the scripts for the choice 显示选项文本				
						Menu(settings);							// Menu 主菜单
					}
				}
				else
				{
					if (LMARGIN < m.x && m.x < LMARGIN + 70 && 400 < m.y && m.y < 430)
						OuttextChoice(1, 7);
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 450 < m.y && m.y < 480)
						OuttextChoice(1, 8);
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 500 < m.y && m.y < 530)
						OuttextChoice(1, 9);
					else if (LMARGIN < m.x && m.x < LMARGIN + 130 && 570 < m.y && m.y < 600)
						OuttextChoice(1, 10);
					else if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 < m.y && m.y < 650)
						OuttextChoice(1, 11);
					else { OuttextScript(2); OuttextDifficulty(settings.difficulty); }
				}
			}
		}

		if(!(LMARGIN < m.x && m.x < LMARGIN + 130 && 400 < m.y && m.y < 650))
			OuttextDifficulty(settings.difficulty);

	}
	return 1;
}