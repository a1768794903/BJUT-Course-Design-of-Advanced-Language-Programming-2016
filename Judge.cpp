#pragma once
#include "DEF.h"
#include "Header.h"

// Calculate the speed after bounce ����������ٶ�
int IfBounce(LinkList &object1, LinkList &object2)
{
	int v1 = object1->object.velocity_x;
	int v2 = object2->object.velocity_x;
	int m1 = object1->object.magnitude;
	int m2 = object2->object.magnitude;

	// v1'=((m1-m2)v1+2m2v2)/(m1+m2)
	// v2'=((m2-m1)v2+2m1v1)/(m1+m2)

	object1->object.x -= (2 * object1->object.htorientation * (object1->object.max_speed_x + 1));
	object1->object.velocity_x = v2;
	object1->object.htorientation *= -1;

	object2->object.x -= (2 * object2->object.htorientation * (object2->object.max_speed_x + 1));
	object2->object.velocity_x = v1;
	object2->object.htorientation *= -1;


	return 1;
}

// Judge whether two fishes meet �ж��������Ƿ�����
int IfMeet(LinkList &head, struct Settings &settings)
{
	LinkList appoint = head->next;

	for (LinkList temp = head->next; temp != NULL && temp->next != NULL; )
	{
		int distance_x = appoint->object.x - temp->object.x;
		int distance_y = appoint->object.y - temp->object.y;

		if (appoint->object.tag != temp->object.tag)
		{
			if ((distance_x > 0 && distance_x <= temp->object.width) || (distance_x < 0 && distance_x >= -appoint->object.width))
			{
				if ((distance_y > 0 && distance_y <= temp->object.height) || (distance_y < 0 && distance_y >= -appoint->object.height))
				{
					if (appoint->object.tag == 0)
						settings.achievements.master_of_collision += 1;

					LinkList p = IfEat(head, appoint, temp, settings);

					if (p != NULL)				// Judge whether catch and eat �ж��Ƿ�ʳ
					{
						temp = p;
						continue;
					}
					else
						break;
				}
			}
		}

		temp = temp->next;
	}

	return 1;
}

// Judge whether if out �ж��Ƿ����
int IfOut(LinkList &head)
{
	LinkList appoint = head->next;

	while (appoint != NULL)
	{
		if (appoint->object.tag > 0)					 // Current is other fishes ��ǰ�ж�����������
		{
			if (appoint->object.x <= 0 || appoint->object.x >= 1024 || appoint->object.y <= 0 || appoint->object.y >= 650) // Out of Boundary ����
			{
				LinkList temp = appoint->next;

				DeleteElement(head, appoint->object.tag);	// Delete the out element ɾ������Ľ��

				appoint = temp;
				continue;
			}
		}
		else if (appoint->object.tag == 0)			// Current is myfish ��ǰ�ж��ĵ�����ҵ���
		{
			// Shift down when close to top or bottom boundary �����������±߽�ʱ����
			if (appoint->object.y < 20 && appoint->object.velocity_y < appoint->object.max_speed_y)
				appoint->object.velocity_y += 1;
			else if (appoint->object.y > 630 && appoint->object.velocity_y > -appoint->object.max_speed_y)
				appoint->object.velocity_y -= 1;

			// Shift down when almost close to top or bottom boundary �������±߽�ʱ����
			if (appoint->object.y < 10 && appoint->object.velocity_y < appoint->object.max_speed_y)
				appoint->object.velocity_y += 1;
			else if (appoint->object.y > 640 && appoint->object.velocity_y > -appoint->object.max_speed_y)
				appoint->object.velocity_y -= 1;

			// Stop when at the top or bottom bound �����±߽紦ֹͣ
			if (appoint->object.y < 4)
				appoint->object.vtorientation = 1;
			else if(appoint->object.y > 646)
				appoint->object.vtorientation = -1;

			// Shift down when close to left or right boundary �����������ұ߽�ʱ����
			if (appoint->object.x < 20 && appoint->object.velocity_x < appoint->object.max_speed_x)
				appoint->object.velocity_x += 1;
			else if (appoint->object.x > 1004 && appoint->object.velocity_x > -appoint->object.max_speed_x)
				appoint->object.velocity_x -= 1;

			// Shift down when almost close to top or bottom boundary �������ұ߽�ʱ����
			if (appoint->object.x < 10 && appoint->object.velocity_x < appoint->object.max_speed_x)
				appoint->object.velocity_x += 1;
			else if (appoint->object.x > 1014 && appoint->object.velocity_x > -appoint->object.max_speed_x)
				appoint->object.velocity_x -= 1;

			// Stop when at the left or right bound �����ұ߽紦ֹͣ
			if (appoint->object.x < 4)
				appoint->object.htorientation = 1;		// Stop when at the top or bottom bound �����±߽紦ֹͣ
			else if (appoint->object.x > 1020)
				appoint->object.htorientation = -1;
		}

		appoint = appoint->next;
	}

	return 0;
}

// Judge if the controler win the game �ж�����Ƿ��ʤ
int IfWin(LinkList &head, struct Settings &settings, struct Fish_motion &myfish)
{
	if (head->next == NULL || head->next->object.tag != 0 || settings.hp <= 0)
		GameOver(head, settings, myfish);

	if (settings.remain_time <= 0)
	{
		if (settings.difficulty == 1 && settings.point > 180) return 1;
		else if (settings.difficulty == 2 && settings.point > 210) return 1;
		else if (settings.difficulty == 3 && settings.point > 240) return 1;

		if (settings.point <= 150 + 30 * settings.difficulty) GameOver(head, settings, myfish);
	}

	return 0;
}

// Judge if level up �ж��Ƿ����� 
int IfLevelUp(LinkList &head)
{
	LinkList temp = head->next;
	static int i = 1;

	if (temp->object.nutrition >= i * VICKY) { ++i; if (temp->object.magnitude < 12) { temp->object.magnitude += 2; temp->object.width += 24; temp->object.height += 18; }	 }
		
	return 1;
}

// Judge whether catch and eat �ж��Ƿ�ʳ
LinkList IfEat(LinkList &head, LinkList &host, LinkList &prey, Settings &settings)
{
	LinkList temp = prey->next;

	if (host->object.ifpredator == 1 && host->object.magnitude > prey->object.magnitude)
	{  
		if (host->object.tag == 0) { settings.achievements.killerss += 1; settings.point += 3 * prey->object.magnitude;	 }

		host->object.nutrition += prey->object.nutrition;		// Increase nutrition value ����Ӫ��ֵ
		DeleteElement(head, prey->object.tag);					// Delete the preyed fish ɾ������ʳ��Ľ��

		return temp;
	}
	else if (prey->object.ifpredator == 1 && host->object.magnitude < prey->object.magnitude)
	{
		if (host->object.tag == 0)
		{
			settings.hp -= settings.difficulty * prey->object.magnitude;
			settings.point -= 2 * host->object.magnitude;

			if (prey->object.magnitude == 12 && settings.hp <= 66) settings.hp = 0;

			DeleteElement(head, prey->object.tag);				// Delete the fish ɾ������ʳ��Ľ��			

			if (settings.hp <= 0) return NULL;
			else return temp;
		}

		prey->object.nutrition += host->object.nutrition;		// Increase nutrition value ����Ӫ��ֵ
		DeleteElement(head, prey->object.tag);					// Delete the preyed fish ɾ������ʳ��Ľ��

		return temp;
	}

	return prey->next;
}