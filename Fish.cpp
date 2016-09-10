#include "Header.h"
#include "DEF.h"

// Generate a fish ������
int GenerateFish(LinkList &head, Settings &settings,int fishtype,int fishnumber)
{
	InsertElement(head,settings, fishtype);						// Insert the new element into the link list �����㵽������
	return 1;
}

// Initiate myfish ��ʼ����ҵ���
int IniMyFish(LinkList &head, Settings &settings, struct Fish_motion &myfish)
{
	CreateLinkList(head);													// Establish a new link list �����µ�����
	settings.label = 0;

	switch (settings.difficulty)
	{
		case 1:InsertElement(head, settings, 8); break;
		case 2:InsertElement(head, settings, 6); break;
		case 3:InsertElement(head, settings, 4); break;
		default:InsertElement(head, settings, 8); break;
	}

	SynchroMyfish(head, myfish);										// Synchronize Myfish ͬ����ҵ���

	return 1;
}

// Generate fish randomly ���������
int RandomGenerateFish(LinkList &head,Settings &settings)
{
	static clock_t last_tick = clock();											// Establish a new static clock_t for saving time break ������̬�����洢ʱ����
	static int interval = 3;

	srand((unsigned)time(NULL));

	if ((clock() - last_tick) >= ((interval * 100 * CLOCKS_PER_SEC / 1000) + VICKY ))
	{
		GenerateFish(head,settings, RandomFishType(),rand()%5 + 1);		// Generate a new random type fish ��������������
		interval = rand() % 14;														// Generate a number between 0 and 14 ����һ����0��14֮��������
		last_tick = clock();															// Record the last time ��¼��һ��ʱ��
	}

	return 1;
}

// Synchronize myfish ������ҿ��Ƶ���
int SynchroMyfish(LinkList &head, struct Fish_motion &myfish)
{
	LinkList temp = head->next;
	myfish = temp->object;
	return 0;
}