#pragma once
#include "k2EngineLow.h"

class Player;

class Track : public IGameObject
{
public:
    Track();
    ~Track();

    bool Start() override;
    void Update() override;
    void Render(RenderContext& rc) override;

    void SetPosition(const Vector3& position);
    Vector3 m_trposition;
private:
    void Move();

    ModelRender m_modelRender;


    Quaternion m_rotation;
    int m_moveDirection = 1;  // 1:ëOêi, 0:å„ëﬁ

    Vector3 m_initialPosition;

    Player* m_player = nullptr;
    CollisionObject* m_collision = nullptr;

    enum class MovingState
    {
        MovingForward,
        MovingBackward
    };
    MovingState m_movingState = MovingState::MovingForward;
};


