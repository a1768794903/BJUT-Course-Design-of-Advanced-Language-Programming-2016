#pragma once
#include "Command.h"
#include "Definition.h"

// DEF_Album
int DeletePicture(int tag);																														// Delete picture form the album �������ɾ��ͼƬ			
int LoadAlbum(IMAGE *album);																											// Load pictures into album ��ȡͼƬ�������

// DEF_Console
int DispatchCmd(int _cmd, LinkList head, struct Settings &settings, struct Fish_motion &myfish);	// Dispatch command order �ַ���������																																								
int GetCommand(Settings settings, struct Fish_motion &myfish);														// Get command ��ȡָ��			
int Quit(void);																																		// Quit the game �˳���Ϸ

// DEF_Entry
int IniBkground(Settings &settings);																									// Background control ��������
int ClickHere(void);																																// Click to enter �������
int Input(Settings &settings);																												// Input ����
int DrawInputBox(void);																														// Draw input box �������봰��
int DrawCursor(int j);																															// Draw shining cursor ������˸�Ĺ�� 

// DEF_Extras	
int LoadMouseCursor(int mouse_type);																								// Load Mouse Cursor ��ȡ�����
int Stringer(Settings settings);																												// Stringer �ʵ�			
int Goldfinger(LinkList &head, Settings &settings);																				// Goldfinger cheat ����ָ������
int Triumph(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);							// Triumph ʤ���ɹ�
int InitSetting(struct Settings &settings, int branch);																			// Initiate the setting ��ʼ������
int SetOptionsMode(Settings &settings, int game_speed, int game_options, int menu_options);		// Set game options mode ������Ϸѡ��ģʽ

// DEF_Fish
int GenerateFish(LinkList &head, Settings &settings, int fishtype, int fishnumber);							// Generate a fish ������
int IniMyFish(LinkList &head, Settings &settings, struct Fish_motion &myfish);									// Initiate myfish ��ʼ����ҵ���																				
int RandomGenerateFish(LinkList &head, Settings &settings);															// Generate fish ���������
int SynchroMyfish(LinkList &head, struct Fish_motion &myfish);														// Synchronize my fish ������ҿ��Ƶ���

// DEF_Function
int HpSleep(int ms);			        																											// Accurate sleep ��ȷ��ʱ			
int RandCoorY(void);																															// Generate coordination y ����������y
int RandOrientation(void);																													// Generate an orientation �����������									
int RandomFishType(void);																													// Generate the fish type ��������������									
int TimeMeter(Settings &settings);																										// Time Meter ��ʱ��														
int CharToTchar(const char * _char, TCHAR * tchar);																			// Convert char into wchar ת�����ַ�Ϊ���ַ�

// DEF_Game
int Difficulty(int difficulty, struct Fish_motion &myfish);																		// Difficulty choice �Ѷ�ѡ��
int Game(struct Settings &settings, struct Fish_motion &myfish);														// Game interface ��Ϸ����
int GameOver(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);						// Game over ��Ϸ����

// DEF_Graphics
int DisplayFish(LinkList appoint);																											// Display all the fishes ��ʾ���е���																						
int DisplayMyFish(LinkList head);																										// Display my fish ��ʾ��ҿ��Ƶ���
int DisplayBackground(int branch);								    																	// Display the background ��ʾ����																					
int DisplayButton(int button_number);																									// Display the buttons ��ʾ��ť													
int DisplayFrame(int frame, Settings settings);																					// Display frame ��ʾ��
int DisplayGameInterface(int game_speed, int branch);																		// Display game interface ��ʾ��Ϸ����																
int DisplayOptions(Settings settings);																									// Display options ��ʾѡ��˵�
int DisplayOptionsMenu(Settings settings);																							// Display options menu ��ʾѡ��˵�																	
int DisplayRankingList(RankList *list);																									// Display ranking list ��ʾ���а�
int DisplaySetting(void);																														// Display setting ��ʾ����										
int DisplayTriumph(Settings settings, struct Fish_motion myfish);														// Display the triumph interface ��ʾʤ������																											
int DisplayWallpaper(void);																													// Display wallpaper ��ʾ��ֽ
int DisplayWorkSpace(Settings &settings);																							// Display the work space ��ʾ��������ʱ�䣩
int OuttextScript(int branch);																												// Display the scripts for menu interface ��ʾ�����ı�
int OuttextChoice(int mode, int choice);																								// Display the scripts for the choice ��ʾѡ���ı�										
int OuttextDifficulty(int difficulty);																											// Display the scripts for the difficulty choice ��ʾ�Ѷ�ѡ���ı�																											
int PrintScreenShot();																															// Print the screenshot ��ӡ����
int ScreenShot(int mode, Settings &settings);																						// Get the screenshot ��ȡ����

