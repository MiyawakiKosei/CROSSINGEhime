#pragma once
#include "sound/SoundSource.h"

class Player;
//タイトル
class Title:public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	//描画関数
	void Render(RenderContext& rc);
	//更新処理
	void Update();
	

private:
	//タイトルのBGM
	SoundSource* titleBGM;

	FontRender		m_fontRender;				//フォントレンダー。
	SpriteRender	m_spriteRender;				//スプライトレンダー。
	SoundSource* m_ClickSE;				//クリックSE
};

