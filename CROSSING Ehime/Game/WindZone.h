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
    int m_windDuration = 0;  // 風が吹いている残り時間（フレーム）
    float m_windDirection = 0.0f; // -1（左）か +1（右）
};
