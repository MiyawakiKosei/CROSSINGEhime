#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////モデルを読み込む
	m_ormodelRender.Init("Assets/modelData/orenge/Orenge01.tkm");
	////プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("Player");

	m_ormodelRender.SetPosition(0.0f, 0.0f, -1000.0f);
}

Orenge::~Orenge() {

}

void Orenge::Update() {
	//上下に移動させる
	//if (orengeCount == 0) {
	//	//上
	//	position.y += 2.0f;
	//}
	//else if (orengeCount == 1) {
	//	//下
	//	position.y -= 2.0f;
	//}

	////posisionyが10を超えたら
	//if (position.y >= 50.0f) {
	//	//オレンジカウントを１にする
	//	orengeCount = 1;
	//}
	////positionyが-10を超えたら
	//else if (position.y <= -50.0f) {
	//	//オレンジカウントを0にする
	//	orengeCount = 0;
	//}
	//
	////座標を教える
	//m_ormodelRender.SetPosition(position);

	//絵描きさんの更新処理
	m_ormodelRender.Update();

	//プレイヤーからオレンジに向かうベクトルを求める
	//Vector3 diff = position - player->position;
	////プレイヤーとオレンジの距離が70.0fより小さかったら
	//if (diff.Length() <= 70.0f) {
	//	DeleteGO(this);
	//}
	
}

void Orenge::Render(RenderContext& renderContext) {
	//オレンジオブジェクトを描画
	m_ormodelRender.Draw(renderContext);
}
