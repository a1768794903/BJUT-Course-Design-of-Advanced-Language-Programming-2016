#pragma once
#include "Command.h"
#include "Definition.h"

// DEF_Album
int DeletePicture(int tag);																														// Delete picture form the album 从相册中删除图片			
int LoadAlbum(IMAGE *album);																											// Load pictures into album 读取图片进入相册

// DEF_Console
int DispatchCmd(int _cmd, LinkList head, struct Settings &settings, struct Fish_motion &myfish);	// Dispatch command order 分发控制命令																																								
int GetCommand(Settings settings, struct Fish_motion &myfish);														// Get command 获取指令			
int Quit(void);																																		// Quit the game 退出游戏

// DEF_Entry
int IniBkground(Settings &settings);																									// Background control 背景控制
int ClickHere(void);																																// Click to enter 点击进入
int Input(Settings &settings);																												// Input 输入
int DrawInputBox(void);																														// Draw input box 画出输入窗口
int DrawCursor(int j);																															// Draw shining cursor 画出闪烁的光标 

// DEF_Extras	
int LoadMouseCursor(int mouse_type);																								// Load Mouse Cursor 读取鼠标光标
int Stringer(Settings settings);																												// Stringer 彩蛋			
int Goldfinger(LinkList &head, Settings &settings);																				// Goldfinger cheat 金手指作弊器
int Triumph(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);							// Triumph 胜利成果
int InitSetting(struct Settings &settings, int branch);																			// Initiate the setting 初始化设置
int SetOptionsMode(Settings &settings, int game_speed, int game_options, int menu_options);		// Set game options mode 设置游戏选项模式

// DEF_Fish
int GenerateFish(LinkList &head, Settings &settings, int fishtype, int fishnumber);							// Generate a fish 生成鱼
int IniMyFish(LinkList &head, Settings &settings, struct Fish_motion &myfish);									// Initiate myfish 初始化玩家的鱼																				
int RandomGenerateFish(LinkList &head, Settings &settings);															// Generate fish 随机生成鱼
int SynchroMyfish(LinkList &head, struct Fish_motion &myfish);														// Synchronize my fish 更新玩家控制的鱼

// DEF_Function
int HpSleep(int ms);			        																											// Accurate sleep 精确延时			
int RandCoorY(void);																															// Generate coordination y 生成纵坐标y
int RandOrientation(void);																													// Generate an orientation 生成随机方向									
int RandomFishType(void);																													// Generate the fish type 生成随机鱼的类型									
int TimeMeter(Settings &settings);																										// Time Meter 计时器														
int CharToTchar(const char * _char, TCHAR * tchar);																			// Convert char into wchar 转换普字符为宽字符

// DEF_Game
int Difficulty(int difficulty, struct Fish_motion &myfish);																		// Difficulty choice 难度选择
int Game(struct Settings &settings, struct Fish_motion &myfish);														// Game interface 游戏界面
int GameOver(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);						// Game over 游戏结束

// DEF_Graphics
int DisplayFish(LinkList appoint);																											// Display all the fishes 显示所有的鱼																						
int DisplayMyFish(LinkList head);																										// Display my fish 显示玩家控制的鱼
int DisplayBackground(int branch);								    																	// Display the background 显示背景																					
int DisplayButton(int button_number);																									// Display the buttons 显示按钮													
int DisplayFrame(int frame, Settings settings);																					// Display frame 显示框
int DisplayGameInterface(int game_speed, int branch);																		// Display game interface 显示游戏界面																
int DisplayOptions(Settings settings);																									// Display options 显示选项菜单
int DisplayOptionsMenu(Settings settings);																							// Display options menu 显示选项菜单																	
int DisplayRankingList(RankList *list);																									// Display ranking list 显示排行榜
int DisplaySetting(void);																														// Display setting 显示设置										
int DisplayTriumph(Settings settings, struct Fish_motion myfish);														// Display the triumph interface 显示胜利界面																											
int DisplayWallpaper(void);																													// Display wallpaper 显示壁纸
int DisplayWorkSpace(Settings &settings);																							// Display the work space 显示工作区（时间）
int OuttextScript(int branch);																												// Display the scripts for menu interface 显示界面文本
int OuttextChoice(int mode, int choice);																								// Display the scripts for the choice 显示选项文本										
int OuttextDifficulty(int difficulty);																											// Display the scripts for the difficulty choice 显示难度选项文本																											
int PrintScreenShot();																															// Print the screenshot 打印截屏
int ScreenShot(int mode, Settings &settings);																						// Get the screenshot 获取截屏

