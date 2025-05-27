#include "stdafx.h"
#include "Track.h"
#include "Player.h"

Track::Track() 
{
	//モデルを読み込む
	tr_modelRender.Init("Assets/modelData/track/Track04.tkm");

	//プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("player");
}

Track::~Track() {

}

void Track::Update() {

	Move();

	//絵描きさんの更新処理
	tr_modelRender.Update();

}

void Track::Move() {
	//前後に移動させる
	if (Tr_Count == 1) {
		//前に進む
		position.z += 10.0f;
	}
	else if (Tr_Count == 0) {
		//後ろに進む
		position.z -= 10.0f;
	}

	//もしz軸が-1000を超えたら
	if (position.z <= -1000.0f) {
		Tr_Count = 1;
		rot.SetRotationDegY(360.0f);
	}
	//もしz軸が-500を超えたら
	if (position.z >= -500.0f) {
		Tr_Count = 0;
		rot.SetRotationDegY(180.0f);
	}

	//座標を教える
	tr_modelRender.SetPosition(position);

	//回転を教える
	tr_modelRender.SetRotation(rot);
}

void Track::Render(RenderContext& renderContext) {
	//トラックの描画
	tr_modelRender.Draw(renderContext);
}