#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSelect.h"
 
Title::Title() {
	//�摜��ǂݍ���
	spriteRender.Init("Assets/modelData/title/title01.DDS",1920.0f,1080.0f);
}

Title::~Title() {

}

void Title::Update() 
{
	if (g_pad[0]->IsTrigger(enButtonA)) 
	{

		NewGO<GameSelect>(0);
		DeleteGO(this);

		/*NewGO<Game>(0);
		DeleteGO(this);*/
	}
}

void Title::Render(RenderContext& rc) {
	//�摜��`�悷��
	spriteRender.Draw(rc);
}