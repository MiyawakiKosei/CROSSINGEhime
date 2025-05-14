#include "stdafx.h"
#include "Track.h"
#include "Player.h"

Track::Track() 
{
	//モデルを読み込む
	//tr_modelRender.Init("Assets/modelData/track/Track01.tkm");

	//プレイヤーのオブジェクトを引っ張ってくる
	////player = FindGO<Player>("player");
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
	//if (Tr_Count == 1) {
	//	//前に進む
	//	position.z += 2.0f;
	//}
	//else if (Tr_Count == 0) {
	//	//後ろに進む
	//	position.z -= 2.0f;
	//}

	////もしz軸が-13500を超えたら
	//if (position.z <= -13500.0f) {
	//	Tr_Count = 1;

	//}
	////もしz軸が-1000を超えたら
	//if (position.z >= -1000.0f) {
	//	Tr_Count = 0;
	//}

	//座標を教える
	//tr_modelRender.SetPosition(position);

}

void Track::Render(RenderContext& renderContext) {
	//トラックの描画
	//tr_modelRender.Draw(renderContext);
}