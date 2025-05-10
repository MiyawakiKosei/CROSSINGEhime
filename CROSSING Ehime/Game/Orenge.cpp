#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////モデルを読み込む
	//modelRender.Init("Assets/modelData/");
	////プレイヤーのオブジェクトを引っ張ってくる
	//player = FindGO<Player>("Player");
}

Orenge::~Orenge() {

}

void Orenge::Update() {
	//上下に移動させる
	//if (moveCount == 0) {
	//	//上
	//	position.y += 1.0f;
	//}
	//else if (moveCount == 1) {
	//	//下
	//	position.y -= 1.0f;
	//}



	//絵描きさんの更新処理
	modelRender.Update();
}

void Orenge::Render(RenderContext& renderContext) {
	//オレンジオブジェクトを描画
	modelRender.Draw(renderContext);
}
