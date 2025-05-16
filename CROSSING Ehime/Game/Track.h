#pragma once
class Player;
class Track : public IGameObject 
{
public:
	Track();
	~Track();
	void Update();
	void Move();
	void Render(RenderContext& renderContext);
	ModelRender tr_modelRender;
	//�������烁���o�ϐ�
	//���W
	Vector3 position;
	//��]
	Quaternion rot;
	int Tr_Count = 1;
	Player* player;
	//Vector3 firstPosition;

};


