#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"

GameSelect::GameSelect() {
	//‰æ‘œ‚ð“Ç‚Ýž‚Þ
	spriteRender.Init("Assets/sprite/Select01.DDS",1920.0f,1080.0f);
}

GameSelect::~GameSelect() {

}

void GameSelect :: Update() {
	//Jƒ{ƒ^ƒ“‚ð‰Ÿ‚µ‚½‚ç
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0);
		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//‰æ‘œ‚ð•`‰æ‚·‚é
	spriteRender.Draw(rc);
}