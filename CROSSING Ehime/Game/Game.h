#pragma once
#include "sound/SoundSource.h"
#include "DebugFont.h"
extern DebugFont g_debugFont;

class Player;
class GameCamera;
class BackGround;
class Timer;
class GameClear;
class GameOver;
class Title;
class GameUI;
class GameSelect;
class WindZone;

//Gameシーンを管理するクラス。
class Game : public IGameObject
{
public:
	Game();
	~Game();
	//更新処理。
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	Player* player;			 //プレイヤー。
	GameCamera* gameCamera;	 //ゲームカメラ。
	BackGround* backGround;  //背景
	//SoundSource* GameBGM;  //ゲーム中のBGM。
	FontRender fontRender;   //文字
	Timer* m_Timer;          //タイマー
	GameClear* m_gameClear;    //ゲームクリア
	GameOver* m_gameOver;
	Title* m_title;            //タイトル
	GameUI* m_GameUI;        //ゲームUI
	Timer* m_timer;
	GameSelect* m_gameSelect; //ゲームセレクト
	WindZone* m_windZone;     //風の領域

};
