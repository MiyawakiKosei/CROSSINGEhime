#include "stdafx.h"
#include "Timer.h"
#include "Player.h"
#include "Game.h"

Timer::Timer() : timeLeft(60 * 30) { // 1800フレーム（1分、30FPS想定）
    m_fontRender.SetPosition({ -100.0f,500.0f,0.0f });
    m_fontRender.SetScale(2.0f);
    m_fontRender.SetColor(g_vec4Black);
}

Timer::~Timer() {}



void Timer::Update() {
    if (timeLeft > 0) {
        timeLeft--;

        // 分と秒を計算（30フレーム = 1秒）
        int minutes = (timeLeft / 30) / 60;  // 分
        int seconds = (timeLeft / 30) % 60;  // 秒

        // "MM:SS" 形式で表示
        wchar_t buffer[6];
        swprintf(buffer, 6, L"%d:%02d", minutes, seconds);
        m_fontRender.SetText(buffer);

        // 残り30秒以下なら赤
        if (timeLeft <= 30 * 30) {
            m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤
        }
        else {
            m_fontRender.SetColor(g_vec4Black);//黒
        }

        if (timeLeft % (30 * 15) == 0) {  // 15秒ごとに増加
            WindCount++;
        }
    }
    else {
        m_fontRender.SetText(L"0:00");
        m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤
        T_Count = 2;//ゲームオーバー
    }
}

void Timer::Render(RenderContext& rc) {
    m_fontRender.Draw(rc);
}