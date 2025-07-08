#pragma once

// ���[�f�B���O��ʗp�N���X
class Loading : public IGameObject {
public:
    Loading();
    ~Loading();
    bool Start() override;
    void Update() override;
    void Render(RenderContext& rc) override;

    // �J�ڐ�̃V�[����\���񋓌^
    enum class SceneType {
        Game,   // �Q�[���{�҂�
        Title   // �^�C�g����ʂ�
    };

    // ���ɑJ�ڂ���V�[���̐ݒ�
    void SetNextScene(SceneType next);



private:
    SpriteRender m_spriteRender;  // ���[�f�B���O��ʂ̃X�v���C�g
    SceneType m_nextScene = SceneType::Title; // ���ɑJ�ڂ���V�[���i�f�t�H���g�̓^�C�g���j
    float m_timer = 0.0f;         // ���[�h���o�p�^�C�}�[
    bool m_isLoaded = false;      // ���[�h�����t���O
};
