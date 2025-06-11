#include "stdafx.h"
#include "GameUI.h"
#include "Score.h"  // Scoreクラス
#include "Player.h"  



bool GameUI::Start()
{
 
    //スコアを作る
    m_Score = NewGO<Score>(0, "score");
 
  
    return true;
}

GameUI::GameUI()
{

}

GameUI::~GameUI()
{
    // スコアのオブジェクトを削除
    DeleteGO(m_Score);

}
void GameUI::Update()
{
  
    m_Score->Update();   
    
}

void GameUI::Render(RenderContext& rc)
{
  
    m_Score->Render(rc);
}

void GameUI::AddScore() {
    m_Score->AddScore();
}
