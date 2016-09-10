#pragma once 
#include "DEF.h"
#include "Header.h"

// Display all the fishes 显示所有的鱼
int DisplayFish(LinkList appoint)
{
	IMAGE img;
	IMAGE img_mask;

	switch (appoint->object.htorientation)
	{
		// Orientation is left 朝向向左
		case -1:
			switch (appoint->object.magnitude)
			{
				case 0:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_PLANKTON_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_PLANKTON_LEFT_MASK"));
					break;
				case 1:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_ALGAE_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_ALGAE_LEFT_MASK"));
					break;
				case 2:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SHRIMP_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SHRIMP_LEFT_MASK"));
					break;
				case 3:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_GOLDFISH_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_GOLDFISH_LEFT_MASK"));
					break;
				case 5:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_NEMOFISH_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_NEMOFISH_LEFT_MASK"));
					break;
				case 7:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_JELLYFISH_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_JELLYFISH_LEFT_MASK"));
					break;
				case 9:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_PIRANHA_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_PIRANHA_LEFT_MASK"));
					break;
				case 10:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_YELLOW_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_YELLOW_LEFT_MASK"));
					break;
				case 11:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_TROPICAL_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_TROPICAL_LEFT_MASK"));
					break;
				case 12:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SHARK_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SHARK_LEFT_MASK"));
					break;
				case 13:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SPONGEBOB_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SPONGEBOB_LEFT_MASK"));
					break;
			}
			break;

		default:
			switch (appoint->object.magnitude)
			{
				case 0:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_PLANKTON_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_PLANKTON_RIGHT_MASK"));
					break;
				case 1:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_ALGAE_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_ALGAE_RIGHT_MASK"));
					break;
				case 2:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SHRIMP_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SHRIMP_RIGHT_MASK"));
					break;
				case 3:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_GOLDFISH_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_GOLDFISH_RIGHT_MASK"));
					break;
				case 5:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_NEMOFISH_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_NEMOFISH_RIGHT_MASK"));
					break;
				case 7:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_JELLYFISH_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_JELLYFISH_RIGHT_MASK"));
					break;
				case 9:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_PIRANHA_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_PIRANHA_RIGHT_MASK"));
					break;
				case 10:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_YELLOW_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_YELLOW_RIGHT_MASK"));
					break;
				case 11:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_TROPICAL_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_TROPICAL_RIGHT_MASK"));
					break;
				case 12:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SHARK_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SHARK_RIGHT_MASK"));
					break;
				case 13:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_SPONGEBOB_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_SPONGEBOB_RIGHT_MASK"));
					break;
			}
			break;
	}

	putimage(appoint->object.x, appoint->object.y, &img_mask, SRCAND);
	putimage(appoint->object.x, appoint->object.y, &img, SRCINVERT);

	return 1;
}

// Display my fish 显示玩家控制的鱼
int DisplayMyFish(LinkList head)
{
	IMAGE img;
	IMAGE img_mask;
	LinkList appoint = head->next;

	switch (appoint->object.htorientation)
	{
		case -1:
			switch (appoint->object.magnitude)
			{	
				case 4:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M4_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M4_LEFT_MASK"));
					break;
				case 6:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M6_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M6_LEFT_MASK"));
					break;
				case 8:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M8_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M8_LEFT_MASK"));
					break;
				case 10:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M10_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M10_LEFT_MASK"));
					break;
				case 12:
				default:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M12_LEFT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M12_LEFT_MASK"));
					break;
			}
			break;
		default:
			switch (appoint->object.magnitude)
			{
				case 4:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M4_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M4_RIGHT_MASK"));
					break;
				case 6:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M6_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M6_RIGHT_MASK"));
					break;
				case 8:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M8_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M8_RIGHT_MASK"));
					break;
				case 10:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M10_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M10_RIGHT_MASK"));
					break;
				case 12:
				default:
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M12_RIGHT"));
					loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_FISH_MYFISH_M12_RIGHT_MASK"));
					break;
			}
			break;
	}

	putimage(appoint->object.x, appoint->object.y, &img_mask, SRCAND);
	putimage(appoint->object.x, appoint->object.y, &img, SRCINVERT);

	return 1;
}

