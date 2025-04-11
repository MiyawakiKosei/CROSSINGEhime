#include "stdafx.h"
#include "Player.h"

Player::Player()
{
    //モデルを初期化する。
    modelRender.Init("Assets/modelData/unityChan.tkm");
    //↑                    //スペルミスに注意!!
    //ここも大文字のi
}

Player::~Player()
{

}

void Player::Update()
{
    //モデルを更新する。
    modelRender.Update();
    position.x = position.x + 1.0f;

    modelRender.SetPosition(position);

    modelRender.Update();
}

void Player::Render(RenderContext& renderContext)
{
    //モデルを表示する。
    modelRender.Draw(renderContext);
}