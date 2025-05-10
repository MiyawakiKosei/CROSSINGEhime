#pragma once
#include "k2EngineLow.h"

class WindZone;
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
	float windPower = 0.0f;        // 風の強さ（0.5fなど）

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
