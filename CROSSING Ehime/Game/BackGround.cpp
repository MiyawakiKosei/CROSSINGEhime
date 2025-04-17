#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	//�R�����g�A�E�g����B
	PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_bgModelRender.Init("Assets/modelData/ground.tkm");//���̃��f���̖��O
	//m_bgModelRender.Init("Assets/modelData/bridge/Bridge_01.tkm");//���̃��f��

	m_bgModelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	m_bgModelRender.SetScale(Vector3(10.0f, 10.0f, 10.0f)); // �L�������邽�߂Ɋg��

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	m_bgModelRender.SetRotation(rot);
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