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
	//ここからメンバ変数
	//座標
	Vector3 position;
	//回転
	Quaternion rot;
	int moveCount = 0;
	Player* player;
};

