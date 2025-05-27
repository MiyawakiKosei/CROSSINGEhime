#include "stdafx.h"
#include "Player.h"
#include "Timer.h"
#include "WindZone.h"
#include "Game.h"
#include "GameCamera.h"

Player::Player()
{
	//モデルデータ読み込み
    //m_bgmodelRender.Init("Assets/model/player.tkm");
	rotX.SetRotationDegX(-90.0f);
	rotY.SetRotationDegZ(180.0f);
	Quaternion rotation = rotX * rotY;
	//m_bgmodelRender.SetRotation(rotation);//ステージの方に進むようにプレイヤーの向きを調整
	
	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	//待機のアニメーション
	animationClips[enAnimationClip_Idle].Load("Assets/anim/skater/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_boardAnimClips[enAnimationClip_Idle].Load("Assets/anim/board/idle.tka");
	m_boardAnimClips[enAnimationClip_Idle].SetLoopFlag(true);

	//スタートランのアニメーション
	animationClips[enAnimationClip_Start].Load("Assets/anim/skater/start.tka");
	animationClips[enAnimationClip_Start].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Start].Load("Assets/anim/board/start.tka");
	m_boardAnimClips[enAnimationClip_Start].SetLoopFlag(false);

	//地面を蹴る時のアニメーション
	animationClips[enAnimationClip_Push].Load("Assets/anim/skater/push.tka");
	animationClips[enAnimationClip_Push].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Push].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Push].SetLoopFlag(false);

	//走っている時のアニメーション
	animationClips[enAnimationClip_Run].Load("Assets/anim/skater/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Run].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Run].SetLoopFlag(false);

	//ドリフトする時のアニメーション
	animationClips[enAnimationClip_Drift].Load("Assets/anim/skater/drift.tka");
	animationClips[enAnimationClip_Drift].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Drift].Load("Assets/anim/board/drift.tka");
	m_boardAnimClips[enAnimationClip_Drift].SetLoopFlag(false);

	//m_bgmodelRender.Init("Assets/model/player.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_bgmodelRender.Init("Assets/ModelData/player/player.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_bgmodelRender.SetPosition(position);
	m_bgmodelRender.SetRotation(rotation);
	m_bgmodelRender.SetScale(m_scale);
	m_bgmodelRender.Update();

	//ボードモデルの初期化
	m_boardModel.Init("Assets/ModelData/player/board.tkm", nullptr, enAnimationClip_Num, enModelUpAxisY);
	m_boardModel.SetPosition(position);
	m_boardModel.SetRotation(rotation);
	m_boardModel.SetScale(m_scale);
	m_boardModel.Update();

	srand(static_cast<unsigned int>(time(nullptr)));

	//キャラクターコントローラーの初期化
	characterController.Init(25.0f, 75.0f, position);
}	


	Player::~Player() {
	}

void Player::Update()
{

	//モデルを更新する
	m_bgmodelRender.Update();
	m_boardModel.Update();

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
	right *= stickL.x * 1440.0f;
	forward *= stickL.y * 1440.0f;

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
	m_boardModel.SetPosition(position);
}

void Player::Rotation() 
{
	
	//xかｚの移動速度があったら(スティックの入力があったら)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//キャラコンの方向を変える
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える
		//m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
		m_bgmodelRender.Draw(renderContext);
		m_boardModel.Draw(renderContext);
}