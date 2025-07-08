#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"
#include "Loading.h"


GameOver::GameOver() {
	// 背景画像（ゲームオーバー）
	m_spriteRender.Init("Assets/sprite/GAME_OVER.DDS", 1920.0f, 1080.0f);

	// 文字色（白）
	Vector4 m_fontColor = { 1, 1, 1, 1 };

	// 左側：A コンテニュー
	m_restartFont.SetText(L"A コンテニューする");
	m_restartFont.SetPosition({ -500.0f, -300.0f, 0.0f });
	m_restartFont.SetScale(1.2f);
	m_restartFont.SetColor(m_fontColor);

	// 右側：B タイトルに戻る
	m_fontRender.SetText(L"B タイトルに戻る");
	m_fontRender.SetPosition({ 100.0f, -300.0f, 0.0f });
	m_fontRender.SetScale(1.2f);
	m_fontRender.SetColor(m_fontColor);
}

GameOver::~GameOver() {}

bool GameOver::Start() {
	return true;
}


void GameOver::Update() {
	// 点滅タイマー
	m_blinkTimer += g_gameTime->GetFrameDeltaTime();
	if (m_blinkTimer >= 0.75f) {
		m_blinkTimer = 0.0f;
		m_isBlinkVisible = !m_isBlinkVisible;
	}

	// 入力処理（左右キー or パッド）
	if (m_canInput) {
		if (
			g_pad[0]->IsTrigger(enButtonLeft) ||
			g_pad[0]->IsTrigger(enButtonRight)
			) {
			// 切り替え
			m_select = (m_select == ReStart) ? Exit : ReStart;
			m_canInput = false;
		}
	}
	else {
		if (
			!g_pad[0]->IsPress(enButtonLeft) &&
			!g_pad[0]->IsPress(enButtonRight)
			) {
			m_canInput = true;
		}
	}

	// 決定処理（Aボタン）
	if (g_pad[0]->IsTrigger(enButtonA)) {
		auto loading = NewGO<Loading>(0, "loading");

		if (m_select == ReStart) {
			loading->SetNextScene(Loading::SceneType::Game);
		}
		else {
			loading->SetNextScene(Loading::SceneType::Title);
		}
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc) {
	m_spriteRender.Draw(rc);

	// コンテニュー（左）
	if (m_select == ReStart && m_isBlinkVisible) {
		m_restartFont.Draw(rc);
	}
	else if (m_select != ReStart) {
		m_restartFont.Draw(rc);
	}

	// タイトルに戻る（右）
	if (m_select == Exit && m_isBlinkVisible) {
		m_fontRender.Draw(rc);
	}
	else if (m_select != Exit) {
		m_fontRender.Draw(rc);
	}
}
