#include "stdafx.h"
#include "Player.h"
#include "WindZone.h"
#include "Game.h"
#include "GameCamera.h"
#include "k2EngineLow.h"

Player::Player()
{

	// 待機のアニメーション
	m_animationClips[enAnimationClip_Idle].Load("Assets/anim/skater/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_boardAnimClips[enAnimationClip_Idle].Load("Assets/anim/board/idle.tka");
	m_boardAnimClips[enAnimationClip_Idle].SetLoopFlag(true);

	// スタートランのアニメーション
	m_animationClips[enAnimationClip_Start].Load("Assets/anim/skater/start.tka");
	m_animationClips[enAnimationClip_Start].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Start].Load("Assets/anim/board/start.tka");
	m_boardAnimClips[enAnimationClip_Start].SetLoopFlag(false);

	// 地面を蹴る時のアニメーション
	m_animationClips[enAnimationClip_Push].Load("Assets/anim/skater/push.tka");
	m_animationClips[enAnimationClip_Push].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Push].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Push].SetLoopFlag(false);

	// 走っている時のアニメーション
	m_animationClips[enAnimationClip_Run].Load("Assets/anim/skater/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Run].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Run].SetLoopFlag(false);

	// ドリフトする時のアニメーション
	m_animationClips[enAnimationClip_Drift].Load("Assets/anim/skater/drift.tka");
	m_animationClips[enAnimationClip_Drift].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Drift].Load("Assets/anim/board/drift.tka");
	m_boardAnimClips[enAnimationClip_Drift].SetLoopFlag(false);

	// プレイヤーモデルの初期化
	m_bgmodelRender.Init("Assets/ModelData/player/player.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	m_bgmodelRender.SetPosition(m_position);
	rotation.SetRotationDegY(180.0f); // 初期回転を90度に設定
	m_bgmodelRender.SetRotation(rotation); // ここで計算した最終的な回転を適用
	m_bgmodelRender.SetScale(m_scale);
	m_bgmodelRender.Update();

	//ボードモデルの初期化
	m_boardModel.Init("Assets/ModelData/player/board.tkm",m_boardAnimClips, enAnimationClip_Num, enModelUpAxisZ);//YからZにしたら立つ
	m_boardModel.SetPosition(m_position);
	rotation.SetRotationDegY(180.0f); // 初期回転を180度に設定
	m_boardModel.SetRotation(rotation); // 同じ回転を適用
	m_boardModel.SetScale(m_scale);
	m_boardModel.Update();

	srand(static_cast<unsigned int>(time(nullptr)));

	// キャラクターコントローラーの初期化
	m_characterController.Init(25.0f, 75.0f, m_position);

	// 初期ステートを待機状態に設定
	m_currentState = enPlayerState_InitialWait;
	// タイマーを初期化
	m_waitTimer = 0.0f;
}	


Player::~Player() {
	
}

