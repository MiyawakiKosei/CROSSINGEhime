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
    float m_windDuration = 0.0f;     // 風が吹いている残り時間（秒）
    float m_windCooldown = 20.0f;     // 風の待機時間（秒）
    float m_windDirection = 0.0f;    // -1（左）か +1（右）

    static constexpr float WIND_ACTIVE_TIME = 10.0f;    // 風が吹く時間（秒）
    static constexpr float WIND_COOLDOWN_TIME = 20.0f;  // 風の待機時間（秒）
  
};

