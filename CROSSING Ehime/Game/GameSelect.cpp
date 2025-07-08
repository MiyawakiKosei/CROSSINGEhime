#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"
#include "Loading.h"

GameSelect::GameSelect() {
	//‰æ‘œ‚ð“Ç‚Ýž‚Þ
	spriteRender.Init("Assets/sprite/Select01.DDS",1920.0f,1080.0f);
}

GameSelect::~GameSelect() {

}

void GameSelect::Update() {

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		auto loading = NewGO<Loading>(0, "loading");
		loading->SetNextScene(Loading::SceneType::Game);

		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//‰æ‘œ‚ð•`‰æ‚·‚é
	spriteRender.Draw(rc);
}