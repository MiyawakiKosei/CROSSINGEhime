#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"
#include "Loading.h"

GameClear::GameClear() {
	//ゲームクリア画像を読み込む
	m_spriteRender.Init("Assets/sprite/GAME_CLEAR.DDS",1920.0f,1080.0f);


	Vector4 m_fontColor = { 1.0f, 1.0f, 1.0f, 1.0f };//白
	m_fontRender.SetText(L"A タイトルに戻る");
	m_fontRender.SetPosition({ -100.0f, -300.0f, 0.0f });
	m_fontRender.SetScale(1.2f);
	m_fontRender.SetColor(m_fontColor);
}

GameClear::~GameClear(){

}

//更新処理
void GameClear::Update() {
	//Aボタンが押されたら
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		auto loading = NewGO<Loading>(0, "loading");
		
		loading->SetNextScene(Loading::SceneType::Title);

		//自身を消去する
		DeleteGO(this);
	}
}

//描画処理
void GameClear::Render(RenderContext&rc)
{
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}