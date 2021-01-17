#pragma once
#include"CSnake.h"
#include"framework.h"
#include"GameMenu.h"
#include"GameMenuPanel.h"

#define KEYDOWN(vk)(GetAsyncKeyState(vk) & 0x8000 )

class Game 
{
public:
	Game();
	~Game();
	//����������ڵľ��
	void SetHandle(HWND hWnd);
	//������Ϸ֡
	bool EnterFrame(DWORD dwTime);
	//��������ƶ��¼�
	void onMouseMove(UINT nFlags, CPoint point);
	//�������̧�����¼�
	void OnLButtonUp(UINT nFlags, CPoint point);
	enum EGameType
	{
		EGameTypeMenu = 0,
		EGameTypeStart,
		EGameTypeGame,
		EGameTypeStop,
		EGameTypeCount,
	};

	void SetStep(Game::EGameType step);
private:
	HWND m_hWnd;

	bool GameInit();

	bool GameInitMenu();

	bool GameInitStart();

	bool GameInitGame();

	bool GameInitStop();

	bool (Game::* m_initFunc[EGameTypeCount])() = 
	{
		&Game::GameInitMenu,        	// �˵��׶�
		&Game::GameInitStart,     	// ��ʼ�׶�
		&Game::GameInitGame,		//��Ϸ�׶�
		&Game::GameInitStop,  	// �����׶�
	};
	/* ��Ϸ�߼�����:
	1. ά��ǰ��״̬
	2. ά���ߵ�����
	�������� ײǽ��ײ������...*/

	void GameRunLogic();

	void GameRunLogicOnMenu();	//��Ϸ�߼������˵��׶�

	void GameRunLogicOnStart();	//��Ϸ�߼�������ʼ�׶�

	void GameRunLogicOnGame();	//��Ϸ�߼�������Ϸ�׶�

	void GameRunLogicStop();	//��Ϸ�߼����������׶�

	void(Game::* m_logicFunc[EGameTypeCount])() = 
	{
		&Game::GameRunLogicOnMenu,         	// �˵��׶�
		&Game::GameRunLogicOnStart, 	// ��ʼ�׶�
		&Game::GameRunLogicOnGame,		//��Ϸ�׶�
		&Game::GameRunLogicStop,      	// �����׶�
	};
	/* ��Ϸ��ͼ����
	���� �滭 ��Ϸ�еĶ���
	*/

	void GameRunDraw();

	void GameRunDrawOnMenu(Graphics& gh);	// ��Ϸ��ͼ���� : �˵��׶�

	void GameRunDrawOnStart(Graphics& gh);	// ��Ϸ��ͼ���� : ��ʼ�׶�

	void GameRunDrawOnGame(Graphics& gh);	// ��Ϸ��ͼ���� : ��Ϸ�׶�

	void GameRunDrawOnStop(Graphics& gh);	// ��Ϸ��ͼ���� : �����׶�

	void(Game::* m_drawFunc[EGameTypeCount])(Graphics&) =
	{
		&Game::GameRunDrawOnMenu, 				// �˵��׶�
		&Game::GameRunDrawOnStart, 		// ��ʼ�׶�
		&Game::GameRunDrawOnGame,		//��Ϸ�׶�
		&Game::GameRunDrawOnStop, 			// �����׶�
	};
private:
	int m_fps{ 0 }; 						// ��¼ ��Ϸÿ�����֡

	EGameType m_eStep{ EGameTypeMenu }; 	// ��ǰ�׶�:�˵�ѡ��׶�

	CSnake m_snake;			//������

	Rect m_map[40][30];//����һ����ͼ����

	void SetBean(Graphics& gh);

	void IsHit();

	void Eat(Graphics& gh);

	GameMenuPanel m_menu;


	//CGameMenuPanel m_menuSelect; 			// ��ʼ�˵�

	//CGameMenuBackground m_menu; 			// ��ʼ�˵�����ͼ

	//CGameMenuPanel2 m_menuBackup; 			// ���ز˵�
};
