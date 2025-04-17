#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	void Update();
	void Render(RenderContext& rc);

	ModelRender m_bgModelRender;
	PhysicsStaticObject m_bgObject;
};

