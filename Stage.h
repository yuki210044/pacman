#pragma once
#include "Engine/GameObject.h"

static const int mapSize = 15;
//◆◆◆を管理するクラス
class Stage : public GameObject
{
    int hModel_[2];    //モデル番号
    
    int map_[mapSize][mapSize];

public:
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    //そこが壁かどうか
    bool Iswall(int x, int z);

    int GetModelHandle() { return hModel_[1]; }
};