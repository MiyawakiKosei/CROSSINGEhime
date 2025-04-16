#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    //モデルを初期化する。
    modelRender.Init("Assets/modelData/Kate.tkm");
    //↑                    //スペルミスに注意!!
    //ここも大文字のi
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

bool Player::Start()
{
	SetPosition(Vector3(0.0f, 180.0f, -10000.0f)); // ← 初期位置！

	return true;
}

Player::~Player()
{

}

void Player::Update()
{
	//position.x += 10.0f;の10の値を変更して移動速度を決める
	if (GetAsyncKeyState('D') & 0x8000)
	{
		position.x += 10.0f;//右に動く
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		position.x -= 10.0f;//左に動く
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		position.z += 10.0f;//前に動く
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		position.z -= 10.0f;//後ろに動く
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		//VK_はVirtual Key(仮想キー)
		//「人間が押す物理キー」を
		//「PCがわかる数字(コード)」にしたもの
		//0x8000は"「そのキーが今まさに押されているかどうか」をチェックするためのもの
	{
		position.y += 10.0f;
	}
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		position.y -= 10.0f;
	}
	//シフトを押したら下がる
    //モデルを更新する。
    modelRender.Update();

	modelRender.SetPosition(Vector3(position));

    modelRender.Update();
}

void Player::SetPosition(const Vector3& pos)
{
	position = pos;               //プレイヤーの論理位置を保存
	modelRender.SetPosition(pos); //見た目にも反映！
}

void Player::Render(RenderContext& renderContext)
{
		modelRender.Draw(renderContext);
}