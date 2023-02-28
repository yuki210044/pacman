#pragma once
#include "Engine/GameObject.h"

static const int mapSize = 15;
//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hModel_[2];    //���f���ԍ�
    
    int map_[mapSize][mapSize];

public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;

    //�������ǂ��ǂ���
    bool Iswall(int x, int z);

    int GetModelHandle() { return hModel_[1]; }
};