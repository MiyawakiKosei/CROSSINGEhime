#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Timer.h"
#include "GameClear.h"
#include "GameOver.h"
#include "Title.h"
#include "GameUI.h"
#include "GameSelect.h"
#include "Debugfont.h"
#include "WindZone.h"
#include "Orenge.h"
//#include "Star.h"
//#include "sound/SoundEngine.h"



Game::Game()
{
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gameCamera");

	//�w�i�̃I�u�W�F�N�g�����B
	backGround = NewGO<BackGround>(0);

	//UI�����
	m_GameUI = NewGO<GameUI>(0, "game_ui");

	//�^�C�}�[�����
	m_timer = NewGO<Timer>(0, "timer");
	fontRender.SetPosition({ -600.0f,100.0f,0.0f });

	//�I�����W�����
	m_orenge = NewGO<Orenge>(0, "orenge");

	m_windZone = NewGO<WindZone>(0, "windZone");
	m_windZone->SetPlayer(player);
	m_windZone->SetTimer(m_timer);

	////�Q�[������BGM��ǂݍ��ށB
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	////�Q�[������BGM���Đ�����
	//GameBGM = NewGO<SoundSource>(0);
	//GameBGM->Init(1);
	//GameBGM->Play(true);

}

Game::~Game()
{
	//�v���C���[���폜����B
	DeleteGO(player);
	//�Q�[���J�������폜����B
	DeleteGO(gameCamera);
	//�Q�[������BGM���폜����B
	//DeleteGO(GameBGM);
	//�w�i���폜����B
	DeleteGO(backGround);
	//UI�̍폜
	DeleteGO(m_GameUI);
	//�^�C�}�[�̍폜
	DeleteGO(m_timer);
	//���̍폜
	DeleteGO(m_windZone);
	//�I�����W�̏���
	DeleteGO(m_orenge);
}

//�X�V�����B
void Game::Update()
{
	// �v���C���[���͈͂ɓ����Ă���ꍇ�ɕ��𔭐�������
	m_windZone->Update();
	
	switch (m_timer->T_Count)//���[�v����
	{
	case 1://�Q�[���N���A
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2://�Q�[���I�[�o�[
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
		break;
	default:
		break;
	}
		
	switch (player->P_Count)//���[�v����
	{
	case 1://�Q�[���N���A
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2://�Q�[���I�[�o�[
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
