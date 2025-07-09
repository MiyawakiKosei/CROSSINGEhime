// main.cpp

#include "stdafx.h"
#include "system/system.h"

#include<InitGUID.h>
#include<dxgidebug.h>

//#include "Game.h" // ���̍s�̓R�����g�A�E�g����Ă��邯�ǁA�K�v�Ȃ�������Ă�
#include "BackGround.h"
#include "Player.h"
#include "Game.h"
#include "Title.h"
#include "Orange.h" 
#include "Score.h" 

const int MAX_ORANGES = 10; // �I�����W�̍ő吔

// �I�����W�̃C���X�^���X���i�[����z��i�O���[�o���ϐ��Ƃ��Đ錾�j
// �����̔z�񎩑̂͐錾���Ă������A���g�̐����Ɖ���͈�U�R�����g�A�E�g
Orange* m_oranges[MAX_ORANGES];

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
	NewGO<Title>(0, "Title");


	//SkyCube�𐶐�
	SkyCube* skyCube = NewGO<SkyCube>(0);
	skyCube->SetType(enSkyCubeType_Day);
	skyCube->SetScale(5000.0f);


	//////////////////////////////////////
	// ���������s���R�[�h�������̂͂����܂ŁI�I�I
	//////////////////////////////////////
	auto& renderContext = g_graphicsEngine->GetRenderContext();

	// ��������Q�[�����[�v�B
	while (DispatchWindowMessage())
	{
		if (g_pad[0]->IsTrigger(enButtonA)) {
			g_pad[0]->SetVibration(/*durationSec=*/0.5f, /*normalizedPower=*/1.0f);
		}

		// K2Engine::GetInstance()->Execute() ��GameObjectManager��Update/Render���Ăяo���̂ŁA
		// �X�݂̂����Update/Render�������Ŏ蓮�ŌĂяo���K�v�͂Ȃ��͂�
		K2Engine::GetInstance()->Execute();
	}

	return 0; // �v���O�����̏I��
}