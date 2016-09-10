#include "DEF.h"

// Establish an empty link list  构建一个空链表
int CreateLinkList(LinkList &head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	return 1;
}

// Delete the specific node 删除链表中特定结点
int DeleteElement(LinkList &head, int tag)
{
	LinkList temp = head;
	LinkList appoint = NULL;

	while (temp->next && temp->next->object.tag != tag) temp = temp->next;

	if (!(temp->next) || (temp->next->object.tag != tag))
		return -1;

	appoint = temp->next;
	temp->next = appoint->next;
	free(appoint);
	return 1;
}

// Delete the link list 删除链表
int DeleteLinkList(LinkList &head)
{
	LinkList temp = head;
	while (head) { temp = head; head = temp->next; free(temp); }
	return 1;
}

// Insert a node into the link list 插入结点
int InsertElement(LinkList &head,Settings &settings, int fishtype)
{
	LinkList temp = SearchEndNode(head);
	LinkList element = (LNode *)malloc(sizeof(LNode));

	switch (fishtype)
	{
		// Plankton 浮游生物
		case 0: element->object = { settings.label , 0 ,   20 ,   15   , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 }; break;

		// Algae 藻类
		case 1: element->object = { settings.label , 1 ,   20  ,  20   , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 }; break;

		// Shrimp 虾
		case 2: element->object = { settings.label , 2 ,   40 ,  30   , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 }; break;

		// Goldfish 金鱼
		case 3: element->object = { settings.label , 3 ,   72 ,  54   , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16 , 0 }; break;

		// Myfish_hard 困难难度的鱼
		case 4: element->object = { settings.label , 4,    96,   72   , 4 , 4 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Nemofish 尼莫鱼
		case 5: element->object = { settings.label , 5 ,  96  ,  72  , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 32 , 0 }; break;

		// Myfish_normal 中等难度的鱼
		case 6: element->object = { settings.label , 6 , 120 ,  90  , 8 , 8 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Jellyfish 水母
		case 7: element->object = { settings.label , 7 , 120 ,  90 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 64 , 0 }; break;

		// Myfsh_easy 简单难度的鱼
		case 8: element->object = { settings.label , 8 , 144 , 108 , 8 , 8 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Piranha 食人鱼
		case 9: element->object = { settings.label , 9 , 160 , 120 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 86 , 1 }; break;

		// Yellow 黄鱼
		case 10: element->object = { settings.label , 10, 160, 120, 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 128 , 0 }; break;

		// Tropical 热带鱼
		case 11: element->object = { settings.label , 11, 160 ,120, 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 128 , 0 }; break;

		// Shark 鲨鱼
		case 12: element->object = { settings.label , 12, 320,240, 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 256 , 1 };break;

		// Spongebob 海绵宝宝
		case 13: element->object = { settings.label ,13 , 480,360, 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1024 , 0 }; break;
	}

	element->object.htorientation = RandOrientation();

	if (element->object.htorientation == 1)						// Orientation is right 朝向向右
		element->object.x = 0;
	else if (element->object.htorientation == -1)			// Orientation is left 朝向向左
		element->object.x = 1014;

	element->object.velocity_x = element->object.htorientation*element->object.max_speed_x;
	element->object.y = RandCoorY();							// Set the coordination y 设置纵坐标

	element->next = NULL;
	temp->next = element;

	++settings.label;
	return 1;
}

// Search for a specific node 寻找特定结点
LinkList SearchNode(LinkList head, int tag)
{
	LinkList temp = head->next;
	while (temp && temp->object.tag != tag) temp = temp->next;
    return temp;
}

// Search for the end node 寻找末尾结点
LinkList SearchEndNode(LinkList head)
{
	LinkList temp = head;
	while (temp->next) temp = temp->next;
	return temp;
}