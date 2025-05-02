#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "GameSelect.h"
 
Title::Title() {
	//画像を読み込む
	spriteRender.Init("Assets/modelData/title/title03.DDS",1920.0f,1080.0f);

	//タイトルのBGMを読み込む
	//g_soundEngine->ResistWaveFileBank(0, "");

	//タイトルのBGMを再生する
	/*titleBGM = NewGO<SoundSource>(0);
	titleBGM->Init(0);
	titleBGM->Play(true);*/

}

Title::~Title() {

}

void Title::Update() 
{
	if (g_pad[0]->IsTrigger(enButtonA)) 
	{

		NewGO<GameSelect>(0);
		DeleteGO(this);

		/*NewGO<Game>(0);
		DeleteGO(this);*/
	}
}

void Title::Render(RenderContext& rc) {
	//画像を描画する
	spriteRender.Draw(rc);
}