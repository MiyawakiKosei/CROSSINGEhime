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
	//プレイヤーのオブジェクトを作る。
	player = NewGO<Player>(0, "player");

	//ゲームカメラのオブジェクトを作る。
	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	//背景のオブジェクトを作る。
	backGround = NewGO<BackGround>(0);

	//タイマーの実装
	m_Timer = NewGO<Timer>(0, "m_timer");
	fontRender.SetPosition({ -600.0f,100.0f,0.0f });
	fontRender.SetScale(2.0f);

	////ゲーム中のBGMを読み込む。
	//g_soundEngine->ResistWaveFileBank(1, "Assets/sound/gamebgm.wav");
	////ゲーム中のBGMを再生する
	//GameBGM = NewGO<SoundSource>(0);
	//GameBGM->Init(1);
	//GameBGM->Play(true);

}

Game::~Game()
{
	////プレイヤーを削除する。
	//DeleteGO(player);
	////ゲームカメラを削除する。
	//DeleteGO(gameCamera);
	////ゲーム中のBGMを削除する。
	//DeleteGO(GameBGM);
	////背景を削除する。
	//DeleteGO(backGround);
}

//更新処理。
void Game::Update()
{
	//プレイヤーの☆カウントが5(☆が全部削除された)になったら。
	//if (player->starCount == 5)
	//{
	//	//ゲームクリアのオブジェクトを作る。
	//	NewGO<GameClear>(0, "gameclear");
	//	//自身を削除する。
	//	DeleteGO(this);
	//}
}
