#include "Header.h"
#include "DEF.h"

// Background control 背景控制
int IniBkground(Settings &settings)
{
	initgraph(1024, 768);
	DisplayWallpaper();
	SoundEffect(settings, 1);
	ClickHere();
	Input(settings);

	return 1;
}

// Click to enter 点击进入
int ClickHere(void)
{
	wchar_t str[30];
	int i = 0;
	IMAGE img;
	MOUSEMSG m;	

	loadimage(&img, _T("IMAGE_BITMAP"), L"P_BACKGROUND_ENTRY");
	putimage(0, 0, &img);

	while (true)
	{
		while(MouseHit())
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONUP) return 1;
			if (_kbhit()) return 1;
		}

		if (_kbhit()) break;

		wsprintf(str, L"P_BACKGROUND_ENTRY_%d", i);
		loadimage(&img, _T("IMAGE_BITMAP"), str);
		putimage(0, 0, &img);
		++i;
		i %= 6;
		Sleep(80);
	}

	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	return 1;
}

// Input 输入
int Input(Settings &settings)
{
	char input[20] = "\0";
	int i = 0 , j = 0 , ch = 0;
	IMAGE bk;
	IMAGE img;
	LOGFONT font;
	MOUSEMSG m = GetMouseMsg();

	loadimage(&bk, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ENTRY"));
	putimage(0, 0, &bk);

	gettextstyle(&font);
	setbkmode(WHITE);
	settextcolor(BLACK);
	font.lfHeight = 15;
	font.lfWidth = 8;
	_tcscpy_s(font.lfFaceName, _T("黑体"));
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);

	outtextxy(410, 463, L"用户名");
	DisplayButton(8);
	DrawInputBox();
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));

	// Enter data 读入数据
	for (j = 0; j < 20;j++)
	{
		ch = DrawCursor(j);									// Draw shining cursor 画出闪烁的光标

		if (ch == -1)
		{
			loadimage(&img, L"IMAGE_BITMAP", L"P_BACKGROUND_ENTER_MENU_10");
			putimage(412, 500, &img);
			break;
		}
		else if (ch == 8)										// Backspace 实现退格键删除数据的功能 
		{
			if (j >= 1)
			{
				input[j - 1] = 0;
				j -= 2;
				continue;
			}
			else if (j == 0)
			{
				input[j] = 0;
				--j;
				continue;
			}		
		}
		else if (ch == 13)										// Enter 回车结束本次输入 
		{
			loadimage(&img, L"IMAGE_BITMAP", L"P_BACKGROUND_ENTER_MENU_10");
			putimage(412, 500, &img);
			break;
		}
		else if (ch == 27)										// Esc 退出游戏
		{
			--j;
			Quit();
		}	
		else
		{
			input[j] = ch;
			outtextxy(491 + 8 * j, 461, input[j]);
		}
	}

	for (i = 0; i < j; i++)
		settings.name[i] = input[i];

	settings.name[i] = '\0';
		
	return 1;
}

// Draw input box 画出输入窗口
int DrawInputBox()
{
	setfillcolor(WHITE);
	solidrectangle(490, 460, 680, 480);

	setlinecolor(BLACK); setlinestyle(PS_SOLID, 2); 
	line(490, 460, 490, 480); line(490, 460, 680, 460); line(680, 460, 680, 480); line(490, 480, 680, 480);

	return 1;
}

// Draw shining cursor 画出闪烁的光标 
int DrawCursor(int j)
{
	char ch;
	wchar_t str[30] = L"\0";
	int i = 1;
	IMAGE img;
	MOUSEMSG m;

	setlinestyle(PS_SOLID, 2);

	while (true) 
	{
		while (MouseHit())
		{
			m = GetMouseMsg();

			if (442 < m.x && m.x < 592 && 525 < m.y && m.y < 570)
			{
				if (m.uMsg == WM_LBUTTONUP)
				{
					loadimage(&img, _T("IMAGE_BITMAP"), _T("P_BACKGROUND_ENTER_MENU"));
					putimage(412, 500, &img);
					return -1;
				}				
				else
				{
					while (!MouseHit())
					{
						wsprintf(str, L"P_BACKGROUND_ENTER_MENU_%d", i);
						loadimage(&img, _T("IMAGE_BITMAP"), str);
						putimage(412, 500, &img);
						++i;
						Sleep(50);
					}
				}
			}
			else { loadimage(&img, _T("IMAGE_BITMAP"), L"P_BACKGROUND_ENTER_MENU"); putimage(412, 500, &img); }
		}

		if (_kbhit()) { ch = _getch(); setlinecolor(WHITE); line(493 + 8 * j, 463, 493 + 8 * j, 476); return ch; }

		setfillcolor(WHITE); solidrectangle(493 + 8 * j, 463, 678, 476); Sleep(250);
		setlinecolor(BLACK); line(493 + 8 * j, 463, 493 + 8 * j, 476); Sleep(250);
		setlinecolor(WHITE); line(493 + 8 * j, 463, 493 + 8 * j, 476);

		i = 1;
	}

	return 1;
}