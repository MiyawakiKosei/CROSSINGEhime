#pragma once

class Player;
class Fish : public IGameObject {
public:
	Fish();
	~Fish();
	void Update();
	void Move();
	void Rotation();
	void State();
	void Render(RenderContext& renderContext);
	ModelRender m_fimodelRender;

	//�������烁���o�ϐ�
	//���W
	Vector3 m_fiposition;
	//��]
	Quaternion rot;
	Player* m_player;
	Vector3 firstPosition;//�����ʒu

	int Fi_Count = 0;

	int m_rotState = 0;//��]��Ԃ��Ǘ�����ϐ�
};

