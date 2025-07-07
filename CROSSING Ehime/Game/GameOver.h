#pragma once

class Title;

class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();

	bool Start();
	void Update();
	void Render(RenderContext& rc);

private:
	SpriteRender m_spriteRender; // 背景スプライト表示用
	FontRender m_restartFont;    // 「コンティニュー」文字表示用
	FontRender m_fontRender;     // その他文字表示用

	enum GameSelect_GameOver {
		ReStart, // コンテニュー
		Exit     // タイトルに戻る
	};
	GameSelect_GameOver m_select = ReStart;// 現在選択中の項目（初期値：ReStart）

	// 点滅・入力用
	float m_blinkTimer = 0.0f;//点滅時間
	bool m_isBlinkVisible = true; //点滅表示
	bool m_canInput = true; //入力受付
};
