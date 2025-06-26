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

	//‚±‚±‚©‚çƒƒ“ƒo•Ï”
	//À•W
	Vector3 m_fiposition;
	//‰ñ“]
	Quaternion rot;
	Player* m_player;
	Vector3 firstPosition;//‰ŠúˆÊ’u

	int Fi_Count = 0;

	int m_rotState = 0;//‰ñ“]ó‘Ô‚ğŠÇ—‚·‚é•Ï”
};

