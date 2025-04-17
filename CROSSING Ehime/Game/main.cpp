#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

//#include "Game.h"
#include "BackGround.h"
#include "Player.h"
<<<<<<< HEAD
#include "Game.h"
=======
>>>>>>> 287ecdd69a4cc46686ef80a21be0849fd9040a3f
#include "Title.h"

//void ReportLiveObjects()
//{
//	IDXGIDebug* pDxgiDebug;
//
//	typedef HRESULT(__stdcall* fPtr)(const IID&, void**);
//	HMODULE hDll = GetModuleHandleW(L"dxgidebug.dll");
//	fPtr DXGIGetDebugInterface = (fPtr)GetProcAddress(hDll, "DXGIGetDebugInterface");
//
//	DXGIGetDebugInterface(__uuidof(IDXGIDebug), (void**)&pDxgiDebug);
//
//	// 出力。
//	pDxgiDebug->ReportLiveObjects(DXGI_DEBUG_D3D12, DXGI_DEBUG_RLO_DETAIL);
//}

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

	//Titleクラスのオブジェクトを作成
	NewGO<Title>(0, "Title");

	//Gameクラスのオブジェクトを作成。
	NewGO<Title>(0, "Title");
	//NewGO<BackGround>(0);


	//SkyCube
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
		K2Engine::GetInstance()->Execute();
	/*g_engine->BeginFrame();

	GameObjectManager::GetInstance()->ExecuteUpdate();
	GameObjectManager::GetInstance()->ExecuteRender(renderContext);

		g_engine->EndFrame();*/
	}
	//GameObjectManager::DeleteInstance();
	return 0;
}

