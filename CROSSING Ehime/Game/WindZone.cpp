#include "stdafx.h"
#include "WindZone.h"
#include "Player.h"
#include "Timer.h"

WindZone::WindZone() {}

WindZone::~WindZone() {}

void WindZone::SetPlayer(Player* player) {
    m_player = player;
}

void WindZone::SetTimer(Timer* timer) {
    m_timer = timer;
}

void WindZone::Update() {
    if (!m_player || !m_timer) return;

    const float playerX = m_player->m_position.x;

    // 風が吹いている状態
    if (m_windActive) {
        // 風の持続時間中はプレイヤーに影響を与える
        if (m_windDuration > 0) {
            m_windDuration--;

            // プレイヤーのX座標を風の方向に少し動かす
            m_player->windPower = m_windDirection * 100.0f;

        }
        else {
            m_windActive = false;
        }
        return;
    }

    // WindCountが1, 3, 5のときだけ風を発生させる
    int count = m_timer->WindCount;
    if ((count == 1 || count == 3 || count == 5) && !m_windActive) {
        // プレイヤーの位置±30以内なら風を発生させる
        m_windActive = true;
        m_windDuration = 5 * 30; // 5秒間
        m_windDirection = (rand() % 2 == 0) ? 1.0f : -1.0f;
    }
}
