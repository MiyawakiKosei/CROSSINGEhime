#pragma once

class Player;
class GameOver:public IGameObject
{
public:
	GameOver();
	~GameOver();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender spriteRender;
};

