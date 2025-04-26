// DebugFont.h
#pragma once


class DebugFont {
public:
	void Init() {
		m_font = std::make_unique<nsK2EngineLow::Font>();
	}
	void Draw(RenderContext& rc, const wchar_t* text, float x, float y) {
		m_font->Begin(rc);

		Vector2 pos = { x, y };
		m_font->Draw(
			text,
			pos,
			{ 1.0f, 1.0f, 1.0f, 1.0f }, // ”’
			0.0f, 1.0f, { 0.0f, 1.0f }
		);

		m_font->End(rc);
	}
private:
	std::unique_ptr<nsK2EngineLow::Font> m_font;
};
