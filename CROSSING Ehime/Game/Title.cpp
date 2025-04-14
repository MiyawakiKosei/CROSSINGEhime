#include "stdafx.h"
#include "Title.h"
#include "Game.h"
 
Title::Title() {
	//�摜��ǂݍ���
	spriteRender.Init("Assets/modelData/title/Title01.png",1920.0f,1080.0f);
}

Title::~Title() {

}

void Title::Update() 
{
	if (g_pad[0]->IsTrigger(enButtonA)) {
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc) {
	//�摜��`�悷��
	spriteRender.Draw(rc);
}