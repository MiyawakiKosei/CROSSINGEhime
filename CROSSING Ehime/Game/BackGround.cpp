#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/ground.tkm");

	Quaternion rot;
	rot.SetRotationDegY(180.0f);
	modelRender.SetRotation(rot);
}

BackGround::~BackGround()
{

}

void BackGround::Update()
{
	modelRender.Update();
}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}