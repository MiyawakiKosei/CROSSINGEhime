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
	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	//À•W
	Vector3 m_orposition;
	//‰ñ“]
	Quaternion rot;
	int Or_Count = 0;
	int Or_Point = 0;
	Player* player;
	Vector3 firstPosition;//‰ŠúˆÊ’u
};

