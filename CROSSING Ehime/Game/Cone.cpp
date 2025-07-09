#include "stdafx.h"
#include "Cone.h"
#include "Player.h"

Cone::Cone() {
	//モデルを読み込む
	m_cnmodelRender.Init("Assets/modelData/cone/Cone02.tkm");
	m_cnmodelRender.SetScale(Vector3(2.0f, 2.0f, 2.0f));
	//プレイヤーの位置を取得
	m_player = FindGO<Player>("player");

}

Cone::~Cone() {

}

void Cone::Update() {
	//座標を教える
	m_cnmodelRender.SetPosition(m_cnposition);

	//絵描きさんの更新処理
	m_cnmodelRender.Update();

	//プレイヤーからコーンに向かうベクトルを求める
	Vector3 diff = m_player->m_position - m_cnposition;
	//ベクトルの長さが70.0fより小さかったら
	if (diff.Length() <= 70.0f) {
		m_player->P_Count = 2;
	}
}

void Cone::Render(RenderContext& renderContext) {
		//絵描きさんの描画処理
	m_cnmodelRender.Draw(renderContext);
}