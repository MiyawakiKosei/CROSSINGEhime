#pragma once
class Player;

class Track : public IGameObject 
{
public:
	Track();
	~Track();
	bool Start() override;
	void Update() override;
	void Render(RenderContext& rc) override;
	/// <summary>
	/// ���W��ݒ�B
	/// </summary>
	/// <param name="position">���W�B</param>
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	ModelRender m_modelRender;
	//�������烁���o�ϐ�
	//���W
	Vector3 m_position;
	//��]
	Quaternion rot;
	int Tr_Count = 1;

	Vector3 firstPosition;

	float m_touchDamageTimer = 0.0f;


private:
	bool m_hasDamaged = false;
	void Move();
	Player* m_player = nullptr;
	PhysicsStaticObject		m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
	CollisionObject* m_collisionObject = nullptr;		//�R���W�����I�u�W�F�N�g�B
	enum enMovingFloorState
	{
		enMovingFloorState_MovingRight,
		enMovingFloorState_MovingLeft
	};
	enMovingFloorState		m_MovingFloorState = enMovingFloorState_MovingRight;
	Track* m_rightTrack;//�E�g���b�N
	Track* m_leftTrack;//���g���b�N
};


