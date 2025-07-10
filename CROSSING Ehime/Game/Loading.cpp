#include "stdafx.h"
#include "Loading.h"
#include "Game.h"
#include "Title.h"

Loading::Loading() {}

Loading::~Loading() {}

bool Loading::Start() {
    m_spriteRender.Init("Assets/sprite/Loading.DDS", 1920.0f, 1080.0f);
    return true;
}

void Loading::Update() {
    m_timer += g_gameTime->GetFrameDeltaTime();

    if (m_timer > 1.5f && !m_isLoaded) {
        m_isLoaded = true;

        switch (m_nextScene) {
        case SceneType::Game:
            NewGO<Game>(0, "game");
            break;
        case SceneType::Title:
            NewGO<Title>(0, "title");
            break;
        }
        DeleteGO(this);
    }
}

void Loading::Render(RenderContext& rc) {
    m_spriteRender.Draw(rc);
}

void Loading::SetNextScene(SceneType next) {
    m_nextScene = next;
}
