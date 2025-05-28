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

    // ���������Ă�����
    if (m_windActive) {
        // ���̎������Ԓ��̓v���C���[�ɉe����^����
        if (m_windDuration > 0) {
            m_windDuration--;

            // �v���C���[��X���W�𕗂̕����ɏ���������
            m_player->windPower = m_windDirection * 100.0f;

        }
        else {
            m_windActive = false;
        }
        return;
    }

    // WindCount��1, 3, 5�̂Ƃ��������𔭐�������
    int count = m_timer->WindCount;
    if ((count == 1 || count == 3 || count == 5) && !m_windActive) {
        // �v���C���[�̈ʒu�}30�ȓ��Ȃ畗�𔭐�������
        m_windActive = true;
        m_windDuration = 5 * 30; // 5�b��
        m_windDirection = (rand() % 2 == 0) ? 1.0f : -1.0f;
    }
}
