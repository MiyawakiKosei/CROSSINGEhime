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
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	//À•W
	Vector3 position;
	//‰ñ“]
	Quaternion rot;
	int Tr_Count = 1;
	Player* player;
	//Vector3 firstPosition;

};


