#include "Wall.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
//コンストラクタ
Wall::Wall(GameObject* parent)
	: GameObject(parent, "Wall"), hModel_(-1)
{
}

//初期化
void Wall::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("Wall.fbx");
	assert(hModel_ >= 0);
}

//更新
void Wall::Update()
{
}

//描画
void Wall::Draw()
{
	//たくさんブロックを表示する
	for (int x = 0; x < 15; x++)
	{
		transform_.position_.x = x;
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
		
	for (int z = 0; z < 15; z++)
		{
			transform_.position_.z = z;
			Model::SetTransform(hModel_, transform_);
			Model::Draw(hModel_);
		}
	}
	Camera::SetPosition(XMFLOAT3(7, 5, -8));
	Camera::SetTarget(XMFLOAT3(7, 3, 0));
}



//開放
void Wall::Release()
{
}
