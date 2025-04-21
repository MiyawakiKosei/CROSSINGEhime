#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    //���f��������������B
    m_bgmodelRender.Init("Assets/modelData/Kate.tkm");
    //��                    //�X�y���~�X�ɒ���!!
    //�������啶����i
	SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	//�A�j���[�V�����N���b�v�����[�h����B
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	//���j�e�B�����̃��f����ǂݍ��ށB
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R��������������B
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	//position.x += 10.0f;��10�̒l��ύX���Ĉړ����x�����߂�
	if (GetAsyncKeyState('D') & 0x8000)
	{
		position.x += 100.0f;//�E�ɓ���
	}
	if (GetAsyncKeyState('A') & 0x8000)
	{
		position.x -= 100.0f;//���ɓ���
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		position.z += 100.0f;//�O�ɓ���
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		position.z -= 100.0f;//���ɓ���
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		//VK_��Virtual Key(���z�L�[)
		//�u�l�Ԃ����������L�[�v��
		//�uPC���킩�鐔��(�R�[�h)�v�ɂ�������
		//0x8000��"�u���̃L�[�����܂��ɉ�����Ă��邩�ǂ����v���`�F�b�N���邽�߂̂���
	{
		position.y += 10.0f;
	}
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		position.y -= 10.0f;
	}
	//�V�t�g���������牺����
	//���f�����X�V����B
	m_bgmodelRender.Update();
	//�G�`������̍X�V�����B
	m_bgmodelRender.SetPosition(position);

	//position.y -= 5.5f;//�d��

	if (position.y <= 0.0f)
	{
		position.y = 0.0f;//y���W��0�ȉ��Ȃ�0�ɂ���
	}
}

void Player::SetPosition(const Vector3& pos)
{
	position = pos;               //�v���C���[�̘_���ʒu��ۑ�
	m_bgmodelRender.SetPosition(pos); //�����ڂɂ����f�I
}

void Player::Render(RenderContext& renderContext)
{
		m_bgmodelRender.Draw(renderContext);
}