// Display the background for game , menu , empty menu , category 显示游戏、菜单、空菜单、难度选择背景 
int DisplayBackground(int branch)
{
	IMAGE bk;

	switch (branch)
	{
		// Display the game background 显示游戏背景
		case 1:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_GAME"));
			putimage(0, 0, &bk);
			break;
		}		

		// Display the menu interface 显示菜单界面
		case 2:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_MENU"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display the empty menu interface 显示空菜单界面
		case 3:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_MENU_EMPTY"));
			putimage(0, 0, &bk);
			Sleep(VICKY);
			break;
		}
		
		// Display the category interface 显示难度选择界面
		case 4:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_CATEGORY"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display the background for ranking list 显示排行榜背景
		case 6:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ACCOMPLISHMENT"));
			putimage(0, 0, &bk);
			break;
		}

		// Display background for help 显示帮助背景
		case 5:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_HELP"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display background for lose 显示游戏失败背景
		case 8:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_EXTRAS_GAME_OVER"));
			putimage(0, 0, &bk);
			Sleep(5 * VICKY);
			break;
		}

		// Display background for setting 显示设置背景
		case 9:
		{
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_SETTING"));
			putimage(0, 0, &bk);
			break;
		}

		// Display background for gallery 显示相册背景
		case 10:
		{
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_GALLERY"));
			putimage(0, 44, &bk);
			break;
		}

		default:
			break;
	}

	return 1;
}

