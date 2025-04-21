#include "stdafx.h"
#include "Timer.h"
#include "Player.h"
#include "Game.h"

Timer::Timer() : timeLeft(120 * 60) { // 120�b�i2���j���t���[���P�ʂŊǗ�
    m_fontRender.SetPosition({ -927.0f,400.0f,0.0f });
    m_fontRender.SetScale(2.0f);
    m_fontRender.SetColor(g_vec4Black);
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
        m_fontRender.SetText(buffer);

        //�c��30�b�ȉ��Ȃ�F��Ԃɂ���
        if (timeLeft <= 30 * 60) {
            m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��
        }
        else {
            m_fontRender.SetColor(g_vec4Black);//��
        }
    }
    else {
        m_fontRender.SetText(L"0:00");
        m_fontRender.SetColor(Vector4(1.0f, 0.0f, 0.0f, 1.0f));//��
        GameCount = 2;//�Q�[���I�[�o�[
    }
}

void Timer::Render(RenderContext& rc) {
    m_fontRender.Draw(rc);
}