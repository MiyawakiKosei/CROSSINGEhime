#pragma once
#include "sound/SoundSource.h"

class Player;
//�^�C�g��
class Title:public IGameObject
{
public:
	Title();
	~Title();
	//�`��֐�
	void Render(RenderContext& rc);
	//�X�V����
	void Update();
	//�X�v���C�g�����_�[
	SpriteRender spriteRender;
	//�^�C�g����BGM
	SoundSource* titleBGM;
};

