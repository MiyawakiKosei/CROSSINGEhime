#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////モデルを読み込む
	m_ormodelRender.Init("Assets/modelData/orenge/Orenge01.tkm");
	////プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("player");

	//m_ormodelRender.SetPosition(0.0f, 0.0f, -1000.0f);
}

Orenge::~Orenge() {

}

void Orenge::Update() {

	Move();

	//絵描きさんの更新処理
	m_ormodelRender.Update();
	
	//プレイヤーからオレンジに向かうベクトルを求める
	Vector3 diff = player->position - position;
	//ベクトルの長さが70.0fより小さかったら
	if (diff.Length() <= 120.0f) {
		orengePoint += 1;
		//自身を消去する
		DeleteGO(this);
	}
}

void Orenge::Move() {
	//上下に移動させる
	if (orengeCount == 0) {
		//上
		position.y += 1.0f;
	}
	else if (orengeCount == 1) {
		//下
		position.y -= 1.0f;
	}

	//posisionyが初期位置+50を超えたら
	if (position.y >= firstPosition.y+30.0f) {
		//オレンジカウントを１にする
		orengeCount = 1;
	}
	//positionyが初期位置-50を超えたら
	else if (position.y <= firstPosition.y -30.0f) {
		//オレンジカウントを0にする
		orengeCount = 0;
	}
	
	//座標を教える
	m_ormodelRender.SetPosition(position);


}

void Orenge::Render(RenderContext& renderContext) {
	//オレンジオブジェクトを描画
	m_ormodelRender.Draw(renderContext);
}
