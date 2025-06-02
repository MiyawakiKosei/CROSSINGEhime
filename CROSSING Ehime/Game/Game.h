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
class Orange;
class Track;
class WindZone;


class Game : public IGameObject
{
public:
	Game();
	~Game();
	
	void Update();
	
	void Render(RenderContext& rc);

	Player* player;		
	GameCamera* gameCamera;	
	BackGround* backGround; 
	//SoundSource* GameBGM;  
	FontRender fontRender; 
	ModelRender modelRender;
	Timer* m_Timer;          
	GameClear* m_gameClear;  
	GameOver* m_gameOver;
	Title* m_title;           
	GameUI* m_GameUI;        
	Timer* m_timer;
	GameSelect* m_gameSelect; 
	Orange* m_Orange; //最初のオレンジ
	Orange* m_rightOrange;//右のオレンジ
	Orange* m_leftOrange;//左のオレンジ
	Orange* m_middleOrange;//中央のオレンジ
	Track* m_rightTrack;//右トラック
	Track* m_leftTrack;//左トラック
	WindZone* m_windZone;   
};
