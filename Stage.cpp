#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"//マップ出す用
//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage")/*, hModel_(-1)*/
{
    
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //モデルデータのロード
    hModel_[1] = Model::Load("Wall.fbx");
    assert(hModel_[1] >= 0);

    //モデルデータのロード
    hModel_[0] = Model::Load("Floor.fbx");
    assert(hModel_[0] >= 0);

    CsvReader csv;
    csv.Load("Map.csv");

    for (int x = 0; x < mapSize; x++) {
        for (int z = 0; z < mapSize; z++) {
            map_[x][z] = csv.GetValue(x, z);
        }
    }
    //csv.GetValue(3, 1);//値を返す

}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    for (int x = 0; x < mapSize; x++) {
        for (int z = 0; z < mapSize; z++)
        {
            int type = map_[x][z];
            transform_.position_.x = x;
            transform_.position_.z = z;
            Model::SetTransform(hModel_[type], transform_);
            Model::Draw(hModel_[type]);
        }
    }
}

//開放
void Stage::Release()
{
}

//壁かどうか確かめる
bool Stage::Iswall(int x, int z)
{
    return map_[x][z] == 1;

    //↑これと同じ
    /*if (map_[x][z] == 0) 
    {
        return false;
    }
    else
    {
        return true;
    }*/
}
