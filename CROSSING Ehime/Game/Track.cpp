#include "stdafx.h"
#include "Track.h"
#include "Player.h"

Track::Track() 
{
	//���f����ǂݍ���
	tr_modelRender.Init("Assets/modelData/track/Track04.tkm");

	//�v���C���[�̃I�u�W�F�N�g�����������Ă���
	player = FindGO<Player>("player");
}

Track::~Track() {

}

void Track::Update() {

	Move();

	//�G�`������̍X�V����
	tr_modelRender.Update();

}

void Track::Move() {
	//�O��Ɉړ�������
	if (Tr_Count == 1) {
		//�O�ɐi��
		position.z += 10.0f;
	}
	else if (Tr_Count == 0) {
		//���ɐi��
		position.z -= 10.0f;
	}

	//����z����-1000�𒴂�����
	if (position.z <= -1000.0f) {
		Tr_Count = 1;
		rot.SetRotationDegY(360.0f);
	}
	//����z����-500�𒴂�����
	if (position.z >= -500.0f) {
		Tr_Count = 0;
		rot.SetRotationDegY(180.0f);
	}

	//���W��������
	tr_modelRender.SetPosition(position);

	//��]��������
	tr_modelRender.SetRotation(rot);
}

void Track::Render(RenderContext& renderContext) {
	//�g���b�N�̕`��
	tr_modelRender.Draw(renderContext);
}