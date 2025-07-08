#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSelect.h"
 
bool Title::Start() {
	//画像を読み込む
	m_spriteRender.Init("Assets/sprite/ROLLING_EHIME.DDS",1920.0f,1080.0f);

	//タイトルのBGMを読み込む
	//g_soundEngine->ResistWaveFileBank(0, "");

	//タイトルのBGMを再生する
	/*titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);*/

	//文字の表示。
	Vector4 m_fontColor = { 1.0f, 1.0f, 1.0f, 1.0f };//白
	m_fontRender.SetText(L"Please PUSH AnyKey");//キー
	m_fontRender.SetPosition({ -280.0f,-300.0f,0.0f });
	m_fontRender.SetScale(1.5f);
	m_fontRender.SetColor(m_fontColor);

	return true;
}

Title::Title() {}

Title::~Title() {}

void Title::Update() {
	if (g_pad[0]->IsTriggerAnyKey()) {
		NewGO<GameSelect>(0);
		DeleteGO(this);
	}
}


void Title::Render(RenderContext& rc) {
	//画像を描画する
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}