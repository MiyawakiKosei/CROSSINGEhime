#pragma once
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

	//int gs_Count = 0;

};

