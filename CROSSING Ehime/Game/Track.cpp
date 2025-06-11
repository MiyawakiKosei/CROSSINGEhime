#include "stdafx.h"
#include "Track.h"
#include "Player.h"


namespace
{
	Vector3	SCALE = Vector3(3.0f, 1.0, 3.0f);
	float SPEED = 200.0f;
	float LIMITED = 300.0f;
	Vector3 COLLISION_HEIGHT = Vector3(0.0f, 50.0f, 0.0f);
	Vector3	COLLISION_SIZE = Vector3(365.0f, 5.0f, 225.0f);
}

Track::Track() 
{
	
}

Track::~Track() {

}

bool Track::Start()
{
	//モデルを読み込む
	m_modelRender.Init("Assets/modelData/track/Track04.tkm");

	//プレイヤーのオブジェクトを引っ張ってくる
	m_player = FindGO<Player>("player");

	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	m_collisionObject = NewGO<CollisionObject>(0, "collisionObject");

	m_collisionObject->SetIsEnableAutoDelete(false);
	firstPosition = m_position;
	return true;

}

void Track::Update() {
	if (m_player == nullptr)
	{
		m_player = FindGO<Player>("player");
		return;
	}

	Move();

	m_modelRender.Update();
	m_physicsStaticObject.SetPosition(m_position);
	m_collisionObject->SetPosition(m_position + COLLISION_HEIGHT);

}


void Track::Move() {
	//前後に移動させる
	if (Tr_Count == 1) {
		//前に進む
		m_position.z += 10.0f;
	}
	else if (Tr_Count == 0) {
		//後ろに進む
		m_position.z -= 10.0f;
	}

	//もしz軸が-1000を超えたら
	if (m_position.z <= -1000.0f) {
		Tr_Count = 1;
		rot.SetRotationDegY(360.0f);
	}
	//もしz軸が-500を超えたら
	if (m_position.z >= -500.0f) {
		Tr_Count = 0;
		rot.SetRotationDegY(180.0f);
	}

	//座標を教える
	m_modelRender.SetPosition(m_position);

	//回転を教える
	m_modelRender.SetRotation(rot);

	
}

void Track::Render(RenderContext& renderContext) {
	//トラックの描画
	m_modelRender.Draw(renderContext);
}