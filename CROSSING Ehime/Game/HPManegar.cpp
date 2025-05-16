#include "stdafx.h"
#include "HPManegar.h"
#include "GameUI.h"

HPManegar::~HPManegar(){}

bool HPManegar::Start(){
    // HPバー初期化
    m_hpSprite.Init("Assets/sprite/HPUI.DDS", 440, 90);
    m_hpSprite.SetPosition({ -240.0f, 200.0f, 0.0f });

    return true;
}

void HPManegar::Update() {
    // HPの状態に応じてスプライトを切り替え
    switch (m_Hp) {
    case en_ZeroHP:
        m_hpSprite.Init("Assets/sprite/HPUI6.dds", 440, 90);
        break;
    case en_LowHP:
        m_hpSprite.Init("Assets/sprite/HPUI5.dds", 440, 90);
        break;
    case en_MidLowHP:
        m_hpSprite.Init("Assets/sprite/HPUI4.dds", 440, 90);
        break;
    case en_MidHighHP:
        m_hpSprite.Init("Assets/sprite/HPUI3.dds", 440, 90);
        break;
    case en_HighHP:
        m_hpSprite.Init("Assets/sprite/HPUI2.dds", 440, 90);
        break;
    case en_MaxHP:
        m_hpSprite.Init("Assets/sprite/HPUI.dds", 440, 90);
        break;
    default:
        m_hpSprite.Init("Assets/sprite/HPUI.dds", 440, 90);
        break;
    }

    m_hpSprite.SetPosition({ -440.0f, 340.0f, 0.0f });
  
}

void HPManegar::Render(RenderContext& rc) {
    m_hpSprite.Draw(rc);
}