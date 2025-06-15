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
	/// 座標を設定。
	/// </summary>
	/// <param name="position">座標。</param>
	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	ModelRender m_modelRender;
	//ここからメンバ変数
	//座標
	Vector3 m_position;
	//回転
	Quaternion rot;
	int Tr_Count = 1;

	Vector3 firstPosition;

	float m_touchDamageTimer = 0.0f;


private:
	bool m_hasDamaged = false;
	void Move();
	Player* m_player = nullptr;
	PhysicsStaticObject		m_physicsStaticObject;				//静的物理オブジェクト。
	CollisionObject* m_collisionObject = nullptr;		//コリジョンオブジェクト。
	enum enMovingFloorState
	{
		enMovingFloorState_MovingRight,
		enMovingFloorState_MovingLeft
	};
	enMovingFloorState		m_MovingFloorState = enMovingFloorState_MovingRight;
	Track* m_rightTrack;//右トラック
	Track* m_leftTrack;//左トラック
};


