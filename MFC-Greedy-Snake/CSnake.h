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

	int Len;	//�����߳���

	point Body[1200];//�������鴢����ÿ�������λ��

	Rect body[1200];//����һ��Rect���鷽���ͼ

	int dire;

	int speed;

	void Init();

	void UpMove();

	void DwMove();

	void LfMove();

	void RtMove();

	void Draw(Graphics& gh);

};

