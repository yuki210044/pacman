#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

namespace
{
    int count = 0;
    XMFLOAT3 nowMove = { 0,0,0 };
}
//�R���X�g���N�^
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//�f�X�g���N�^
Player::~Player()
{
    
}

//������
void Player::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("Pacman.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = XMFLOAT3(1.5, 0, 1.5);

    pStage = (Stage*)FindObject("Stage");
    assert(pStage != nullptr);
}

//�X�V
void Player::Update()
{
    //�ړ��O�̈ʒu�x�N�g��
    XMVECTOR prevPosition = XMLoadFloat3(&transform_.position_);
    
    if (Input::IsKey(DIK_W))
    {
        nowMove.z = 1;
        nowMove.x = 0;
    }
    if (Input::IsKey(DIK_S))
    {
        nowMove.z = -1;
        nowMove.x = 0;
    }if (Input::IsKey(DIK_A))
    {
        nowMove.x = -1;
        nowMove.z = 0;
    }if (Input::IsKey(DIK_D))
    {
        nowMove.x = 1;
        nowMove.z = 0;
    }
    if (count >= 10)
    {
        transform_.position_.x += nowMove.x;
        transform_.position_.z += nowMove.z;
        count = 0;
        nowMove = { 0,0,0 };
    }
    else
    {
        count++;
    }
    //���݂̈ʒu�x�N�g��
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_);

    //����̈ړ��x�N�g��
    move = nowPosition - prevPosition;

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

    //�ǂƂ̏Փ˔���
    int checkX, checkZ;

    //�E
        checkX = (int)(transform_.position_.x);
        checkZ = (int)transform_.position_.z;

        if (pStage->Iswall(checkX, checkZ))
        {
            XMStoreFloat3(&transform_.position_, prevPosition);
           // transform_.position_.x =  
              //  (float)((int)(transform_.position_.x + 0.5f)) - 0.3f; //�l�̌ܓ�0.5����
        }
    
    ////��
    //checkX = (int)(transform_.position_.x - 0.3f);
    //checkZ = (int)transform_.position_.z;

    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.x =
    //        (float)((int)(transform_.position_.x + 0.5f)) + 0.3f; //�l�̌ܓ�0.5����
    //}
    //
    ////��
    //checkX = (int)transform_.position_.x;
    //checkZ = (int)(transform_.position_.z + 0.3f);
    //
    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.z =
    //        (float)((int)(transform_.position_.z + 0.5f)) - 0.3f; //�l�̌ܓ�0.5����
    //}

    ////��
    //checkX = (int)transform_.position_.x;
    //checkZ = (int)(transform_.position_.z - 0.3f);

    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.z =
    //        (float)((int)(transform_.position_.z + 0.5f)) + 0.3f; //�l�̌ܓ�0.5����
    //}

}

//�`��
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//�J��
void Player::Release()
{
}