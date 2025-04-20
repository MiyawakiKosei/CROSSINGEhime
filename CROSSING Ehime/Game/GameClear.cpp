#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear() {
	//ゲームクリア画像を読み込む
	spriteRender.Init("Assets/modelData/clear/Clear01.DDS",1920.0f,1080.0f);
}

GameClear::~GameClear(){

}

//更新処理
void GameClear::Update() {
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		//タイトル画面を作る
		NewGO<Title>(0, "title");
		//自身を消去する
		DeleteGO(this);
	}
}

//描画処理
void GameClear::Render(RenderContext&rc)
{
	spriteRender.Draw(rc);
}