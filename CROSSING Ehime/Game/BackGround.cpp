#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	//コメントアウトする。
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/bg.tkm");

	modelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	modelRender.SetScale(Vector3(10.0f, 1.0f, 10.0f)); // 広く見せるために拡大

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	modelRender.SetRotation(rot);
}

BackGround::~BackGround()
{

}

void BackGround::Update()
{
	modelRender.Update();
}

void BackGround::Render(RenderContext& renderContext)
{
	modelRender.Draw(renderContext);
}