#include "stdafx.h"
#include "Cone.h"
#include "Player.h"

Cone::Cone() {
	//コーンのモデルを読み込む
	m_cnmodelRender.Init("Assets/modelData/cone/Cone02.tkm");
	m_cnmodelRender.SetScale(Vector3(2.0f, 2.0f, 2.0f));
	//プレイヤーを見つける
	m_player = FindGO<Player>("player");

}

Cone::~Cone() {

}

void Cone::Update() {
	//コーンの移動処理
	m_cnmodelRender.SetPosition(m_cnposition);

	//絵描きさんの更新処理
	m_cnmodelRender.Update();

	//プレイヤーからコーンに向かうベクトルを求める
	Vector3 diff = m_player->m_position - m_cnposition;
	//ベクトルの長さが50.0f以下だったら
	if (diff.Length() <= 50.0f) {
		m_player->P_Count = 2;
	}
}

void Cone::Render(RenderContext& renderContext) {
	// コーンのモデルを描画
	m_cnmodelRender.Draw(renderContext);
}