#include "DEF.h"

// Establish an empty link list  ����һ��������
int CreateLinkList(LinkList &head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	return 1;
}

// Delete the specific node ɾ���������ض����
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

// Delete the link list ɾ������
int DeleteLinkList(LinkList &head)
{
	LinkList temp = head;
	while (head) { temp = head; head = temp->next; free(temp); }
	return 1;
}

// Insert a node into the link list ������
int InsertElement(LinkList &head,Settings &settings, int fishtype)
{
	LinkList temp = SearchEndNode(head);
	LinkList element = (LNode *)malloc(sizeof(LNode));

	switch (fishtype)
	{
		// Plankton ��������
		case 0: element->object = { settings.label , 0 ,   20 ,   15   , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 2 , 0 }; break;

		// Algae ����
		case 1: element->object = { settings.label , 1 ,   20  ,  20   , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 4 , 0 }; break;

		// Shrimp Ϻ
		case 2: element->object = { settings.label , 2 ,   40 ,  30   , 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 0 }; break;

		// Goldfish ����
		case 3: element->object = { settings.label , 3 ,   72 ,  54   , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 16 , 0 }; break;

		// Myfish_hard �����Ѷȵ���
		case 4: element->object = { settings.label , 4,    96,   72   , 4 , 4 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Nemofish ��Ī��
		case 5: element->object = { settings.label , 5 ,  96  ,  72  , 3 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 32 , 0 }; break;

		// Myfish_normal �е��Ѷȵ���
		case 6: element->object = { settings.label , 6 , 120 ,  90  , 8 , 8 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Jellyfish ˮĸ
		case 7: element->object = { settings.label , 7 , 120 ,  90 , 4 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 64 , 0 }; break;

		// Myfsh_easy ���Ѷȵ���
		case 8: element->object = { settings.label , 8 , 144 , 108 , 8 , 8 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 0 , 0 , 1 }; break;

		// Piranha ʳ����
		case 9: element->object = { settings.label , 9 , 160 , 120 , 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 86 , 1 }; break;

		// Yellow ����
		case 10: element->object = { settings.label , 10, 160, 120, 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 128 , 0 }; break;

		// Tropical �ȴ���
		case 11: element->object = { settings.label , 11, 160 ,120, 6 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 128 , 0 }; break;

		// Shark ����
		case 12: element->object = { settings.label , 12, 320,240, 8 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 256 , 1 };break;

		// Spongebob ���౦��
		case 13: element->object = { settings.label ,13 , 480,360, 2 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1024 , 0 }; break;
	}

	element->object.htorientation = RandOrientation();

	if (element->object.htorientation == 1)						// Orientation is right ��������
		element->object.x = 0;
	else if (element->object.htorientation == -1)			// Orientation is left ��������
		element->object.x = 1014;

	element->object.velocity_x = element->object.htorientation*element->object.max_speed_x;
	element->object.y = RandCoorY();							// Set the coordination y ����������

	element->next = NULL;
	temp->next = element;

	++settings.label;
	return 1;
}

// Search for a specific node Ѱ���ض����
LinkList SearchNode(LinkList head, int tag)
{
	LinkList temp = head->next;
	while (temp && temp->object.tag != tag) temp = temp->next;
    return temp;
}

// Search for the end node Ѱ��ĩβ���
LinkList SearchEndNode(LinkList head)
{
	LinkList temp = head;
	while (temp->next) temp = temp->next;
	return temp;
}