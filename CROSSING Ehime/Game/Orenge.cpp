#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////���f����ǂݍ���
	m_ormodelRender.Init("Assets/modelData/orenge/Orenge01.tkm");
	////�v���C���[�̃I�u�W�F�N�g�����������Ă���
	player = FindGO<Player>("Player");

	m_ormodelRender.SetPosition(0.0f, 0.0f, -1000.0f);
}

Orenge::~Orenge() {

}

void Orenge::Update() {
	//�㉺�Ɉړ�������
	//if (orengeCount == 0) {
	//	//��
	//	position.y += 2.0f;
	//}
	//else if (orengeCount == 1) {
	//	//��
	//	position.y -= 2.0f;
	//}

	////posisiony��10�𒴂�����
	//if (position.y >= 50.0f) {
	//	//�I�����W�J�E���g���P�ɂ���
	//	orengeCount = 1;
	//}
	////positiony��-10�𒴂�����
	//else if (position.y <= -50.0f) {
	//	//�I�����W�J�E���g��0�ɂ���
	//	orengeCount = 0;
	//}
	//
	////���W��������
	//m_ormodelRender.SetPosition(position);

	//�G�`������̍X�V����
	m_ormodelRender.Update();

	//�v���C���[����I�����W�Ɍ������x�N�g�������߂�
	//Vector3 diff = position - player->position;
	////�v���C���[�ƃI�����W�̋�����70.0f��菬����������
	//if (diff.Length() <= 70.0f) {
	//	DeleteGO(this);
	//}
	
}

void Orenge::Render(RenderContext& renderContext) {
	//�I�����W�I�u�W�F�N�g��`��
	m_ormodelRender.Draw(renderContext);
}
