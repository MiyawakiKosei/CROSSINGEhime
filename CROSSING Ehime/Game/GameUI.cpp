#include "stdafx.h"
#include "GameUI.h"
#include "Score.h"
#include "Player.h"

GameUI::GameUI() {}

GameUI::~GameUI()
{
    DeleteGO(m_Score);
}

bool GameUI::Start()
{
    m_Score = NewGO<Score>(0, "score");

    m_timerFont.SetPosition({ -100.0f, 500.0f, 0.0f });
    m_timerFont.SetScale(2.0f);
    m_timerFont.SetColor(g_vec4Black);

    // スタートカウントダウン用フォント
    m_startCountdownFont.SetPosition({ -100.0f, m_countdownY, 0.0f });
    m_startCountdownFont.SetScale(8.0f);
    m_startCountdownFont.SetColor(Vector4(1, 0, 0, 1));

    m_isCountingDown = false;

    return true;
}

void GameUI::StartStartCountDown()
{
    m_startCountdown = 4;     // 表示: 3,2,1,GO!!
    m_countdownY = 400.0f;
    m_alpha = 1.0f;
    m_countState = 0;
    m_isCountingDown = true;
}

void GameUI::Update()
{
    m_Score->Update();

    float deltaTime = g_gameTime->GetFrameDeltaTime();

    if (m_isCountingDown) {
        UpdateStartCountDown(deltaTime);
    }
    else {
        CountDownTime();
    }
}

void GameUI::CountDownTime()
{
    float deltaTime = g_gameTime->GetFrameDeltaTime();

    if (m_timeLeftSeconds > 0.0f) {
        m_timeLeftSeconds -= deltaTime;

        if (m_timeLeftSeconds < 0.0f) {
            m_timeLeftSeconds = 0.0f;

            if (!m_gameOverCreated) {
                m_Player->P_Count = 2;
                m_gameOverCreated = true;
            }
        }
    }

    int totalSeconds = static_cast<int>(m_timeLeftSeconds);
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    wchar_t buffer[6];
    swprintf(buffer, 6, L"%d:%02d", minutes, seconds);
    m_timerFont.SetText(buffer);

    if (m_timeLeftSeconds <= 30.0f) {
        m_timerFont.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));
    }
    else {
        m_timerFont.SetColor(g_vec4Black);
    }
}

void GameUI::UpdateStartCountDown(float deltaTime)
{
    constexpr float dropSpeed = 300.0f;
    constexpr float fadeSpeed = 1.0f;

    switch (m_countState) {
    case 0: // 落下
        m_countdownY -= dropSpeed * deltaTime;
        if (m_countdownY <= 200.0f) {
            m_countdownY = 200.0f;
            m_countState = 1;
        }
        break;

    case 1: // フェード
        m_alpha -= fadeSpeed * deltaTime;
        if (m_alpha <= 0.0f) {
            m_alpha = 0.0f;
            m_countState = 2;
        }
        break;

    case 2: // 次へ
        m_startCountdown--;
        if (m_startCountdown == 0) {
            m_isCountingDown = false;
        }
        else {
            m_alpha = 1.0f;
            m_countdownY = 300.0f;
            m_countState = 0;
        }
        break;
    }
}

void GameUI::Render(RenderContext& rc)
{
    m_Score->Render(rc);
    m_timerFont.Draw(rc);

    if (m_isCountingDown) {
        RenderStartCountDown(rc);
    }
}

void GameUI::RenderStartCountDown(RenderContext& rc)
{
    int displayNum = m_startCountdown - 1;
    wchar_t buffer[16];

    if (displayNum > 0) {
        swprintf(buffer, 16, L"%d", displayNum);
    }
    else if (displayNum == 0) {
        wcscpy(buffer, L"GO!!");
        m_startCountdownFont.SetPosition({ -200.0f, m_countdownY, 0.0f });
    }
    else {
        return; // 何も表示しない
    }

    m_startCountdownFont.SetText(buffer);
    m_startCountdownFont.SetPosition({ -100.0f, m_countdownY, 0.0f });
    m_startCountdownFont.SetColor(Vector4(1, 0, 0, m_alpha));
    m_startCountdownFont.Draw(rc);
}

