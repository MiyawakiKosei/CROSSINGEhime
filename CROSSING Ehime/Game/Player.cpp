#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    //���f��������������B
    modelRender.Init("Assets/modelData/Kate.tkm");
    //��                    //�X�y���~�X�ɒ���!!
    //�������啶����i
	//�A�j���[�V�����N���b�v�����[�h����B
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	//���j�e�B�����̃��f����ǂݍ��ށB
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	modelRender.Init("Assets/modelData/Kate.tkm", nullptr, 0, enModelUpAxisY);//�����搶�ɂ��ꎞ�I���u

	//�L�����R��������������B
	//characterController.Init(25.0f, 75.0f, position);//
}

Player::~Player()
{

}

void Player::Update()
{
    //���f�����X�V����B
    modelRender.Update();
	position = Vector3(0.0f, 0.0f, 0.0f);

    modelRender.SetPosition(position);

    modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
    //���f����\������B
    modelRender.Draw(renderContext);
}