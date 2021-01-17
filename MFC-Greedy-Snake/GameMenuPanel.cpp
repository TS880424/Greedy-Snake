#include "pch.h"
#include "GameMenuPanel.h"
#include "Game.h"

RectF rc;
GameMenuPanel::GameMenuPanel()
{
    // 背景图
    m_imgBackground = Image::FromFile(_T("Snake_Menu_Bk.jpg"));


    m_menuItems[0].index = 0;
    for (int i = 0; i < 2; i++) 
    {
        TCHAR path[MAX_PATH];
        _stprintf_s(path, _T("Snake_Start_%d.jpg"), i);
        auto imgPtr = Image::FromFile(path);
        RectF rc(300, 300, static_cast<float>(imgPtr->GetWidth()),
            static_cast<float>(imgPtr->GetHeight()));
        m_menuItems[0].vImgInfoPtr.push_back(make_tuple(imgPtr, rc));
    }

}

GameMenuPanel::~GameMenuPanel()
{

}

void GameMenuPanel::Draw(Graphics& gh) const
{
    gh.DrawImage(m_imgBackground, m_rect);

    // 画子菜单
    for (auto menuItem : m_menuItems) 
    {
        auto img = get<0>(menuItem.vImgInfoPtr[menuItem.index]);
        auto rect = get<1>(menuItem.vImgInfoPtr[menuItem.index]);
        gh.DrawImage(img, rect);
    }
}

// 处理 鼠标移动事件
void GameMenuPanel::OnMouseMove(UINT nFlags, CPoint point)
{
    PointF pt(static_cast<float>(point.x), static_cast<float>(point.y));
    // 画子菜单
    for (auto& menuItem : m_menuItems) 
    {
        auto img = get<0>(menuItem.vImgInfoPtr[menuItem.index]);
        auto rect = get<1>(menuItem.vImgInfoPtr[menuItem.index]);
        if (rect.Contains(pt)) 
        {
            menuItem.index = 1;
        }
        else 
        {
            menuItem.index = 0;
        }
    }
}

// 处理 鼠标左键抬起事件
void GameMenuPanel::OnLButtonUp(UINT nFlags, CPoint point)
{
    PointF pt(static_cast<float>(point.x), static_cast<float>(point.y));
    {
        auto& menuItem = m_menuItems[0];
        auto img = get<0>(menuItem.vImgInfoPtr[menuItem.index]);
        auto rect = get<1>(menuItem.vImgInfoPtr[menuItem.index]);
        if (rect.Contains(pt))
        {
            m_pParent->SetStep(Game::EGameTypeStart);
            return;
        }
    }
}


KeyMenuStart::KeyMenuStart()
{
    m_img[0] = Image::FromFile(_T("Snake_Start_0.png"));
    m_img[1] = Image::FromFile(_T("Snake_Start_1.png"));
    /*if (m_img[0])
    {
        rc = { 300, 300, static_cast<float>(m_img[0]->GetWidth()), static_cast<float>(m_img[0]->GetHeight()) };
    }*/
}

KeyMenuStart::~KeyMenuStart()
{

}

void KeyMenuStart::Draw(Graphics& gh) const
{
    if (m_bStop)
    {
        gh.DrawImage(m_img[0], rc);
        return;
    }

    static bool bFlag{ false };
    if (bFlag)
    {
        gh.DrawImage(m_img[0], rc);
    }
    else
    {
        gh.DrawImage(m_img[1], rc);
    }

}