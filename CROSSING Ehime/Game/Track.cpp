#include "stdafx.h"
#include "Track.h"
#include "Player.h"

Track::Track() 
{
	//���f����ǂݍ���
	//tr_modelRender.Init("Assets/modelData/track/Track01.tkm");

	//�v���C���[�̃I�u�W�F�N�g�����������Ă���
	////player = FindGO<Player>("player");
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
	//if (Tr_Count == 1) {
	//	//�O�ɐi��
	//	position.z += 2.0f;
	//}
	//else if (Tr_Count == 0) {
	//	//���ɐi��
	//	position.z -= 2.0f;
	//}

	////����z����-13500�𒴂�����
	//if (position.z <= -13500.0f) {
	//	Tr_Count = 1;

	//}
	////����z����-1000�𒴂�����
	//if (position.z >= -1000.0f) {
	//	Tr_Count = 0;
	//}

	//���W��������
	//tr_modelRender.SetPosition(position);

}

void Track::Render(RenderContext& renderContext) {
	//�g���b�N�̕`��
	//tr_modelRender.Draw(renderContext);
}