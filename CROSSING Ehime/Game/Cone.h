#pragma once

class Player;
class Cone :public IGameObject {
public:
	Cone();
	~Cone();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender m_cnmodelRender;


	//座標
	Vector3 m_cnposition;
	Player* player;
	Vector3 firstPosition; //初期位置

};

