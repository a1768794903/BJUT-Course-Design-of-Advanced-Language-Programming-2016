#pragma once
#include "DEF.h"
#include "Header.h"

// Load Mouse Cursor ��ȡ�����
int LoadMouseCursor(int mouse_type)
{
	//HCURSOR hcur = (HCURSOR)LoadImage(NULL, _T("res\\icons\\icon_mouse.cur"), IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
	//HWND hwnd = GetHWnd();							
	//SetClassLong(hwnd, GCL_HCURSOR, (long)hcur);

	return 1;
}

// Stringer �ʵ�	
int Stringer(Settings settings)
{
	StartBkMusic(settings,3);
	StopBkMusic();

	return 1;
}

// Goldfinger cheat ����ָ������
int Goldfinger(LinkList &head, Settings &settings)
{
	LinkList appoint = NULL;
	wchar_t ccode[13];
	const wchar_t c_speedup[] = _T("SPEEDUP");
	const wchar_t c_speeddown[] = _T("SPEEDDOWN");
	const wchar_t c_invisible[] = _T("INVISIBLE");
	const wchar_t c_points[] = _T("POINTS");
	const wchar_t c_stringer[] = _T("VICKY");

	InputBox(ccode, 12, _T("���������״���"));

	if (wcscmp(ccode, c_speedup) == 0)	 { if (head->next->object.tag == 0) { head->next->object.max_speed_x += 2; head->next->object.max_speed_y += 2; } }	// Speed up ����
	else if (wcscmp(ccode, c_speeddown) == 0)	 { if (head->next->object.tag == 0) { head->next->object.max_speed_x -= 2; head->next->object.max_speed_y -= 2; } }	// Speed down ����
	else if (wcscmp(ccode, c_invisible) == 0)  ;											// Invisible ����
	else if (wcscmp(ccode, c_points) == 0)	settings.point += 100;				// Add points �ӷ�	
	else if (wcscmp(ccode, c_stringer) == 0) settings.point += VICKY;		// Stringer �ʵ�
		
	return 1;
}

// Triumph ʤ���ɹ�
int Triumph(LinkList &head, struct Settings &settings, struct Fish_motion &myfish)
{
	RankList list[50];

	InitRankingList(list);																				// Initiate a ranking list ��ʼ�����а�
	LoadRankingList(list);																			// Load a ranking list from files ���ļ��ж�ȡ���а�
	settings.rank = InsertRankingListNode(list, settings.name,settings.point);		// Insert a ranking list element �������а�Ԫ��
	SaveRankingList(list);																			// Save a ranking list from files ���ļ��д洢���а�
	SaveRecord(settings, myfish);																// Save the record �洢�浵
	DeleteLinkList(head);																			// Delete the link list ɾ������

	SoundEffect(settings, 3);																		// Play applauds sound ���Ż�������
	DisplayTriumph(settings,myfish);														// Show the triumph չʾʤ���ɹ�
	InitSetting(settings, 2);																			// Initiate the setting ��ʼ������
	InitSetting(settings, 3);																			// Initiate the setting ��ʼ������
	InitSetting(settings, 4);																			// Initiate the setting ��ʼ������
	WorkSpace(settings, myfish, RETURNTOMENU);								// Return to the main menu  �������˵�

	return 1;
}

// Initiate the setting ��ʼ������
int InitSetting(struct Settings &settings, int branch)
{
	switch (branch)
	{
		case 1:
			settings.switch_music = 1;
			settings.switch_mouse = 0;
			settings.game_speed = 0;
			settings.game_options = 0;
			break;
		case 2:
			settings.achievements.fish_is_fish = 0;
			settings.achievements.gourmet = 0;
			settings.achievements.killerss = 0;
			settings.achievements.master_of_collision = 0;
			settings.game_options = 0;
			settings.game_speed = 0;
			settings.menu_options = 0;
			settings.point = 0;
			settings.label = 0;
			settings.rank = 1;
			settings.total_time = 0;
			break;
		case 3:
			settings.game_options = 0;
			settings.game_speed = 0;
			settings.menu_options = 0;
			settings.record_mode = 1;
			break;
		case 4:
			settings.remain_time = 210 - settings.difficulty * 30;
			settings.hp = 100;
			break;
	}

	return 1;
}

// Set game options mode ������Ϸѡ��ģʽ
int SetOptionsMode(Settings &settings, int game_speed, int game_options, int menu_options)
{
	settings.game_speed = game_speed;
	settings.game_options = game_options;
	settings.menu_options = menu_options;
	return 1;
}