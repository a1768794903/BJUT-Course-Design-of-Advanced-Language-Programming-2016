#include "Header.h"
#include "DEF.h"

// Initiate a ranking list 初始化排行榜
int InitRankingList(RankList *list)
{
	int i = 0;

	for (i = 0; i < 50; i++)
	{
		list[i].name[0] ='\0';
		list[i].point = 0;
		list[i].rank = i + 1;
	}	

	strcpy(list[0].name, "RichardBrook");
	list[0].point = 0;
	list[0].rank = 1;

	return 1;
}

// Insert a ranking list element 插入排行榜元素
int InsertRankingListNode(RankList *list,char name[], int point )
{
	int i = 0 , j = 49 , k = 0;

	while (i < 49 && list[i].point > point)
		++i;

	for (j = 49; j > i; j--)
	{
		list[j] = list[j - 1];

		if(list[j].rank != 0)
			list[j].rank += 1;
	}

	strcpy(list[i].name, name);
	list[i].point = point;

	return list[i].rank;
}

// Save a ranking list from files 向文件中存储排行榜
int SaveRankingList(RankList *list)
{
	FILE *fp;
	int i = 0;

	if ((fp = fopen("save\\RankingList.txt", "w")) == NULL)
	{
		printf("Error when saving the ranking list\n");
		return -1;
	}

	for (i = 0; i < 50; i++)
	{
		fwrite(list[i].name, sizeof(char), 30, fp);
		fwrite(&list[i].point, sizeof(int), 1, fp);
		fwrite(&list[i].rank, sizeof(int), 1, fp);
	}

	fclose(fp);

	return 1;
}

// Load a ranking list from files 从文件中读取排行榜
int LoadRankingList(RankList *list)
{
	FILE *fp;
	int i = 0;

	if ((fp = fopen("save\\RankingList.txt", "r")) == NULL)
	{
		printf("Error when loading the ranking list\n");
		return -1;
	}

	for (i = 0; i < 50;i++)
	{
		fread(list[i].name, sizeof(char), 30, fp);
		fread(&list[i].point, sizeof(int), 1, fp);
		fread(&list[i].rank, sizeof(int), 1, fp);
	}
	
	fclose(fp);

	return 1;
}