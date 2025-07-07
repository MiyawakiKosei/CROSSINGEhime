#pragma once

class Player;
//ゲームクリア
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);
private:
	//メンバ変数
	FontRender m_fontRender;//文字
	SpriteRender m_spriteRender;//絵

};

