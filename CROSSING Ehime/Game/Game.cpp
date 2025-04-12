#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "GameCamera.h"
#include "BackGround.h"
#include "Timer.h"
//#include "Star.h"
//#include "sound/SoundEngine.h"
//#include "GameClear.h"


Game::Game()
{
	//�v���C���[�̃I�u�W�F�N�g�����B
	player = NewGO<Player>(0, "player");

	//�Q�[���J�����̃I�u�W�F�N�g�����B
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//�w�i�̃I�u�W�F�N�g�����B
	backGround = NewGO<BackGround>(0);

	//�^�C�}�[�̎���
	m_Timer = NewGO<Timer>(0, "m_timer");
	fontRender.SetPosition({ -600.0f,100.0f,0.0f });
	fontRender.SetScale(2.0f);

	////�Q�[������BGM��ǂݍ��ށB
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	////�Q�[������BGM���Đ�����
	//GameBGM = NewGO<SoundSource>(0);
	//GameBGM->Init(1);
	//GameBGM->Play(true);

}

Game::~Game()
{
	////�v���C���[���폜����B
	//DeleteGO(player);
	////�Q�[���J�������폜����B
	//DeleteGO(gameCamera);
	////�Q�[������BGM���폜����B
	//DeleteGO(GameBGM);
	////�w�i���폜����B
	//DeleteGO(backGround);
}

//�X�V�����B
void Game::Update()
{
	//�v���C���[�́��J�E���g��5(�����S���폜���ꂽ)�ɂȂ�����B
	//if (player->starCount == 5)
	//{
	//	//�Q�[���N���A�̃I�u�W�F�N�g�����B
	//	NewGO<GameClear>(0, "gameclear");
	//	//���g���폜����B
	//	DeleteGO(this);
	//}
}
