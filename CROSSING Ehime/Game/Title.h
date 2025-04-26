#pragma once
#include "sound/SoundSource.h"

class Player;
//タイトル
class Title:public IGameObject
{
public:
	Title();
	~Title();
	//描画関数
	void Render(RenderContext& rc);
	//更新処理
	void Update();
	//スプライトレンダー
	SpriteRender spriteRender;
	//タイトルのBGM
	SoundSource* titleBGM;
};

