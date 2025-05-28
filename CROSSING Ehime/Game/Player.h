#pragma once
#include "k2EngineLow.h"
#include <Track.h>

class WindZone;
//�v���C���[�N���X�B
class Player : public IGameObject
{
public:
	Player();
	~Player();
	//�X�V�����B
	void Update();

	//�`�揈���B
	void Render(RenderContext& rc);
	//�ړ�����
	void Move();
	//void SetPosition(const Vector3& pos);
	//��]����
	void Rotation();
	const Vector3& GetPosition() const
	{
		return m_position;
	}

	//�����o�ϐ��B
	float windPower = 0.0f;        // ���̋����i0.5f�Ȃǁj

	ModelRender m_bgmodelRender;	    //���f�������_�\�B
	ModelRender m_boardModel;	//�{�[�h���f���B
	Vector3 m_position;               //���W�B
	Vector3 moveSpeed;

	CharacterController& GetCharacterController()
	{
		return m_characterController;
	}
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Start,
		enAnimationClip_Push,
		enAnimationClip_Run,
		enAnimationClip_Drift,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];//�A�j���[�V�����N���b�v�B
	AnimationClip m_boardAnimClips[enAnimationClip_Num];//�{�[�h�̃A�j���[�V�����N���b�v�B
	
	//Vector3 moveSpeed;		//�ړ����x�B
	Quaternion rotX, rotY; //�N�H�[�^�j�I���B
	Quaternion rotation; //�N�H�[�^�j�I���B
	//int playerState = 0;	//�v���C���[�̃X�e�[�g(���)��\���ϐ��B
	//int starCount = 0;	//�W�߂����̐����J�E���g����B

	int P_Count = 0;
private:
	
	CharacterController m_characterController;  //�L�����N�^�[�R���g���[���[�B
	Vector3				m_scale = Vector3::One;
};
