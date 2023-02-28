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
    //移動前の位置ベクトル
    XMVECTOR prevPosition = XMLoadFloat3(&transform_.position_);

    transform_.position_ = ai->ChasePlayer(this);

    //現在の位置ベクトル
    XMVECTOR nowPosition = XMLoadFloat3(&transform_.position_);

    //今回の移動ベクトル
    XMVECTOR move = nowPosition - prevPosition;

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
    //モデルデータのロード
    hModel_ = Model::Load("enemyPacman.fbx");
    assert(hModel_ >= 0);
}