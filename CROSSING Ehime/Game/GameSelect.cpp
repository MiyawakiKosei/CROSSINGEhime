#include "stdafx.h"
#include "GameSelect.h"
#include "Game.h"
#include "Title.h"
#include "Loading.h"
#include "sound/SoundEngine.h"

GameSelect::GameSelect() {
	//�摜��ǂݍ���
	spriteRender.Init("Assets/sprite/Select.DDS",1920.0f,1080.0f);

	//�Q�[���Z���N�g��SE��ǂݍ���
	g_soundEngine->ResistWaveFileBank(5, "Assets/sound/StartSE.wav");
}

GameSelect::~GameSelect() {

}

void GameSelect::Update() {

	if (g_pad[0]->IsTrigger(enButtonA))
	{
		auto loading = NewGO<Loading>(0, "loading");
		loading->SetNextScene(Loading::SceneType::Game);

		//�Q�[���Z���N�g��SE���Đ�
		m_GameSelectSE = NewGO<SoundSource>(0, "GameSelectSE");
		m_GameSelectSE->Init(5);
		m_GameSelectSE->Play(false);

		DeleteGO(this);
	}
}

void GameSelect::Render(RenderContext& rc) {
	//�摜��`�悷��
	spriteRender.Draw(rc);
}