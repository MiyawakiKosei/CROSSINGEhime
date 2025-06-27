#include "stdafx.h"
#include "Fish.h"
#include "Player.h"

Fish::Fish() {
	//モデルを読み込む
	m_fimodelRender.Init("Assets/modelData/fish/fish01.tkm");
	//プレイヤーの位置を取得
	m_player = FindGO<Player>("player");
}

Fish::~Fish() {

}

void Fish::Update() {
	Move();
	Rotation();
	State();

	//座標を教える
	m_fimodelRender.SetPosition(m_fiposition);

	//回転を教える
	//m_fimodelRender.SetRotation(rot);
	
	m_fimodelRender.Update();

	//プレイヤーから魚に向かうベクトルを求める
	Vector3 diff = m_player->m_position - m_fiposition;
	//ベクトルの長さが40.0fより小さかったら
	if (diff.Length() <= 70.0f) {
		m_player->P_Count = 2;
		//自身を消去する
		//DeleteGO(this);
	}


}

void Fish::Move() {

	if (Fi_Count == 0) {
		if (m_fiposition.x >= 0.0f) {
			m_fiposition.x -= 5.0f;
		    m_fiposition.y += 1.75f;
		}
		else if(m_fiposition.x< 0.0f) {
			m_fiposition.x -= 5.0f;
			m_fiposition.y -= 1.75f;
		}
	}
	else if (Fi_Count == 1) {
		if (m_fiposition.x <= 0.0f) {
			m_fiposition.x += 5.0f;
			m_fiposition.y += 1.75f;
		}
		else if (m_fiposition.x > 0.0f) {
			m_fiposition.x += 5.0f;
			m_fiposition.y -= 1.75f;
		}
	}
	else if (Fi_Count == 2) {
		m_fiposition.y += 1.0f;
		
	}
	
}

void Fish::Rotation() {

	switch (Fi_Count) {
	case 0:
		// 右向き
		rot.SetRotationDegY(0.0f);
		if (m_fiposition.x >= 0.0f) {
			rot.AddRotationZ(-220.0f);
			m_fimodelRender.SetRotation(rot);
		}
		else if (m_fiposition.x < 0.0f) {
			rot.AddRotationDegZ(25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		m_fimodelRender.SetRotation(rot);
		break;
	case 1:
		// 左向き
		rot.SetRotationDegY(180.0f);
		if (m_fiposition.x <= 0.0f) {
			rot.AddRotationDegZ(-25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		else if (m_fiposition.x > 0.0f) {
			rot.AddRotationDegZ(25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		m_fimodelRender.SetRotation(rot);
		break;
	}
}

void Fish::State() {

	if (m_fiposition.y <= -100.0f) {
		Fi_Count = 2;
	}

	if (Fi_Count==2){
		if (m_fiposition.x < 0.0f) {
			//rot.SetRotationDegY(0.0f);
			Fi_Count = 1;
		}
		else if (m_fiposition.x >= 0.0f) {
			//rot.SetRotationDegY(180.0f);
			Fi_Count = 0;
		}
	}
}

void Fish::Render(RenderContext& rc) {
	//魚オブジェクトを描画
	m_fimodelRender.Draw(rc);
}