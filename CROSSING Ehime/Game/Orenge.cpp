#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////���f����ǂݍ���
	//modelRender.Init("Assets/modelData/");
	////�v���C���[�̃I�u�W�F�N�g�����������Ă���
	//player = FindGO<Player>("Player");
}

Orenge::~Orenge() {

}

void Orenge::Update() {
	//�㉺�Ɉړ�������
	//if (moveCount == 0) {
	//	//��
	//	position.y += 1.0f;
	//}
	//else if (moveCount == 1) {
	//	//��
	//	position.y -= 1.0f;
	//}



	//�G�`������̍X�V����
	modelRender.Update();
}

void Orenge::Render(RenderContext& renderContext) {
	//�I�����W�I�u�W�F�N�g��`��
	modelRender.Draw(renderContext);
}
