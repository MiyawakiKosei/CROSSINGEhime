#pragma once

class Player;
//�Q�[���N���A
class GameClear:public IGameObject
{
public:
	GameClear();
	~GameClear();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender spriteRender;
};

