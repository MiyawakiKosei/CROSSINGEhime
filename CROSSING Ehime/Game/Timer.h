#pragma once
class Player;
class Timer : public IGameObject {
public:
    Timer();
    ~Timer();
    void Update();
    void Render(RenderContext& rc);

private:
    int timeLeft;
    FontRender fontRender;
    Player* player;			//プレイヤー。
};
