#include "DEF.h"

// Sound effect ��Ч
int SoundEffect(Settings settings , int branch)
{
	if (settings.switch_music == 1)
	{
		switch (branch)
		{
			// Play the bubble sound ������������
			case 1: PlaySound(TEXT("res\\music\\m_bubble.wav"), 0, SND_FILENAME); break;
			// Play the click sound ���ŵ������
			case 2: PlaySound(TEXT("res\\music\\m_click.wav"), 0, SND_FILENAME); break;
			// Play applauds sound ���Ż�������
			case 3: mciSendString(_T("close all"), NULL, 0, NULL); mciSendString(_T("open \"res\\music\\m_applauds.mp3\" alias bkmusic"), NULL, 0, NULL); break;
			// Play warning sound ���ž�����
			case 4: PlaySound(TEXT("res\\music\\m_warning.wav"), 0, SND_FILENAME); break;
		}
	}

	return 1;
}

// Start the background music ��ʼ���ű�������
int StartBkMusic(Settings settings, int branch)
{
	if (settings.switch_music == 1)
	{
		switch (branch)
		{
			// Play the background music for the game ������Ϸ��������
			case 1:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music �ر������ļ�
				mciSendString(_T("open \"res\\music\\m_gamebackground.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the gameinterface background music ����Ϸ���汳������
				mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL); // Stop the gameinterface background music   ��ʼѭ��������Ϸ���汳������
				break;
			}
			// Play the background music for the menu ���Ų˵���������
			case 2:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music �ر������ļ�
				mciSendString(_T("open \"res\\music\\m_menubackground.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the menu background music �����˵���������
				mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL); // Stop the menu background music   ��ʼѭ���������˵���������
				break;
			}
			// Play the background music for the stringer ���Ųʵ���������
			case 3:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music �ر������ļ�
				mciSendString(_T("open \"res\\music\\m_stringer.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the menu background music �򿪱�������
				mciSendString(_T("play bkmusic"), NULL, 0, NULL); // Stop the menu background music   ��ʼѭ�����ű�������
				break;
			}
		}
	}

	return 1;
}

// Stop the background music ֹͣ���ű�������
int StopBkMusic(void)
{
	mciSendString(_T("stop bkmusic"), NULL, 0, NULL);  // Stop the gameinterface background music ֹͣ������Ϸ���汳������
	mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music �ر������ļ�
	return 1;
}