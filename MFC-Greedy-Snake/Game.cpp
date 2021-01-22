#include "pch.h"
#include "Game.h"
#include"CSnake.h"
#include"MainFrm.h"
#include"GameMenu.h"

int i = 0;
int bean = 0;
Rect Bean;
Game::Game()
{
	m_menu.m_pParent = this;						// ���ò˵�ѡ����ָ��ǰ����
	//m_menuBackup.m_pParent = this;						// ���ò˵�������ָ��ǰ����
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			m_map[i][j].X = -10 + i * 20;
			m_map[i][j].Width = 20;
			m_map[i][j].Y = -10 + j * 20;
			m_map[i][j].Height = 20;
		}
	}

}

Game::~Game()
{ }

void Game::SetHandle(HWND hWnd)
{
	m_hWnd = hWnd;
}

bool Game::EnterFrame(DWORD dwTime)//��Ӧ��ʱ��ÿ���¼�
{

	/*if (m_snack.speed == 200)
	{
		i++;
	}
	if (i == 20)
	{
		m_snack.speed = 300;
		i = 0;
	}*/
	if (dwTime % 10 == 0)
	{
		GameRunDraw();
	}
	GameRunLogic();
	return false;
}
//��������ƶ��¼�
void Game::onMouseMove(UINT nFlags, CPoint point)
{
	 //ѡ��׶�
	if (m_eStep == EGameTypeMenu)
	{
		m_menu.OnMouseMove(nFlags, point); 		// ѡ����Ϸ����
	}
}
//�������̧�����¼�
void Game::OnLButtonUp(UINT nFlags, CPoint point)
{
	// ѡ��׶�
	if (m_eStep == EGameTypeMenu)
	{
		m_menu.OnLButtonUp(nFlags, point); 		// ѡ����Ϸ����
	}

}

void Game::SetStep(Game::EGameType step)
{
	m_eStep = step;
	GameInit();											// ���ó�ʼ������
}

/* ��Ϸ��ʼ��
���� ��Ϸ���󣬳�ʼ����ͼ������λ�õ�
*/

bool Game::GameInit()//��Ϸ��ʼ��
{
	// TODO: �ڴ˴����ʵ�ִ���.
	m_snake.Init();				//��ʼ����

	return (this->*m_initFunc[m_eStep])();// ���ݲ�ͬ�׶ε��ò�ͬ�Ĵ�����
}

bool Game::GameInitMenu()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return true;
}

bool Game::GameInitStart()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return true;
}

bool Game::GameInitGame()
{
	return true;
}

bool Game::GameInitStop()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return true;
}

void Game::GameRunLogic()//��Ϸ�߼�����
{
	// TODO: �ڴ˴����ʵ�ִ���.
	(this->*m_logicFunc[m_eStep])();
}

void Game::GameRunLogicOnMenu()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	/*if (KEYDOWN(' '))
	{
		SetStep(EGameTypeStrat);
	}*/
}

void Game::GameRunLogicOnStart()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	/*IsHit();
	switch (m_snake.dire)
	{
	case 1:
		m_snake.UpMove();
		break;
	case 2:
		m_snake.DwMove();
		break;
	case 3:
		m_snake.LfMove();
		break;
	case 4:
		m_snake.RtMove();
		break;
	}*/
	if (KEYDOWN(VK_UP))
	{
		/*if (m_snake.dire == 1)
		{
			m_snake.speed = 300;
		}
		else*/ if (m_snake.dire != 2/* && m_snake.dire != 1*/)
		{
			m_snake.dire = 1;
			/*m_snake.UpMove();*/
		}
	}
	if (KEYDOWN(VK_DOWN))
	{
		/*if (m_snake.dire == 2)
		{
			m_snake.speed = 300;
		}
		else*/ if (/*m_snake.dire != 2 &&*/ m_snake.dire != 1)
		{
			m_snake.dire = 2;
			/*m_snake.DwMove();*/
		}
	}
	if (KEYDOWN(VK_LEFT))
	{
		/*if (m_snake.dire == 3)
		{
			m_snake.speed = 300;
		}
		else*/ if (/*m_snake.dire != 3 &&*/ m_snake.dire != 4)
		{
			m_snake.dire = 3;
			/*m_snake.LfMove();*/
		}
	}
	if (KEYDOWN(VK_RIGHT))
	{
		/*if (m_snake.dire == 4)
		{
			m_snake.speed = 300;
		}
		else*/ if (m_snake.dire != 3 /*&& m_snake.dire != 4*/)
		{
			m_snake.dire = 4;
			/*m_snake.RtMove();*/
		}
	}

}

