#include "stdafx.h"
#include "Score.h"
#include "orange.h"

Score::Score() {
    fontRenderNumber.SetPosition({ 660.0f, 0.0f, 0.0f }); // 初期位置（左寄せ）
    fontRenderNumber.SetScale(2.0f);
    fontRenderNumber.SetColor(g_vec4Black);
}

Score::~Score() {}

void Score::Update() {
    wchar_t buffer[16];
    swprintf_s(buffer, 16, L"%d", score);  // 数字を文字列に変換
    fontRenderNumber.SetText(buffer);

    // 桁数で横幅を算出（等幅フォント前提）
    int digitCount = wcslen(buffer);
    float digitWidth = 20.0f;  // 文字1桁の幅（調整可）
    float numberWidth = digitCount * digitWidth;

    // 数字の右端を固定（例：800）
    float rightEdgeX = 800.0f;

    Vector3 numberPos = {
        rightEdgeX - numberWidth, // 左端 = 右端 - 幅
        -410.0f,
        0.0f
    };

    fontRenderNumber.SetPosition(numberPos);

    
}




void Score::AddScore() {
   
    const int addPoint = 100;  // オレンジ取得時の加点

    score += addPoint;

    if (score > maxScore) {
        score = maxScore;
    }
        currentScore = score;
    }


void Score::Render(RenderContext& rc) {
    fontRenderNumber.Draw(rc);  // 数字だけ描画
}