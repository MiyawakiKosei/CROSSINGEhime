#include "stdafx.h"
#include "GameUI.h"
#include "Score.h"  // Score�N���X
#include "Timer.h"  // Timer�N���X
#include "Player.h"  


bool GameUI::Start()
{
    m_SpriteRender.Init("Assets/sprite/CrossingUI.dds", 1920, 1080);
    m_SpriteRender.SetPosition({ 0.0f, 0.0f,0.0f });

    // HP�o�[������
    m_hpSprite.Init("Assets/sprite/HPUI.DDS", 440, 90);
    m_hpSprite.SetPosition({ -240.0f, 200.0f, 0.0f });


    // �X�R�A�ƃ^�C�}�[�̐����i�`��͂��ꂼ��ɔC����j
    m_Score = NewGO<Score>(0, "score");
    fontRender.SetPosition({ 600.0f, 430.0f, 0.0f });
    m_Timer = NewGO<Timer>(0, "timer");
    fontRender.SetPosition({ -600.0f,100.0f,0.0f });
    return true;
}

GameUI::GameUI()
{

}

GameUI::~GameUI()
{
    // �X�R�A�̃I�u�W�F�N�g���폜
    DeleteGO(m_Score);
    DeleteGO(m_Timer);

}
void GameUI::Update()
{




    // HP�̏�Ԃɉ����ăX�v���C�g��؂�ւ�
    switch (m_hp) {
    case 1:
        m_hpSprite.Init("Assets/sprite/HPUI2.dds", 440, 90);
        break;
    case 2:
        m_hpSprite.Init("Assets/sprite/HPUI3.dds", 440, 90);
        break;
    case 3:
        m_hpSprite.Init("Assets/sprite/HPUI4.dds", 440, 90);
        break;
    case 4:
        m_hpSprite.Init("Assets/sprite/HPUI5.dds", 440, 90);
        break;
    case 5:
        m_hpSprite.Init("Assets/sprite/HPUI6.dds", 440, 90);
        break;
    default:
        m_hpSprite.Init("Assets/sprite/HPUI.dds", 440, 90);
        break;
    }

    m_hpSprite.SetPosition({ -440.0f, 340.0f, 0.0f });
    m_hpSprite.Update();
    m_Score->Update();
}

void GameUI::Render(RenderContext& rc)
{
    m_SpriteRender.Draw(rc);
    m_hpSprite.Draw(rc);
    m_Score->Render(rc);
}

void GameUI::AddScore(int points) {
    m_Score->AddScore(points);
}
