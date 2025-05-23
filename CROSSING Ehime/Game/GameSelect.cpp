#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"

GameSelect::GameSelect() {
	//画像を読み込む
	spriteRender.Init("Assets/modelData/title/Select01.DDS",1920.0f,1080.0f);
}

GameSelect::~GameSelect() {

}

void GameSelect :: Update() {
	//Jボタンを押したら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//画像を描画する
	spriteRender.Draw(rc);
}