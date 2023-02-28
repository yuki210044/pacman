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

//AI�̊��N���X
class BasicEnemy : public GameObject
{
    
    Stage* pStage;
    BasicAI* ai;

protected:
    int hModel_;
    XMFLOAT3 nowMove;
public:
    
    BasicEnemy(GameObject* parent, std::string objectName, int aiNumber);
    //������
    virtual void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    /// <summary>
    /// �p�����Enemy�̃��f�����Ⴄ�ꍇ�͂����ŕύX����
    /// </summary>
    virtual void LoadModel();

     Stage* GetStage() { return pStage; }


};

