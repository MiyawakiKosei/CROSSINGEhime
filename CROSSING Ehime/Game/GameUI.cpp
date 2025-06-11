#include "stdafx.h"
#include "GameUI.h"
#include "Score.h"  // Score�N���X
#include "Player.h"  



bool GameUI::Start()
{
 
    //�X�R�A�����
    m_Score = NewGO<Score>(0, "score");
 
  
    return true;
}

GameUI::GameUI()
{

}

GameUI::~GameUI()
{
    // �X�R�A�̃I�u�W�F�N�g���폜
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
