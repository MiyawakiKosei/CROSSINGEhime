#pragma once
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Timer;
class GameClear;
class GameOver;
class Title;
class GameUI;

//Game�V�[�����Ǘ�����N���X�B
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//�X�V�����B
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	Player* player;			 //�v���C���[�B
	GameCamera* gameCamera;	 //�Q�[���J�����B
	BackGround* backGround;  //�w�i
	//SoundSource* GameBGM;  //�Q�[������BGM�B
	FontRender fontRender;   //����
	Timer* m_Timer;          //�^�C�}�[
	GameClear* m_gameClear;    //�Q�[���N���A
	GameOver* m_gameOver;
	Title* m_title;            //�^�C�g��
	GameUI* m_GameUI;        //�Q�[��UI

	int GameCount = 0;//���[�v�p
};
