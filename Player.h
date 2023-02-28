#pragma once
#include "Engine/GameObject.h"
#include "Stage.h"
//���������Ǘ�����N���X
class Player : public GameObject
{
    int hModel_;    //���f���ԍ�
    Stage* pStage;
    XMVECTOR prevPosition;
public:
    XMVECTOR move;
    //�R���X�g���N�^
    Player(GameObject* parent);

    //�f�X�g���N�^
    ~Player();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};