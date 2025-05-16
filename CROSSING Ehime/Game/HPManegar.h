#pragma once
class Player;
class Timer;
class Score;
class Game;
class GameUI;

class HPManegar: public IGameObject
{
public:
	~HPManegar();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	enum enHPState //お試しenum　体力に応じて変化させたい用ステート
	{
		en_ZeroHP,//0　　死
		en_LowHP, //1
		en_MidLowHP, //2
		en_MidHighHP, //3　　
		en_HighHP,//4　　　　
		en_MaxHP, //5　最大体力
	};

	enHPState m_Hp = en_MaxHP;//5
	SpriteRender m_hpSprite; // HPのスプライト

private:
	


};

