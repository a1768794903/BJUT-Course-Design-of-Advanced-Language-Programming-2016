#pragma once 
#include "DEF.h"
#include "Header.h"

// Delete picture form the album 从相册中删除图片
int DeletePicture(int tag)
{
	char c_picture_name[50];

	sprintf(c_picture_name, "under_the_sea_screen_shot_%d.jpg", tag);
	remove(c_picture_name);
	return 1;
}

// Load pictures into album 读取图片进入相册
int LoadAlbum(IMAGE *album)
{
	wchar_t c_pic[50];

	for (int i = 0; i < 10; i++)
	{
		album[i] = NULL;
		wsprintf(c_pic, L"screenshots\\under_the_sea_screen_shot_%d.jpg", i);
		loadimage(&album[i], c_pic);
	}

	return 1;
}