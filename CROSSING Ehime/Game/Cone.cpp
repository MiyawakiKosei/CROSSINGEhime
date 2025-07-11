#include "stdafx.h"
#include "Cone.h"
#include "Player.h"
#include "Score.h"
#include "sound/SoundEngine.h"

Cone::Cone() {
	//コーンのモデルを読み込む
	m_cnmodelRender.Init("Assets/modelData/cone/Cone02.tkm");
	m_cnmodelRender.SetScale(Vector3(2.0f, 2.0f, 2.0f));

	//SEの読み込み
	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/DamageSE.wav");
}

Cone::~Cone() {

}

bool Cone::Start() {
	//プレイヤーを見つける
	m_player = FindGO<Player>("player");
	m_Score = FindGO<Score>("score");

	return true;
}

void Cone::Update() {
	//コーンの移動処理
	m_cnmodelRender.SetPosition(m_cnposition);

	//絵描きさんの更新処理
	m_cnmodelRender.Update();

	//プレイヤーからコーンに向かうベクトルを求める
	Vector3 diff = m_player->m_position - m_cnposition;
	//ベクトルの長さが50.0f以下だったら
	if (diff.Length() <= 40.0f) {
		m_Score->score -= 5;
		// コーンのSEを再生
		m_ConeSE = NewGO<SoundSource>(0, "DamageSE");
		m_ConeSE->Init(4);
		m_ConeSE->Play(false);
		//音量を上げる
		m_ConeSE->SetVolume(5.0f);
		DeleteGO(this);//コーンを削除
	}
}

void Cone::Render(RenderContext& renderContext) {
	// コーンのモデルを描画
	m_cnmodelRender.Draw(renderContext);
}