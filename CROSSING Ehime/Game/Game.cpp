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



Game::Game()
{
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gameCamera");

	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0);

	//UIを作る
	m_GameUI = NewGO<GameUI>(0, "game_ui");

	//オレンジを作る
	m_Orange = NewGO<Orange>(0, "orange");
	m_Orange->position = { 0.0f,0.0f,-1000.0f };

	//オレンジ2を作る
	m_rightOrange = NewGO<Orange>(0, "orange2");
	m_rightOrange->position = { 150.0f,0.0f,-6000.0f };

	//オレンジ3を作る
	m_leftOrange = NewGO<Orange>(0, "orange3");
	m_leftOrange->position = { -300.0f,0.0f,-10000.0f };

	//オレンジ４を作る
	m_middleOrange = NewGO<Orange>(0, "orange4");
	m_middleOrange->position = { 0.0f,0.0f,-13000.0f };

	//トラックを作る
	m_rightTrack = NewGO<Track>(0, "track");
	m_rightTrack->m_position = { 150.0f,30.0f,-1000.0f };

	//トラック2を作る
	m_leftTrack= NewGO<Track>(0, "track2");
	m_leftTrack->m_position = { -300.0f,30.0f,-1000.0f };

	m_windZone = NewGO<WindZone>(0, "windZone");
	m_windZone->SetPlayer(player);
	m_windZone->SetTimer(m_timer);

	//ゲーム中のBGMを読み込む。
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/GameBGM_Play.wav");
	//ゲーム中のBGMを再生する
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	GameBGM->Play(true);

}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(player);
	//ゲームカメラを削除する。
	DeleteGO(gameCamera);
	//ゲーム中のBGMを削除する。
	DeleteGO(GameBGM);
	//背景を削除する。
	DeleteGO(backGround);
	//UIの削除
	DeleteGO(m_GameUI);

	//風の削除
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
}

//更新処理。
void Game::Update()
{
	static bool started = false;
	if (!started)
	{
		m_GameUI->StartStartCountDown();
		started = true;
	}

	// スタートカウントダウン中はプレイヤーとカウントダウン停止
	if (m_GameUI->IsStartCountingDown())
	{
		// カウントダウン更新のみ
		m_GameUI->Update();
		return;  // プレイヤーのUpdateやゲーム進行はストップ
	}

	switch (player->P_Count) // ループ判定
	{
	case 1: // ゲームクリア
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2: // ゲームオーバー
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
		break;
	default:
		break;
	}
}





//描画処理
void Game::Render(RenderContext& rc) 
{

}