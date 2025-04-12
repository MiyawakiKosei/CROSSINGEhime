#pragma once
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Timer;

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();

	Player* player;			 //�v���C���[�B
	GameCamera* gameCamera;	 //�Q�[���J�����B
	BackGround* backGround;  //�w�i
	//SoundSource* GameBGM;  //�Q�[������BGM�B
	FontRender fontRender;   //����
	Timer* m_Timer;          //�^�C�}�[
};
