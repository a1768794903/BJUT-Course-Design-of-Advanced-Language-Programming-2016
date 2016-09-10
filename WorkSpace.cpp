#pragma once
#include "Command.h"
#include "Header.h"
#include "DEF.h"

// Work space 工作面板
int WorkSpace(Settings &settings, struct Fish_motion &myfish,int branch)
{
	char ch;
	MOUSEMSG m;
	IMAGE album[10];
	int tag = 0;

	switch (branch)
	{
		case RETURNTOMENU:	OuttextChoice(1, 11); break;						// Return to the menu 返回主菜单
		case CHANGESETTING:	DisplaySetting(); break;								// Display the setting 显示设置
		case GALLERY:
			LoadAlbum(album);												// Load pictures into album 读取图片进入相册
			DisplayBackground(10);										// Display background for gallery 显示相册背景
			DisplayButton(5);													// Display the left arrow 显示左箭头
			DisplayButton(6);													// Display the right arrow 显示右箭头
			break;
		case OPTIONSMENU:																			// Options menu 选项菜单
			BeginBatchDraw();
			DisplayBackground(1);
			DisplayGameInterface(settings.game_speed, settings.game_options);
			DisplayWorkSpace(settings);
			DisplayOptionsMenu(settings);
			EndBatchDraw(); FlushBatchDraw();
			break;
		case GAMESETTINGS:																			// Game Settings 游戏选项
			DisplayGameInterface(settings.game_speed, settings.game_options);
			DisplayWorkSpace(settings);
			DisplayFrame(3, settings);
			break;
		case HELP:		DisplayFrame(4, settings); break;									// Help 帮助
		case CREDITS:	DisplayFrame(5, settings); break;								// Credits 制作人员
		case ACCOMPLISHMENT:		DisplayFrame(6, settings);  break;			// Accomplishment 成就
		case EXITTOMAINMENU:	DisplayFrame(7, settings); break;				// Exit to main menu 退出至主菜单
		case EXITGAME:	DisplayFrame(8, settings); break;							// Exit Game 退出游戏
		case CANNOTSAVE:	DisplayFrame(9, settings); break;						// Cannot save 不能储存													
	}

	while (true)
	{
		if (branch == GALLERY) { BeginBatchDraw(); putimage(1, 95, &album[tag]); }

		if (_kbhit())
		{
			ch = _getch();

			switch (branch)
			{		
				case PAUSE:							// Pause the game 暂停游戏
					if (ch == ' ') { settings.game_speed = 1; return 1; }
					else if (ch == 27) Quit();
					break;

				case RETURNTOMENU:		// Return to the menu 返回主菜单			
				case CHANGESETTING:		// Change the setting 更改设置
					if (ch == 27) { OuttextChoice(2, 11); Menu(settings); SoundEffect(settings, 2); } break;

				case OPTIONSMENU:
					settings.game_options = 0;
				default:
					if (ch == 27) { Sleep(VICKY); FlushMouseMsgBuffer(); return 1;}					
			}			
		}

		while (MouseHit())
		{
			m = GetMouseMsg();

			if(branch == RETURNTOMENU && LMARGIN < m.x && m.x < LMARGIN + 95 && 620 < m.y && m.y < 650) OuttextChoice(4, 11);

			if (m.uMsg == WM_LBUTTONUP)
			{
				switch (branch)
				{
					// Pause the game 暂停游戏
					case PAUSE:
						if (515 < m.x && m.x < 535 && 723 < m.y && m.y < 748) { settings.game_speed = 1; return 1; }
						else if (548 < m.x && m.x < 570 && 728 < m.y && m.y < 748) { settings.game_speed = 2; return 1; }
						else if (580 < m.x && m.x < 605 && 728 < m.y && m.y < 748) { settings.game_speed = 3; return 1; }
						break;

					// Return to the menu 返回主菜单
					case RETURNTOMENU:
						if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 < m.y && m.y < 650) { OuttextChoice(2, 11); SoundEffect(settings, 2); Menu(settings); }
						break;

					// Change the setting 更改设置
					case CHANGESETTING:		
						if (30 <= m.x && m.x <= 280 && 330 <= m.y && m.y <= 380) {
							settings.switch_mouse ^= 1;

							if (settings.switch_mouse == 1) DisplayButton(1);
							else DisplayButton(2);
						}
						else if (30 <= m.x && m.x <= 280 && 470 <= m.y && m.y <= 520) {
							settings.switch_music ^= 1;

							if (settings.switch_music == 0) { StopBkMusic(); DisplayButton(4); }
							else { StartBkMusic(settings, 2); DisplayButton(3); }
						}
						else if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 <= m.y && m.y <= 650) { OuttextChoice(2, 11); Menu(settings); }
						break;

					// Gallery 相册
					case GALLERY:
						if (1006 < m.x && m.x < 1020 && 49 < m.y && m.y < 64)
							return 1;
						// Click the delete icon 点击删除按钮
						else if (925 < m.x && m.x < 1006 && 339 < m.y && m.y < 431)
							DeletePicture(tag);
						// Click the left arrow 点击左箭头
						else if (0 < m.x && m.x < 100 && 334 < m.y && m.y < 434)
						{
							--tag;

							if (tag <= 0)
								tag = settings.screenshots_num - 1;

							putimage(1, 95, &album[tag]);
							DisplayButton(5);													// Display the left arrow 显示左箭头
							DisplayButton(6);													// Display the right arrow 显示右箭头
						}
						// Click the right arrow 点击右箭头
						else if (804 < m.x && m.x < 904 && 334 < m.y && m.y < 434)
						{
							++tag;

							if (tag >= settings.screenshots_num)
								tag = 0;

							putimage(1, 95, &album[tag]);
							DisplayButton(5);													// Display the left arrow 显示左箭头
							DisplayButton(6);													// Display the right arrow 显示右箭头
						}
						break;

					// Options menu 选项菜单
					case OPTIONSMENU:
						if (432 < m.x && m.x < 605)
						{
							// Save 存储
							if (432 < m.x && m.x < 605 && 249 < m.y && m.y < 280) { settings.menu_options = 1; DisplayOptionsMenu(settings); Sleep(VICKY); SaveRecord(settings, myfish); }
							// Save as 存储为
							else if (432 < m.x && m.x < 605 && 288 < m.y && m.y < 319) { settings.menu_options = 2; DisplayOptionsMenu(settings); Sleep(VICKY); SaveRecord(settings, myfish); }
							// Game options 游戏选项
							else if (432 < m.x && m.x < 605 && 326 < m.y && m.y < 357) { settings.menu_options = 3; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings,myfish,GAMESETTINGS); DisplayOptions(settings); }
							// Help 帮助
							else if (432 < m.x && m.x < 605 && 364 < m.y && m.y < 395) { settings.menu_options = 4; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings, myfish, HELP); DisplayOptions(settings); }
							// Credits 制作人员
							else if (432 < m.x && m.x < 605 && 400 < m.y && m.y < 431) { settings.menu_options = 5; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings, myfish, CREDITS); DisplayOptions(settings); }
							// Accomplishment 成就
							else if (432 < m.x && m.x < 605 && 438 < m.y && m.y < 470) { settings.menu_options = 6; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings, myfish, ACCOMPLISHMENT);  DisplayOptions(settings); }
							// Exit to main menu 退出至主菜单
							else if (432 < m.x && m.x < 605 && 476 < m.y && m.y < 507) { settings.menu_options = 7; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings, myfish, EXITTOMAINMENU); DisplayOptions(settings); }
							// Exit game 退出游戏 
							else if (432 < m.x && m.x < 605 && 528 < m.y && m.y < 560) { settings.menu_options = 8; DisplayOptionsMenu(settings); Sleep(VICKY); WorkSpace(settings, myfish, EXITGAME); DisplayOptions(settings); }
						}					
						// Cancel the menu options 退出选项菜单
						else if (624 < m.x && m.x < 645 && 204 < m.y && m.y < 224) return 1;
						break;

					// Game Settings 游戏选项
					case GAMESETTINGS:
						if (910 < m.x && m.x < 939 && 76 < m.y && m.y < 104)
							return 1;
						// Restore defaults 恢复初始设置
						else if (530 < m.x && m.x < 727 && 654 < m.y && m.y < 686) { DisplayFrame(10, settings); Sleep(VICKY); DisplayFrame(3, settings); break; }
						// Apply changes 应用设置 
						else if (740 < m.x && m.x < 937 && 654 < m.y && m.y < 686){ DisplayFrame(11, settings); Sleep(VICKY); DisplayFrame(3, settings); return 1; }
						break;

					// Help 帮助
					case HELP:
						if (1006 < m.x && m.x < 1020 && 49 < m.y && m.y < 64) { Sleep(VICKY); FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); return 1; }
						break;

					// Credits 工作人员
					case CREDITS:
						if (732 < m.x && m.x < 757 && 58 < m.y && m.y < 80) { Sleep(VICKY); FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); return 1; }
						break;

					// Accomplishment 成就
					case ACCOMPLISHMENT:
						if (785 < m.x && m.x < 807 && 192 < m.y && m.y < 211) return 1;
						break;

					// Exit to main menu 退出至主菜单
					case EXITTOMAINMENU:
						if (347 < m.x && m.x < 677 && 420 < m.y && m.y < 452) { SaveRecord(settings, myfish); DisplayFrame(12, settings); Sleep(VICKY); exit(0); }
						else if (347 < m.x && m.x < 677 && 459 < m.y && m.y < 491)
						{
							DisplayFrame(13, settings); Sleep(VICKY);

							if (WorkSpace(settings, myfish, CANNOTSAVE)) { settings.game_options = 0; StopBkMusic(); StartBkMusic(settings, 2); InitSetting(settings, 2); Menu(settings); }
							else { settings.menu_options = 0; DisplayOptions(settings); FlushMouseMsgBuffer(); return 1; }
						}
						else if (347 < m.x && m.x < 677 && 497 < m.y && m.y < 529) { DisplayFrame(14, settings); Sleep(VICKY); return 1; }
						else if (662 < m.x && m.x < 683 && 240 < m.y && m.y < 261) return 1;
						break;

					// Exit Game 退出游戏
					case EXITGAME:
						if (347 < m.x && m.x < 677 && 420 < m.y && m.y < 452) { SaveRecord(settings, myfish); DisplayFrame(15, settings); Sleep(VICKY); exit(0); }
						else if (347 < m.x && m.x < 677 && 459 < m.y && m.y < 491)
						{
							DisplayFrame(16, settings); Sleep(VICKY);

							if (WorkSpace(settings, myfish, CANNOTSAVE)) exit(0);
							else { settings.menu_options = 0; DisplayOptions(settings); FlushMouseMsgBuffer(); return 1; }
						}
						else if (347 < m.x && m.x < 677 && 497 < m.y && m.y < 529) { DisplayFrame(17, settings); Sleep(VICKY); return 1; }
						else if (662 < m.x && m.x < 683 && 240 < m.y && m.y < 261) return 1;
						break;

					// Cannot save 不能储存
					case CANNOTSAVE:
						if (597 < m.x && m.x < 634 && 464 < m.y && m.y < 499) return 0;
						else if (637 < m.x && m.x < 680 && 459 < m.y && m.y < 502) return 1;
						break;
				}
			}
			else
			{
				switch (branch)
				{
					case RETURNTOMENU: OuttextChoice(1, 11);					// Return to the menu 返回主菜单			
						if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 <= m.y && m.y <= 650) OuttextChoice(4, 11);
						else OuttextChoice(1, 11);
						break;

					case CHANGESETTING:													// Change the setting 更改设置
						if(LMARGIN < m.x && m.x < LMARGIN + 95 && 620 <= m.y && m.y <= 650) OuttextChoice(1, 11);
						else OuttextChoice(3, 11);
						break;
				}
			}
		}

		switch (branch)
		{
			// Gallery 相册
			case GALLERY:
				DisplayButton(5);													// Display the left arrow 显示左箭头
				DisplayButton(6);													// Display the right arrow 显示右箭头
				EndBatchDraw(); FlushBatchDraw(); HpSleep(25);
				break;

			// Options menu 选项菜单
			case OPTIONSMENU:
				settings.menu_options = 0;
				DisplayOptionsMenu(settings);
				break;
		}
	}

	return 1;
}