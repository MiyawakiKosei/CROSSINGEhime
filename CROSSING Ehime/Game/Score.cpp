#include "stdafx.h"
#include "Score.h"
#include "orange.h"

Score::Score() {
    fontRenderNumber.SetPosition({ 660.0f, 0.0f, 0.0f }); // �����ʒu�i���񂹁j
    fontRenderNumber.SetScale(2.0f);
    fontRenderNumber.SetColor(g_vec4Black);
}

Score::~Score() {}

void Score::Update() {
    wchar_t buffer[16];
    swprintf_s(buffer, 16, L"%d", score);  // �����𕶎���ɕϊ�
    fontRenderNumber.SetText(buffer);

    // �����ŉ������Z�o�i�����t�H���g�O��j
    int digitCount = wcslen(buffer);
    float digitWidth = 20.0f;  // ����1���̕��i�����j
    float numberWidth = digitCount * digitWidth;

    // �����̉E�[���Œ�i��F800�j
    float rightEdgeX = 800.0f;

    Vector3 numberPos = {
        rightEdgeX - numberWidth, // ���[ = �E�[ - ��
        -410.0f,
        0.0f
    };

    fontRenderNumber.SetPosition(numberPos);

    
}




void Score::AddScore() {
   
    const int addPoint = 100;  // �I�����W�擾���̉��_

    score += addPoint;

    if (score > maxScore) {
        score = maxScore;
    }
        currentScore = score;
    }


void Score::Render(RenderContext& rc) {
    fontRenderNumber.Draw(rc);  // ���������`��
}