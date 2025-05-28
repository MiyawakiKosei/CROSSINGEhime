#pragma once
#include "k2EngineLow.h"
#include <Track.h>

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
	const Vector3& GetPosition() const
	{
		return m_position;
	}

	//メンバ変数。
	float windPower = 0.0f;        // 風の強さ（0.5fなど）

	ModelRender m_bgmodelRender;	    //モデルレンダ―。
	ModelRender m_boardModel;	//ボードモデル。
	Vector3 m_position;               //座標。
	Vector3 moveSpeed;

	CharacterController& GetCharacterController()
	{
		return m_characterController;
	}
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Start,
		enAnimationClip_Push,
		enAnimationClip_Run,
		enAnimationClip_Drift,
		enAnimationClip_Num,
	};
	AnimationClip animationClips[enAnimationClip_Num];//アニメーションクリップ。
	AnimationClip m_boardAnimClips[enAnimationClip_Num];//ボードのアニメーションクリップ。
	
	//Vector3 moveSpeed;		//移動速度。
	Quaternion rotX, rotY; //クォータニオン。
	Quaternion rotation; //クォータニオン。
	//int playerState = 0;	//プレイヤーのステート(状態)を表す変数。
	//int starCount = 0;	//集めた☆の数をカウントする。

	int P_Count = 0;
private:
	
	CharacterController m_characterController;  //キャラクターコントローラー。
	Vector3				m_scale = Vector3::One;
};