void Player::Update()
{
	if (m_currentState == enPlayerState_InitialWait) {
		m_waitTimer += g_gameTime->GetFrameDeltaTime(); // 時間を進める
		if (m_waitTimer >= 3.0f) { // 3秒経過したら
			m_currentState = enPlayerState_Run; // アイドル状態に移行
			// 必要であれば、ここでプレイヤーの自動進行などを開始する処理を記述
		}
		// 待機中は、モデルの更新とアニメーションの再生は行うが、
		// 移動、回転、キー入力などのロジックはスキップする
		m_bgmodelRender.Update();
		m_boardModel.Update();
		PlayAnimation(); // アニメーションは待機状態のアニメーションを再生
		return; // これ以降の処理は行わない
	}

	//モデルを更新する
	m_bgmodelRender.Update();
	m_boardModel.Update();

	//移動処理
	Move();
	//回転処理
	Rotation();

	//ステート管理。
	ManageState();

	//アニメーションの再生。
	PlayAnimation();

	//もしプレイヤーがY-500以下なら
	if (m_position.y <= -500.0f)
	{
		//プレイヤーカウントを2にする
		P_Count = 2;
		//position.y = 0.0f;
	}
	//もしプレイヤーがZ-17500を超えたら
	else if (m_position.z <= -17500.0f) {
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
	if (m_currentState == enPlayerState_InitialWait) {
		// moveSpeedをリセットして、完全に停止させる
		moveSpeed = Vector3::Zero;
		// キャラクターコントローラーを更新して現在位置を維持（重力もかからないようにする）
		m_characterController.Execute(moveSpeed, 1.0f / 60.0f);
		m_bgmodelRender.SetPosition(m_position); // モデルの位置も更新しておく
		m_boardModel.SetPosition(m_position);
		return;
	}
	//xzの移動速度を1000.0fにする
	moveSpeed.x = 0.0f;
	moveSpeed.z = -200.0f;

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
	right *= stickL.x * 520.0f;
	//forward *= stickL.y * 1000.0f;

	//移動速度にスティックの入力量を加算する
	moveSpeed += right + forward;

	//地面に付いていたら
	if (m_characterController.IsOnGround())
	{
		//重力をなくす
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる
			moveSpeed.y += 500.0f;
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
	m_position = m_characterController.Execute(moveSpeed, 1.0f / 45.0f);

	//絵描きさんに座標を教える
	m_bgmodelRender.SetPosition(m_position);
	m_boardModel.SetPosition(m_position);
}

void Player::Rotation() 
{
	// 待機ステート中は回転しない
	if (m_currentState == enPlayerState_InitialWait) {
		return;
	}
	
	//xかｚの移動速度があったら(スティックの入力があったら)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//キャラコンの方向を変える
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える
		//m_bgmodelRender.SetRotation(rotation);
	}
}

//ステート管理。
void Player::ManageState()
{
	// 待機ステート中は、キー入力によるステート変更を無効にする
	if (m_currentState == enPlayerState_InitialWait) {
		return;
	}
	if (g_pad[0]->IsTrigger(enButtonB))//Bボタンを押したら
	{
		//ステートを1(スタート)にする。
		m_currentState = enPlayerState_Start;
		//ここでManageStateの関数の処理を終わらせる。
		return;
	}

	//地面に付いていたら。
	//xかzの移動速度があったら(スティックの入力があったら)。
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//ステートを2(走る)にする。
		m_currentState = enPlayerState_Run;

		return;
	}

	//m_currentState = enPlayerState_Run;
}

//アニメーションの再生。
void Player::PlayAnimation()
{
	switch (m_currentState) {
		//プレイヤーステートが初期待機状態の時
	case enPlayerState_InitialWait:
		m_bgmodelRender.PlayAnimation(enAnimationClip_Idle);
		m_boardModel.PlayAnimation(enAnimationClip_Idle);
		break;
		//プレイヤーステートが0(待機中)の時
	case enPlayerState_Idle:
		//待機のアニメーションを再生する。
		m_bgmodelRender.PlayAnimation(enAnimationClip_Idle);
		m_boardModel.PlayAnimation(enAnimationClip_Idle);
		break;
		//プレイヤーステートが1(スタート)の時
	case enPlayerState_Start:
		//スタートのアニメーションを再生する。
		m_bgmodelRender.PlayAnimation(enAnimationClip_Start);
		m_boardModel.PlayAnimation(enAnimationClip_Start);
		break;
		//プレイヤーステートが2(歩き)の時
	case enPlayerState_Run:
		//歩きのアニメーションを再生する。
		m_bgmodelRender.PlayAnimation(enAnimationClip_Run);
		m_boardModel.PlayAnimation(enAnimationClip_Run);
		break;
		//プレイヤーステートが3(ドリフト)の時
	case enPlayerState_Drift:
		//ドリフトのアニメーションを再生する。
		m_bgmodelRender.PlayAnimation(enAnimationClip_Drift);
		m_boardModel.PlayAnimation(enAnimationClip_Drift);
		break;
	}
}

void Player::Render(RenderContext & renderContext)
{
		m_bgmodelRender.Draw(renderContext);
		m_boardModel.Draw(renderContext);
}