#pragma once
#include "k2EngineLow.h"

class Bike : public IGameObject
{
public:
	Bike();
	~Bike();

	void Update();
	void Render(RenderContext& rc);

	ModelRender m_bgModelRender;
	PhysicsStaticObject m_bgObject;
};