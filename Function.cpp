#include "Header.h"
#include "DEF.h"


// Accurate sleep 精确延时
int HpSleep(int ms)
{
	static clock_t oldclock = clock();								// Establish a new static clock_t for saving time break 建立静态变量存储时间间隔

	oldclock += ms * CLOCKS_PER_SEC / 1000;		// Transition 转换

	if (clock() > oldclock)												// Out of the specific time break 超出特定时间间隔
		oldclock = clock();
	else
		while (clock() < oldclock)										
			Sleep(1);

	return 1;
}

// Generate coordination y 生成纵坐标y
int RandCoorY(void)
{
	srand((unsigned)time(NULL));							// Set seed by time 以时间为种子设置随机种子
	return (13 * (rand() % 50));
}

// Generate an orientation 生成随机方向
int RandOrientation(void)
{
	srand((unsigned)time(NULL));

	int temp = rand() % 2;

	if (temp == 0) return -1;	// Left 左
	else return 1;	// Right 右

	return 1;
}

// Generate the fish type 生成随机鱼的类型
int RandomFishType(void)
{
	int temp = 0;

	srand((unsigned)time(NULL));
	temp = rand() % 30;      // Generate a number between 0 and 30 生成一个在0到30之间的随机数

	if (temp < 5) return 0;
	else if (temp < 8) return 1;
	else if (temp < 10) return 2;
	else if (temp < 15) return 3;
	else if (temp < 20) return 5;
	else if (temp < 22) return 7;
	else if (temp < 26) return 9;
	else if (temp < 28) return 10;
	else if (temp < 29) return 11;
	else if (temp < 30) return 12;
	else return 13;
}

// Time Meter 计时器
int TimeMeter(Settings &settings)
{
	static clock_t oldclock = clock();										// Establish a new static clock_t for saving time break 建立静态变量存储时间间隔
	static clock_t interval;

	interval = clock() - oldclock;

	if (interval > 1000 * CLOCKS_PER_SEC / 1000)			// Out of the specific time break 超出特定时间间隔
	{
		oldclock = clock();														// Record last tick 记录上一次 tick
		settings.remain_time -= 1;
		settings.total_time += 1;
	}

	return 1;
}

// Convert char into wchar 转换普字符为宽字符
int CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);

	return 1;
}