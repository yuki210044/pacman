#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

namespace
{
    int count = 0;
    XMFLOAT3 nowMove = { 0,0,0 };
}
//コンストラクタ
Player::Player(GameObject* parent)
    :GameObject(parent, "Player"), hModel_(-1)
{
}

//デストラクタ
Player::~Player()
{
    
}

//初期化
void Player::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("Pacman.fbx");
    assert(hModel_ >= 0);
    transform_.position_ = XMFLOAT3(1.5, 0, 1.5);

    pStage = (Stage*)FindObject("Stage");
    assert(pStage != nullptr);
}

//更新
void Player::Update()
{
    //移動前の位置ベクトル
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
    //現在の位置ベクトル
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_);

    //今回の移動ベクトル
    move = nowPosition - prevPosition;

    //移動ベクトルの長さを測る
    XMVECTOR length = XMVector3Length(move);

    //0.1以上移動してたなら回転処理
    if (XMVectorGetX(length) > 0)
    {
        //角度を求めるために長さを一にする正規化
        move = XMVector3Normalize(move);

        //基準となるベクトル
        XMVECTOR front = { 0,0,1,0 };

        //frontとmoveの内積を求める
        XMVECTOR vecDot = XMVector3Dot(front, move);
        float dot = XMVectorGetX(vecDot);//ベクトルを抜き取る

        //向いている角度を求める（ラジアン）
        float angle = acos(dot);

        //frontとmoveの外積を求める
        XMVECTOR cross = XMVector3Cross(front, move);


        //外積の結果がマイナス = 下向き ＝ 左に進んでる
        if (XMVectorGetY(cross) < 0)
        {
            angle *= -1;
        }

        //その分回転させる
        transform_.rotate_.y = angle * 180.0f / 3.14f;

    }

    //壁との衝突判定
    int checkX, checkZ;

    //右
        checkX = (int)(transform_.position_.x);
        checkZ = (int)transform_.position_.z;

        if (pStage->Iswall(checkX, checkZ))
        {
            XMStoreFloat3(&transform_.position_, prevPosition);
           // transform_.position_.x =  
              //  (float)((int)(transform_.position_.x + 0.5f)) - 0.3f; //四捨五入0.5足す
        }
    
    ////左
    //checkX = (int)(transform_.position_.x - 0.3f);
    //checkZ = (int)transform_.position_.z;

    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.x =
    //        (float)((int)(transform_.position_.x + 0.5f)) + 0.3f; //四捨五入0.5足す
    //}
    //
    ////上
    //checkX = (int)transform_.position_.x;
    //checkZ = (int)(transform_.position_.z + 0.3f);
    //
    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.z =
    //        (float)((int)(transform_.position_.z + 0.5f)) - 0.3f; //四捨五入0.5足す
    //}

    ////下
    //checkX = (int)transform_.position_.x;
    //checkZ = (int)(transform_.position_.z - 0.3f);

    //if (pStage->Iswall(checkX, checkZ))
    //{
    //    //XMStoreFloat3(&transform_.position_, prevPosition);
    //    transform_.position_.z =
    //        (float)((int)(transform_.position_.z + 0.5f)) + 0.3f; //四捨五入0.5足す
    //}

}

//描画
void Player::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

//開放
void Player::Release()
{
}