void Game::GameRunLogicOnGame()
{
	//IsHit();
	//switch (m_snack.dire)
	//{
	//case 1:
	//	m_snack.UpMove();
	//	break;
	//case 2:
	//	m_snack.DwMove();
	//	break;
	//case 3:
	//	m_snack.LfMove();
	//	break;
	//case 4:
	//	m_snack.RtMove();
	//	break;
	//}
	//if (KEYDOWN(VK_UP))
	//{
	//	/*if (m_snack.dire == 1)
	//	{
	//		m_snack.speed = 300;
	//	}
	//	else*/ if (m_snack.dire != 2 && m_snack.dire != 1)
	//	{
	//		m_snack.dire = 1;
	//	}
	//}
	//if (KEYDOWN(VK_DOWN))
	//{
	//	/*if (m_snack.dire == 2)
	//	{
	//		m_snack.speed = 300;
	//	}
	//	else*/ if (m_snack.dire != 2 && m_snack.dire != 1)
	//	{
	//		m_snack.dire = 2;
	//	}
	//}
	//if (KEYDOWN(VK_LEFT))
	//{
	//	/*if (m_snack.dire == 3)
	//	{
	//		m_snack.speed = 300;
	//	}
	//	else*/ if (m_snack.dire != 3 && m_snack.dire != 4)
	//	{
	//		m_snack.dire = 3;
	//	}
	//}
	//if (KEYDOWN(VK_RIGHT))
	//{
	//	/*if (m_snack.dire == 4)
	//	{
	//		m_snack.speed = 300;
	//	}
	//	else*/ if (m_snack.dire != 3 && m_snack.dire != 4)
	//	{
	//		m_snack.dire = 4;
	//	}
	//}
}

void Game::GameRunLogicStop()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	SetStep(EGameTypeMenu);

}

void Game::GameRunDraw()//��Ϸ��ͼ����
{
	// TODO: �ڴ˴����ʵ�ִ���.
	HDC hdc = ::GetDC(m_hWnd);							// �豸:ͼƬҪ����������
	CRect rc; 											// �ͻ����Ĵ�С
	GetClientRect(m_hWnd, &rc);

	CDC* dc = CClientDC::FromHandle(hdc);

	CDC m_dcMemory; 										// ˫�����ͼ��
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(dc, rc.Width(), rc.Height());
	m_dcMemory.CreateCompatibleDC(dc);
	CBitmap* pOldBitmap = m_dcMemory.SelectObject(&bmp);

	Graphics gh(m_dcMemory.GetSafeHdc());				// �������
	gh.Clear(Color::White); 								// �������
	gh.ResetClip();


	(this->*m_drawFunc[m_eStep])(gh); 					// �����ڴ�


	::BitBlt(hdc, 0, 0, rc.Width(), rc.Height(), 		// ��������Ļ
		m_dcMemory.GetSafeHdc(), 0, 0, SRCCOPY);
	::ReleaseDC(m_hWnd, hdc); 							// �ͷ�
	return;
}

void Game::GameRunDrawOnMenu(Graphics& gh)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	m_menu.Draw(gh);


}

void Game::GameRunDrawOnStart(Graphics& gh)
{
	// TODO: �ڴ˴����ʵ�ִ���.

	IsHit();

	switch (m_snake.dire)
	{
	case 1:
		m_snake.UpMove();
		break;
	case 2:
		m_snake.DwMove();
		break;
	case 3:
		m_snake.LfMove();
		break;
	case 4:
		m_snake.RtMove();
		break;
	}
	
	Pen myPen(Color(6, 128, 67), 6);

	SolidBrush myBrush(Color(174, 221, 129));

	RectF rc(0, 0, 800, 600);

	gh.FillRectangle(&myBrush, rc);

	gh.DrawRectangle(&myPen, rc);

	m_snake.Draw(gh);
	
	SolidBrush headbrush(Color::Yellow);
	SolidBrush bodybrush(Color::YellowGreen);
	Pen pen(Color::Red);
	
	gh.FillEllipse(&headbrush, Rect(1, 1, 100, 100));
	gh.DrawEllipse(&pen, Rect(3, 12, 11, 11));
	
}

void Game::GameRunDrawOnGame(Graphics& gh)
{
	
}

void Game::GameRunDrawOnStop(Graphics& gh)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	/*m_eStep = EGameTypeStart;*/
}

void Game::IsHit()
{
	if (m_snake.body[0].X < 0 || m_snake.body[0].X>780 || m_snake.body[0].Y < 0 || m_snake.body[0].Y>580)
	{
		m_eStep = EGameTypeStop;
		AfxMessageBox(_T("��Ϸ����"));
		return;
	}
	for (int i = 1; i < m_snake.Len; i++)
	{
		if (m_snake.body[0].X == m_snake.body[i].X && m_snake.body[0].Y == m_snake.body[i].Y)
		{
			m_eStep = EGameTypeStop;
			AfxMessageBox(_T("��Ϸ����"));
			return;
		}
	}
}

void Game::SetBean(Graphics& gh)
{
	SolidBrush brush(Color::Blue);

	if (bean == 0)
	{
		Bean = m_map[rand() % 40][rand() % 30];
		bean = 1;
	}
	gh.FillEllipse(&brush, Bean);
}

void Game::Eat(Graphics& gh)
{
	SolidBrush myBrush(Color(174, 221, 129));
	if (bean == 1)
	{
		if (m_snake.body[0].X == Bean.X && m_snake.body[0].Y == Bean.Y)
		{
			m_snake.Len++;
			gh.FillEllipse(&myBrush, Bean);
			bean = 0;
		}
	}

}
