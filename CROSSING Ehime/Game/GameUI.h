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
    SpriteRender m_hpSprite; // HP�o�[�̃X�v���C�g
    SpriteRender fontRender;
    SpriteRender m_SpriteRender;
    int m_hp = 0;            // HP�l�i0�`5�j
    int currentKeyCount;    // �v���C���[�̌��݂̃L�[��
    Score* m_Score;
    Timer* m_Timer;
    Player* player;
};
