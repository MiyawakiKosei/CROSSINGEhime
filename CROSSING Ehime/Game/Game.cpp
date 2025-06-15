#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Title.h"
#include "GameUI.h"
#include "GameSelect.h"
#include "Debugfont.h"
#include "WindZone.h"
#include "Orange.h"
#include "Track.h"
#include "sound/SoundEngine.h"
#include "Cone.h";



Game::Game()
{
	//�v���C���[�̃I�u�W�F�N�g����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g����B
	gameCamera = NewGO<GameCamera>(0, "gameCamera");

	//�w�i�̃I�u�W�F�N�g����B
	backGround = NewGO<BackGround>(0);

	//UI����
	m_GameUI = NewGO<GameUI>(0, "game_ui");

	//�I�����W����
	m_Orange = NewGO<Orange>(0, "orange");
	m_Orange->position = { 0.0f,0.0f,-1000.0f };

	//�I�����W2����
	m_rightOrange = NewGO<Orange>(0, "orange2");
	m_rightOrange->position = { 150.0f,0.0f,-6000.0f };

	//�I�����W3����
	m_leftOrange = NewGO<Orange>(0, "orange3");
	m_leftOrange->position = { -300.0f,0.0f,-10000.0f };

	//�I�����W�S����
	m_middleOrange = NewGO<Orange>(0, "orange4");
	m_middleOrange->position = { 0.0f,0.0f,-13000.0f };

	//�g���b�N����
	m_rightTrack = NewGO<Track>(0, "track");
	m_rightTrack->m_position = { 150.0f,30.0f,-1000.0f };

	//�g���b�N2����
	m_leftTrack= NewGO<Track>(0, "track2");
	m_leftTrack->m_position = { -300.0f,30.0f,-1000.0f };

	m_windZone = NewGO<WindZone>(0, "windZone");
	m_windZone->SetPlayer(player);
	m_windZone->SetTimer(m_timer);

	//�Q�[������BGM��ǂݍ��ށB
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/GameBGM_Play.wav");
	//�Q�[������BGM��Đ�����
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	GameBGM->Play(true);

}

Game::~Game()
{
	//�v���C���[��폜����B
	DeleteGO(player);
	//�Q�[���J������폜����B
	DeleteGO(gameCamera);
	//�Q�[������BGM��폜����B
	DeleteGO(GameBGM);
	//�w�i��폜����B
	DeleteGO(backGround);
	//UI�̍폜
	DeleteGO(m_GameUI);

	//���̍폜
	DeleteGO(m_windZone);
	//�I�����W�̏���
	DeleteGO(m_Orange);
	//�I�����W2�̏���
	DeleteGO(m_rightOrange);
	//�I�����W3�̏���
	DeleteGO(m_leftOrange);
	//�I�����W4�̏���
	DeleteGO(m_middleOrange);
	//�g���b�N�̏���
	DeleteGO(m_rightTrack);
	//�g���b�N2�̏���
	DeleteGO(m_leftTrack);
	//�R�[���̏���
	DeleteGO(m_cone);
}

//�X�V�����B
void Game::Update()
{
	static bool started = false;
	if (!started)
	{
		m_GameUI->StartStartCountDown();
		started = true;
	}

	// �X�^�[�g�J�E���g�_�E�����̓v���C���[�ƃJ�E���g�_�E����~
	if (m_GameUI->IsStartCountingDown())
	{
		// �J�E���g�_�E���X�V�̂�
		m_GameUI->Update();
		return;  // �v���C���[��Update��Q�[���i�s�̓X�g�b�v
	}

	switch (player->P_Count) // ���[�v����
	{
	case 1: // �Q�[���N���A
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2: // �Q�[���I�[�o�[
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
		break;
	default:
		break;
	}
}





//�`�揈��
void Game::Render(RenderContext& rc) 
{

}