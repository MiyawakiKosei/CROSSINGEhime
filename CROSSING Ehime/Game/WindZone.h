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
    int m_windDuration = 0;  // ���������Ă���c�莞�ԁi�t���[���j
    float m_windDirection = 0.0f; // -1�i���j�� +1�i�E�j
};
