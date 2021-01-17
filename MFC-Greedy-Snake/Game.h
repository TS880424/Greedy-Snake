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
	//设置输出窗口的句柄
	void SetHandle(HWND hWnd);
	//进入游戏帧
	bool EnterFrame(DWORD dwTime);
	//处理鼠标移动事件
	void onMouseMove(UINT nFlags, CPoint point);
	//处理左键抬起是事件
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
		&Game::GameInitMenu,        	// 菜单阶段
		&Game::GameInitStart,     	// 开始阶段
		&Game::GameInitGame,		//游戏阶段
		&Game::GameInitStop,  	// 结束阶段
	};
	/* 游戏逻辑处理:
	1. 维护前进状态
	2. 维护蛇的身体
	检测包括： 撞墙，撞击身体...*/

	void GameRunLogic();

	void GameRunLogicOnMenu();	//游戏逻辑处理：菜单阶段

	void GameRunLogicOnStart();	//游戏逻辑处理：开始阶段

	void GameRunLogicOnGame();	//游戏逻辑处理：游戏阶段

	void GameRunLogicStop();	//游戏逻辑处理：结束阶段

	void(Game::* m_logicFunc[EGameTypeCount])() = 
	{
		&Game::GameRunLogicOnMenu,         	// 菜单阶段
		&Game::GameRunLogicOnStart, 	// 开始阶段
		&Game::GameRunLogicOnGame,		//游戏阶段
		&Game::GameRunLogicStop,      	// 结束阶段
	};
	/* 游戏绘图处理
	负责 绘画 游戏中的对象
	*/

	void GameRunDraw();

	void GameRunDrawOnMenu(Graphics& gh);	// 游戏绘图处理 : 菜单阶段

	void GameRunDrawOnStart(Graphics& gh);	// 游戏绘图处理 : 开始阶段

	void GameRunDrawOnGame(Graphics& gh);	// 游戏绘图处理 : 游戏阶段

	void GameRunDrawOnStop(Graphics& gh);	// 游戏绘图处理 : 结束阶段

	void(Game::* m_drawFunc[EGameTypeCount])(Graphics&) =
	{
		&Game::GameRunDrawOnMenu, 				// 菜单阶段
		&Game::GameRunDrawOnStart, 		// 开始阶段
		&Game::GameRunDrawOnGame,		//游戏阶段
		&Game::GameRunDrawOnStop, 			// 结束阶段
	};
private:
	int m_fps{ 0 }; 						// 记录 游戏每秒多少帧

	EGameType m_eStep{ EGameTypeMenu }; 	// 当前阶段:菜单选择阶段

	CSnake m_snake;			//定义蛇

	Rect m_map[40][30];//定义一个地图坐标

	void SetBean(Graphics& gh);

	void IsHit();

	void Eat(Graphics& gh);

	GameMenuPanel m_menu;


	//CGameMenuPanel m_menuSelect; 			// 开始菜单

	//CGameMenuBackground m_menu; 			// 开始菜单背景图

	//CGameMenuPanel2 m_menuBackup; 			// 返回菜单
};
