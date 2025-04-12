#pragma once
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Timer;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();

	Player* player;			 //プレイヤー。
	GameCamera* gameCamera;	 //ゲームカメラ。
	BackGround* backGround;  //背景
	//SoundSource* GameBGM;  //ゲーム中のBGM。
	FontRender fontRender;   //文字
	Timer* m_Timer;          //タイマー
};
