#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
#include "Astar.h"
#include "BasicAI.h"

enum AI
{
    BASIC = 0,
    AHEAD,
    FOOL,
};

//AIの基底クラス
class BasicEnemy : public GameObject
{
    
    Stage* pStage;
    BasicAI* ai;

protected:
    int hModel_;
    XMFLOAT3 nowMove;
public:
    
    BasicEnemy(GameObject* parent, std::string objectName, int aiNumber);
    //初期化
    virtual void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;

    /// <summary>
    /// 継承先のEnemyのモデルが違う場合はここで変更する
    /// </summary>
    virtual void LoadModel();

     Stage* GetStage() { return pStage; }


};

