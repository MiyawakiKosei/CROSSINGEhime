#pragma once
#include "sound/SoundSource.h"
#include "DebugFont.h"
extern DebugFont g_debugFont;

class Player;
class GameCamera;
class BackGround;
class Timer;
class GameClear;
class GameOver;
class Title;
class GameUI;
class GameSelect;
class Orenge;
class Track;
class WindZone;

//Game�V�[����Ǘ�����N���X�B
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
	ModelRender modelRender;
	Timer* m_Timer;          //�^�C�}�[
	GameClear* m_gameClear;    //�Q�[���N���A
	GameOver* m_gameOver;
	Title* m_title;            //�^�C�g��
	GameUI* m_GameUI;        //�Q�[��UI
	Timer* m_timer;
	GameSelect* m_gameSelect; //�Q�[���Z���N�g
	Orenge* m_orenge; //�I�����W�I�u�W�F�N�g
	Track* m_track;//トラック
	WindZone* m_windZone;     //���̗̈�

};
