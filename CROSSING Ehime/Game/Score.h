#pragma once
class Orenge;
class Score : public IGameObject {
public:
    Score();
    ~Score();
    void Update();
    void Render(RenderContext& rc);
    void AddScore();

    
private:
    Orenge* m_Orenge;
    FontRender fontRenderNumber; // �����p
    FontRender fontRenderPt;     // "Pt" �p
  
    int score = 0;
    int currentScore = 0;  // ���݂̃X�R�A
    const int maxScore = 9999;  // �X�R�A�̏��

};