// DEF_Judge
int IfBounce(LinkList &object1, LinkList &object2);																				// Calculate the speed after bounce ����������ٶ�
int IfMeet(LinkList &head, struct Settings &settings);																			// Judge whether two fishes meet �ж��������Ƿ�����
int IfOut(LinkList &head);																														// Judge whether if out �ж��Ƿ����
int IfWin(LinkList &head, struct Settings &settings, struct Fish_motion &myfish);								// Judge if the controler win the game �ж�����Ƿ��ʤ											
int IfLevelUp(LinkList &head);																												// Judge if level up �ж��Ƿ����� 
LinkList IfEat(LinkList &head, LinkList &host, LinkList &prey, struct Settings &settings);					// Judge whether catch and eat �ж��Ƿ�ʳ

// DEF_Menu
int Category(struct Settings &settings, struct Fish_motion &myfish);													// Category directory ���ࣨ�Ѷȣ�Ŀ¼		
int Menu(Settings &settings);																												// Menu ���˵�

// DEF_Motion
int Move(LinkList &head, struct Settings &settings);																			// Move �ƶ�																										
int MyFishMoveUp(LinkList &head, struct Settings &settings);															// Myfish move up ��ҵ��������ƶ�																							
int MyFishMoveDown(LinkList &head, struct Settings &settings);														// Myfish move down ��ҵ��������ƶ�
int MyFishMoveLeft(LinkList &head, struct Settings &settings);															// Myfish move left ��ҵ��������ƶ�																													
int MyFishMoveRight(LinkList &head, struct Settings &settings);														// Myfish move right ��ҵ��������ƶ�																					
int MyFishStay(LinkList &head, Settings &settings);																			// Myfish stay ��ҵ���ֹͣ																						
int LimitSpeed(LinkList &appoint, int branch);																						// Limit speed ����																
int UpdateOrientation(LinkList &appoint);																							// Update the orientation ���³���
int SetOrientation(LinkList &appoint, int orientation);																			// Set random orientation �����������
int SetFishMotion(LinkList &element, int htorientation);																		// Set the motion attributes of fish ��������˶�����
int Fluctuate(LinkList &appoint);																											// Fluctuate ��������\

// DEF_Music
int SoundEffect(Settings settings, int branch);																						// Sound effect ��Ч
int StartBkMusic(Settings settings, int branch);																					// Start the background music ��ʼ���ű�������
int StopBkMusic(void);																															// Stop the background music ֹͣ���ű�������

// DEF_Object
int CreateLinkList(LinkList &head);																										// Establish an empty link list  ����һ��������
int DeleteElement(LinkList &head, int tag);																							// Delete the specific node ɾ���������ض����
int DeleteLinkList(LinkList &head);																										// Delete the link list ɾ������								
int InsertElement(LinkList &head, Settings &settings, int fishtype);														// Insert a node into the link list �����㣨ͷ�巨��						
LinkList SearchNode(LinkList head, int tag);																						// Search for a specific node Ѱ���ض����
LinkList SearchEndNode(LinkList head);																							// Search for the end node Ѱ��ĩβ���		

// DEF_RankingList
int InitRankingList(RankList *list);																										// Initiate a ranking list ��ʼ�����а�
int InsertRankingListNode(RankList *list, char name[], int point);														// Insert a ranking list element �������а�Ԫ��													
int SaveRankingList(RankList *list);																										// Save a ranking list from files ���ļ��д洢���а�
int LoadRankingList(RankList *list);																										// Load a ranking list from files ���ļ��ж�ȡ���а�

// DEF_Record
int MatchUser(struct Settings &settings);																							// Match the user with the record ƥ�����д浵���
int LoadRecord(struct Settings &settings, struct Fish_motion &myfish);												// Load the record ��ȡ�浵																									
int SaveRecord(struct Settings &settings, struct Fish_motion myfish);												// Save the record �洢�浵

// DEF_WorkSpace
int WorkSpace(Settings &settings, struct Fish_motion &myfish, int branch);										// Work space �������