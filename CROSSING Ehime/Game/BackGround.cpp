#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//コメントアウトする。
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	//m_bgModelRender.Init("Assets/modelData/ground.tkm");//このモデルの名前
	m_bgModelRender.Init("Assets/modelData/bridge/Bridge_02.tkm");//橋のモデル

	m_bgModelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	m_bgModelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f)); // 広く見せるために拡大

	m_bgModelRender.Update();

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	m_bgModelRender.SetRotation(rot);
	//当たり判定初期化
	m_bgObject.CreateFromModel(m_bgModelRender.GetModel(),
		m_bgModelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Update()
{
	m_bgModelRender.Update();
}

void BackGround::Render(RenderContext& renderContext)
{
	m_bgModelRender.Draw(renderContext);
}