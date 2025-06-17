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
	//Playerを生成
	player = NewGO<Player>(0, "player");

	//ゲームカメラの生成
	gameCamera = NewGO<GameCamera>(0, "gameCamera");

	//ステージの生成
	backGround = NewGO<BackGround>(0);

	//UIの生成
	m_GameUI = NewGO<GameUI>(0, "game_ui");

	CreateObject();//オレンジとトラックとコーンの生成

	m_windZone = NewGO<WindZone>(0, "windZone");
	m_windZone->SetPlayer(player);
	m_windZone->SetTimer(m_timer);

	//BGMの生成
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/GameBGM_Play.wav");
	//
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	GameBGM->Play(true);

}

Game::~Game()
{
	//playerの消去
	DeleteGO(player);
	//カメラの消去
	DeleteGO(gameCamera);
	//BGMの消去
	DeleteGO(GameBGM);
	//ステージの消去
	DeleteGO(backGround);
	//UIの消去
	DeleteGO(m_GameUI);
	//風の消去
	DeleteGO(m_windZone);
	//オレンジの消去
	DeleteGO(m_Orange);
	//オレンジ2の消去
	DeleteGO(m_rightOrange);
	//オレンジ3の消去
	DeleteGO(m_leftOrange);
	//オレンジ4の消去
	DeleteGO(m_middleOrange);
	//トラックの消去
	DeleteGO(m_rightTrack);
	//トラック2の消去
	DeleteGO(m_leftTrack);
	//コーンの消去
	DeleteGO(m_cone);
}

void Game::Update()
{
	static bool started = false;
	if (!started)
	{
		m_GameUI->StartStartCountDown();
		started = true;
	}

	// カウントダウン
	if (m_GameUI->IsStartCountingDown())
	{
		//UIの更新
		m_GameUI->Update();
		return;  
	}

	switch (player->P_Count) 
	{
	case 1: //１の時
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2: //２の時
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
		break;
	default:
		break;
	}
}


void Game::CreateObject() {
	//オレンジの生成
	m_Orange = NewGO<Orange>(0, "orange");
	m_Orange->m_orposition = { 0.0f,0.0f,-1000.0f };

	//オレンジ2の生成
	m_rightOrange = NewGO<Orange>(0, "orange2");
	m_rightOrange->m_orposition = { 150.0f,0.0f,-6000.0f };

	//オレンジ３の生成
	m_leftOrange = NewGO<Orange>(0, "orange3");
	m_leftOrange->m_orposition = { -300.0f,0.0f,-10000.0f };

	//オレンジ4の生成
	m_middleOrange = NewGO<Orange>(0, "orange4");
	m_middleOrange->m_orposition = { 0.0f,0.0f,-13000.0f };

	//トラックの生成
	m_rightTrack = NewGO<Track>(0, "track");
	m_rightTrack->m_trposition = { 150.0f,30.0f,-1000.0f };

	//トラック２の生成
	m_leftTrack = NewGO<Track>(0, "track2");
	m_leftTrack->m_trposition = { -300.0f,30.0f,-1000.0f };

	//コーンの生成
	m_cone = NewGO<Cone>(0, "cone");
	m_cone->m_cnposition = { 0.0f,-10.0f,-7000.0f };
}


//モデルレンダー
void Game::Render(RenderContext& rc) 
{

}