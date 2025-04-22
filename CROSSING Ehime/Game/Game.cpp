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
//#include "Star.h"
//#include "sound/SoundEngine.h"
//#include "GameClear.h"


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

	//タイマーを作る
	m_timer = NewGO<Timer>(0, "timer");
	fontRender.SetPosition({ -600.0f,100.0f,0.0f });

	////ゲーム中のBGMを読み込む。
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	////ゲーム中のBGMを再生する
	//GameBGM = NewGO<SoundSource>(0);
	//GameBGM->Init(1);
	//GameBGM->Play(true);

}

Game::~Game()
{
	//プレイヤーを削除する。
	DeleteGO(player);
	//ゲームカメラを削除する。
	DeleteGO(gameCamera);
	//ゲーム中のBGMを削除する。
	//DeleteGO(GameBGM);
	//背景を削除する。
	DeleteGO(backGround);
	//UIの削除
	DeleteGO(m_GameUI);
	//タイマーの削除
	DeleteGO(m_Timer);
}

//更新処理。
void Game::Update()
{
	
	switch (m_timer->GameCount)//ループ判定
	{
	case 1://ゲームクリア
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2://ゲームオーバー
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
