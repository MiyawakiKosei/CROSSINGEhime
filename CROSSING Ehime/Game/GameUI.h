#pragma once

class Score;
class Timer;
class Player;


class GameUI : public IGameObject
{
public:
    GameUI();
    ~GameUI();
    bool Start();
    void Update();
    void Render(RenderContext& rc);
    void AddScore();

private:
    SpriteRender fontRender;
    SpriteRender m_SpriteRender;
    
    Score* m_Score;

    Player* player;
};
