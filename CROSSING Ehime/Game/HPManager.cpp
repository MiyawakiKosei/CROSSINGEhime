#include "stdafx.h"
#include "HPManager.h"
#include "GameUI.h"

HPManager::~HPManager() {}

bool HPManager::Start() {
    // HPÉoÅ[èâä˙âª
    m_hpSprite.Init("Assets/sprite/HPUI.DDS", 440, 90);
    m_hpSprite.SetPosition({ -240.0f, 200.0f, 0.0f });

    return true;
}

void HPManager::Update() {
    enHPState state = static_cast<enHPState>(m_Hp);  // Å© enumÇ…ïœä∑

    switch (state) {
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
    default:
        m_hpSprite.Init("Assets/sprite/HPUI.dds", 440, 90);
        break;
    }

    m_hpSprite.SetPosition({ -440.0f, 340.0f, 0.0f });
}

void HPManager::Render(RenderContext& rc) {
    m_hpSprite.Draw(rc);
}