#pragma once

struct point
{
	int x;
	int y;
};

class CSnake
{
public:
	CSnake();
	~CSnake();

	int Len;	//定义蛇长度

	point Body[1200];//定义数组储存蛇每节身体的位置

	Rect body[1200];//定义一个Rect数组方便绘图

	int dire;

	int speed;

	void Init();

	void UpMove();

	void DwMove();

	void LfMove();

	void RtMove();

	void Draw(Graphics& gh);

};

