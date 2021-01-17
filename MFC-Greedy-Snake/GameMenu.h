#pragma once

class Game;

class GameMenu
{
public:
    GameMenu();
    ~GameMenu();

    void SetParent(Game* g)
    {
        m_pParent = g;
    };

    Game* m_pParent{ nullptr };

    // ��
    virtual void Draw(Graphics& gh) const;


    // �Լ��ķ�Χ
    RectF m_rect{ 0, 0, 800, 600 };

    // ����ͼ
    Image* m_imgBackground;

};

