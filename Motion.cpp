#include "DEF.h"

// Move �ƶ�
int Move(LinkList &head, struct Settings &settings)
{
	LinkList appoint = head->next->next;

	while (appoint != NULL)
	{
		appoint->object.x += settings.game_speed * appoint->object.velocity_x;			// Add to coordination x �ƶ�x����
		appoint->object.y += settings.game_speed * appoint->object.velocity_y;			// Add to coordination y �ƶ�y����
		DisplayFish(appoint);																							// Display the fishes ��ʾ��
		appoint = appoint->next;
	}

	return 1;
}

// Myfish move up ��ҵ��������ƶ�
int MyFishMoveUp(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 1);						// Limit speed ����
	UpdateOrientation(head->next);				// Update the orientation ���³���
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	return 1;
}

// Myfish move down ��ҵ��������ƶ�
int MyFishMoveDown(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 2);						// Limit speed ����
	UpdateOrientation(head->next);				// Update the orientation ���³���
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	return 1;
}

// Myfish move left ��ҵ��������ƶ�
int MyFishMoveLeft(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 3);						// Limit speed ����
	UpdateOrientation(head->next);				// Update the orientation ���³���
	head->next->object.x += settings.game_speed * head->next->object.velocity_x;

	return 1;
}

// Myfish move right ��ҵ��������ƶ�
int MyFishMoveRight(LinkList &head, struct Settings &settings)
{
	LimitSpeed(head->next, 4);						// Limit speed ����
	UpdateOrientation(head->next);				// Update the orientation ���³���
	head->next->object.x += settings.game_speed * head->next->object.velocity_x;

	return 1;
}

// Myfish stay ��ҵ���ֹͣ
int MyFishStay(LinkList &head, Settings &settings)
{
	LimitSpeed(head->next, 0);						// Limit speed ����

	head->next->object.x += settings.game_speed * head->next->object.velocity_x;
	head->next->object.y += settings.game_speed * head->next->object.velocity_y;

	if (head->next->object.velocity_x == 0 && head->next->object.velocity_y == 0)
		Fluctuate(head->next);

	return 1;
}

// Limit speed ����
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

// Update the orientation ���³���
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

// Set random orientation �����������
int SetOrientation(LinkList &appoint, int orientation)
{
	switch (orientation)
	{
	case 0: // Static or slow down ��̬������ٶ�
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = 0;
		break;
	case 1: // GoUp ����
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = -1;
		break;
	case 2: // GoDown ����
		appoint->object.htorientation = 0;
		appoint->object.vtorientation = 1;
		break;
	case 3: // Go Left ����
		appoint->object.htorientation = -1;
		appoint->object.vtorientation = 0;
		break;
	case 4: // Go Right ����
		appoint->object.htorientation = 1;
		appoint->object.vtorientation = 0;
		break;
	}
	return 1;
}

// Set the motion attributes of fish ��������˶�����
int SetFishMotion(LinkList &element, int htorientation)
{
	element->object.htorientation = htorientation;			// Set random orientation ����������ɵĳ���
	return 1;
}

// Fluctuate ��������
int Fluctuate(LinkList &appoint)
{
	return 1;
}