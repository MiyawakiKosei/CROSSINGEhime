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
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	//À•W
	Vector3 position;
	//‰ñ“]
	Quaternion rot;
	int moveCount = 0;
	Player* player;
};

