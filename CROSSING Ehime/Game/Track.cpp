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
    m_collision->CreateBox(m_trposition + collisionOffset, m_rotation, collisionSize);
    m_collision->SetIsEnableAutoDelete(false);

    m_initialPosition = m_trposition;

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
        m_collision->SetPosition(m_trposition + collisionOffset);
        m_collision->SetRotation(m_rotation);
    }
    Vector3 diff = m_trposition - m_player->m_position;
    //ベクトルの長さが70.0fより小さかったら
    if (diff.Length() <= 110.0f) {

        m_player->P_Count = 2;
   
       
    }
 
}

void Track::Move()
{
    if (m_moveDirection == 1)
    {
        m_trposition.z += 10.0f;
        m_trposition.y += 0.005;
    }
    else if (m_moveDirection == 0)
    {
        m_trposition.z -= 10.0f;
		m_trposition.y -= 0.005;
    }

    /*if (m_trposition.z <= -1000.0f)
    {
        m_moveDirection = 1;
        m_rotation.SetRotationDegY(360.0f);
    }
    else if (m_trposition.z >= -500.0f)
    {
        m_moveDirection = 0;
        m_rotation.SetRotationDegY(180.0f);
    }*/

	//Y座標が30未満なら前進、31以上なら後退
    if (m_trposition.y < 30)
    {
        m_moveDirection = 1;
        m_rotation.SetRotationDegY(360.0f);
    }
    else if (m_trposition.y >= 31.0f)
    {
        m_moveDirection = 0;
        m_rotation.SetRotationDegY(180.0f);
    }

    m_modelRender.SetPosition(m_trposition);
    m_modelRender.SetRotation(m_rotation);
}

void Track::Render(RenderContext& rc)
{
    m_modelRender.Draw(rc);
}