// DEF_Judge
int IfBounce(LinkList &object1, LinkList &object2);																				// Calculate the speed after bounce 计算对碰后速度
int IfMeet(LinkList &head, struct Settings &settings);																			// Judge whether two fishes meet 判断两条鱼是否相遇
int IfOut(LinkList &head);																														// Judge whether if out 判断是否出界
int IfWin(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);								// Judge if the controler win the game 判定玩家是否获胜											
int IfLevelUp(LinkList &head);																												// Judge if level up 判定是否升级 
LinkList IfEat(LinkList &head, LinkList &host, LinkList &prey, struct Settings &settings);					// Judge whether catch and eat 判断是否捕食

// DEF_Menu
int Category(struct Settings &settings, struct Fish_motion &myfish);													// Category directory 分类（难度）目录		
int Menu(Settings &settings);																												// Menu 主菜单

// DEF_Motion
int Move(LinkList &head, struct Settings &settings);																			// Move 移动																										
int MyFishMoveUp(LinkList &head, struct Settings &settings);															// Myfish move up 玩家的鱼向上移动																							
int MyFishMoveDown(LinkList &head, struct Settings &settings);														// Myfish move down 玩家的鱼向下移动
int MyFishMoveLeft(LinkList &head, struct Settings &settings);															// Myfish move left 玩家的鱼向左移动																													
int MyFishMoveRight(LinkList &head, struct Settings &settings);														// Myfish move right 玩家的鱼向右移动																					
int MyFishStay(LinkList &head, Settings &settings);																			// Myfish stay 玩家的鱼停止																						
int LimitSpeed(LinkList &appoint, int branch);																						// Limit speed 限速																
int UpdateOrientation(LinkList &appoint);																							// Update the orientation 更新朝向
int SetOrientation(LinkList &appoint, int orientation);																			// Set random orientation 设置随机朝向
int SetFishMotion(LinkList &element, int htorientation);																		// Set the motion attributes of fish 设置鱼的运动属性
int Fluctuate(LinkList &appoint);																											// Fluctuate 波动函数\

// DEF_Music
int SoundEffect(Settings settings, int branch);																						// Sound effect 音效
int StartBkMusic(Settings settings, int branch);																					// Start the background music 开始播放背景音乐
int StopBkMusic(void);																															// Stop the background music 停止播放背景音乐

// DEF_Object
int CreateLinkList(LinkList &head);																										// Establish an empty link list  构建一个空链表
int DeleteElement(LinkList &head, int tag);																							// Delete the specific node 删除链表中特定结点
int DeleteLinkList(LinkList &head);																										// Delete the link list 删除链表								
int InsertElement(LinkList &head, Settings &settings, int fishtype);														// Insert a node into the link list 插入结点（头插法）						
LinkList SearchNode(LinkList head, int tag);																						// Search for a specific node 寻找特定结点
LinkList SearchEndNode(LinkList head);																							// Search for the end node 寻找末尾结点		

// DEF_RankingList
int InitRankingList(RankList *list);																										// Initiate a ranking list 初始化排行榜
int InsertRankingListNode(RankList *list, char name[], int point);														// Insert a ranking list element 插入排行榜元素													
int SaveRankingList(RankList *list);																										// Save a ranking list from files 向文件中存储排行榜
int LoadRankingList(RankList *list);																										// Load a ranking list from files 从文件中读取排行榜

// DEF_Record
int MatchUser(struct Settings &settings);																							// Match the user with the record 匹配已有存档玩家
int LoadRecord(struct Settings &settings, struct Fish_motion &myfish);												// Load the record 读取存档																									
int SaveRecord(struct Settings &settings, struct Fish_motion myfish);												// Save the record 存储存档

// DEF_WorkSpace
int WorkSpace(Settings &settings, struct Fish_motion &myfish, int branch);										// Work space 工作面板