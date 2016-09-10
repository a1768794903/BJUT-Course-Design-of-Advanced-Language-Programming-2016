#include "DEF.h"

// Sound effect 音效
int SoundEffect(Settings settings , int branch)
{
	if (settings.switch_music == 1)
	{
		switch (branch)
		{
			// Play the bubble sound 播放气泡声音
			case 1: PlaySound(TEXT("res\\music\\m_bubble.wav"), 0, SND_FILENAME); break;
			// Play the click sound 播放点击声音
			case 2: PlaySound(TEXT("res\\music\\m_click.wav"), 0, SND_FILENAME); break;
			// Play applauds sound 播放欢呼声音
			case 3: mciSendString(_T("close all"), NULL, 0, NULL); mciSendString(_T("open \"res\\music\\m_applauds.mp3\" alias bkmusic"), NULL, 0, NULL); break;
			// Play warning sound 播放警报声
			case 4: PlaySound(TEXT("res\\music\\m_warning.wav"), 0, SND_FILENAME); break;
		}
	}

	return 1;
}

// Start the background music 开始播放背景音乐
int StartBkMusic(Settings settings, int branch)
{
	if (settings.switch_music == 1)
	{
		switch (branch)
		{
			// Play the background music for the game 播放游戏背景音乐
			case 1:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music 关闭音乐文件
				mciSendString(_T("open \"res\\music\\m_gamebackground.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the gameinterface background music 打开游戏界面背景音乐
				mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL); // Stop the gameinterface background music   开始循环播放游戏界面背景音乐
				break;
			}
			// Play the background music for the menu 播放菜单背景音乐
			case 2:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music 关闭音乐文件
				mciSendString(_T("open \"res\\music\\m_menubackground.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the menu background music 打开主菜单背景音乐
				mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL); // Stop the menu background music   开始循环播放主菜单背景音乐
				break;
			}
			// Play the background music for the stringer 播放彩蛋背景音乐
			case 3:
			{
				mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music 关闭音乐文件
				mciSendString(_T("open \"res\\music\\m_stringer.mp3\" alias bkmusic"), NULL, 0, NULL); // Open the menu background music 打开背景音乐
				mciSendString(_T("play bkmusic"), NULL, 0, NULL); // Stop the menu background music   开始循环播放背景音乐
				break;
			}
		}
	}

	return 1;
}

// Stop the background music 停止播放背景音乐
int StopBkMusic(void)
{
	mciSendString(_T("stop bkmusic"), NULL, 0, NULL);  // Stop the gameinterface background music 停止播放游戏界面背景音乐
	mciSendString(_T("close all"), NULL, 0, NULL);          // Close the music 关闭音乐文件
	return 1;
}