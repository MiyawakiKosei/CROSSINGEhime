#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver() {
	//ゲームオーバーの画像を読み込む
	spriteRender.Init("Assets/sprite/GameOver01.DDS",1920.0f,1080.0f);
}

GameOver::~GameOver() {

}

//更新処理
void GameOver::Update() {
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//タイトルのオブジェクトを作成
		NewGO<Title>(0, "title");
		//自身を消去する
		DeleteGO(this);
	}
}

//描画処理
void GameOver::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}
