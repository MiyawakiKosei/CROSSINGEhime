// main.cpp

#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

//#include "Game.h" // この行はコメントアウトされているけど、必要なら解除してね
#include "BackGround.h"
#include "Player.h"
#include "Game.h"
#include "Title.h"
#include "Orange.h" 
#include "Score.h" 

const int MAX_ORANGES = 10; // オレンジの最大数

// オレンジのインスタンスを格納する配列（グローバル変数として宣言）
// ※この配列自体は宣言しておくが、中身の生成と解放は一旦コメントアウト
Orange* m_oranges[MAX_ORANGES];

///////////////////////////////////////////////////////////////////
// ウィンドウプログラムのメイン関数。
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//ゲームの初期化。
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

	//////////////////////////////////////
	// ここから初期化を行うコードを記述する。
	//////////////////////////////////////
	NewGO<Title>(0, "Title");


	//SkyCubeを生成
	SkyCube* skyCube = NewGO<SkyCube>(0);
	skyCube->SetType(enSkyCubeType_Day);
	skyCube->SetScale(5000.0f);


	//////////////////////////////////////
	// 初期化を行うコードを書くのはここまで！！！
	//////////////////////////////////////
	auto& renderContext = g_graphicsEngine->GetRenderContext();

	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		if (g_pad[0]->IsTrigger(enButtonA)) {
			g_pad[0]->SetVibration(/*durationSec=*/0.5f, /*normalizedPower=*/1.0f);
		}

		// K2Engine::GetInstance()->Execute() がGameObjectManagerのUpdate/Renderを呼び出すので、
		// 個々のみかんのUpdate/Renderをここで手動で呼び出す必要はないはず
		K2Engine::GetInstance()->Execute();
	}

	return 0; // プログラムの終了
}