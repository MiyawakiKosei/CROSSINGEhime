#include "stdafx.h"
#include "BackGround.h"
#include "Bike.h"

Bike::Bike()
{
	//�R�����g�A�E�g����B
    PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_bgModelRender.Init("Assets/modelData/bike.tkm");//���̃��f��

	m_bgModelRender.SetPosition(Vector3(400.0f, 100.0f, 300.0f));
	m_bgModelRender.SetScale(Vector3(1.0f, 1.0f, 1.0f)); // �L�������邽�߂Ɋg��

	m_bgModelRender.Update();

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	m_bgModelRender.SetRotation(rot);
	//�����蔻�菉����
	m_bgObject.CreateFromModel(m_bgModelRender.GetModel(),
		m_bgModelRender.GetModel().GetWorldMatrix());
}

Bike::~Bike()
{

}

void Bike::Update()
{
	m_bgModelRender.Update();
}

void Bike::Render(RenderContext& renderContext)
{
	m_bgModelRender.Draw(renderContext);
}