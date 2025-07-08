#pragma once

// ローディング画面用クラス
class Loading : public IGameObject {
public:
    Loading();
    ~Loading();
    bool Start() override;
    void Update() override;
    void Render(RenderContext& rc) override;

    // 遷移先のシーンを表す列挙型
    enum class SceneType {
        Game,   // ゲーム本編へ
        Title   // タイトル画面へ
    };

    // 次に遷移するシーンの設定
    void SetNextScene(SceneType next);



private:
    SpriteRender m_spriteRender;  // ローディング画面のスプライト
    SceneType m_nextScene = SceneType::Title; // 次に遷移するシーン（デフォルトはタイトル）
    float m_timer = 0.0f;         // ロード演出用タイマー
    bool m_isLoaded = false;      // ロード完了フラグ
};
