#pragma once
class Player;
class Game;
class Timer : public IGameObject {
public:
    Timer();
    ~Timer();
    void Update();
    void Render(RenderContext& rc);

  

private:
    int timeLeft;
    FontRender m_fontRender;
    Player* m_player;			//プレイヤー。
    Game* m_game;
};
