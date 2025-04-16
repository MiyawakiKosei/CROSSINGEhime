#pragma once

class Player;
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();
	//XVˆ—
	void Update();
	//•`‰æˆ—
	void Render(RenderContext& rc);

	//ƒƒ“ƒo•Ï”
	SpriteRender spriteRender;
};

