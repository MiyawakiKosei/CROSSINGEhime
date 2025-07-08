#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"

GameOver::GameOver() {
	// �w�i�摜�i�Q�[���I�[�o�[�j
	m_spriteRender.Init("Assets/sprite/GAME_OVER.DDS", 1920.0f, 1080.0f);

	// �����F�i���j
	Vector4 m_fontColor = { 1, 1, 1, 1 };

	// �����FA �R���e�j���[
	m_restartFont.SetText(L"A �R���e�j���[����");
	m_restartFont.SetPosition({ -500.0f, -300.0f, 0.0f });
	m_restartFont.SetScale(1.2f);
	m_restartFont.SetColor(m_fontColor);

	// �E���FB �^�C�g���ɖ߂�
	m_fontRender.SetText(L"B �^�C�g���ɖ߂�");
	m_fontRender.SetPosition({ 100.0f, -300.0f, 0.0f });
	m_fontRender.SetScale(1.2f);
	m_fontRender.SetColor(m_fontColor);
	


	//// �E���FB �Q�[�����I������
	//m_exitFont.SetText(L"�^�C�g���ɖ߂�");
	//m_exitFont.SetPosition({ 0.0f, -300.0f, 0.0f });
	//m_exitFont.SetScale(1.2f);
	//m_exitFont.SetColor(fontColor);
}

GameOver::~GameOver() {}

bool GameOver::Start() {
	return true;
}

void GameOver::Update() {
	 //�_�Ń^�C�}�[
	m_blinkTimer += g_gameTime->GetFrameDeltaTime();
	if (m_blinkTimer >= 0.75f) {
		m_blinkTimer = 0.0f;
		m_isBlinkVisible = !m_isBlinkVisible;
	}

	// ���͏����i���E�L�[ or �p�b�h�j
	if (m_canInput) {
		if (
			g_pad[0]->IsTrigger(enButtonLeft) ||
			g_pad[0]->IsTrigger(enButtonRight)
			) {
			// �؂�ւ�
			m_select = (m_select == ReStart) ? Exit : ReStart;
			m_canInput = false;
		}
	}
	else {
		// ���͉���҂��i�������ςȂ��h�~�j
		if (
			!g_pad[0]->IsPress(enButtonLeft) &&
			!g_pad[0]->IsPress(enButtonRight)
			) {
			m_canInput = true;
		}
	}

	/*if (g_pad[0]->IsTrigger(enButtonA)) {
		
			DeleteGO(this);
			NewGO<Title>(0, "title");
		
	}*/

	// ���菈���iEnter or A�{�^���j
	if (g_pad[0]->IsTrigger(enButtonA)) {
		if (m_select == ReStart) {
			DeleteGO(this);
			NewGO<Game>(0, "game");
		}
		else if (m_select == Exit) {
			DeleteGO(this);
			NewGO<Title>(0, "title");
			
		}
	}
}

void GameOver::Render(RenderContext& rc) {
	m_spriteRender.Draw(rc);

	// �R���e�j���[�i���j
	if (m_select == ReStart && m_isBlinkVisible) {
		m_restartFont.Draw(rc);
	}
	else if (m_select != ReStart) {
		m_restartFont.Draw(rc);
	}

	// �^�C�g���ɖ߂�i�E�j
	if (m_select == Exit && m_isBlinkVisible) {
		m_fontRender.Draw(rc);
	}
	else if (m_select != Exit) {
		m_fontRender.Draw(rc);
	}
}
