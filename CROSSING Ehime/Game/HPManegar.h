#pragma once
class Player;
class Timer;
class Score;
class Game;

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
		en_LowHP, //1,2
		en_MidHP, //3�@�@
		en_HighHP,//4�@�@�@�@
		en_MaxHP, //5�@�ő�̗�
	};

private:
	SpriteRender m_fontRender;
	
};

