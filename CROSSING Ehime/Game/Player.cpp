#include "stdafx.h"
#include "Player.h"
#include "Timer.h"

Player::Player()
{
    //���f�������������B
    m_bgmodelRender.Init("Assets/modelData/Kate.tkm");
    //��                    //�X�y���~�X�ɒ���!!
    //������啶����i
	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	//�A�j���[�V�����N���b�v����[�h����B
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	//���j�e�B�����̃��f����ǂݍ��ށB
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R�������������B
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	//position.x += 10.0f;��10�̒l��ύX���Ĉړ����x����߂�
	//if (GetAsyncKeyState('D') & 0x8000)
	//{
	//	position.x += 100.0f;//�E�ɓ���
	//}
	//if (GetAsyncKeyState('A') & 0x8000)
	//{
	//	position.x -= 100.0f;//���ɓ���
	//}
	//if (GetAsyncKeyState('W') & 0x8000)
	//{
	//	position.z += 100.0f;//�O�ɓ���
	//}
	//if (GetAsyncKeyState('S') & 0x8000)
	//{
	//	position.z -= 100.0f;//���ɓ���
	//}
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	//VK_��Virtual Key(���z�L�[)
	//	//�u�l�Ԃ����������L�[�v��
	//	//�uPC���킩�鐔��(�R�[�h)�v�ɂ������
	//	//0x8000��"�u���̃L�[�����܂��ɉ�����Ă��邩�ǂ����v��`�F�b�N���邽�߂̂��
	//{
	//	position.y += 10.0f;
	//}
	//if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	//{
	//	position.y -= 10.0f;
	//}
	//�V�t�g��������牺����
	//���f����X�V����B
	m_bgmodelRender.Update();
	//�G�`������̍X�V�����B
	m_bgmodelRender.SetPosition(position);

	//�ړ�����
	Move();

	//��]����
	Rotation();

	//position.y -= 5.5f;//�d��

	if (position.y <= -500.0f)
	{
		P_Count = 2;
		//position.y = 0.0f;//y���W��0�ȉ��Ȃ�0�ɂ���
	}
	else if (position.z <= -17500.0f) {
		P_Count = 1;
	}
}

//void Player::SetPosition(const Vector3& pos)
//{
//	position = pos;               //�v���C���[�̘_���ʒu��ۑ�
//	m_bgmodelRender.SetPosition(pos); //�����ڂɂ���f�I
//}

void  Player::Move() 
{
	//xz�̈ړ����x��0.0f�ɂ���B
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�擾�B
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g��������Ă���B
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y�����ɂ͈ړ������Ȃ��B
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�120.0f���Z�B
	right *= stickL.x * 1255.0f;
	forward *= stickL.y * 1255.0f;
	right *= stickL.x * 1920.0f;
	forward *= stickL.y * 1920.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ���Z����B
	moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����B
	if (characterController.IsOnGround())
	{
		//�d�͂𖳂����B
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��B
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������B
			moveSpeed.y += 520.0f;
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������B
	else
	{
		//�d�͂𔭐�������B
		moveSpeed.y -= 15.0f;
	}

	//�L�����N�^�[�R���g���[���[��g���č��W��ړ�������B
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W�������B
	m_bgmodelRender.SetPosition(position);
}

void Player::Rotation() 
{
	//x��z�̈ړ����x����������i�X�e�B�b�N�̓��͂���������j
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//�L�����N�^�[�̕�����ς���
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]�������
		m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
		m_bgmodelRender.Draw(renderContext);
}