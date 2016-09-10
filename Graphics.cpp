#pragma once 
#include "DEF.h"
#include "Header.h"

// Display all the fishes ��ʾ���е���
int DisplayFish(LinkList appoint)
{
	IMAGE img;
	IMAGE img_mask;

	switch (appoint->object.htorientation)
	{
		// Orientation is left ��������
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

// Display my fish ��ʾ��ҿ��Ƶ���
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

// Display the background for game , menu , empty menu , category ��ʾ��Ϸ���˵����ղ˵����Ѷ�ѡ�񱳾� 
int DisplayBackground(int branch)
{
	IMAGE bk;

	switch (branch)
	{
		// Display the game background ��ʾ��Ϸ����
		case 1:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_GAME"));
			putimage(0, 0, &bk);
			break;
		}		

		// Display the menu interface ��ʾ�˵�����
		case 2:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_MENU"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display the empty menu interface ��ʾ�ղ˵�����
		case 3:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_MENU_EMPTY"));
			putimage(0, 0, &bk);
			Sleep(VICKY);
			break;
		}
		
		// Display the category interface ��ʾ�Ѷ�ѡ�����
		case 4:		
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_CATEGORY"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display the background for ranking list ��ʾ���а񱳾�
		case 6:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ACCOMPLISHMENT"));
			putimage(0, 0, &bk);
			break;
		}

		// Display background for help ��ʾ��������
		case 5:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_HELP"));
			putimage(0, 0, &bk);
			break;
		}
		
		// Display background for lose ��ʾ��Ϸʧ�ܱ���
		case 8:
		{
			cleardevice();
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_EXTRAS_GAME_OVER"));
			putimage(0, 0, &bk);
			Sleep(5 * VICKY);
			break;
		}

		// Display background for setting ��ʾ���ñ���
		case 9:
		{
			loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_SETTING"));
			putimage(0, 0, &bk);
			break;
		}

		// Display background for gallery ��ʾ��ᱳ��
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

