#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	void Update();
	void Render(RenderContext& rc);

	ModelRender modelRender;
	//PhysicsStaticObject physicsStaticObject;
};

