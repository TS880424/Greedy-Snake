#include "pch.h"
#include "CSnake.h"
#define Snack_Len 20

CSnake::CSnake()
{
	//初始化蛇的长度以及开始时前进的方向和位置
	Len = 1;
	dire = 1;	//上下左右分别为1,2,3,4
	speed = 300;
	Body[0].x = 20;
	Body[0].y = 15;
}

CSnake::~CSnake()
{ }

//游戏开始和结束后的初始化
void CSnake::Init()
{
	// TODO: 在此处添加实现代码.
	Len = 1;
	dire = 1;
	Body[0].x = 20;
	Body[0].y = 15;
}


void CSnake::UpMove()
{
	// TODO: 在此处添加实现代码.
	for (int i = Len - 1; i > 0; --i)
	{
		Body[i].x = Body[i - 1].x;
		Body[i].y = Body[i - 1].y;
	}
	Body[0].y--;
	dire = 1;

}


void CSnake::DwMove()
{
	// TODO: 在此处添加实现代码.
	for (int i = Len - 1; i > 0; --i)
	{
		Body[i].x = Body[i - 1].x;
		Body[i].y = Body[i - 1].y;
	}
	Body[0].y++;
	dire = 2;

}


void CSnake::LfMove()
{
	// TODO: 在此处添加实现代码.
	for (int i = Len - 1; i > 0; --i)
	{
		Body[i].x = Body[i - 1].x;
		Body[i].y = Body[i - 1].y;
	}
	Body[0].x--;
	dire = 3;

}


void CSnake::RtMove()
{
	// TODO: 在此处添加实现代码.
	for (int i = Len - 1; i > 0; --i)
	{
		Body[i].x = Body[i - 1].x;
		Body[i].y = Body[i - 1].y;
	}
	Body[0].x++;
	dire = 4;

}
//画出蛇
void CSnake::Draw(Graphics& gh)
{
	SolidBrush headbrush(Color::Yellow);
	SolidBrush bodybrush(Color::YellowGreen);
	for (int i = 0; i < Len; i++)
	{
		body[i].X = (Body[i].x * Snack_Len - Snack_Len / 2);
		body[i].Y = (Body[i].y * Snack_Len - Snack_Len / 2);
		body[i].Width = Snack_Len;
		body[i].Height = Snack_Len;
	}
	gh.FillEllipse(&headbrush, body[0]);
	for (int i = 1; i < Len; i++)
	{
		gh.FillEllipse(&bodybrush, body[i]);
	}
}