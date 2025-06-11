#include "stdafx.h"
#include "Timer.h"
#include "Player.h"
#include "Game.h"

Timer::Timer() : timeLeft(60 * 30) { // 1800�t���[���i1���A30FPS�z��j
    m_fontRender.SetPosition({ -100.0f,500.0f,0.0f });
    m_fontRender.SetScale(2.0f);
    m_fontRender.SetColor(g_vec4Black);
}

Timer::~Timer() {}



void Timer::Update() {
    if (timeLeft > 0) {
        timeLeft--;

        // ���ƕb���v�Z�i30�t���[�� = 1�b�j
        int minutes = (timeLeft / 30) / 60;  // ��
        int seconds = (timeLeft / 30) % 60;  // �b

        // "MM:SS" �`���ŕ\��
        wchar_t buffer[6];
        swprintf(buffer, 6, L"%d:%02d", minutes, seconds);
        m_fontRender.SetText(buffer);

        // �c��30�b�ȉ��Ȃ��
        if (timeLeft <= 30 * 30) {
            m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��
        }
        else {
            m_fontRender.SetColor(g_vec4Black);//��
        }

        if (timeLeft % (30 * 15) == 0) {  // 15�b���Ƃɑ���
            WindCount++;
        }
    }
    else {
        m_fontRender.SetText(L"0:00");
        m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��
        T_Count = 2;//�Q�[���I�[�o�[
    }
}

void Timer::Render(RenderContext& rc) {
    m_fontRender.Draw(rc);
}