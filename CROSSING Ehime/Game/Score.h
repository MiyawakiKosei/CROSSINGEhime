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
    FontRender fontRenderNumber; // 数字用
    FontRender fontRenderPt;     // "Pt" 用
  
    int score = 0;
    int currentScore = 0;  // 現在のスコア
    const int maxScore = 9999;  // スコアの上限

};
