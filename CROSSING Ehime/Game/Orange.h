#pragma once
class Player;
class Orange : public IGameObject
{
public:
	Orange();
	~Orange();
	void Update();
	void Move();
	void Render(RenderContext& renderContext);
	ModelRender or_modelRender;
	//ここからメンバ変数
	//座標
	Vector3 m_orposition;
	//回転
	Quaternion rot;
	int Or_Count = 0;
	int Or_Point = 0;
	Player* player;
	Vector3 firstPosition;//初期位置
};

