#include "stdafx.h"
#include "Player.h"
#include "Timer.h"

Player::Player()
{
    m_bgmodelRender.Init("Assets/modelData/Kate.tkm");
	rotation.SetRotationDegY(180.0f);
	m_bgmodelRender.SetRotation(rotation);//ステージの方に進むようにプレイヤーの向きを調整
	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		windTriggerZ = -12000.0f + static_cast<float>(rand() % 4001);
		windPower = 100.0f;
	}

	
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	if (!windActive && position.z > windTriggerZ) {
		windActive = true;

		// ランダムに左右どちらかへ風を吹かせる
		windForceX = (rand() % 2 == 0 ? -1.0f : 1.0f) * windPower;

		windDuration = 180; // 180フレーム（約3秒）風を持続
		//60フレームで1秒
	}

	if (windActive) {
		moveSpeed.x += windForceX;

		windDuration--;
		if (windDuration <= 0) {
			windActive = false; // 終了
		}
	}

	m_bgmodelRender.Update();
	m_bgmodelRender.SetPosition(position);

	
	Move();

	
	Rotation();

	//position.y -= 5.5f;

	if (position.y <= -500.0f)
	{
		P_Count = 2;
		//position.y = 0.0f;
	}
	else if (position.z <= -17500.0f) {
		P_Count = 1;
	}
}

//void Player::SetPosition(const Vector3& pos)
//{
//	position = pos;               
//	m_bgmodelRender.SetPosition(pos);
//}

void  Player::Move() 
{
	
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	
	forward.y = 0.0f;
	right.y = 0.0f;

	
	//right *= stickL.x * 1255.0f;
	//forward *= stickL.y * 1255.0f;
	right *= stickL.x * 1920.0f;
	forward *= stickL.y * 1920.0f;

	
	moveSpeed += right + forward;


	if (characterController.IsOnGround())
	{
		
		moveSpeed.y = 0.0f;
		
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			moveSpeed.y += 520.0f;
		}
	}
	
	else
	{
		moveSpeed.y -= 15.0f;
	}

	
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	
	m_bgmodelRender.SetPosition(position);
}

void Player::Rotation() 
{

	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
	
		m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
	m_bgmodelRender.Draw(renderContext);
}