// Dixplay the buttons 显示按钮
int DisplayButton(int button_number)
{
	IMAGE button;
	IMAGE button_mask;

	switch (button_number)
	{
		// Display the switch-on button on the first place 显示开关-开按钮在1位置
		case 1:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_ON"));
			putimage(30, 330, &button);
			break;

		// Display the switch-off button on the first place 显示开关-关按钮在1位置
		case 2:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_OFF"));
			putimage(30, 330, &button);
			break;

		// Display the switch-on button on the second place 显示开关-开按钮在2位置
		case 3:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_ON"));
			putimage(30, 470, &button);
			break;

		// Display the switch-off button on the second place 显示开关-开按钮在2位置
		case 4:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_OFF"));
			putimage(30, 470, &button);
			break;

		// Display the left arrow 显示左箭头
		case 5:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_LEFT"));
			loadimage(&button_mask, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_LEFT_MASK"));
			putimage(0, 334, &button_mask, SRCAND);
			putimage(0, 334, &button, SRCINVERT);
			break;
	
		// Display the right arrow 显示右箭头
		case 6:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_RIGHT"));
			loadimage(&button_mask, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_RIGHT_MASK"));
			putimage(804, 334, &button_mask, SRCAND);
			putimage(804, 334, &button, SRCINVERT);
			break;

		// Enter the menu 进入菜单
		case 8:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ENTER_MENU"));
			putimage(412, 500, &button);
			break;

		default:
			break;
	}

	return 1;
}

// Display frame 显示框
int DisplayFrame(int frame_number,Settings settings)
{
	wchar_t c_name[30];
	LOGFONT font;
	IMAGE frame;
	IMAGE lock;

	switch (frame_number)
	{
		// Save as 存储为
		case 2:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_BUTTON_SAVE_GAME"));
			putimage(262, 174, &frame);
			gettextstyle(&font);															// Get font style 获取当前字体设置
			font.lfHeight = 9;																// Set the text height 60 pixels 设置字高度为60
			font.lfWidth = 25;																// Set the text width 20 pixels设置字宽度为20
			_tcscpy_s(font.lfFaceName, _T("Quartz Regular"));		// Set the font Song 设置字体为宋体
			font.lfQuality = ANTIALIASED_QUALITY;						// Set the font antialiased 设置输出效果为抗锯齿
			settextcolor(GREEN);														// Set the font white 设置字体为绿色
			settextstyle(&font);															// Flush the text font setting 设置字体样式
			CharToTchar(settings.name, c_name);
			outtextxy(156, 72, c_name);
			break;

		// Game options 游戏选项
		case 3:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_SETTINGS"));
			putimage(82, 74, &frame);
			break;

		// Help 帮助
		case 4:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_HELP"));
			putimage( 0, 44, &frame);
			break;

		// Credits 制作人员
		case 5:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CREDITS"));
			putimage(262, 50, &frame);
			break;

		// Achievements 成就
		case 6:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_ACHIEVEMENTS"));
			putimage(212, 184, &frame);
			loadimage(&lock, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_ACHIEVEMENTS_LOCK"));

			if (settings.achievements.fish_is_fish == 0)
				putimage(419, 290, &lock);

			if (settings.achievements.gourmet < 10)
				putimage(419, 368, &lock);

			if (settings.achievements.killerss < 10)
				putimage(419, 444, &lock);

			if (settings.achievements.master_of_collision < 10)
				putimage(419, 523, &lock);

			break;

		// Exit to main menu 退出至主菜单
		case 7:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE"));
			putimage(337, 234, &frame);
			break;

		// Exit game 退出游戏 
		case 8:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE"));
			putimage(337, 234, &frame);
			break;

		// Cannot save 无法储存
		case 9:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CANNOT_SAVE"));
			putimage(337, 259, &frame);
			break;

		// Game options : Restore defaults 游戏选项-恢复初始设置
		case 10:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_RESTORE_DEFAULTS_EFFECT"));
			putimage(82, 74, &frame);
			break;

		// Game options : Apply changes 游戏选项-应用设置
		case 11:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_APPLY_CHANGES_EFFECT"));
			putimage(82, 74, &frame);
			break;

		// Exit to main menu : Save and exit 退出至主菜单 - 存储并退出
		case 12:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_SAVE_AND_EXIT_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit to main menu : Exit to main menu 退出至主菜单 - 退出至主菜单
		case 13:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_EXIT_TO_MAIN_MENU_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit to main menu : Cancel 退出至主菜单 - 取消
		case 14:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_CANCEL_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game : Save and exit 退出游戏 - 存储并退出
		case 15:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_SAVE_AND_EXIT_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game : Exit to main menu 退出游戏 - 退出至主菜单
		case 16:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_EXIT_GAME_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game :  Cancel 退出游戏 - 取消
		case 17:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_CANCEL_EFFECT"));
			putimage(337, 234, &frame);
			break;
	}

	return 1;
}

// Display game interface 显示游戏界面
int DisplayGameInterface(int game_speed , int game_options)
{
	IMAGE img;
	IMAGE img_mask;
	IMAGE img_dup;
	IMAGE img_dup_mask;

	switch (game_speed)
	{
		// Diplay the information bar 显示暂停信息栏
		case 0:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_PAUSE_BOTTOM"));
			break;

		// Diplay the information bar 显示1×倍速信息栏
		case 1:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_NORMAL_BOTTOM"));
			break;

		// Diplay the information bar 显示2×倍速信息栏
		case 2:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_FAST_BOTTOM"));
			break;

		// Diplay the information bar 显示3×倍速信息栏
		case 3:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_ULTRA_BOTTOM"));
			break;
	}

	loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_MASK_BOTTOM"));
	putimage(0, 718, &img_mask, SRCAND);
	putimage(0, 718, &img, SRCINVERT);

	switch(game_options)
	{
		// Display options bar 显示选项栏
		case 0:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS"));
			break;

		// Display options bar with options effect 显示选项栏中选项的效果
		case 1:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_OPTIONS_EFFECT"));
			break;

		// Display options bar with options effect 显示选项栏中相册的效果
		case 2:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_GALLERY_EFFECT"));
			break;

		// Display options bar with settings effect 显示选项栏中设置的效果
		case 3:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_SETTINGS_EFFECT"));
			break;

		// Display options bar with new game effect 显示选项栏中新游戏的效果
		case 4:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_NEW_GAME_EFFECT"));
			break;

		// Display options bar with save effect 显示选项栏中存储的效果
		case 5:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_SAVE_EFFECT"));
			break;
	}

	loadimage(&img_dup_mask, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_MASK"));
	putimage(824, 0, &img_dup_mask, SRCAND);
	putimage(824, 0, &img_dup, SRCINVERT);

	return 1;
}

// Display options 显示选项菜单
int DisplayOptions(Settings settings)
{
	DisplayBackground(1);
	DisplayGameInterface(0, 0);
	DisplayWorkSpace(settings);
	DisplayOptionsMenu(settings);
	return 1;
}

// Display options menu 显示选项菜单
int DisplayOptionsMenu(Settings settings)
{
	IMAGE img_menu;

	switch (settings.menu_options)
	{
		// Menu interface 菜单界面
		case 0:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU"));
			putimage(372, 194, &img_menu);
			break;

		// Save interface 菜单界面-存储
		case 1:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_SAVE_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Save as interface 菜单界面-存储为
		case 2:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_SAVE_AS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// GameOptions interface 菜单界面-游戏选项
		case 3:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Help interface 菜单界面-帮助
		case 4:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_HELP_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Credits interface 菜单界面=制作人员
		case 5:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CREDITS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Achievements interface 菜单界面-成就
		case 6:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_ACHIEVEMENTS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// ExitToMenu interface 菜单界面-退出至主菜单
		case 7:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MENU_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// ExitGame interface 菜单界面-退出游戏
		case 8:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

	}

	return 1;
}

// Display ranking list 显示排行榜
int DisplayRankingList(RankList *list)
{
	wchar_t c_point[10];
	wchar_t c_name[30];
	DisplayBackground(6);

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 52;
	font.lfWidth = 26;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(CYAN);

	if (list[0].point != 0)
	{
		wsprintf(c_point, L"%d", list[0].point);
		CharToTchar(list[0].name, c_name);
		outtextxy(160, 297, c_name);												// Outtext the name of the first place 显示第一名的姓名
		outtextxy(560, 297, (LPTSTR)c_point);								// Outtext the point of the first place 显示第一名的分数
		wcscpy(c_point,L"");
	}
	if (list[1].point != 0)
	{
		wsprintf(c_point, L"%d", list[1].point);
		CharToTchar(list[1].name, c_name);
		outtextxy(310, 439, c_name);												// Outtext the name of the second place 显示第二名的姓名
		outtextxy(700, 439, (LPTSTR)c_point);								// Outtext the point of the second place 显示第二名的分数
		wcscpy(c_point, L"");
	}

	if (list[2].point != 0)
	{
		wsprintf(c_point, L"%d", list[2].point);
		CharToTchar(list[2].name, c_name);
		outtextxy(445, 575, c_name);												// Outtext the name of the third place 显示第三名的姓名
		outtextxy(845, 575, (LPTSTR)c_point);								// Outtext the point of the third place 显示第三名的分数
	}
	
	return 1;
}

// Display setting 显示设置
int DisplaySetting(void)
{
	const wchar_t c_control[] = L"鼠标操控";
	const wchar_t c_background_music[] = L"背景音乐";
	IMAGE switch1;
	IMAGE switch2;

	DisplayBackground(9);

	settextcolor(WHITE);
	outtextxy(30, 280, c_control);
	outtextxy(30, 420, c_background_music);
	OuttextChoice(3, 11);
	loadimage(&switch1, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_OFF"));
	loadimage(&switch2, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_ON"));
	putimage(30, 330, &switch1);
	putimage(30, 470, &switch2);

	return 1;
}

// Display the triumph interface 显示胜利界面
int DisplayTriumph(Settings settings, struct Fish_motion myfish)
{
	wchar_t str[30];
	wchar_t c_name[30];
	IMAGE img;
	LOGFONT font;

	loadimage(&img, _T("IMAGE_BITMAP"), _T("P_EXTRAS_TRIUMPH_WIN"));
	putimage(0, 0, &img);
	Sleep(2 * VICKY);
	loadimage(&img, _T("IMAGE_BITMAP"), _T("P_EXTRAS_TRIUMPH_CONGRATULATIONS"));
	putimage(0, 0, &img);
	Sleep(2 * VICKY);
	loadimage(&img, _T("IMAGE_BITMAP"), _T("P_EXTRAS_TRIUMPH_RESULT"));
	putimage(0, 0, &img);
	Sleep(VICKY);

	gettextstyle(&font);
	font.lfHeight = 80;
	font.lfWidth = 40;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextcolor(BLACK);
	settextstyle(&font);
	CharToTchar(settings.name, c_name);
	outtextxy(565, 225, c_name);								// Outtext the gamer's name 显示玩家姓名

	font.lfHeight = 48;
	font.lfWidth = 24;
	settextstyle(&font);
	wsprintf(str, L"%d POINTS", settings.point);
	outtextxy(436, 320, str);										// Outtext the gamer's point 显示玩家得分

	wsprintf(str, L"%d", myfish.nutrition);
	outtextxy(680, 387, str);										// Outtext the nutrition 显示鱼的营养分

	wsprintf(str, L"%d", settings.rank);

	if (settings.rank == 1)
		wcscat(str, L"ST");
	else if (settings.rank == 2)
		wcscat(str, L"ND");
	else if (settings.rank == 3)
		wcscat(str, L"RD");
	else
		wcscat(str, L"TH");

	outtextxy(272, 448, str);									// Outtext the rank 显示玩家的排名
	 
	return 1;
}

// Display wallpaper 显示壁纸
int DisplayWallpaper(void)
{
	srand((unsigned)time(NULL));
	IMAGE randBkground;
	int randbk = rand() % 3;

	switch (randbk)
	{
		case 0:
			loadimage(&randBkground, _T("IMAGE_BITMAP"), _T("P_BACKGROUND1"));
			putimage(0, 0, &randBkground);
			break;
		case 1:
			loadimage(&randBkground, _T("IMAGE_BITMAP"), _T("P_BACKGROUND2"));
			putimage(0, 0, &randBkground);
			break;
		default:
			loadimage(&randBkground, _T("IMAGE_BITMAP"), _T("P_BACKGROUND3"));
			putimage(0, 0, &randBkground);
			break;
	}

	Sleep(VICKY);

	return 1;
}

// Display the work space 显示工作区（时间）
int DisplayWorkSpace(Settings &settings)
{
	wchar_t c_hp[5];
	wchar_t c_total_time[5];
	wchar_t c_remain_time[5];
	wchar_t c_point[5];
	wchar_t c_name[30];
	const wchar_t c_pause[] = L"暂停";
	const wchar_t c_player[] = L"玩家";
	IMAGE img;
	IMAGE img_mask;
	LOGFONT font;

	setfillcolor(RED);																// Set fill color as red 设置填充颜色为红色
	setlinecolor(BLACK);														// Set line color as black 设置线颜色为黑
	fillrectangle(55, 718, 75 + 2*settings.hp, 738);				// Print the hp 显示血槽

	gettextstyle(&font);															// Get font style 获取当前字体设置
	font.lfHeight = 18;															// Set the text height 18 pixels 设置字高度为18
	font.lfWidth = 12;																// Set the text width 12 pixels设置字宽度为12
	_tcscpy_s(font.lfFaceName, _T("黑体"));						// Set the font Song 设置字体为黑体
	font.lfQuality = ANTIALIASED_QUALITY;						// Set the font antialiased 设置输出效果为抗锯齿
	settextstyle(&font);															// Flush the text font setting 设置字体样式

	wsprintf(c_hp, L"%d", settings.hp);
	wsprintf(c_total_time, L"%d", settings.total_time);
	wsprintf(c_remain_time, L"%d", settings.remain_time);
	wsprintf(c_point, L"%d", settings.point);

	settextcolor(RED);															// Set the font red 设置字体为红色
	outtextxy(18, 720, L"HP");												// Outtext slogan for life hp 显示生命值标示
	settextcolor(GREEN);														// Set the font green 设置字体为绿色
	outtextxy(222, 744, c_remain_time);								// Outtext the remain time 显示剩余时间
	settextcolor(WHITE);														// Set the font white 设置字体为白色
	outtextxy(140, 720, c_hp);												// Outtext life hp 显示生命值		
	outtextxy(90, 742, c_point);												// Outtext score 显示得分			
	outtextxy(780, 743, c_player);											// Outtext "player" 显示“玩家”

	font.lfHeight = 10;															// Set the text height 10 pixels 设置字高度为10
	font.lfWidth = 6;																// Set the text width 6 pixels设置字宽度为6
	settextstyle(&font);															// Flush the text font setting 设置字体样式
	outtextxy(532, 753, c_total_time);									// Outtext the remain time 显示已过时间			

	if (settings.game_speed == 0)
	{
		settextcolor(WHITE);
		outtextxy(523, 703, c_pause);
	}

	font.lfHeight = 30;															// Set the text height 30 pixels 设置字高度为 30
	font.lfWidth = 15;																// Set the text width 15 pixels设置字宽度为15
	settextstyle(&font);															// Flush the text font setting 设置字体样式
	CharToTchar(settings.name, c_name);
	outtextxy(835, 734, c_name);											// Outtext the player 显示用户名

	return 1;
}

// Display the scripts for menu interface 显示界面文本
int OuttextScript(int branch)
{
	const wchar_t c_start[] = L"开始游戏";
	const wchar_t c_loading[] = L"读取存档";
	const wchar_t c_help[] = L"帮助";
	const wchar_t c_accomplishment[] = L"成就";
	const wchar_t c_setting[] = L"设置";
	const wchar_t c_quit[] = L"退出";
	const wchar_t c_menu[] = L"主菜单";
	const wchar_t c_easy[] = L"简单";
	const wchar_t c_norm[] = L"中等";
	const wchar_t c_hard[] = L"困难";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	switch (branch)
	{
		// Display the scripts for menu interface 显示菜单界面文本
		case 1:
			outtextxy(LMARGIN, 280, c_start);
			outtextxy(LMARGIN, 330, c_loading);
			outtextxy(LMARGIN, 380, c_help);
			outtextxy(LMARGIN, 430, c_accomplishment);
			outtextxy(LMARGIN, 480, c_setting);
			outtextxy(LMARGIN, 580, c_quit);
			break;
		// Display the scripts for category interface 显示难度选择界面文本
		case 2:
			outtextxy(LMARGIN, 400, c_easy);
			outtextxy(LMARGIN, 450, c_norm);
			outtextxy(LMARGIN, 500, c_hard);
			outtextxy(LMARGIN, 570, c_start);
			outtextxy(LMARGIN, 620, c_menu);
			break;
	}

	return 1;
}

// Display the scripts for the choice 显示选项文本
int OuttextChoice( int mode , int choice)
{
	const wchar_t c_start[] = L"开始游戏";
	const wchar_t c_loading[] = L"读取存档";
	const wchar_t c_help[] = L"帮助";
	const wchar_t c_accomplishment[] = L"成就";
	const wchar_t c_setting[] = L"设置";
	const wchar_t c_quit[] = L"退出";
	const wchar_t c_menu[] = L"主菜单";
	const wchar_t c_easy[] = L"简单";
	const wchar_t c_norm[] = L"中等";
	const wchar_t c_hard[] = L"困难";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);

	if (mode == 1)
		settextcolor(LIGHTGRAY);
	else if (mode == 2)
		settextcolor(MAGENTA);
	else if (mode == 3)
		settextcolor(WHITE);
	else if(mode ==  4)
		settextcolor(GREEN);

	switch (choice)
	{
		case 0: break;
		case 1: outtextxy(LMARGIN, 280, c_start); break;
		case 2: outtextxy(LMARGIN, 330, c_loading); break;
		case 3: outtextxy(LMARGIN, 380, c_help); break;
		case 4: outtextxy(LMARGIN, 430, c_accomplishment); break;
		case 5: outtextxy(LMARGIN, 480, c_setting); break;
		case 6: outtextxy(LMARGIN, 580, c_quit); break;
		case 7: outtextxy(LMARGIN, 400, c_easy); break;
		case 8: outtextxy(LMARGIN, 450, c_norm); break;
		case 9: outtextxy(LMARGIN, 500, c_hard); break;
		case 10: outtextxy(LMARGIN, 570, c_start); break;
		case 11: outtextxy(LMARGIN, 620,c_menu); break;
		default: break;
	}

	if (mode == 2) Sleep(VICKY);

	return 1;
}

// Display the scripts for the difficulty choice 显示难度选项文本
int OuttextDifficulty(int difficulty)
{
	const wchar_t c_easy[] = L"简单";
	const wchar_t c_norm[] = L"中等";
	const wchar_t c_hard[] = L"困难";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(GREEN);

	switch (difficulty)
	{
		case 1: outtextxy(LMARGIN, 400, c_easy); break;
		case 2: outtextxy(LMARGIN, 450, c_norm); break;
		case 3: outtextxy(LMARGIN, 500, c_hard); break;
	}

	return 1;
}

// Print the screenshot 打印截屏
int PrintScreenShot(void)
{
	IMAGE temp;
	loadimage(&temp, L"screenshots\\temp.jpg");
	putimage(0, 0, &temp);
	return 1;
}

// Get the screenshot 获取截屏
int ScreenShot(int mode,Settings &settings)
{
	wchar_t c_image_screen_shot[50];
	IMAGE screen_shot;
	static int tag = 0;

	switch (mode)
	{
		case 0:
			getimage(&screen_shot, 0, 0, 1024, 768);
			saveimage(L"screenshots\\temp.jpg", &screen_shot);
			break;
		case 1:
			++settings.screenshots_num;
			getimage(&screen_shot, 50, 65, 905, 620);
			wsprintf(c_image_screen_shot, L"screenshots\\under_the_sea_screen_shot_%d.jpg", tag);
			++settings.screenshots_num;
			saveimage(c_image_screen_shot, &screen_shot);
			++tag;
			Sleep(VICKY);
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			break;
	}
	
	return tag;
}