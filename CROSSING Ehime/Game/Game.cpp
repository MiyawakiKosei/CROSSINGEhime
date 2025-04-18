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

	m_GameUI = NewGO<GameUI>(0, "game_ui");


	////Starクラスのオブジェクトを作る。
	//Star* star1 = NewGO<Star>(0, "star");
	//star1->position = { 100.0f,150.0f,-200.0f };
	//star1->firstPosition = star1->position;

	//Star* star2 = NewGO<Star>(0, "star");
	//star2->position = { 1000.0f,150.0f,-200.0f };
	//star2->firstPosition = star2->position;

	//Star* star3 = NewGO<Star>(0, "star");
	//star3->position = { 100.0f,250.0f,400.0f };
	//star3->firstPosition = star3->position;

	//Star* star4 = NewGO<Star>(0, "star");
	//star4->position = { 2300.0f,50.0f,-200.0f };
	//star4->firstPosition = star4->position;

	//Star* star5 = NewGO<Star>(0, "star");
	//star5->position = { 2700.0f,450.0f,400.0f };
	//star5->firstPosition = star5->position;

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
}

//更新処理。
void Game::Update()
{
	
	switch (GameCount)//ループ判定
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
