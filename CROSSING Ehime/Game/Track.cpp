#include "stdafx.h"
#include "Track.h"
#include "Player.h"

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

    m_initialPosition = m_position;

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

    if (m_collision)
    {
        m_collision->SetPosition(m_position + collisionOffset);
        m_collision->SetRotation(m_rotation);
    }

    // P_Count の処理をここで実行。プレイヤーの状態に影響させる
    if (m_position.y <= -500.0f)
    {
        m_player->P_Count = 2;
    }
    else if (m_position.z <= -17500.0f)
    {
        m_player->P_Count = 1;
    }
}

void Track::Move()
{
    if (m_moveDirection == 1)
    {
        m_position.z += 10.0f;
    }
    else if (m_moveDirection == 0)
    {
        m_position.z -= 10.0f;
    }

    if (m_position.z <= -1000.0f)
    {
        m_moveDirection = 1;
        m_rotation.SetRotationDegY(360.0f);
    }
    else if (m_position.z >= -500.0f)
    {
        m_moveDirection = 0;
        m_rotation.SetRotationDegY(180.0f);
    }

    m_modelRender.SetPosition(m_position);
    m_modelRender.SetRotation(m_rotation);
}

void Track::Render(RenderContext& rc)
{
    m_modelRender.Draw(rc);
}
