#pragma once
#include "sound/SoundSource.h"
class Player;
//�Q�[���Z���N�g
class GameSelect:public IGameObject
{
public:
	GameSelect();
	~GameSelect();
	//�`��֐�
	void Render(RenderContext& rc);
	//�X�V����
	void Update();
	//�X�v���C�g�����_�[
	SpriteRender spriteRender;

	SoundSource* m_GameSelectSE; //�Q�[���Z���N�g��SE

	//int gs_Count = 0;

};

