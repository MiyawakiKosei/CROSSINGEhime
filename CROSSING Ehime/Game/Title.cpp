#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSelect.h"
 
Title::Title() {
	//‰æ‘œ‚ð“Ç‚Ýž‚Þ
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
	//‰æ‘œ‚ð•`‰æ‚·‚é
	spriteRender.Draw(rc);
}