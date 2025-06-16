#pragma once

class Score;
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
    void CountDownTime();

    float GetTimeLeftSeconds() const { return m_timeLeftSeconds; }

    // スタートカウントダウン用
    void StartStartCountDown();
    void UpdateStartCountDown(float deltaTime);
    void RenderStartCountDown(RenderContext& rc);

    bool m_startCountdownActive = true;
    bool IsStartCountingDown() const { return m_isCountingDown; }
    bool IsStartCountdownFinished() const { return !m_startCountdownActive; }

private:
    Score* m_Score = nullptr;
    Player* m_Player = nullptr;

    FontRender m_timerFont;
    FontRender m_startCountdownFont;

    float m_timeLeftSeconds = 120.0f;
    bool m_gameOverCreated = false;

    bool m_isCountingDown = false;
    bool m_readyToStartTimer = false;

    float m_startCountdown = 3.0f;
    float m_countdownY = 300.0f;
    float m_alpha = 1.0f;

    int m_countState = 0;      // 0:落下, 1:フェード, 2:次の数字へ
    float m_countTimer = 0.0f; // いまは未使用だけど念のため

};

