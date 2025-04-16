#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	//�R�����g�A�E�g����B
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/bridge/Bridge_01.tkm");

	modelRender.SetPosition(Vector3(0.0f, 0.0f, 0.0f));
	modelRender.SetScale(Vector3(10.0f, 1.0f, 10.0f)); // �L�������邽�߂Ɋg��

	Quaternion rot;
	rot.SetRotationDegY(0.0f);
	modelRender.SetRotation(rot);
	physicsStaticObject.CreateFromModel(modelRender.GetModel(),
		modelRender.GetModel().GetWorldMatrix());
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