#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSelect.h"
 
bool Title::Start() {
	//�摜��ǂݍ���
	m_spriteRender.Init("Assets/sprite/ROLLING_EHIME.DDS",1920.0f,1080.0f);

	//�^�C�g����BGM��ǂݍ���
	//g_soundEngine->ResistWaveFileBank(0, "");

	//�^�C�g����BGM���Đ�����
	/*titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);*/

	//�����̕\���B
	Vector4 m_fontColor = { 1.0f, 1.0f, 1.0f, 1.0f };//��
	m_fontRender.SetText(L"Please PUSH AnyKey");//�L�[
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
	//�摜��`�悷��
	m_spriteRender.Draw(rc);
	m_fontRender.Draw(rc);
}