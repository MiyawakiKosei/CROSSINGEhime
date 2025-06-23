#include "stdafx.h"
#include "Player.h"
#include "WindZone.h"
#include "Game.h"
#include "GameCamera.h"
#include "k2EngineLow.h"

Player::Player()
{

	// �ҋ@�̃A�j���[�V����
	m_animationClips[enAnimationClip_Idle].Load("Assets/anim/skater/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_boardAnimClips[enAnimationClip_Idle].Load("Assets/anim/board/idle.tka");
	m_boardAnimClips[enAnimationClip_Idle].SetLoopFlag(true);

	// �X�^�[�g�����̃A�j���[�V����
	m_animationClips[enAnimationClip_Start].Load("Assets/anim/skater/start.tka");
	m_animationClips[enAnimationClip_Start].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Start].Load("Assets/anim/board/start.tka");
	m_boardAnimClips[enAnimationClip_Start].SetLoopFlag(false);

	// �n�ʂ��R�鎞�̃A�j���[�V����
	m_animationClips[enAnimationClip_Push].Load("Assets/anim/skater/push.tka");
	m_animationClips[enAnimationClip_Push].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Push].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Push].SetLoopFlag(false);

	// �����Ă��鎞�̃A�j���[�V����
	m_animationClips[enAnimationClip_Run].Load("Assets/anim/skater/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Run].Load("Assets/anim/board/push.tka");
	m_boardAnimClips[enAnimationClip_Run].SetLoopFlag(false);

	// �h���t�g���鎞�̃A�j���[�V����
	m_animationClips[enAnimationClip_Drift].Load("Assets/anim/skater/drift.tka");
	m_animationClips[enAnimationClip_Drift].SetLoopFlag(false);
	m_boardAnimClips[enAnimationClip_Drift].Load("Assets/anim/board/drift.tka");
	m_boardAnimClips[enAnimationClip_Drift].SetLoopFlag(false);

	// �v���C���[���f���̏�����
	m_bgmodelRender.Init("Assets/ModelData/player/player.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisZ);
	m_bgmodelRender.SetPosition(m_position);
	rotation.SetRotationDegY(180.0f); // ������]��90�x�ɐݒ�
	m_bgmodelRender.SetRotation(rotation); // �����Ōv�Z�����ŏI�I�ȉ�]��K�p
	m_bgmodelRender.SetScale(m_scale);
	m_bgmodelRender.Update();

	//�{�[�h���f���̏�����
	m_boardModel.Init("Assets/ModelData/player/board.tkm",m_boardAnimClips, enAnimationClip_Num, enModelUpAxisZ);//Y����Z�ɂ����痧��
	m_boardModel.SetPosition(m_position);
	rotation.SetRotationDegY(180.0f); // ������]��180�x�ɐݒ�
	m_boardModel.SetRotation(rotation); // ������]��K�p
	m_boardModel.SetScale(m_scale);
	m_boardModel.Update();

	srand(static_cast<unsigned int>(time(nullptr)));

	// �L�����N�^�[�R���g���[���[�̏�����
	m_characterController.Init(25.0f, 75.0f, m_position);
}	


Player::~Player() {
	
}

void Player::Update()
{
	// �Q�[���J�n����̎��Ԃ��X�V
	m_gameStartTime += g_gameTime->GetFrameDeltaTime();

	// 5�b�o�߂�����v���C���[�𑀍�\�ɂ���
	if (!m_isPlayerControllable && m_gameStartTime >= INITIAL_WAIT_TIME) {
		m_isPlayerControllable = true;
		playerState = enAnimationClip_Idle;
	}

	//���f�����X�V����
	m_bgmodelRender.Update();
	m_boardModel.Update();

	//�ړ�����
	Move();
	//��]����
	Rotation();

	//�X�e�[�g�Ǘ��B
	ManageState();

	//�A�j���[�V�����̍Đ��B
	PlayAnimation();

	//�����v���C���[��Y-500�ȉ��Ȃ�
	if (m_position.y <= -500.0f)
	{
		//�v���C���[�J�E���g��2�ɂ���
		P_Count = 2;
		//position.y = 0.0f;
	}
	//�����v���C���[��Z-17500�𒴂�����
	else if (m_position.z <= -17500.0f) {
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
	//xz�̈ړ����x��1000.0f�ɂ���
	moveSpeed.x = 0.0f;
	moveSpeed.z = -200.0f;

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
	right *= stickL.x * 520.0f;
	//forward *= stickL.y * 1000.0f;

	//�ړ����x�ɃX�e�B�b�N�̓��͗ʂ����Z����
	moveSpeed += right + forward;

	//�n�ʂɕt���Ă�����
	if (m_characterController.IsOnGround())
	{
		//�d�͂��Ȃ���
		moveSpeed.y = 0.0f;
		//A�{�^���������ꂽ��
		if (g_pad[0]->IsTrigger(enButtonA))
		{
			//�W�����v������
			moveSpeed.y += 460.0f;
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
	m_position = m_characterController.Execute(moveSpeed, 1.0f / 45.0f);

	//�G�`������ɍ��W��������
	m_bgmodelRender.SetPosition(m_position);
	m_boardModel.SetPosition(m_position);
}

void Player::Rotation() 
{
	
	//x�����̈ړ����x����������(�X�e�B�b�N�̓��͂���������)
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f) {
		//�L�����R���̕�����ς���
		rotation.SetRotationYFromDirectionXZ(moveSpeed);
		//�G�`������ɉ�]��������
		//m_bgmodelRender.SetRotation(rotation);
	}
}

//�X�e�[�g�Ǘ��B
void Player::ManageState()
{
	if (g_pad[0]->IsTrigger(enButtonB))//B�{�^������������
	{
		//�X�e�[�g��1(�X�^�[�g)�ɂ���B
		playerState = 1;
		//������ManageState�̊֐��̏������I��点��B
		return;
	}

	//�n�ʂɕt���Ă�����B
	//x��z�̈ړ����x����������(�X�e�B�b�N�̓��͂���������)�B
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//�X�e�[�g��2(����)�ɂ���B
		playerState = 2;

		return;
	}
}

//�A�j���[�V�����̍Đ��B
void Player::PlayAnimation()
{
	switch (playerState) {
		//�v���C���[�X�e�[�g��0(�ҋ@��)�̎�
	case 0:
		//�ҋ@�̃A�j���[�V�������Đ�����B
		m_bgmodelRender.PlayAnimation(enAnimationClip_Idle);
		m_boardModel.PlayAnimation(enAnimationClip_Idle);
		break;
		//�v���C���[�X�e�[�g��1(�X�^�[�g)�̎�
	case 1:
		//�X�^�[�g�̃A�j���[�V�������Đ�����B
		m_bgmodelRender.PlayAnimation(enAnimationClip_Start);
		m_boardModel.PlayAnimation(enAnimationClip_Start);
		break;
		//�v���C���[�X�e�[�g��2(����)�̎�
	case 2:
		//�����̃A�j���[�V�������Đ�����B
		m_bgmodelRender.PlayAnimation(enAnimationClip_Run);
		m_boardModel.PlayAnimation(enAnimationClip_Run);
		break;
		//�v���C���[�X�e�[�g��3(�h���t�g)�̎�
	case 3:
		//�h���t�g�̃A�j���[�V�������Đ�����B
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