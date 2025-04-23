#pragma once
#include "k2EngineLow.h"
//プレイヤークラス。
class Player : public IGameObject
{
public:
	Player();
	~Player();
	//更新処理。
	void Update();

	//描画処理。
	void Render(RenderContext& rc);
	//移動処理
	void Move();
	//void SetPosition(const Vector3& pos);
	//回転処理
	void Rotation();

	//メンバ変数。
	// 風関連の変数。
	float windTriggerZ = 0.0f;     // 風が吹くZ座標（ランダムに決める）
	bool windActive = false;      // 風が吹いているかどうか
	float windForceX = 0.0f;       // X方向の風の強さ（±で左右どちらか）
	int windDuration = 0;          // 風が吹いてる残り時間（フレーム数）
	float windPower = 0.5f;        // 風の強さ（0.5fなど）

	ModelRender m_bgmodelRender;	    //モデルレンダ―。
	Vector3 position;               //座標。
	Vector3 moveSpeed;
	//enum EnAnimationClip {		//アニメーション。
	//	enAnimationClip_Idle,
	//	enAnimationClip_Walk,
	//	enAnimationClip_Jump,
	//	enAnimationClip_Num,
	//};
	//AnimationClip animationClips[enAnimationClip_Num];		//アニメーションクリップ。
	CharacterController characterController;  //キャラクターコントローラー。
	//Vector3 moveSpeed;		//移動速度。
	Quaternion rotation;  //クォータニオン。
	//int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	//int starCount = 0;	//集めた☆の数をカウントする。

	int P_Count = 0;
};
