class HPManager : public IGameObject
{
public:
    ~HPManager();
    bool Start();
    void Update();
    void Render(RenderContext& rc);

    enum enHPState {
        en_ZeroHP = 0,
        en_LowHP,
        en_MidLowHP,
        en_MidHighHP,
        en_HighHP,
        en_MaxHP,
    };

    int m_Hp = en_MaxHP; 

    SpriteRender m_hpSprite;
};


