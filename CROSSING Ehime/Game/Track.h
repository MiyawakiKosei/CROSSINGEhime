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
	//ここからメンバ変数
	//座標
	Vector3 position;
	//回転
	Quaternion rot;
	int Tr_Count = 1;
	Player* player;
	Vector3 firstPosition;

};


