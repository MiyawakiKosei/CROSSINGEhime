#pragma once
class Player;
class Orenge : public IGameObject
{
public:
	Orenge();
	~Orenge();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender m_ormodelRender;
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	//À•W
	Vector3 position;
	//‰ñ“]
	Quaternion rot;
	int orengeCount = 0;
	Player* player;
};

