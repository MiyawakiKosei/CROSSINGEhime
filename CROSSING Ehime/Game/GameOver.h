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
	SpriteRender m_spriteRender; // �w�i�X�v���C�g�\���p
	FontRender m_restartFont;    // �u�R���e�B�j���[�v�����\���p
	FontRender m_fontRender;     // ���̑������\���p

	enum GameSelect_GameOver {
		ReStart, // �R���e�j���[
		Exit     // �^�C�g���ɖ߂�
	};
	GameSelect_GameOver m_select = ReStart;// ���ݑI�𒆂̍��ځi�����l�FReStart�j

	// �_�ŁE���͗p
	float m_blinkTimer = 0.0f;//�_�Ŏ���
	bool m_isBlinkVisible = true; //�_�ŕ\��
	bool m_canInput = true; //���͎�t
};
