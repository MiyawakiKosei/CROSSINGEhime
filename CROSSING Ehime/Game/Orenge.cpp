#include "stdafx.h"
#include "Orenge.h"
#include "Player.h"

Orenge::Orenge() {
	////���f����ǂݍ���
	m_ormodelRender.Init("Assets/modelData/orenge/Orenge01.tkm");
	////�v���C���[�̃I�u�W�F�N�g�����������Ă���
	player = FindGO<Player>("player");

	//m_ormodelRender.SetPosition(0.0f, 0.0f, -1000.0f);
}

Orenge::~Orenge() {

}

void Orenge::Update() {

	Move();

	//�G�`������̍X�V����
	m_ormodelRender.Update();
	
	//�v���C���[����I�����W�Ɍ������x�N�g�������߂�
	Vector3 diff = player->position - position;
	//�x�N�g���̒�����70.0f��菬����������
	if (diff.Length() <= 120.0f) {
		orengePoint += 1;
		//���g����������
		DeleteGO(this);
	}
}

void Orenge::Move() {
	//�㉺�Ɉړ�������
	if (orengeCount == 0) {
		//��
		position.y += 1.0f;
	}
	else if (orengeCount == 1) {
		//��
		position.y -= 1.0f;
	}

	//posisiony�������ʒu+50�𒴂�����
	if (position.y >= firstPosition.y+30.0f) {
		//�I�����W�J�E���g���P�ɂ���
		orengeCount = 1;
	}
	//positiony�������ʒu-50�𒴂�����
	else if (position.y <= firstPosition.y -30.0f) {
		//�I�����W�J�E���g��0�ɂ���
		orengeCount = 0;
	}
	
	//���W��������
	m_ormodelRender.SetPosition(position);


}

void Orenge::Render(RenderContext& renderContext) {
	//�I�����W�I�u�W�F�N�g��`��
	m_ormodelRender.Draw(renderContext);
}
