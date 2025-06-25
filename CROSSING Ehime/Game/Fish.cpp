#include "stdafx.h"
#include "Fish.h"
#include "Player.h"

Fish::Fish() {
	//���f����ǂݍ���
	m_fimodelRender.Init("Assets/modelData/fish/fish01.tkm");
	//�v���C���[�̈ʒu���擾
	player = FindGO<Player>("player");
}

Fish::~Fish() {

}

void Fish::Update() {
	Move();
	Rotation();
	State();

	//���W��������
	m_fimodelRender.SetPosition(m_fiposition);

	//��]��������
	//m_fimodelRender.SetRotation(rot);
	
	m_fimodelRender.Update();

	//�v���C���[���狛�Ɍ������x�N�g�������߂�
	Vector3 diff = player->m_position - m_fiposition;
	//�x�N�g���̒�����40.0f��菬����������
	if (diff.Length() <= 70.0f) {
		//���g����������
		DeleteGO(this);
	}


}

void Fish::Move() {
	/*if (Fi_Count == 0) {
		m_fiposition.x -= 5.0f;
		m_fiposition.y += 1.5f;
	}
	else if (Fi_Count == 1) {
		m_fiposition.x -= 5.0f;
		m_fiposition.y -= 1.5f;
	}
	else if (Fi_Count == 2) {
		m_fiposition.x += 200.0f;
		m_fiposition.y += 0.5f;
	}*/

	if (Fi_Count == 0) {
		if (m_fiposition.x >= 0.0f) {
			m_fiposition.x -= 5.0f;
		    m_fiposition.y += 1.75f;
		}
		else if(m_fiposition.x< 0.0f) {
			m_fiposition.x -= 5.0f;
			m_fiposition.y -= 1.75f;
		}
	}
	else if (Fi_Count == 1) {
		if (m_fiposition.x <= 0.0f) {
			m_fiposition.x += 5.0f;
			m_fiposition.y += 1.75f;
		}
		else if (m_fiposition.x > 0.0f) {
			m_fiposition.x += 5.0f;
			m_fiposition.y -= 1.75f;
		}
	}
	else if (Fi_Count == 2) {
		m_fiposition.y += 1.0f;
		/*if (m_fiposition.x < 0.0f) {
			rot.SetRotationDegY(0.0f);
			Fi_Count = 1;
		}
		else if (m_fiposition.x >= 0.0f) {
			rot.SetRotationDegY(180.0f);
			Fi_Count = 0;
		}*/
	}
	
}

void Fish::Rotation() {
	/*if (Fi_Count == 0) {
		
	}
	else if (Fi_Count == 1) {
		
	}
	else if (Fi_Count == 2) {
		
	}*/

	switch (Fi_Count) {
	case 0:
		// �E����
		rot.SetRotationDegY(0.0f);
		if (m_fiposition.x >= 0.0f) {
			rot.AddRotationZ(-220.0f);
			m_fimodelRender.SetRotation(rot);
		}
		else if (m_fiposition.x < 0.0f) {
			rot.AddRotationDegZ(25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		m_fimodelRender.SetRotation(rot);
		break;
	case 1:
		// ������
		rot.SetRotationDegY(180.0f);
		if (m_fiposition.x <= 0.0f) {
			rot.AddRotationDegZ(-25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		else if (m_fiposition.x > 0.0f) {
			rot.AddRotationDegZ(25.0f);
			m_fimodelRender.SetRotation(rot);
		}
		m_fimodelRender.SetRotation(rot);
		break;
	}
}

void Fish::State() {
	/*if (m_fiposition.x > 0.0f&&m_fiposition.y>=-9.0f) {
		Fi_Count = 0;
	}
	else if (m_fiposition.x <= 0.0f && m_fiposition.y > -6.0f) {
		Fi_Count = 1;
	}
	else if (m_fiposition.y <= -10.0f) {
		Fi_Count = 2;
	}*/

	/*if (m_fiposition.x > 0.0f && m_fiposition.y >= -15.0f) {
		Fi_Count = 0;
	}
	else if (m_fiposition.x <= 0.0f && m_fiposition.y > -15.0f) {
		Fi_Count = 1;
	}*/

	if (m_fiposition.y <= -100.0f) {
		Fi_Count = 2;
	}

	if (Fi_Count==2){
		if (m_fiposition.x < 0.0f) {
			//rot.SetRotationDegY(0.0f);
			Fi_Count = 1;
		}
		else if (m_fiposition.x >= 0.0f) {
			//rot.SetRotationDegY(180.0f);
			Fi_Count = 0;
		}
	}
}

void Fish::Render(RenderContext& rc) {
	//���I�u�W�F�N�g��`��
	m_fimodelRender.Draw(rc);
}