#pragma once
#include "sound/SoundSource.h"

class Player;
//�^�C�g��
class Title:public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	//�`��֐�
	void Render(RenderContext& rc);
	//�X�V����
	void Update();
	

private:
	//�^�C�g����BGM
	SoundSource* titleBGM;

	FontRender		m_fontRender;				//�t�H���g�����_�[�B
	SpriteRender	m_spriteRender;				//�X�v���C�g�����_�[�B
	SoundSource* m_ClickSE;				//�N���b�NSE
};

