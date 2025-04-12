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

	modelRender.Init("Assets/modelData/Kate.tkm", nullptr, 0, enModelUpAxisY);//清原先生による一時的処置

	//キャラコンを初期化する。
	//characterController.Init(25.0f, 75.0f, position);//
}

Player::~Player()
{

}

void Player::Update()
{
    //モデルを更新する。
    modelRender.Update();
	position = Vector3(0.0f, 0.0f, 0.0f);

    modelRender.SetPosition(position);

    modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
    //モデルを表示する。
    modelRender.Draw(renderContext);
}