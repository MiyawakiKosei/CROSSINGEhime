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


	//座標
	Vector3 m_cnposition;
	Player* m_player;
	Vector3 firstPosition; //初期位置
	Score* m_Score;
	SoundSource* m_ConeSE; //コーンのSE

};

