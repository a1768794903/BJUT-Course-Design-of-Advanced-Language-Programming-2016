#pragma once
#include "Command.h"
#include "DEF.h"
#include "Header.h"

// Game interface ��Ϸ����
int Game(struct Settings &settings, struct Fish_motion &myfish)
{	
	LinkList head;

	if(settings.record_mode == 0)
	{
		InitSetting(settings, 2);	 InitSetting(settings, 4);						// Initiate the setting ��ʼ������
		IniMyFish(head, settings, myfish);											// Initiate my fish ��ʼ����Ҳٿص���
	}
	else
	{
		LoadRecord(settings, myfish);													// Load the record ��ȡ�浵
		InitSetting(settings, 2);																// Initiate the setting ��ʼ������
		IniMyFish(head, settings, myfish);											// Initiate my fish ��ʼ����Ҳٿص���
	}

	StartBkMusic(settings, 1);															// Start the background music ��ʼ���ű�������
	DisplayBackground(1);																// Display the game interface background ��ʾ��Ϸ���汳��
	DisplayGameInterface(0, 0);														// Display game interface ��ʾ��Ϸ����
	DisplayWorkSpace(settings);														// Display the work space ��ʾ��������ʱ�䣩

	WorkSpace(settings, myfish, PAUSE); 										// Pause the game ��ͣ��Ϸ
	Sleep(VICKY);

	while (true)
	{
		if (settings.game_speed == 0)
			WorkSpace(settings, myfish, PAUSE); 								// Pause the game ��ͣ��Ϸ

		if (IfWin(head, settings, myfish))												// Judge if win �ж��Ƿ�ʤ��
			Triumph(head,settings, myfish);											// Triumph ʤ��
		else
			IfLevelUp(head);																	// Judge if level up �ж��Ƿ����� 

		RandomGenerateFish(head,settings);									// Random generate fish ���������
		SynchroMyfish(head,myfish);													// Synchronize myfish ͬ����ҵ���
		TimeMeter(settings);																// Time meter ��ʱ��

		DispatchCmd(GetCommand(settings,myfish),head,settings,myfish);
																										// Console board ����̨

		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		BeginBatchDraw();

		DisplayBackground(1);															// Display the game interface background ��ʾ��Ϸ���汳��
		Move(head, settings);																// Move �ƶ�
		IfOut(head);																				// Judge whether if out �ж��Ƿ����
		IfMeet(head, settings);																// If meet other fishs or pradate �ж��Ƿ����������������Ƿ���в�ʳ

		DisplayMyFish(head);																// Display my fish ��ʾ��ҵ���
		DisplayGameInterface(settings.game_speed, settings.game_options);
																										// Display game interface ��ʾ��Ϸ����
		DisplayWorkSpace(settings);													// Display the work space ��ʾ��������ʱ�䣩
		
		HpSleep(25);																			// Set a proper free time ���ú���ʱ����ʱ����
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		EndBatchDraw();
		FlushBatchDraw();
	}

	StopBkMusic();																			// End the background music �������ű�������
	return 1;
}

// Game over ��Ϸ����
int GameOver(LinkList &head, struct Settings &settings, struct Fish_motion &myfish)
{
	InitSetting(settings, 2);	 InitSetting(settings, 3); InitSetting(settings, 4);// Initiate the setting ��ʼ������
	DeleteLinkList(head);																	// Delete the link list ɾ������
	DisplayBackground(8);
	WorkSpace(settings, myfish, RETURNTOMENU);						// Return to the main menu  �������˵�
	return 1;
}

// Difficulty choice �Ѷ�ѡ��
int Difficulty(int difficulty,struct Fish_motion &myfish)
{
	switch (difficulty)							// Set the difficulty    �Ѷ��趨
	{
		case 0:	 break;
		case 1: myfish = { 0 , 8 , 160 , 120 , 6 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Easy    ��ģʽ
		case 2: myfish = { 0 , 6 , 120 ,  90 , 4 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Normal �е�ģʽ
		case 3: myfish = { 0 , 4 ,  96 ,  72   , 3 , 0 , 0 , 0 , 1 , 0 , 0 , 0 , 1 , 0 , 0 , 1 };	break;		// Hard     ����ģʽ	
		default: return -1;
	}

	return 1;
}