#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

//#include "Game.h"
#include "Player.h"
#include "BackGround.h"

///////////////////////////////////////////////////////////////////
// �E�B���h�E�v���O�����̃��C���֐��B
///////////////////////////////////////////////////////////////////
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	//�Q�[���̏������B
	InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));
	//////////////////////////////////////
	// �������珉�������s���R�[�h���L�q����B
	//////////////////////////////////////

	//Game�N���X�̃I�u�W�F�N�g���쐬�B
	NewGO<BackGround>(0);
	NewGO<Player>(0);

	g_camera3D->SetPosition(0, 50.0f, -200.0f);

	//////////////////////////////////////
	// ���������s���R�[�h�������̂͂����܂ŁI�I�I
	//////////////////////////////////////
	auto& renderContext = g_graphicsEngine->GetRenderContext();
	
	// ��������Q�[�����[�v�B
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
//	// �o�́B
//	pDxgiDebug->ReportLiveObjects(DXGI_DEBUG_D3D12, DXGI_DEBUG_RLO_DETAIL);
//}

