#include "stdafx.h"
#include "Player.h"
#include "Timer.h"

Player::Player()
{
    //モデルを初期化する。
    m_bgmodelRender.Init("Assets/modelData/Kate.tkm");
    //↑                    //スペルミスに注意!!
    //ここも大文字のi
	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	//アニメーションクリップをロードする。
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	//ユニティちゃんのモデルを読み込む。
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//キャラコンを初期化する。
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	//position.x += 10.0f;の10の値を変更して移動速度を決める
	//if (GetAsyncKeyState('D') & 0x8000)
	//{
	//	position.x += 100.0f;//右に動く
	//}
	//if (GetAsyncKeyState('A') & 0x8000)
	//{
	//	position.x -= 100.0f;//左に動く
	//}
	//if (GetAsyncKeyState('W') & 0x8000)
	//{
	//	position.z += 100.0f;//前に動く
	//}
	//if (GetAsyncKeyState('S') & 0x8000)
	//{
	//	position.z -= 100.0f;//後ろに動く
	//}
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	//VK_はVirtual Key(仮想キー)
	//	//「人間が押す物理キー」を
	//	//「PCがわかる数字(コード)」にしたもの
	//	//0x8000は"「そのキーが今まさに押されているかどうか」をチェックするためのもの
	//{
	//	position.y += 10.0f;
	//}
	//if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	//{
	//	position.y -= 10.0f;
	//}
	//シフトを押したら下がる
	//モデルを更新する。
	m_bgmodelRender.Update();
	//絵描きさんの更新処理。
	m_bgmodelRender.SetPosition(position);

	//移動処理
	Move();

	//回転処理
	Rotation();

	//position.y -= 5.5f;//重力

	if (position.y <= -500.0f)
	{
		P_Count = 2;
		//position.y = 0.0f;//y座標が0以下なら0にする
	}
	else if (position.z <= -17500.0f) {
		P_Count = 1;
	}
}

//void Player::SetPosition(const Vector3& pos)
//{
//	position = pos;               //プレイヤーの論理位置を保存
//	m_bgmodelRender.SetPosition(pos); //見た目にも反映！
//}

void  Player::Move() 
{
	//xzの移動速度を0.0fにする。
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//左スティックの入力量を取得。
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの前方向と右方向のベクトルを持ってくる。
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y方向には移動させない。
	forward.y = 0.0f;
	right.y = 0.0f;

	//左スティックの入力量と120.0fを乗算。
	right *= stickL.x * 1920.0f;
	forward *= stickL.y * 1920.0f;

	//移動速度にスティックの入力量を加算する。
	moveSpeed += right + forward;

	//地面に付いていたら。
	if (characterController.IsOnGround())
	{
		//重力を無くす。
		moveSpeed.y = 0.0f;
		//Aボタンが押されたら。
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//ジャンプさせる。
			moveSpeed.y += 1040.0f;
		}
	}
	//地面に付いていなかったら。
	else
	{
		//重力を発生させる。
		moveSpeed.y -= 15.0f;
	}

	//キャラクターコントローラーを使って座標を移動させる。
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//絵描きさんに座標を教える。
	m_bgmodelRender.SetPosition(position);
}

void Player::Rotation() 
{
	//xかzの移動速度があったら（スティックの入力があったら）
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//キャラクターの方向を変える
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//絵描きさんに回転を教える
		m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
		m_bgmodelRender.Draw(renderContext);
}