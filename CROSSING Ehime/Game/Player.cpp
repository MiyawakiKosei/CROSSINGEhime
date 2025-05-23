#include "stdafx.h"
#include "Player.h"
#include "Timer.h"
#include "WindZone.h"
#include "Skateboarding.h"
#include "Game.h"
#include "GameCamera.h"

Player::Player()
{
	//���f���f�[�^�ǂݍ���
    //m_bgmodelRender.Init("Assets/model/player.tkm");
	rotation.SetRotationDegY(180.0f);
	m_bgmodelRender.SetRotation(rotation);//�X�e�[�W�̕��ɐi�ނ悤�Ƀv���C���[�̌����𒲐�
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
	moveSpeed.x += windPower;
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
		m_bgmodelRender.Draw(renderContext);
}