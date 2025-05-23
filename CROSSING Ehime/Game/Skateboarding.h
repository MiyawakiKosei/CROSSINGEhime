#pragma once
class Skateboarding : public IGameObject
{
public:
	Skateboarding();
	~Skateboarding();

	void Update();
	void Render(RenderContext& rc);

	ModelRender m_bgModelRender;
	PhysicsStaticObject m_bgObject;
};

