#include "DEF.h"

// Move 移动
int Move(LinkList &head, struct Settings &settings)
{
	LinkList appoint = head->next->next;

	while (appoint != NULL)
	{
		appoint->object.x += settings.game_speed * appoint->object.velocity_x;			// Add to coordination x 移动x坐标
		appoint->object.y += settings.game_speed * appoint->object.velocity_y;			// Add to coordination y 移动y坐标
		DisplayFish(appoint);																							// Display the fishes 显示鱼
		appoint = appoint->next;
	}

	return 1;
}

// Myfish move up 玩家的鱼向上移动
int MyFishMoveUp(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 1);						// Limit speed 限速
	UpdateOrientation(head->next);				// Update the orientation 更新朝向
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	return 1;
}

// Myfish move down 玩家的鱼向下移动
int MyFishMoveDown(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 2);						// Limit speed 限速
	UpdateOrientation(head->next);				// Update the orientation 更新朝向
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	return 1;
}

// Myfish move left 玩家的鱼向左移动
int MyFishMoveLeft(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 3);						// Limit speed 限速
	UpdateOrientation(head->next);				// Update the orientation 更新朝向
	head->next->object.x += settings.game_speed * head->next->object.velocity_x;

	return 1;
}

// Myfish move right 玩家的鱼向右移动
int MyFishMoveRight(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 4);						// Limit speed 限速
	UpdateOrientation(head->next);				// Update the orientation 更新朝向
	head->next->object.x += settings.game_speed * head->next->object.velocity_x;

	return 1;
}

// Myfish stay 玩家的鱼停止
int MyFishStay(LinkList &head, Settings &settings)
{
	LimitSpeed(head->next, 0);						// Limit speed 限速

	head->next->object.x += settings.game_speed * head->next->object.velocity_x;
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	if (head->next->object.velocity_x == 0 && head->next->object.velocity_y == 0)
		Fluctuate(head->next);

	return 1;
}

// Limit speed 限速
int LimitSpeed(LinkList &appoint,int branch)
{
	switch (branch)
	{
		case 1:
			if (appoint->object.velocity_y > -appoint->object.max_speed_y)
				appoint->object.velocity_y -= appoint->object.vtacceleration;
			break;
		case 2:
			if (appoint->object.velocity_y < appoint->object.max_speed_y)
				appoint->object.velocity_y += appoint->object.vtacceleration;
			break;
		case 3:
			if (appoint->object.velocity_x > -appoint->object.max_speed_x)
				appoint->object.velocity_x -= appoint->object.htacceleration;
			break;
		case 4:
			if (appoint->object.velocity_x < appoint->object.max_speed_x)
				appoint->object.velocity_x += appoint->object.htacceleration;
			break;
		case 0:
			if (appoint->object.velocity_x > 0)
				appoint->object.velocity_x -= appoint->object.htacceleration;
			else if (appoint->object.velocity_x < 0)
				appoint->object.velocity_x += appoint->object.htacceleration;

			if (appoint->object.velocity_y > 0)
				appoint->object.velocity_y -= appoint->object.vtacceleration;
			else if (appoint->object.velocity_y < 0)
				appoint->object.velocity_y += appoint->object.vtacceleration;
			break;
	}

	return 1;
}

// Update the orientation 更新朝向
int UpdateOrientation(LinkList &appoint)
{
	if (appoint->object.velocity_x > 0)
		appoint->object.htorientation = 1;
	else if (appoint->object.velocity_x < 0)
		appoint->object.htorientation = -1;
	else
		appoint->object.htorientation = 0;

	if (appoint->object.velocity_y > 0)
		appoint->object.vtorientation = 1;
	else if (appoint->object.velocity_y < 0)
		appoint->object.vtorientation = -1;
	else
		appoint->object.vtorientation = 0;

	return 1;
}

// Set random orientation 设置随机朝向
int SetOrientation(LinkList &appoint, int orientation)
{
	switch (orientation)
	{
	case 0: // Static or slow down 静态或减慢速度
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = 0;
		break;
	case 1: // GoUp 向上
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = -1;
		break;
	case 2: // GoDown 向下
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = 1;
		break;
	case 3: // Go Left 向左
		appoint->object.htorientation = -1;
		appoint->object.vtorientation = 0;
		break;
	case 4: // Go Right 向右
		appoint->object.htorientation = 1;
		appoint->object.vtorientation = 0;
		break;
	}
	return 1;
}

// Set the motion attributes of fish 设置鱼的运动属性
int SetFishMotion(LinkList &element, int htorientation)
{
	element->object.htorientation = htorientation;			// Set random orientation 接受随机生成的朝向
	return 1;
}

// Fluctuate 波动函数
int Fluctuate(LinkList &appoint)
{
	return 1;
}