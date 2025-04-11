#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

//#include "Game.h"
#include "Player.h"
#include "BackGround.h"

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

	//Gameクラスのオブジェクトを作成。
	NewGO<BackGround>(0);
	NewGO<Player>(0);

	g_camera3D->SetPosition(0, 50.0f, -200.0f);

	//////////////////////////////////////
	// 初期化を行うコードを書くのはここまで！！！
	//////////////////////////////////////
	auto& renderContext = g_graphicsEngine->GetRenderContext();
	
	// ここからゲームループ。
	while (DispatchWindowMessage())
	{
		g_engine->BeginFrame();

		GameObjectManager::GetInstance()->ExecuteUpdate();
		GameObjectManager::GetInstance()->ExecuteRender(renderContext);

		g_engine->EndFrame();
	}
	GameObjectManager::DeleteInstance();
	return 0;
}

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

