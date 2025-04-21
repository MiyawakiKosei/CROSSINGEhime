#include "stdafx.h"
#include "Timer.h"
#include "Player.h"
#include "Game.h"

Timer::Timer() : timeLeft(120 * 60) { // 120秒（2分）をフレーム単位で管理
    m_fontRender.SetPosition({ -927.0f,400.0f,0.0f });
    m_fontRender.SetScale(2.0f);
    m_fontRender.SetColor(g_vec4Black);
}

Timer::~Timer() {}



void Timer::Update() {
    if (timeLeft > 0) {
        timeLeft--;

        // 分と秒を計算
        int minutes = (timeLeft / 60) / 60;  // 分
        int seconds = (timeLeft / 60) % 60;  // 秒

        // "MM:SS" 形式で表示
        wchar_t buffer[6];
        swprintf(buffer, 6, L"%d:%02d", minutes, seconds);
        m_fontRender.SetText(buffer);

        //残り30秒以下なら色を赤にする
        if (timeLeft <= 30 * 60) {
            m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤
        }
        else {
            m_fontRender.SetColor(g_vec4Black);//黒
        }
    }
    else {
        m_fontRender.SetText(L"0:00");
        m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤
        GameCount = 2;//ゲームオーバー
    }
}

void Timer::Render(RenderContext& rc) {
    m_fontRender.Draw(rc);
}