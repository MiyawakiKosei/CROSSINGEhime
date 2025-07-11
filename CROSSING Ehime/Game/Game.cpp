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
	GameBGM = NewGO<SoundSource>(0);
	GameBGM->Init(1);
	

}

Game::~Game()
{
   // playerの消去
   DeleteGO(player);
   // カメラの消去
   DeleteGO(gameCamera);
   // BGMの消去
   DeleteGO(GameBGM);
   // ステージの消去
   DeleteGO(backGround);
   // UIの消去
   DeleteGO(m_GameUI);
   // 風の消去
   DeleteGO(m_windZone);

   // オレンジ全ての消去
   for (int i = 0; i < 34; i++)
   {
       DeleteGO(m_Orange[i]);
   }
   // オレンジレフトの消去
   for (int i = 0; i < 34; i++)
   {
       DeleteGO(m_OrangeLeft[i]);
   }
   // オレンジライトの消去
   for (int i = 0; i < 34; i++)
   {
       DeleteGO(m_OrangeRight[i]);
   }
   // トラックの消去
   DeleteGO(m_Track);
   // トラック1の消去
   DeleteGO(m_rightTrack);
   // トラック2の消去
   DeleteGO(m_leftTrack);
   // トラック3の消去
   DeleteGO(m_middleTrack);
   // コーンの消去
   DeleteGO(m_cone);
   // コーン1の消去
   DeleteGO(m_firstcone);
   // コーン2の消去
   DeleteGO(m_secondcone);
   // コーン3の消去
   DeleteGO(m_thirdcone);
   // コーン4の消去
   DeleteGO(m_fourthcone);
   // コーン5の消去
   DeleteGO(m_fifthcone);
   // 魚の消去
   DeleteGO(m_fish);
   // 魚1の消去
   DeleteGO(m_firstfish);
   // 魚2の消去
   DeleteGO(m_secondfish);
   // 魚3の消去
   DeleteGO(m_thirdfish);
   // 魚4の消去
   DeleteGO(m_fourthfish);
   // 魚5の消去
   DeleteGO(m_fifthfish);
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
	//トラックの消去
	DeleteGO(m_Track);
	//トラック1の消去
	DeleteGO(m_rightTrack);
	//トラック2の消去
	DeleteGO(m_leftTrack);
	//トラック3の消去
	DeleteGO(m_middleTrack);
	//トラック4の消去
	DeleteGO(m_finalTrack);
	//トラック5の消去
	DeleteGO(m_firstTrack);
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
	//コーン6の消去
	DeleteGO(m_sixthcone);
	//コーン7の消去
	DeleteGO(m_seventhcone);
	//コーン8の消去
	DeleteGO(m_eighthcone);
	//コーン9の消去
	DeleteGO(m_ninthcone);
	//コーン10の消去
	DeleteGO(m_tenthcone);
	//コーン11の消去
	DeleteGO(m_eleventhcone);
	//コーン12の消去
	DeleteGO(m_twelfthcone);
	//コーン13の消去
	DeleteGO(m_thirteenthcone);
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

   for (int i = 0; i < 34; i++) {  
       m_Orange[i] = NewGO<Orange>(0, "orange");  
       m_Orange[i]->m_orposition = { 0.0f, 100.0f, -1000.0f - (i * 500.0f) };  
   }  

   m_Orange[0]->m_orposition = { 0.0f, 500.0f, 0.0f }; 
   m_Orange[1]->m_orposition = { 0.0f, 100.0f, -1500.0f }; 
   m_Orange[2]->m_orposition = { 0.0f, 500.0f, 0.0f }; 
   m_Orange[3]->m_orposition = { 0.0f, 100.0f, -2500.0f }; 
   m_Orange[4]->m_orposition = { 0.0f, 500.0f, 0.0f }; 
   m_Orange[5]->m_orposition = { 0.0f, 100.0f, -3500.0f }; 
   m_Orange[6]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[7]->m_orposition = { 0.0f, 100.0f, -4500.0f };
   m_Orange[8]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[9]->m_orposition = { 0.0f, 100.0f, -5500.0f };
   m_Orange[10]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[11]->m_orposition = { 0.0f, 100.0f, -6500.0f };
   m_Orange[12]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[13]->m_orposition = { 0.0f, 100.0f, -7500.0f };
   m_Orange[14]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[15]->m_orposition = { 0.0f, 100.0f, -8500.0f };
   m_Orange[16]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[17]->m_orposition = { 0.0f, 100.0f, -9500.0f };
   m_Orange[18]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[19]->m_orposition = { 0.0f, 100.0f, -10500.0f };
   m_Orange[20]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[21]->m_orposition = { 0.0f, 100.0f, -11500.0f };
   m_Orange[22]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[23]->m_orposition = { 0.0f, 100.0f, -12500.0f };
   m_Orange[24]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[25]->m_orposition = { 0.0f, 100.0f, -13500.0f };
   m_Orange[26]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[27]->m_orposition = { 0.0f, 100.0f, -14500.0f };
   m_Orange[28]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[29]->m_orposition = { 0.0f, 100.0f, -15500.0f };
   m_Orange[30]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[31]->m_orposition = { 0.0f, 100.0f, -16500.0f };
   m_Orange[32]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_Orange[33]->m_orposition = { 0.0f, 100.0f, -17500.0f }; // 最後のオレンジの位置を調整



   for (int i = 0; i < 34; i++) {  
       m_OrangeLeft[i] = NewGO<Orange>(0, "orangeLeft");  
       m_OrangeLeft[i]->m_orposition = { 250.0f, 100.0f, -1000.0f - (i * 500.0f) }; 
   }  

   m_OrangeLeft[0]->m_orposition = { 0.0f, 500.0f, 0.0f }; // 1番目のオレンジの位置を調整
   m_OrangeLeft[1]->m_orposition = { 0.0f, 500.0f, 0.0f }; // 2番目のオレンジの位置を調整
   m_OrangeLeft[2]->m_orposition = { 250.0f, 100.0f, -2000.0f }; // 3番目のオレンジの位置を調整
   m_OrangeLeft[3]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[4]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[5]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[6]->m_orposition = { 250.0f, 100.0f, -4000.0f };
   m_OrangeLeft[7]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[8]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[9]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[10]->m_orposition = { 250.0f,100.0f,-6000.0f };
   m_OrangeLeft[11]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[12]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[13]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[14]->m_orposition = { 250.0f,100.0f,-8000.0f };
   m_OrangeLeft[15]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[16]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[17]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[18]->m_orposition = { 250.0f,100.0f,-10000.0f };
   m_OrangeLeft[19]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[20]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[21]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[22]->m_orposition = { 250.0f,100.0f,-12000.0f };
   m_OrangeLeft[23]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[24]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[25]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[26]->m_orposition = { 250.0f,100.0f,-14000.0f };
   m_OrangeLeft[27]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[28]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[29]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[30]->m_orposition = { 250.0f,100.0f,-16000.0f };
   m_OrangeLeft[31]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[32]->m_orposition = { 0.0f, 500.0f, 0.0f };
   m_OrangeLeft[33]->m_orposition = { 0.0f, 500.0f, 0.0f }; // 最後のオレンジの位置を調整


   for (int i = 0; i < 34; i++) {  
       m_OrangeRight[i] = NewGO<Orange>(0, "orangeRight");  
       m_OrangeRight[i]->m_orposition = { -250.0f, 100.0f, -1000.0f - (i * 500.0f) };  
   } 

   m_OrangeRight[0]->m_orposition = { -250.0f, 100.0f,-1000.0f }; // 1番目のオレンジの位置を調整
   m_OrangeRight[1]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[2]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[3]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[4]->m_orposition = { -250.0f,100.0f,-3000.0f };
   m_OrangeRight[5]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[6]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[7]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[8]->m_orposition = { -250.0f,100.0f,-5000.0f };
   m_OrangeRight[9]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[10]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[11]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[12]->m_orposition = { -250.0f,100.0f,-7000.0f };
   m_OrangeRight[13]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[14]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[15]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[16]->m_orposition = { -250.0f,100.0f,-9000.0f };
   m_OrangeRight[17]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[18]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[19]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[20]->m_orposition = { -250.0f,100.0f,-11000.0f };
   m_OrangeRight[21]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[22]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[23]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[24]->m_orposition = { -250.0f,100.0f,-13000.0f };
   m_OrangeRight[25]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[26]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[27]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[28]->m_orposition = { -250.0f,100.0f,-15000.0f };
   m_OrangeRight[29]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[30]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[31]->m_orposition = { 0.0f,500.0f,0.0f };
   m_OrangeRight[32]->m_orposition = { -250.0f,100.0f,-17000.0f };
   m_OrangeRight[33]->m_orposition = { 0.0f,500.0f,0.0f }; // 最後のオレンジの位置を調整

	//srand(time(nullptr)); // 乱数の初期化
	int m_TrP = 0;

	////オレンジの生成
	//m_Orange = NewGO<Orange>(0, "orange");
	//m_Orange->m_orposition = { 0.0f,0.0f,-1000.0f };

	//トラックの配列
	Vector3 m_tr[10];//Vectior3の配列だからVector3型で宣言
	m_tr[0] = Vector3(0.0f,30.0f,-3800.0f);
	m_tr[1] = Vector3(-175.0f, 30.0f, -6700.0f);
	m_tr[2] = Vector3(175.0f, 30.0f, -6700.0f);
	m_tr[3] = Vector3(150.0f, 30.0f, -2000.0f);
	m_tr[4] = Vector3(-300.0f, 30.0f, -2000.0f);
	m_tr[5] = Vector3(150.0f, 30.0f, -9400.0f);
	m_tr[6] = Vector3(-150.0f, 30.0f, -9400.0f);
	m_tr[7] = Vector3(-100.0f,30.0f,-12500.0f);
	m_tr[8] = Vector3(100.0f,30.0f, -12500.0f);
	m_tr[9] = Vector3(0.0f, 30.0f, -16000.0f);

	//ここでトラックを生成する
	//最初のトラックの生成
	m_firstTrack = NewGO<Track>(0, "track5");
	//最初のトラックは固定
	m_firstTrack->m_trposition = m_tr[0];

	//トラックの生成
	m_Track = NewGO<Track>(0, "track");
	//トラックの位置はランダムに設定
	m_TrP = rand() % 2 + 1;// 0~2の乱数に1を足して1~2の範囲にする
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
	m_TrP = rand() % 2 + 7; // 0~2の乱数に7を足して7~8の範囲にする
	m_middleTrack->m_trposition = m_tr[m_TrP];

	//トラック4の生成
	m_finalTrack = NewGO<Track>(0, "track4");
	m_finalTrack->m_trposition = m_tr[9]; // 最後のトラックは固定位置

   // コーンの生成  
   m_cone = NewGO<Cone>(0, "cone");  
   m_cone->m_cnposition = { 0.0f, -10.0f, -7100.0f };  

   // コーン1の生成  
   m_firstcone = NewGO<Cone>(0, "cone1");  
   m_firstcone->m_cnposition = { 35.0f, -10.0f, -7100.0f };  

   // コーン2の生成  
   m_secondcone = NewGO<Cone>(0, "cone2");  
   m_secondcone->m_cnposition = { -35.0f, -10.0f, -7100.0f };  

   // コーン3の生成  
   m_thirdcone = NewGO<Cone>(0, "cone3");  
   m_thirdcone->m_cnposition = { 0.0f, -10.0f, -12000.0f };  

   // コーン4の生成  
   m_fourthcone = NewGO<Cone>(0, "cone4");  
   m_fourthcone->m_cnposition = { 35.0f, -10.0f, -10000.0f };  

	//コーン5の生成
	m_fifthcone = NewGO<Cone>(0, "cone5");
	m_fifthcone->m_cnposition = { -180.0f,-10.0f,-3000.0f };

	//コーン6の生成
	m_sixthcone = NewGO<Cone>(0, "cone6");
	m_sixthcone->m_cnposition = { 60.0f,-10.0f,-4100.0f };

	//コーン7の生成
	m_seventhcone = NewGO<Cone>(0, "cone7");
	m_seventhcone->m_cnposition = { -60.0f,-10.0f,-4100.0f };

	//コーン8の生成
	m_eighthcone = NewGO<Cone>(0, "cone8");
	m_eighthcone->m_cnposition = { 0.0f,-10.0f,-8500.0f };

	//コーン9の生成
	m_ninthcone = NewGO<Cone>(0, "cone9");
	m_ninthcone->m_cnposition = { 0.0f,-10.0f,-17100.0f };

	//コーン10の生成
	m_tenthcone = NewGO<Cone>(0, "cone10");
	m_tenthcone->m_cnposition = { 0.0f,-10.0f,-16900.0f };

	//コーン11の生成
	m_eleventhcone = NewGO<Cone>(0, "cone11");
	m_eleventhcone->m_cnposition = { 85.0f,-10.0f,-17000.0f };

	//コーン12の生成
	m_twelfthcone = NewGO<Cone>(0, "cone12");
	m_twelfthcone->m_cnposition = { -85.0f,-10.0f,-17000.0f };

	//コーン13の生成
	m_thirteenthcone = NewGO<Cone>(0, "cone13");
	m_thirteenthcone->m_cnposition = { 180.0f,-10.0f,-3000.0f };

   // 魚の生成  
   m_fish = NewGO<Fish>(0, "fish");  
   m_fish->m_fiposition = { 300.0f, 0.0f, -4000.0f };  

   // 魚1の生成  
   m_firstfish = NewGO<Fish>(0, "fish1");  
   m_firstfish->m_fiposition = { -300.0f, 0.0f, -4100.0f };  

   // 魚2の生成  
   m_secondfish = NewGO<Fish>(0, "fish2");  
   m_secondfish->m_fiposition = { 0.0f, 70.0f, -4200.0f };  

   // 魚3の生成  
   m_thirdfish = NewGO<Fish>(0, "fish3");  
   m_thirdfish->m_fiposition = { 0.0f, 50.0f, -1000.0f };  

   // 魚4の生成  
   m_fourthfish = NewGO<Fish>(0, "fish4");  
   m_fourthfish->m_fiposition = { 0.0f, 50.0f, -12000.0f };  

   // 魚5の生成  
   m_fifthfish = NewGO<Fish>(0, "fish5");  
   m_fifthfish->m_fiposition = { 0.0f, 50.0f, -8000.0f };  
}


//モデルレンダー
void Game::Render(RenderContext& rc) 
{

}