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
class Cone;
class Fish;


class Game : public IGameObject
{
public:
	Game();
	~Game();
	
	void Update();
	void CreateObject();
	void Render(RenderContext& rc);


	bool m_hasStartedCountDown = false;  // カウントダウン開始フラグ
	bool m_bgmStarted = false;           // BGM再生フラグ

	Player* player;		
	GameCamera* gameCamera;	
	BackGround* backGround; 
	SoundSource* GameBGM;  
	SoundSource* GameSE;
	FontRender fontRender; 
	ModelRender modelRender;
	Timer* m_Timer;          
	GameClear* m_gameClear;  
	GameOver* m_gameOver;
	Title* m_title;           
	GameUI* m_GameUI;        
	Timer* m_timer;
	GameSelect* m_gameSelect; 
	Orange* m_Orange[34]; //最初のオレンジ
	Orange* m_OrangeLeft[34]; //左のオレンジ
	Orange* m_OrangeRight[34]; //右のオレンジ
	//Orange* m_Orange; //オレンジ
	//Orange* m_firstOrange;//オレンジ1
	//Orange* m_secondOrange;//オレンジ2
	//Orange* m_thirdOrange;//オレンジ3
	//Orange* m_fourthOrange;//オレンジ4
	//Orange* m_fifthOrange;//オレンジ5
	//Orange* m_sixthOrange;//オレンジ6
	//Orange* m_seventhOrange;//オレンジ7
	//Orange* m_eighthOrange; //オレンジ8
	//Orange* m_ninthOrange; //オレンジ9
	Track* m_Track; //トラック
	Track* m_rightTrack;//トラック1
	Track* m_leftTrack;//トラック2
	Track* m_middleTrack; //トラック3
	Track* m_finalTrack; //トラック4
	Track* m_firstTrack;//トラック5
	WindZone* m_windZone; 
	Cone* m_cone; //コーン0
	Cone* m_firstcone; //コーン1
	Cone* m_secondcone; //コーン2
	Cone* m_thirdcone; //コーン3
	Cone* m_fourthcone; //コーン4
	Cone* m_fifthcone; //コーン5
	Cone* m_sixthcone; //コーン6
	Cone* m_seventhcone; //コーン7
	Cone* m_eighthcone; //コーン8
	Cone* m_ninthcone; //コーン9
	Cone* m_tenthcone; //コーン10
	Cone* m_eleventhcone; //コーン11
	Cone* m_twelfthcone; //コーン12
	Cone* m_thirteenthcone; //コーン13
	Fish* m_fish; //魚
	Fish* m_firstfish; //魚１
	Fish* m_secondfish; //魚２
	Fish* m_thirdfish; //魚３
	Fish* m_fourthfish; //魚４
	Fish* m_fifthfish; //魚５

};
