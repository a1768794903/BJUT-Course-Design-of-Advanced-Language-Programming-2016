#pragma once
#include "Header.h"
#include "DEF.h"

// Match the user with the record ∆•≈‰“—”–¥ÊµµÕÊº“
int MatchUser(struct Settings &settings)
{
	char name[80];
	FILE *fp;
	struct Fish_motion myfish = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 1 };

	if ((fp = fopen("save\\UserList.txt", "r")) == NULL)
	{
		printf("Error when openning the list of users\n");
		return -1;
	}

	while (!feof(fp))
	{
		fread(name, sizeof(char), 30, fp);

		if (strcmp(name, settings.name) == 0)
		{
			LoadRecord(settings, myfish);
			settings.record_mode = 1;
			return 1;
		}
	}

	fclose(fp);

	SaveRecord(settings, myfish);
	settings.record_mode = 0;

	return 0;
}

// Load the record ∂¡»°¥Êµµ
int LoadRecord(struct Settings &settings, struct Fish_motion &myfish)
{
	char name[50];
	FILE *fp;

	sprintf(name, "save\\%s.txt", settings.name);

	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Error when loading the record\n");
		return -1;
    }

	fread(&settings, sizeof(struct Settings), 1, fp);
	fread(&myfish, sizeof(struct Fish_motion), 1, fp);

	fclose(fp);
	return settings.difficulty;
}

// Save the record ¥Ê¥¢¥Êµµ
int SaveRecord(struct Settings &settings, struct Fish_motion myfish)
{
	char name[80];
	FILE *fp;

	if ((fp = fopen("save\\UserList.txt", "a")) == NULL)
	{
		printf("Error when openning the list of users\n");
		return -1;
	}

	fwrite(&settings.name, sizeof(char), 30, fp);
	fclose(fp);
	sprintf(name, "save\\%s.txt", settings.name);
	InitSetting(settings, 3);
	settings.record_mode = 1;

	if ((fp = fopen(name, "w")) == NULL)
	{
		printf("Error when saving the record\n");
		return -1;
	}

	fwrite(&settings, sizeof(struct Settings), 1, fp);
	fwrite(&myfish, sizeof(struct Fish_motion), 1, fp);

	fclose(fp);
	return 1;
}