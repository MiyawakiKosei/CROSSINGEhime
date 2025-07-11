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

	//ここからメンバ変数
	//座標
	Vector3 m_fiposition;
	//回転
	Quaternion rot;
	Player* m_player;
	Vector3 firstPosition;//初期位置

	int Fi_Count = 0;

	int m_rotState = 0;//回転状態を管理する変数
};

