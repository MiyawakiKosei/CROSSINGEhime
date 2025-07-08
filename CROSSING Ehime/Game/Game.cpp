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
#include "Cone.h"
#include "Fish.h"
#include "time.h"



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
	DeleteGO(m_Track);
	//トラック1の消去
	DeleteGO(m_rightTrack);
	//トラック2の消去
	DeleteGO(m_leftTrack);
	//トラック3の消去
	DeleteGO(m_middleTrack);
	//コーンの消去
	DeleteGO(m_cone);
	//コーン1の消去
	DeleteGO(m_firstcone);
	//コーン2の消去
	DeleteGO(m_secondcone);
	//コーン3の消去
	DeleteGO(m_thirdcone);
	//コーン4の消去
	DeleteGO(m_fourthcone);
	//コーン5の消去
	DeleteGO(m_fifthcone);
	//魚の消去
	DeleteGO(m_fish);
	//魚１の消去
	DeleteGO(m_firstfish);
	//魚2の消去
	DeleteGO(m_secondfish);
	//魚3の消去
	DeleteGO(m_thirdfish);
	//魚4の消去
	DeleteGO(m_fourthfish);
	//魚5の消去
	DeleteGO(m_fifthfish);
}

void Game::Update()
{
	if (!m_hasStartedCountDown)
	{
		m_GameUI->StartStartCountDown();
		m_hasStartedCountDown = true;
	}

	// カウントダウン中
	if (m_GameUI->IsStartCountingDown())
	{
		m_GameUI->Update();
		return;
	}

	// BGM再生（カウントダウン終了後に1度だけ）
	if (!m_bgmStarted)
	{
		GameBGM->Play(true);  // ← ここで初めて再生
		m_bgmStarted = true;
	}

	// 判定
	switch (player->P_Count)
	{
	case 1:
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
		break;
	case 2:
		NewGO<GameOver>(0, "gameOver");
		DeleteGO(this);
		break;
	default:
		break;
	}
}



void Game::CreateObject() {
	srand(time(nullptr)); // 乱数の初期化
	int m_TrP = 0;

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

	//トラックの配列
	Vector3 m_tr[10];//Vectior3の配列だからVector3型で宣言
	m_tr[0] = Vector3(0.0f,30.0f,-3800.0f);
	m_tr[1] = Vector3(-175.0f, 30.0f, -6700.0f);
	m_tr[2] = Vector3(175.0f, 30.0f, -6700.0f);
	m_tr[3] = Vector3(150.0f, 30.0f, -2000.0f);
	m_tr[4] = Vector3(-300.0f, 30.0f, -2000.0f);
	m_tr[5] = Vector3(150.0f, 30.0f, -9400.0f);
	m_tr[6] = Vector3(-150.0f, 30.0f, -9400.0f);
	m_tr[7] = Vector3(0.0f, 30.0f, -16000.0f);
	m_tr[8] = Vector3(75.0f,30.0f, -12500.0f);
	m_tr[9] = Vector3(-75.0f,30.0f,-12500.0f);

	//ここでトラックを生成する
	//トラックの生成
	m_Track = NewGO<Track>(0, "track");
	//トラックの位置はランダムに設定
	m_TrP = rand() % 3; // 0~2の乱数を生成
	m_Track->m_trposition = m_tr[m_TrP];

	//トラック1の生成
	m_rightTrack = NewGO<Track>(0, "track1");
	m_TrP=rand()% 2 + 3; // 0~2の乱数に3を足して3~4の範囲にする
	m_rightTrack->m_trposition = m_tr[m_TrP];

	//トラック２の生成
	m_leftTrack = NewGO<Track>(0, "track2");
	m_TrP = rand() % 2 + 5; // 0~2の乱数に5を足して5~6の範囲にする
	m_leftTrack->m_trposition = m_tr[m_TrP];

	//トラック3の生成
	m_middleTrack = NewGO<Track>(0, "track3");
	m_TrP = rand() % 3 + 7; // 0~2の乱数に7を足して7~8の範囲にする
	m_middleTrack->m_trposition = m_tr[m_TrP];

	//コーン0の生成
	m_cone = NewGO<Cone>(0, "cone");
	m_cone->m_cnposition = { 0.0f,-10.0f,-7100.0f };

	//コーン1の生成
	m_firstcone = NewGO<Cone>(0, "cone1");
	m_firstcone->m_cnposition = { 35.0f,-10.0f,-7100.0f };

	//コーン2の生成
	m_secondcone = NewGO<Cone>(0, "cone2");
	m_secondcone->m_cnposition = { -35.0f,-10.0f,-7100.0f };

	//コーン3の生成
	m_thirdcone = NewGO<Cone>(0, "cone3");
	m_thirdcone->m_cnposition = { 0.0f,-10.0f,-12000.0f };

	//コーン4の生成
	m_fourthcone = NewGO<Cone>(0, "cone4");
	m_fourthcone->m_cnposition = { 35.0f,-10.0f,-10000.0f };

	//コーン5の生成
	m_fifthcone = NewGO<Cone>(0, "cone5");
	m_fifthcone->m_cnposition = { -35.0f,-10.0f,-3000.0f };

	//魚の生成
	m_fish = NewGO<Fish>(0, "fish");
	m_fish->m_fiposition = { 300.0f,0.0f,-4000.0f };

	//魚1の生成
	m_firstfish = NewGO<Fish>(0, "fish1");
	m_firstfish->m_fiposition = { -300.0f,0.0f,-4100.0f };

	//魚2の生成
	m_secondfish = NewGO<Fish>(0, "fish2");
	m_secondfish->m_fiposition = { 0.0f,70.0f,-4200.0f };

	//魚3の生成
	m_thirdfish = NewGO<Fish>(0, "fish3");
	m_thirdfish->m_fiposition = { 0.0f,50.0f,-1000.0f };

	//魚4の生成
	m_fourthfish = NewGO<Fish>(0, "fish4");
	m_fourthfish->m_fiposition = { 0.0f,50.0f,-12000.0f };

	//魚5の生成
	m_fifthfish = NewGO<Fish>(0, "fish5");
	m_fifthfish->m_fiposition = { 0.0f,50.0f,-8000.0f };

}


//モデルレンダー
void Game::Render(RenderContext& rc) 
{

}