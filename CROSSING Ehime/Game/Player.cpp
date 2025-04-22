#include "stdafx.h"
#include "Player.h"
#include "Timer.h"

Player::Player()
{
	//���f���f�[�^�ǂݍ���
    m_bgmodelRender.Init("Assets/modelData/Kate.tkm");

	//SetPosition(Vector3(0.0f, 180.0f, -10000.0f));
	/*animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);*/
	// modelRender.Init("Assets/modelData/Kate.tkm", animationClips, enAnimationClip_Num, enModelUpAxisY);

	//�L�����R����������
	characterController.Init(25.0f, 75.0f, position);
}

Player::~Player()
{

}

void Player::Update()
{
	//position.x += 10.0f;
	//if (GetAsyncKeyState('D') & 0x8000)
	//{
	//	position.x += 100.0f;
	//}
	//if (GetAsyncKeyState('A') & 0x8000)
	//{
	//	position.x -= 100.0f;
	//}
	//if (GetAsyncKeyState('W') & 0x8000)
	//{
	//	position.z += 100.0f;
	//}
	//if (GetAsyncKeyState('S') & 0x8000)
	//{
	//	position.z -= 100.0f;
	//}
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	
	//{
	//	position.y += 10.0f;
	//}
	//if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	//{
	//	position.y -= 10.0f;
	//}

	//���f�����X�V����
	m_bgmodelRender.Update();
	//�G�`������
	m_bgmodelRender.SetPosition(position);

	//�ړ�����
	Move();
	//��]����
	Rotation();

	//position.y -= 5.5f;

	//�����v���C���[��Y-500�ȉ��Ȃ�
	if (position.y <= -500.0f)
	{
		//�v���C���[�J�E���g��2�ɂ���
		P_Count = 2;
		//position.y = 0.0f;
	}
	//�����v���C���[��Z-17500�𒴂�����
	else if (position.z <= -17500.0f) {
		//�v���C���[�J�E���g���P�ɂ���
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
	//xz�̈ړ����x��0.0f�ɂ���
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ��擾
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//�J�����̑O�����ƉE�����̃x�N�g���������Ă���
	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();
	//y�����ɂ͈ړ������Ȃ�
	forward.y = 0.0f;
	right.y = 0.0f;

	//���X�e�B�b�N�̓��͗ʂ�120.0f����Z
	right *= stickL.x * 1920.0f;
	forward *= stickL.y * 1920.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����
	moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����
	if (characterController.IsOnGround())
	{
		//�d�͂��Ȃ���
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������
			moveSpeed.y += 520.0f;
		}
	}
	//�n�ʂɕt���Ă��Ȃ�������
	else
	{
		//�d�͂𔭐�������
		moveSpeed.y -= 15.0f;
	}

	//�L�����N�^�[�R���g���[���[���g���č��W���ړ�������
	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);

	//�G�`������ɍ��W��������
	m_bgmodelRender.SetPosition(position);
}

void Player::Rotation() 
{
	//x�����̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//�L�����R���̕�����ς���
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������
		m_bgmodelRender.SetRotation(rotation);
	}
}

void Player::Render(RenderContext& renderContext)
{
	//���f����\��������
		m_bgmodelRender.Draw(renderContext);
}