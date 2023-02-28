#include "BasicEnemy.h"
#include "Engine/Model.h"
#include "Stage.h"
#include "AheadAI.h"
#include "FoolAI.h"

namespace
{
    int setAINumber = 0;

   
}

BasicEnemy::BasicEnemy(GameObject* parent, std::string objectName, int aiNumber)
    : GameObject(parent, objectName), hModel_(-1), pStage(nullptr), nowMove(0, 0, 0),ai(nullptr)
{
    setAINumber = aiNumber;
}

void BasicEnemy::Initialize()
{
    LoadModel();
    pStage = (Stage*)FindObject("Stage");
    assert(pStage != nullptr);
   
    switch (setAINumber)
    {
    case BASIC:
        ai = new BasicAI(pStage);
        break;
    case AHEAD:
        ai = new AheadAI(pStage);
        break;
    case FOOL:
        ai = new FoolAI(pStage);
        break;
    default:
        ai = new BasicAI(pStage);
        break;
    }

}

void BasicEnemy::Update()
{
    //�ړ��O�̈ʒu�x�N�g��
    XMVECTOR prevPosition = XMLoadFloat3(&transform_.position_);

    transform_.position_ = ai->ChasePlayer(this);

    //���݂̈ʒu�x�N�g��
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_);

    //����̈ړ��x�N�g��
    XMVECTOR move = nowPosition - prevPosition;

    //�ړ��x�N�g���̒����𑪂�
    XMVECTOR length = XMVector3Length(move);

    //0.1�ȏ�ړ����Ă��Ȃ��]����
    if (XMVectorGetX(length) > 0)
    {
        //�p�x�����߂邽�߂ɒ�������ɂ��鐳�K��
        move = XMVector3Normalize(move);

        //��ƂȂ�x�N�g��
        XMVECTOR front = { 0,0,1,0 };

        //front��move�̓��ς����߂�
        XMVECTOR vecDot = XMVector3Dot(front, move);
        float dot = XMVectorGetX(vecDot);//�x�N�g���𔲂����

        //�����Ă���p�x�����߂�i���W�A���j
        float angle = acos(dot);

        //front��move�̊O�ς����߂�
        XMVECTOR cross = XMVector3Cross(front, move);


        //�O�ς̌��ʂ��}�C�i�X = ������ �� ���ɐi��ł�
        if (XMVectorGetY(cross) < 0)
        {
            angle *= -1;
        }

        //���̕���]������
        transform_.rotate_.y = angle * 180.0f / 3.14f;

    }
}

void BasicEnemy::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void BasicEnemy::Release()
{

}

void BasicEnemy::LoadModel()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("enemyPacman.fbx");
    assert(hModel_ >= 0);
}