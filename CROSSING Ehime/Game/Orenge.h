#pragma once
class Player;
class Orenge : public IGameObject
{
public:
	Orenge();
	~Orenge();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender modelRender;
	//�������烁���o�ϐ�
	//���W
	Vector3 position;
	//��]
	Quaternion rot;
	int moveCount = 0;
	Player* player;
};

