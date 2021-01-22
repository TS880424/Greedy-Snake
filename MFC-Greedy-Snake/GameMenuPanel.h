#pragma once

#include <tuple>
#include <vector>

using namespace std;

class Game;

class GameMenuPanel
{
public:
    GameMenuPanel();
    ~GameMenuPanel();

    void SetParent(Game* g)
    {
        m_pParent = g;
    };

    Game* m_pParent;

    // 画
    virtual void Draw(Graphics& gh) const;


    // 自己的范围
    RectF m_rect{ 0, 0, 800, 600 };

    // 处理 鼠标移动事件
    void OnMouseMove(UINT nFlags, CPoint point);

    // 处理 鼠标左键抬起事件
    void OnLButtonUp(UINT nFlags, CPoint point);

    // 背景图
    Image* m_imgBackground;

    // 菜单项
    struct 
    {
        vector<tuple<Image*, RectF>> vImgInfoPtr;
        int index;
    } m_menuItems[2];
};

class KeyMenuStart
{
public:
    KeyMenuStart();
    ~KeyMenuStart();

    // 画
    virtual void Draw(Gdiplus::Graphics& gh) const;
    void SetStop(bool bStop = true)
    {
        m_bStop = bStop;
    };
    bool GetStop() const
    {
        return m_bStop;
    }

private:


    // 菜单 图片
    Image* m_img[2];

    // 是否停止动画状态
    bool m_bStop{ false };
};