#pragma once

class Score : public IGameObject {
public:
    Score();
    ~Score();
    void Update();
    void Render(RenderContext& rc);
    void AddScore(int points);

private:
    int score = 0;
    FontRender fontRenderNumber; // �����p
    FontRender fontRenderPt;     // "Pt" �p
    int currentScore = 0;  // ���݂̃X�R�A
    const int maxScore = 9999;  // �X�R�A�̏��
};
