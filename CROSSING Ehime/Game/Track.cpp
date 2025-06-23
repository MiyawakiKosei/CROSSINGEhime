#include "stdafx.h"
#include "Track.h"
#include "Player.h"
#

namespace
{
    const Vector3 collisionOffset = Vector3(0.0f, 50.0f, 0.0f);
    const Vector3 collisionSize = Vector3(365.0f, 5.0f, 225.0f);
}

Track::Track()
{
}

Track::~Track()
{
    if (m_collision)
    {
        DeleteGO(m_collision);
        m_collision = nullptr;
    }
}

bool Track::Start()
{
    m_modelRender.Init("Assets/modelData/track/Track04.tkm");

    m_player = FindGO<Player>("player");

    m_collision = NewGO<CollisionObject>(0, "collisionObject");
    m_collision->CreateBox(m_position + collisionOffset, m_rotation, collisionSize);
    m_collision->SetIsEnableAutoDelete(false);

	m_collisionObject->SetIsEnableAutoDelete(false);
	firstPosition = m_position;
	return true;

    return true;
}

void Track::Update()
{
    if (!m_player)
    {
        m_player = FindGO<Player>("player");
        return;
    }

    Move();

	m_modelRender.Update();
	m_physicsStaticObject.SetPosition(m_position);
	m_collisionObject->SetPosition(m_position + COLLISION_HEIGHT);

    if (m_collision)
    {
        m_collision->SetPosition(m_position + collisionOffset);
        m_collision->SetRotation(m_rotation);
    }

    // P_Count �̏����������Ŏ��s�B�v���C���[�̏�Ԃɉe��������
    if (m_position.z <= -900.0f)
    {
        m_player->P_Count = 2;
    }
}

void Track::Move() {
	//�O��Ɉړ�������
	if (Tr_Count == 1) {
		//�O�ɐi��
		m_position.z += 10.0f;
	}
	else if (Tr_Count == 0) {
		//���ɐi��
		m_position.z -= 10.0f;
	}

	//����z����-1000�𒴂�����
	if (m_position.z <= -1000.0f) {
		Tr_Count = 1;
		rot.SetRotationDegY(360.0f);
	}
	//����z����-500�𒴂�����
	if (m_position.z >= -500.0f) {
		Tr_Count = 0;
		rot.SetRotationDegY(180.0f);
	}

	//���W��������
	m_modelRender.SetPosition(m_position);

	//��]��������
	m_modelRender.SetRotation(rot);

	
}

void Track::Render(RenderContext& rc)
{
    m_modelRender.Draw(rc);
}
