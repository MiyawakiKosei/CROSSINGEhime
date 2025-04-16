#include "stdafx.h"
#include "Timer.h"
#include "Player.h"

Timer::Timer() : timeLeft(120 * 60) { // 120�b�i2���j���t���[���P�ʂŊǗ�
    fontRender.SetPosition({ -927.0f,400.0f,0.0f });
    fontRender.SetScale(2.0f);
    fontRender.SetColor(g_vec4Black);
}

Timer::~Timer() {}

void Timer::Update() {
    if (timeLeft > 0) {
        timeLeft--;

        // ���ƕb���v�Z
        int minutes = (timeLeft / 60) / 60;  // ��
        int seconds = (timeLeft / 60) % 60;  // �b

        // "MM:SS" �`���ŕ\��
        wchar_t buffer[6];
        swprintf(buffer, 6, L"%d:%02d", minutes, seconds);
        fontRender.SetText(buffer);

        //�c��30�b�ȉ��Ȃ�F��Ԃɂ���
        if (timeLeft <= 30 * 60) {
            fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��
        }
        else {
            fontRender.SetColor(g_vec4Black);//��
        }
    }
    else {
        fontRender.SetText(L"0:00");
        fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��

    }
}

void Timer::Render(RenderContext& rc) {
    fontRender.Draw(rc);
}