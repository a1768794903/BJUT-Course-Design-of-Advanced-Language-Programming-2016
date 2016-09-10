#pragma once
#include <easyx.h>
#include <graphics.h>
#define LMARGIN 70
#define Vicky 514

// A struct to save the object motion attributes �洢Ŀ���˶����ԵĽṹ��
struct Fish_motion
{
	int tag;						// Label ��ǩ
	int magnitude;			// Size of the fish from 0 to 13 �ȼ���С
	int width;					// Width ���
	int height;					// Height �߶�
	int max_speed_x;	// Horizontal Speed Maximum ˮƽ����ٶ�
	int max_speed_y;	// Vertical Speed Maximum ��ֱ����ٶ�
	int velocity_x;			// Horizontal Speed ˮƽ�ٶ�
	int velocity_y;			// Vertical Speed ��ֱ�ٶ�
	int htacceleration;	//  Horizontal Acceleration ˮƽ���ٶ�
	int vtacceleration;		// Vertical Acceleration ��ֱ���ٶ�
	int x;							// Coordination_x ������(0,1024)
	int y;							// Coordination_y ������(0,768)
	int htorientation;		// Horizontal Orientation  ˮƽ����-1=����1=���ң�
	int vtorientation;		// Vertical Orientation  ��ֱ����-1=���£�1=���ϣ�
	int nutrition;				//  Nutrition Ӫ����Ӱ���С��
	bool ifpredator;			// Eat other fish	��0=food��1=predator���Ƿ�ʳ��0=����ʳ�ߣ�1=��ʳ�ߣ�
};

// A link list to save the object motion attributes �洢Ŀ���˶����Ե����Ե�������
typedef struct Object
{
	Fish_motion object;
	Object *next;
}LNode, *LinkList;

// A struct to record the accomplishment
struct Achievements
{
	int fish_is_fish;
	int gourmet;
	int killerss;
	int master_of_collision;
};

// A struct to save the settings �����趨�Ľṹ��
struct Settings
{
	char name[30];
	int difficulty;
	int total_time;
	int remain_time;
	int point;
	int hp;
	int game_speed;
	int game_options;
	int menu_options;
	int record_mode;
	int switch_mouse;
	int switch_music;
	int label;
	int rank;
	int screenshots_num;
	struct Achievements achievements;
};

// A struct to save the gamers' rank ����������еĽṹ��
typedef struct Rank{
	char name[30];
	int point;
	int rank;
}RankList;