#include "stdafx.h"
#include "GameUI.h"
#include "Score.h"  // Score�N���X
#include "Timer.h"  // Timer�N���X
#include "Player.h"  
#include "HPManegar.h"  


bool GameUI::Start()
{
    m_SpriteRender.Init("Assets/sprite/CrossingUI.dds", 1920, 1080);
    m_SpriteRender.SetPosition({ 0.0f, 0.0f,0.0f });

    //HP�o�[�����
    m_Hpbar = NewGO<HPManegar>(0, "hp");
    m_Hpbar->m_hpSprite.SetPosition({ -240.0f, 200.0f, 0.0f });
    //�X�R�A�����
    m_Score = NewGO<Score>(0, "score");
    fontRender.SetPosition({ 600.0f, 430.0f, 0.0f });
  
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
    m_Hpbar->m_hpSprite.Update();
    m_Score->Update();   
}

void GameUI::Render(RenderContext& rc)
{
    m_SpriteRender.Draw(rc);
    m_Hpbar->m_hpSprite.Draw(rc);
    m_Score->Render(rc);
}

void GameUI::AddScore(int points) {
    m_Score->AddScore(points);
}
