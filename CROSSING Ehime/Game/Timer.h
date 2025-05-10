#pragma once
class Player;
class Game;
class Timer : public IGameObject {
public:
    Timer();
    ~Timer();
    void Update();
    void Render(RenderContext& rc);
    int T_Count = 0;
    int WindCount = 0;

private:
    int timeLeft;
 
    FontRender m_fontRender;
    Player* m_player;			//プレイヤー。

   };
