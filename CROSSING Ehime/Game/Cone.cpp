#include "stdafx.h"
#include "Cone.h"
#include "Player.h"

Cone::Cone() {
	//���f����ǂݍ���
	m_cnmodelRender.Init("Assets/modelData/cone/Cone02.tkm");
	m_cnmodelRender.SetScale(Vector3(2.0f, 2.0f, 2.0f));
	//�v���C���[�̈ʒu��擾
	m_player = FindGO<Player>("player");

}

Cone::~Cone() {

}

void Cone::Update() {
	//���W�������
	m_cnmodelRender.SetPosition(m_cnposition);

	//�G�`������̍X�V����
	m_cnmodelRender.Update();

	//�v���C���[����R�[���Ɍ������x�N�g������߂�
	Vector3 diff = m_player->m_position - m_cnposition;
	//�x�N�g���̒�����70.0f��菬����������
	if (diff.Length() <= 70.0f) {
		m_player->P_Count = 2;
	}
}

void Cone::Render(RenderContext& renderContext) {
		//�G�`������̕`�揈��
	m_cnmodelRender.Draw(renderContext);
}