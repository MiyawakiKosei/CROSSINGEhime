#include "stdafx.h"
#include "Skateboarding.h"

Skateboarding::Skateboarding()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_bgModelRender.Init("Assets/model/board.tkm");//スケボーのモデル

	m_bgModelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	m_bgModelRender.SetScale(Vector3(5.0f, 5.0f, 5.0f)); // 広く見せるために拡大

	m_bgModelRender.Update();

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	m_bgModelRender.SetRotation(rot);
	//当たり判定初期化
	m_bgObject.CreateFromModel(m_bgModelRender.GetModel(),
		m_bgModelRender.GetModel().GetWorldMatrix());
}

Skateboarding::~Skateboarding()
{

}

void Skateboarding::Update()
{
	m_bgModelRender.Update();
}

void Skateboarding::Render(RenderContext& renderContext)
{
	m_bgModelRender.Draw(renderContext);
}
