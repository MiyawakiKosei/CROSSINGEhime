#include "stdafx.h"
#include "WindZone.h"
#include "Player.h"


WindZone::WindZone() //ai
    : m_windActive(false)
, m_windCooldown(20.0f)
, m_windDuration(0.0f)
{}

WindZone::~WindZone() {}

void WindZone::SetPlayer(Player* player) {
    m_player = player;
}

void WindZone::SetTimer(Timer* timer) {
    m_timer = timer;
}

void WindZone::Update() {
    if (!m_player) return;

    float deltaTime = g_gameTime->GetFrameDeltaTime();

    if (m_windActive) {
        if (m_windDuration > 0.0f) {
            m_windDuration -= deltaTime;
            m_player->windPower = m_windDirection * 100.0f;
        }
        else {
            m_windActive = false;
            m_player->windPower = 0.0f;
            m_windCooldown = WIND_COOLDOWN_TIME;  // 20�b�ҋ@
        }
    }
    else {
        if (m_windCooldown > 0.0f) {
            m_windCooldown -= deltaTime;
        }
        else {
            // �ҋ@���Ԃ��I������̂ŕ��𐁂�����i�m������Ȃ��j
            m_windActive = true;
            m_windDuration = WIND_ACTIVE_TIME;    // 10�b�ԕ�������
            m_windDirection = (rand() % 2 == 0) ? 1.0f : -1.0f;  // �������������_��
        }
    }
}

