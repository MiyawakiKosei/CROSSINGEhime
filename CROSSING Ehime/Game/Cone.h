#pragma once
#include "sound/SoundSource.h"

class Player;
class Score;
class Cone :public IGameObject {
public:
	Cone();
	~Cone();
	bool Start();
	void Update();
	void Render(RenderContext& renderContext);
	ModelRender m_cnmodelRender;


	//���W
	Vector3 m_cnposition;
	Player* m_player;
	Vector3 firstPosition; //�����ʒu
	Score* m_Score;
	SoundSource* m_ConeSE; //�R�[����SE

};

