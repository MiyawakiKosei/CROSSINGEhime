#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"
#include "Loading.h"
#include "sound/SoundEngine.h"

GameSelect::GameSelect() {
	//画像を読み込む
	spriteRender.Init("Assets/sprite/Select.DDS",1920.0f,1080.0f);

	//ゲームセレクトのSEを読み込む
	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/StartSE.wav");
}

GameSelect::~GameSelect() {

}

void GameSelect::Update() {

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		auto loading = NewGO<Loading>(0, "loading");
		loading->SetNextScene(Loading::SceneType::Game);

		//ゲームセレクトのSEを再生
		m_GameSelectSE = NewGO<SoundSource>(0, "GameSelectSE");
		m_GameSelectSE->Init(5);
		m_GameSelectSE->Play(false);

		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//画像を描画する
	spriteRender.Draw(rc);
}