// Dixplay the buttons ��ʾ��ť
int DisplayButton(int button_number)
{
	IMAGE button;
	IMAGE button_mask;

	switch (button_number)
	{
		// Display the switch-on button on the first place ��ʾ����-����ť��1λ��
		case 1:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_ON"));
			putimage(30, 330, &button);
			break;

		// Display the switch-off button on the first place ��ʾ����-�ذ�ť��1λ��
		case 2:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_OFF"));
			putimage(30, 330, &button);
			break;

		// Display the switch-on button on the second place ��ʾ����-����ť��2λ��
		case 3:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_ON"));
			putimage(30, 470, &button);
			break;

		// Display the switch-off button on the second place ��ʾ����-����ť��2λ��
		case 4:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_SWITCH_OFF"));
			putimage(30, 470, &button);
			break;

		// Display the left arrow ��ʾ���ͷ
		case 5:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_LEFT"));
			loadimage(&button_mask, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_LEFT_MASK"));
			putimage(0, 334, &button_mask, SRCAND);
			putimage(0, 334, &button, SRCINVERT);
			break;
	
		// Display the right arrow ��ʾ�Ҽ�ͷ
		case 6:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_RIGHT"));
			loadimage(&button_mask, _T("IMAGE_BITMAP"), _T("P_BUTTON_ARROW_RIGHT_MASK"));
			putimage(804, 334, &button_mask, SRCAND);
			putimage(804, 334, &button, SRCINVERT);
			break;

		// Enter the menu ����˵�
		case 8:
			loadimage(&button, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ENTER_MENU"));
			putimage(412, 500, &button);
			break;

		default:
			break;
	}

	return 1;
}

// Display frame ��ʾ��
int DisplayFrame(int frame_number,Settings settings)
{
	wchar_t c_name[30];
	LOGFONT font;
	IMAGE frame;
	IMAGE lock;

	switch (frame_number)
	{
		// Save as �洢Ϊ
		case 2:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_BUTTON_SAVE_GAME"));
			putimage(262, 174, &frame);
			gettextstyle(&font);															// Get font style ��ȡ��ǰ��������
			font.lfHeight = 9;																// Set the text height 60 pixels �����ָ߶�Ϊ60
			font.lfWidth = 25;																// Set the text width 20 pixels�����ֿ��Ϊ20
			_tcscpy_s(font.lfFaceName, _T("Quartz Regular"));		// Set the font Song ��������Ϊ����
			font.lfQuality = ANTIALIASED_QUALITY;						// Set the font antialiased �������Ч��Ϊ�����
			settextcolor(GREEN);														// Set the font white ��������Ϊ��ɫ
			settextstyle(&font);															// Flush the text font setting ����������ʽ
			CharToTchar(settings.name, c_name);
			outtextxy(156, 72, c_name);
			break;

		// Game options ��Ϸѡ��
		case 3:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_SETTINGS"));
			putimage(82, 74, &frame);
			break;

		// Help ����
		case 4:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_HELP"));
			putimage( 0, 44, &frame);
			break;

		// Credits ������Ա
		case 5:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CREDITS"));
			putimage(262, 50, &frame);
			break;

		// Achievements �ɾ�
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

		// Exit to main menu �˳������˵�
		case 7:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE"));
			putimage(337, 234, &frame);
			break;

		// Exit game �˳���Ϸ 
		case 8:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE"));
			putimage(337, 234, &frame);
			break;

		// Cannot save �޷�����
		case 9:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CANNOT_SAVE"));
			putimage(337, 259, &frame);
			break;

		// Game options : Restore defaults ��Ϸѡ��-�ָ���ʼ����
		case 10:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_RESTORE_DEFAULTS_EFFECT"));
			putimage(82, 74, &frame);
			break;

		// Game options : Apply changes ��Ϸѡ��-Ӧ������
		case 11:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_APPLY_CHANGES_EFFECT"));
			putimage(82, 74, &frame);
			break;

		// Exit to main menu : Save and exit �˳������˵� - �洢���˳�
		case 12:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_SAVE_AND_EXIT_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit to main menu : Exit to main menu �˳������˵� - �˳������˵�
		case 13:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_EXIT_TO_MAIN_MENU_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit to main menu : Cancel �˳������˵� - ȡ��
		case 14:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MAIN_MENU_SAVE_CANCEL_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game : Save and exit �˳���Ϸ - �洢���˳�
		case 15:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_SAVE_AND_EXIT_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game : Exit to main menu �˳���Ϸ - �˳������˵�
		case 16:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_EXIT_GAME_EFFECT"));
			putimage(337, 234, &frame);
			break;

		// Exit game :  Cancel �˳���Ϸ - ȡ��
		case 17:
			loadimage(&frame, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_SAVE_CANCEL_EFFECT"));
			putimage(337, 234, &frame);
			break;
	}

	return 1;
}

// Display game interface ��ʾ��Ϸ����
int DisplayGameInterface(int game_speed , int game_options)
{
	IMAGE img;
	IMAGE img_mask;
	IMAGE img_dup;
	IMAGE img_dup_mask;

	switch (game_speed)
	{
		// Diplay the information bar ��ʾ��ͣ��Ϣ��
		case 0:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_PAUSE_BOTTOM"));
			break;

		// Diplay the information bar ��ʾ1��������Ϣ��
		case 1:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_NORMAL_BOTTOM"));
			break;

		// Diplay the information bar ��ʾ2��������Ϣ��
		case 2:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_FAST_BOTTOM"));
			break;

		// Diplay the information bar ��ʾ3��������Ϣ��
		case 3:
			loadimage(&img, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_SPEED_ULTRA_BOTTOM"));
			break;
	}

	loadimage(&img_mask, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_MASK_BOTTOM"));
	putimage(0, 718, &img_mask, SRCAND);
	putimage(0, 718, &img, SRCINVERT);

	switch(game_options)
	{
		// Display options bar ��ʾѡ����
		case 0:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS"));
			break;

		// Display options bar with options effect ��ʾѡ������ѡ���Ч��
		case 1:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_OPTIONS_EFFECT"));
			break;

		// Display options bar with options effect ��ʾѡ����������Ч��
		case 2:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_GALLERY_EFFECT"));
			break;

		// Display options bar with settings effect ��ʾѡ���������õ�Ч��
		case 3:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_SETTINGS_EFFECT"));
			break;

		// Display options bar with new game effect ��ʾѡ����������Ϸ��Ч��
		case 4:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_NEW_GAME_EFFECT"));
			break;

		// Display options bar with save effect ��ʾѡ�����д洢��Ч��
		case 5:
			loadimage(&img_dup, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_SAVE_EFFECT"));
			break;
	}

	loadimage(&img_dup_mask, _T("IMAGE_BITMAP"), _T("P_GAME_INTERFACE_OPTIONS_MASK"));
	putimage(824, 0, &img_dup_mask, SRCAND);
	putimage(824, 0, &img_dup, SRCINVERT);

	return 1;
}

// Display options ��ʾѡ��˵�
int DisplayOptions(Settings settings)
{
	DisplayBackground(1);
	DisplayGameInterface(0, 0);
	DisplayWorkSpace(settings);
	DisplayOptionsMenu(settings);
	return 1;
}

// Display options menu ��ʾѡ��˵�
int DisplayOptionsMenu(Settings settings)
{
	IMAGE img_menu;

	switch (settings.menu_options)
	{
		// Menu interface �˵�����
		case 0:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU"));
			putimage(372, 194, &img_menu);
			break;

		// Save interface �˵�����-�洢
		case 1:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_SAVE_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Save as interface �˵�����-�洢Ϊ
		case 2:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_SAVE_AS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// GameOptions interface �˵�����-��Ϸѡ��
		case 3:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_GAME_OPTIONS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Help interface �˵�����-����
		case 4:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_HELP_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Credits interface �˵�����=������Ա
		case 5:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_CREDITS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// Achievements interface �˵�����-�ɾ�
		case 6:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_ACHIEVEMENTS_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// ExitToMenu interface �˵�����-�˳������˵�
		case 7:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_TO_MENU_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

		// ExitGame interface �˵�����-�˳���Ϸ
		case 8:
			loadimage(&img_menu, _T("IMAGE_BITMAP"), _T("P_OPTIONS_MENU_EXIT_GAME_EFFECT"));
			putimage(372, 194, &img_menu);
			break;

	}

	return 1;
}

// Display ranking list ��ʾ���а�
int DisplayRankingList(RankList *list)
{
	wchar_t c_point[10];
	wchar_t c_name[30];
	DisplayBackground(6);

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 52;
	font.lfWidth = 26;
	_tcscpy_s(font.lfFaceName, _T("����"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(CYAN);

	if (list[0].point != 0)
	{
		wsprintf(c_point, L"%d", list[0].point);
		CharToTchar(list[0].name, c_name);
		outtextxy(160, 297, c_name);												// Outtext the name of the first place ��ʾ��һ��������
		outtextxy(560, 297, (LPTSTR)c_point);								// Outtext the point of the first place ��ʾ��һ���ķ���
		wcscpy(c_point,L"");
	}
	if (list[1].point != 0)
	{
		wsprintf(c_point, L"%d", list[1].point);
		CharToTchar(list[1].name, c_name);
		outtextxy(310, 439, c_name);												// Outtext the name of the second place ��ʾ�ڶ���������
		outtextxy(700, 439, (LPTSTR)c_point);								// Outtext the point of the second place ��ʾ�ڶ����ķ���
		wcscpy(c_point, L"");
	}

	if (list[2].point != 0)
	{
		wsprintf(c_point, L"%d", list[2].point);
		CharToTchar(list[2].name, c_name);
		outtextxy(445, 575, c_name);												// Outtext the name of the third place ��ʾ������������
		outtextxy(845, 575, (LPTSTR)c_point);								// Outtext the point of the third place ��ʾ�������ķ���
	}
	
	return 1;
}

// Display setting ��ʾ����
int DisplaySetting(void)
{
	const wchar_t c_control[] = L"���ٿ�";
	const wchar_t c_background_music[] = L"��������";
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

// Display the triumph interface ��ʾʤ������
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
	_tcscpy_s(font.lfFaceName, _T("����"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextcolor(BLACK);
	settextstyle(&font);
	CharToTchar(settings.name, c_name);
	outtextxy(565, 225, c_name);								// Outtext the gamer's name ��ʾ�������

	font.lfHeight = 48;
	font.lfWidth = 24;
	settextstyle(&font);
	wsprintf(str, L"%d POINTS", settings.point);
	outtextxy(436, 320, str);										// Outtext the gamer's point ��ʾ��ҵ÷�

	wsprintf(str, L"%d", myfish.nutrition);
	outtextxy(680, 387, str);										// Outtext the nutrition ��ʾ���Ӫ����

	wsprintf(str, L"%d", settings.rank);

	if (settings.rank == 1)
		wcscat(str, L"ST");
	else if (settings.rank == 2)
		wcscat(str, L"ND");
	else if (settings.rank == 3)
		wcscat(str, L"RD");
	else
		wcscat(str, L"TH");

	outtextxy(272, 448, str);									// Outtext the rank ��ʾ��ҵ�����
	 
	return 1;
}

// Display wallpaper ��ʾ��ֽ
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

// Display the work space ��ʾ��������ʱ�䣩
int DisplayWorkSpace(Settings &settings)
{
	wchar_t c_hp[5];
	wchar_t c_total_time[5];
	wchar_t c_remain_time[5];
	wchar_t c_point[5];
	wchar_t c_name[30];
	const wchar_t c_pause[] = L"��ͣ";
	const wchar_t c_player[] = L"���";
	IMAGE img;
	IMAGE img_mask;
	LOGFONT font;

	setfillcolor(RED);																// Set fill color as red ���������ɫΪ��ɫ
	setlinecolor(BLACK);														// Set line color as black ��������ɫΪ��
	fillrectangle(55, 718, 75 + 2*settings.hp, 738);				// Print the hp ��ʾѪ��

	gettextstyle(&font);															// Get font style ��ȡ��ǰ��������
	font.lfHeight = 18;															// Set the text height 18 pixels �����ָ߶�Ϊ18
	font.lfWidth = 12;																// Set the text width 12 pixels�����ֿ��Ϊ12
	_tcscpy_s(font.lfFaceName, _T("����"));						// Set the font Song ��������Ϊ����
	font.lfQuality = ANTIALIASED_QUALITY;						// Set the font antialiased �������Ч��Ϊ�����
	settextstyle(&font);															// Flush the text font setting ����������ʽ

	wsprintf(c_hp, L"%d", settings.hp);
	wsprintf(c_total_time, L"%d", settings.total_time);
	wsprintf(c_remain_time, L"%d", settings.remain_time);
	wsprintf(c_point, L"%d", settings.point);

	settextcolor(RED);															// Set the font red ��������Ϊ��ɫ
	outtextxy(18, 720, L"HP");												// Outtext slogan for life hp ��ʾ����ֵ��ʾ
	settextcolor(GREEN);														// Set the font green ��������Ϊ��ɫ
	outtextxy(222, 744, c_remain_time);								// Outtext the remain time ��ʾʣ��ʱ��
	settextcolor(WHITE);														// Set the font white ��������Ϊ��ɫ
	outtextxy(140, 720, c_hp);												// Outtext life hp ��ʾ����ֵ		
	outtextxy(90, 742, c_point);												// Outtext score ��ʾ�÷�			
	outtextxy(780, 743, c_player);											// Outtext "player" ��ʾ����ҡ�

	font.lfHeight = 10;															// Set the text height 10 pixels �����ָ߶�Ϊ10
	font.lfWidth = 6;																// Set the text width 6 pixels�����ֿ��Ϊ6
	settextstyle(&font);															// Flush the text font setting ����������ʽ
	outtextxy(532, 753, c_total_time);									// Outtext the remain time ��ʾ�ѹ�ʱ��			

	if (settings.game_speed == 0)
	{
		settextcolor(WHITE);
		outtextxy(523, 703, c_pause);
	}

	font.lfHeight = 30;															// Set the text height 30 pixels �����ָ߶�Ϊ 30
	font.lfWidth = 15;																// Set the text width 15 pixels�����ֿ��Ϊ15
	settextstyle(&font);															// Flush the text font setting ����������ʽ
	CharToTchar(settings.name, c_name);
	outtextxy(835, 734, c_name);											// Outtext the player ��ʾ�û���

	return 1;
}

// Display the scripts for menu interface ��ʾ�����ı�
int OuttextScript(int branch)
{
	const wchar_t c_start[] = L"��ʼ��Ϸ";
	const wchar_t c_loading[] = L"��ȡ�浵";
	const wchar_t c_help[] = L"����";
	const wchar_t c_accomplishment[] = L"�ɾ�";
	const wchar_t c_setting[] = L"����";
	const wchar_t c_quit[] = L"�˳�";
	const wchar_t c_menu[] = L"���˵�";
	const wchar_t c_easy[] = L"��";
	const wchar_t c_norm[] = L"�е�";
	const wchar_t c_hard[] = L"����";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("����"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	switch (branch)
	{
		// Display the scripts for menu interface ��ʾ�˵������ı�
		case 1:
			outtextxy(LMARGIN, 280, c_start);
			outtextxy(LMARGIN, 330, c_loading);
			outtextxy(LMARGIN, 380, c_help);
			outtextxy(LMARGIN, 430, c_accomplishment);
			outtextxy(LMARGIN, 480, c_setting);
			outtextxy(LMARGIN, 580, c_quit);
			break;
		// Display the scripts for category interface ��ʾ�Ѷ�ѡ������ı�
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

// Display the scripts for the choice ��ʾѡ���ı�
int OuttextChoice( int mode , int choice)
{
	const wchar_t c_start[] = L"��ʼ��Ϸ";
	const wchar_t c_loading[] = L"��ȡ�浵";
	const wchar_t c_help[] = L"����";
	const wchar_t c_accomplishment[] = L"�ɾ�";
	const wchar_t c_setting[] = L"����";
	const wchar_t c_quit[] = L"�˳�";
	const wchar_t c_menu[] = L"���˵�";
	const wchar_t c_easy[] = L"��";
	const wchar_t c_norm[] = L"�е�";
	const wchar_t c_hard[] = L"����";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("����"));
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

// Display the scripts for the difficulty choice ��ʾ�Ѷ�ѡ���ı�
int OuttextDifficulty(int difficulty)
{
	const wchar_t c_easy[] = L"��";
	const wchar_t c_norm[] = L"�е�";
	const wchar_t c_hard[] = L"����";

	LOGFONT font;
	gettextstyle(&font);
	font.lfHeight = 30;
	font.lfWidth = 15;
	_tcscpy_s(font.lfFaceName, _T("����"));
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

// Print the screenshot ��ӡ����
int PrintScreenShot(void)
{
	IMAGE temp;
	loadimage(&temp, L"screenshots\\temp.jpg");
	putimage(0, 0, &temp);
	return 1;
}

// Get the screenshot ��ȡ����
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