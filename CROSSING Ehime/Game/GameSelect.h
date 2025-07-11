#pragma once
#include "sound/SoundSource.h"
class Player;
//ゲームセレクト
class GameSelect:public IGameObject
{
public:
	GameSelect();
	~GameSelect();
	//描画関数
	void Render(RenderContext& rc);
	//更新処理
	void Update();
	//スプライトレンダー
	SpriteRender spriteRender;

	SoundSource* m_GameSelectSE; //ゲームセレクトのSE

	//int gs_Count = 0;

};

