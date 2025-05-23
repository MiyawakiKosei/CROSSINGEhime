#include "stdafx.h"
#include "Skateboarding.h"

Skateboarding::Skateboarding()
{
	//�R�����g�A�E�g����B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	m_bgModelRender.Init("Assets/model/board.tkm");//�X�P�{�[�̃��f��

	m_bgModelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	m_bgModelRender.SetScale(Vector3(5.0f, 5.0f, 5.0f)); // �L�������邽�߂Ɋg��

	m_bgModelRender.Update();

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	m_bgModelRender.SetRotation(rot);
	//�����蔻�菉����
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
