#pragma once 
#include "DEF.h"
#include "Header.h"

// Menu ���˵�
int Menu(Settings &settings)
{
	char ch;
	MOUSEMSG m = GetMouseMsg();
	RankList list[50];
	static int trigger = 0;
	struct Fish_motion myfish = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 };
	
	if (trigger == 0)
	{
		InitSetting(settings, 1);												// Initiate the setting ��ʼ������
		StartBkMusic(settings, 2);										// Start the background music for menu �������˵���������
	}

	LoadMouseCursor(settings.switch_mouse);				// Change the mouse cursor �ı������
	++trigger;																		// Add trigger �Ʋ�������
	DisplayBackground(2);												// Display the menu interface ��ʾ�˵�����
	OuttextScript(1);															// Outtext the menu scripts ��ӡ�˵��ı�

	while (true)
	{
		if (_kbhit()) { ch = _getch(); if(ch == 27) Quit(); }		// Quit the game �˳���Ϸ
	
		while (MouseHit())
		{
			m = GetMouseMsg();

			if (LMARGIN < m.x && m.x < LMARGIN + 130 && 280 < m.y && m.y < 620)
			{
				// Click the buttons �����ťЧ��
				if (m.uMsg == WM_LBUTTONUP)
				{
					// Start game and choose the mode ��ʼ��Ϸ��ѡ������ģʽ
					if (LMARGIN < m.x && m.x < LMARGIN + 130 && 280 < m.y && m.y < 310)
					{
						OuttextChoice(2, 1);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������
						Category(settings, myfish);							// Category directory ���ࣨ�Ѷȣ�Ŀ¼
					}

					// Load previous record ��ȡ֮ǰ�浵
					else if (LMARGIN < m.x && m.x < LMARGIN + 130 && 330 < m.y && m.y < 360)
					{
						OuttextChoice(2, 2);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������

						if (settings.record_mode == 1)
							Game(settings, myfish);							// Enter the game ������Ϸ
					}

					// Display help information ��ʾ������Ϣ
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 380 < m.y && m.y < 410)
					{
						OuttextChoice(2, 3);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������
						DisplayBackground(5);								// Display background for help ��ʾ��������
						WorkSpace(settings, myfish, RETURNTOMENU);		// Return to the main menu  �������˵�
					}

					// Display the ranking list ��ʾ���а�
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 430 < m.y && m.y < 460)
					{
						OuttextChoice(2, 4);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������
						InitRankingList(list);										// Initiate a ranking list ��ʼ�����а�
						LoadRankingList(list);									// Load a ranking list from files ���ļ��ж�ȡ���а�
						DisplayRankingList(list);								// Display ranking list ��ʾ���а�
						WorkSpace(settings, myfish, RETURNTOMENU);		// Return to the main menu  �������˵�
					}

					// Change setting ��������
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 480 < m.y && m.y < 510)
					{
						OuttextChoice(2, 5);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������
						WorkSpace(settings, myfish, CHANGESETTING);		// Change the setting ��������
					}

					// Exit �˳���Ϸ
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 580 < m.y && m.y < 610)
					{
						OuttextChoice(2, 6);									// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);								// Play the click sound ���ŵ������
						Quit();															// Quit the game �˳���Ϸ
					}

					// Display the scripts for menu interface ��ʾ�˵������ı�
					else
						OuttextScript(1);							
					
					Sleep(20);									// Sleep for 20ms ˯��20����
				}
				// Stress the buttons ��ťЧ������ǿ��
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
						OuttextScript(1);							// Display the scripts for menu interface ��ʾ�˵������ı�
				}
			}		
		}		
	}

	StopBkMusic(); // Stop the background music for menu �������˵���������

	return 1;
}

// Category directory ���ࣨ�Ѷȣ�Ŀ¼
int Category(Settings &settings, struct Fish_motion &myfish)
{
	char ch;
	MOUSEMSG m = GetMouseMsg();

	DisplayBackground(4);						// Display the category interface ��ʾ�Ѷ�ѡ�����
	OuttextScript(2);									// Display the scripts for category interface ��ʾ�Ѷ�ѡ������ı�

	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();										// Keyboard hit  �������

			if( ch ==27)											// Esc  Esc��
					Menu(settings);							// Menu ���˵�
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
						OuttextScript(2);							// Display the scripts for category interface ��ʾ�Ѷ�ѡ������ı�
						OuttextChoice(2, 7);					// Display the scripts for the choice ��ʾѡ���ı�
						SoundEffect(settings, 2);				// Play the click sound ���ŵ������
						settings.difficulty = 1;					// Set the difficulty as easy ������Ϸ�Ѷ�Ϊ��
						settings.remain_time = 180;		// Set the remain time as 180s ������Ϸʱ��Ϊ180��
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 450 < m.y && m.y < 480)
					{
						OuttextScript(2);							// Display the scripts for category interface ��ʾ�Ѷ�ѡ������ı�
						OuttextChoice(2, 8);					// Display the scripts for the choice ��ʾѡ���ı�	
						SoundEffect(settings, 2);				// Play the click sound ���ŵ������
						settings.difficulty = 2;					// Set the difficulty as normal ������Ϸ�Ѷ�Ϊ�е�
						settings.remain_time = 150;		// Set the remain time as 150s ������Ϸʱ��Ϊ150��
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 70 && 500 < m.y && m.y < 530)
					{
						OuttextScript(2);							// Display the scripts for category interface ��ʾ�Ѷ�ѡ������ı�
						OuttextChoice(2, 9);					// Display the scripts for the choice ��ʾѡ���ı�	
						SoundEffect(settings, 2);				// Play the click sound ���ŵ������
						settings.difficulty = 3;					// Set the difficulty as hard ������Ϸ�Ѷ�Ϊ����
						settings.remain_time = 120;		// Set the remain time as 120s ������Ϸʱ��Ϊ120��
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 130 && 570 < m.y && m.y < 600)
					{
						OuttextChoice(2, 10);					// Display the scripts for the choice ��ʾѡ���ı�	
						SoundEffect(settings, 2);				// Play the click sound ���ŵ������
						settings.record_mode = 0;
						Game(settings, myfish);				// Start the game ��ʼ����Ϸ
					}
					else if (LMARGIN < m.x && m.x < LMARGIN + 95 && 620 < m.y && m.y < 650)
					{
						OuttextChoice(2, 11);					// Display the scripts for the choice ��ʾѡ���ı�				
						Menu(settings);							// Menu ���˵�
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