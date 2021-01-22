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

    // ��
    virtual void Draw(Graphics& gh) const;


    // �Լ��ķ�Χ
    RectF m_rect{ 0, 0, 800, 600 };

    // ���� ����ƶ��¼�
    void OnMouseMove(UINT nFlags, CPoint point);

    // ���� ������̧���¼�
    void OnLButtonUp(UINT nFlags, CPoint point);

    // ����ͼ
    Image* m_imgBackground;

    // �˵���
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

    // ��
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


    // �˵� ͼƬ
    Image* m_img[2];

    // �Ƿ�ֹͣ����״̬
    bool m_bStop{ false };
};