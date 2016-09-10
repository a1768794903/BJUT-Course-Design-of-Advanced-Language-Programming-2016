#include "Header.h"
#include "DEF.h"


// Accurate sleep ��ȷ��ʱ
int HpSleep(int ms)
{
	static clock_t oldclock = clock();								// Establish a new static clock_t for saving time break ������̬�����洢ʱ����

	oldclock += ms * CLOCKS_PER_SEC / 1000;		// Transition ת��

	if (clock() > oldclock)												// Out of the specific time break �����ض�ʱ����
		oldclock = clock();
	else
		while (clock() < oldclock)										
			Sleep(1);

	return 1;
}

// Generate coordination y ����������y
int RandCoorY(void)
{
	srand((unsigned)time(NULL));							// Set seed by time ��ʱ��Ϊ���������������
	return (13 * (rand() % 50));
}

// Generate an orientation �����������
int RandOrientation(void)
{
	srand((unsigned)time(NULL));

	int temp = rand() % 2;

	if (temp == 0) return -1;	// Left ��
	else return 1;	// Right ��

	return 1;
}

// Generate the fish type ��������������
int RandomFishType(void)
{
	int temp = 0;

	srand((unsigned)time(NULL));
	temp = rand() % 30;      // Generate a number between 0 and 30 ����һ����0��30֮��������

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

// Time Meter ��ʱ��
int TimeMeter(Settings &settings)
{
	static clock_t oldclock = clock();										// Establish a new static clock_t for saving time break ������̬�����洢ʱ����
	static clock_t interval;

	interval = clock() - oldclock;

	if (interval > 1000 * CLOCKS_PER_SEC / 1000)			// Out of the specific time break �����ض�ʱ����
	{
		oldclock = clock();														// Record last tick ��¼��һ�� tick
		settings.remain_time -= 1;
		settings.total_time += 1;
	}

	return 1;
}

// Convert char into wchar ת�����ַ�Ϊ���ַ�
int CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);

	return 1;
}