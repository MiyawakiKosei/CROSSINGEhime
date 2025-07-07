#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"

GameOver::GameOver() {
	//�Q�[���I�[�o�[�̉摜��ǂݍ���
	spriteRender.Init("Assets/sprite/GameOver01.DDS",1920.0f,1080.0f);
}

GameOver::~GameOver() {

}

//�X�V����
void GameOver::Update() {
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//�^�C�g���̃I�u�W�F�N�g���쐬
		NewGO<Title>(0, "title");
		//���g����������
		DeleteGO(this);
	}
}

//�`�揈��
void GameOver::Render(RenderContext& rc) {
	spriteRender.Draw(rc);
}
