#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    //���f��������������B
    modelRender.Init("Assets/modelData/unityChan.tkm");
    //��                    //�X�y���~�X�ɒ���!!
    //�������啶����i
}

Player::~Player()
{

}

void Player::Update()
{
    //���f�����X�V����B
    modelRender.Update();
    position.x = position.x + 1.0f;

    modelRender.SetPosition(position);

    modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
    //���f����\������B
    modelRender.Draw(renderContext);
}