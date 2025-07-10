#pragma once

class Player;
class Cone :public IGameObject {
public:
	Cone();
	~Cone();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender m_cnmodelRender;


	//À•W
	Vector3 m_cnposition;
	Player* m_player;
	Vector3 firstPosition; //‰ŠúˆÊ’u

};

