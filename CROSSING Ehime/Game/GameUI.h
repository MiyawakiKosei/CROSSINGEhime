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
    void AddScore(int points);

private:
    SpriteRender m_hpSprite; // HPバーのスプライト
    SpriteRender fontRender;
    SpriteRender m_SpriteRender;
    int m_hp = 0;            // HP値（0～5）
    int currentKeyCount;    // プレイヤーの現在のキー数
    Score* m_Score;
    Timer* m_Timer;
    Player* player;
};
