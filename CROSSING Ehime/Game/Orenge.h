#pragma once
class Player;
class Orenge : public IGameObject
{
public:
	Orenge();
	~Orenge();
	void Update();
	void Move();
	void Render(RenderContext& renderContext);
	ModelRender m_ormodelRender;
	//�������烁���o�ϐ�
	//���W
	Vector3 position;
	//��]
	Quaternion rot;
	int orengeCount = 0;
	Player* player;
	Vector3 firstPosition;//�����ʒu
};

