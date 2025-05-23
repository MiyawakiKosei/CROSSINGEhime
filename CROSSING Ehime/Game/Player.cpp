#include "stdafx.h"
#include "Player.h"
#include "Timer.h"
#include "WindZone.h"
#include "Skateboarding.h"
#include "Game.h"
#include "GameCamera.h"

Player::Player()
{
	//モデルデータ読み込み
    //m_bgmodelRender.Init("Assets/model/player.tkm");
	rotation.SetRotationDegY(180.0f);
	m_bgmodelRender.SetRotation(rotation);//ステージの方に進むようにプレイヤーの向きを調整
	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	animationClips[enAnimationClip_Idle].Load("Assets/skater/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Drift].Load("Assets/skater/drift.tka");
	animationClips[enAnimationClip_Drift].SetLoopFlag(true);
	animationClips[enAnimationClip_Run].Load("Assets/skater/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(false);
	m_bgmodelRender.Init("Assets/model/player.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);
	
	srand(static_cast<unsigned int>(time(nullptr)));

	
	characterController.Init(25.0f, 75.0f, position);
}	


	Player::~Player() {
	}

void Player::Update()
{

	//モデルを更新する
	m_bgmodelRender.Update();
	//絵描きさん
	m_bgmodelRender.SetPosition(position);

	//移動処理
	Move();
	//回転処理
	Rotation();

	//position.y -= 5.5f;

	//もしプレイヤーがY-500以下なら
	if (position.y <= -500.0f)
	{
		//プレイヤーカウントを2にする
		P_Count = 2;
		//position.y = 0.0f;
	}
	//もしプレイヤーがZ-17500を超えたら
	else if (position.z <= -17500.0f) {
		//プレイヤーカウントを１にする
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
	//xzの移動速度を0.0fにする
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y方向には移動させない
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と120.0fを乗算
	right *= stickL.x * 1920.0f;
	forward *= stickL.y * 1920.0f;

	//移動速度にスティックの入力量を加算する
	moveSpeed += right + forward;

	//地面に付いていたら
	if (characterController.IsOnGround())
	{
		//重力をなくす
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる
			moveSpeed.y += 520.0f;
		}
	}
	//地面に付いていなかったら
	else
	{
		//重力を発生させる
		moveSpeed.y -= 15.0f;
	}
	moveSpeed.x += windPower;
	//キャラクターコントローラーを使って座標を移動させる
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える
	m_bgmodelRender.SetPosition(position);
}

void Player::Rotation() 
{
	//xかｚの移動速度があったら(スティックの入力があったら)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//キャラコンの方向を変える
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える
		m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
		m_bgmodelRender.Draw(renderContext);
}