#include "pch.h"
#include "GameMenu.h"

GameMenu::GameMenu()
{
    // ±³¾°Í¼
    m_imgBackground = Image::FromFile(_T("Snake_Menu_Bk.jpg"));
}

GameMenu::~GameMenu()
{

}

void GameMenu::Draw(Graphics& gh) const
{
    gh.DrawImage(m_imgBackground, m_rect);
}
