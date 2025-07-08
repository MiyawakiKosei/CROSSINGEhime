#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"

GameSelect::GameSelect() {
	//�摜��ǂݍ���
	spriteRender.Init("Assets/sprite/Select01.DDS",1920.0f,1080.0f);
}

GameSelect::~GameSelect() {

}

void GameSelect :: Update() {
	//J�{�^������������
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//�摜��`�悷��
	spriteRender.Draw(rc);
}