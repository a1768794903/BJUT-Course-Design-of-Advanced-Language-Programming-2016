#include "Header.h"
#include "DEF.h"

// Generate a fish 生成鱼
int GenerateFish(LinkList &head, Settings &settings,int fishtype,int fishnumber)
{
	InsertElement(head,settings, fishtype);						// Insert the new element into the link list 插入结点到链表中
	return 1;
}

// Initiate myfish 初始化玩家的鱼
int IniMyFish(LinkList &head, Settings &settings, struct Fish_motion &myfish)
{
	CreateLinkList(head);													// Establish a new link list 构建新的链表
	settings.label = 0;

	switch (settings.difficulty)
	{
		case 1:InsertElement(head, settings, 8); break;
		case 2:InsertElement(head, settings, 6); break;
		case 3:InsertElement(head, settings, 4); break;
		default:InsertElement(head, settings, 8); break;
	}

	SynchroMyfish(head, myfish);										// Synchronize Myfish 同步玩家的鱼

	return 1;
}

// Generate fish randomly 随机生成鱼
int RandomGenerateFish(LinkList &head,Settings &settings)
{
	static clock_t last_tick = clock();											// Establish a new static clock_t for saving time break 建立静态变量存储时间间隔
	static int interval = 3;

	srand((unsigned)time(NULL));

	if ((clock() - last_tick) >= ((interval * 100 * CLOCKS_PER_SEC / 1000) + VICKY ))
	{
		GenerateFish(head,settings, RandomFishType(),rand()%5 + 1);		// Generate a new random type fish 生成随机种类的鱼
		interval = rand() % 14;														// Generate a number between 0 and 14 生成一个在0到14之间的随机数
		last_tick = clock();															// Record the last time 记录上一次时间
	}

	return 1;
}

// Synchronize myfish 更新玩家控制的鱼
int SynchroMyfish(LinkList &head, struct Fish_motion &myfish)
{
	LinkList temp = head->next;
	myfish = temp->object;
	return 0;
}