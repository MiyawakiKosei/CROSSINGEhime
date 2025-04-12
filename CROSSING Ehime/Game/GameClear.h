#pragma once

class Player;
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//XVˆ—
	void Update();
	//•`‰æˆ—
	void Render(RenderContext& rc);

	//ƒƒ“ƒo•Ï”
	SpriteRender spriteRender;
};

