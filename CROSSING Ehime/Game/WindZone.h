#pragma once
class Player;
class Timer;

class WindZone : public IGameObject {
public:
    WindZone();
    ~WindZone();
    void Update() override;
    void SetPlayer(Player* player);
    void SetTimer(Timer* timer);

private:
    Player* m_player = nullptr;
    Timer* m_timer = nullptr;

    bool m_windActive = false;
    float m_windDuration = 0.0f;     // ���������Ă���c�莞�ԁi�b�j
    float m_windCooldown = 20.0f;     // ���̑ҋ@���ԁi�b�j
    float m_windDirection = 0.0f;    // -1�i���j�� +1�i�E�j

    static constexpr float WIND_ACTIVE_TIME = 10.0f;    // �����������ԁi�b�j
    static constexpr float WIND_COOLDOWN_TIME = 20.0f;  // ���̑ҋ@���ԁi�b�j
  
};

