#include "stdafx.h"
#include "Timer.h"
#include "Player.h"

Timer::Timer() : timeLeft(120 * 60) { // 120秒（2分）をフレーム単位で管理
    fontRender.SetPosition({ -927.0f,400.0f,0.0f });
    fontRender.SetScale(2.0f);
    fontRender.SetColor(g_vec4Black);
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
        fontRender.SetText(buffer);

        //残り30秒以下なら色を赤にする
        if (timeLeft <= 30 * 60) {
            fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤
        }
        else {
            fontRender.SetColor(g_vec4Black);//黒
        }
    }
    else {
        fontRender.SetText(L"0:00");
        fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//赤

    }
}

void Timer::Render(RenderContext& rc) {
    fontRender.Draw(rc);
}