#pragma once
#include <easyx.h>
#include <graphics.h>
#define LMARGIN 70
#define Vicky 514

// A struct to save the object motion attributes 存储目标运动属性的结构体
struct Fish_motion
{
	int tag;						// Label 标签
	int magnitude;			// Size of the fish from 0 to 13 等级大小
	int width;					// Width 宽度
	int height;					// Height 高度
	int max_speed_x;	// Horizontal Speed Maximum 水平最大速度
	int max_speed_y;	// Vertical Speed Maximum 垂直最大速度
	int velocity_x;			// Horizontal Speed 水平速度
	int velocity_y;			// Vertical Speed 垂直速度
	int htacceleration;	//  Horizontal Acceleration 水平加速度
	int vtacceleration;		// Vertical Acceleration 垂直加速度
	int x;							// Coordination_x 横坐标(0,1024)
	int y;							// Coordination_y 纵坐标(0,768)
	int htorientation;		// Horizontal Orientation  水平朝向（-1=向左，1=向右）
	int vtorientation;		// Vertical Orientation  垂直朝向（-1=向下，1=向上）
	int nutrition;				//  Nutrition 营养（影响大小）
	bool ifpredator;			// Eat other fish	（0=food，1=predator）是否捕食（0=被捕食者，1=捕食者）
};

// A link list to save the object motion attributes 存储目标运动属性的线性单链表结点
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

// A struct to save the settings 储存设定的结构体
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

// A struct to save the gamers' rank 储存玩家排行的结构体
typedef struct Rank{
	char name[30];
	int point;
	int rank;
}RankList;