#include "stdafx.h"
#include "Orange.h"
#include "Player.h"
#include "Score.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Orange::Orange() {
	////モデルを読み込む
	or_modelRender.Init("Assets/modelData/orenge/Orenge01.tkm");
	//SEを読み込む
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/coin04.wav");
	////プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("player");

		//m_ormodelRender.SetPosition(0.0f, 0.0f, -1000.0f);
}

Orange::~Orange() {

}

void Orange::Update() {

	Move();

	//絵描きさんの更新処理
	or_modelRender.Update();
	
	//プレイヤーからオレンジに向かうベクトルを求める
	Vector3 diff = player->m_position - m_orposition;
	//ベクトルの長さが70.0fより小さかったら
	if (diff.Length() <= 120.0f) {
		Score* score = FindGO<Score>("score");
		if (score != nullptr) {
			score->AddScore();  // これだけ呼ぶ
		}
		//SoundSourceのインスタンスを作成
		SoundSource* GameSE = NewGO<SoundSource>(0);
		GameSE->Init(2);
		GameSE->Play(false);
		//音量を上げる
		GameSE->SetVolume(3.5f);
		//自身を消去する
		DeleteGO(this);
	}
}

void Orange::Move() {
	//上下に移動させる
	if (Or_Count == 0) {
		//上
		m_orposition.y += 0.5f;
	}
	else if (Or_Count == 1) {
		//下
		m_orposition.y -= 0.5f;
	}

	//posisionyが初期位置+50を超えたら
	if (m_orposition.y >= firstPosition.y+30.0f) {
		//オレンジカウントを１にする
		Or_Count = 1;
	}
	//positionyが初期位置-50を超えたら
	else if (m_orposition.y <= firstPosition.y -30.0f) {
		//オレンジカウントを0にする
		Or_Count = 0;
	}
	
	//座標を教える
	or_modelRender.SetPosition(m_orposition);


}

void Orange::Render(RenderContext& renderContext) {
	//オレンジオブジェクトを描画
	or_modelRender.Draw(renderContext);
}
