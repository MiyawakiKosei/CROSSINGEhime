#pragma once
class Player;
class Timer;
class Score;
class Game;
class GameUI;

class HPManegar: public IGameObject
{
public:
	~HPManegar();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	enum enHPState //������enum�@�̗͂ɉ����ĕω����������p�X�e�[�g
	{
		en_ZeroHP,//0�@�@��
		en_LowHP, //1
		en_MidLowHP, //2
		en_MidHighHP, //3�@�@
		en_HighHP,//4�@�@�@�@
		en_MaxHP, //5�@�ő�̗�
	};

	enHPState m_Hp = en_MaxHP;//5
	SpriteRender m_hpSprite; // HP�̃X�v���C�g

private:
	


};

