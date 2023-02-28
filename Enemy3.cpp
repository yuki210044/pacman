#include "Enemy3.h"
#include "Engine/Model.h"

namespace
{
}
Enemy3::Enemy3(GameObject* parent)
	: BasicEnemy(parent, "Enemy3", FOOL)
{

}

void Enemy3::LoadModel()
{
    //モデルデータのロード
    hModel_ = Model::Load("enemyPacman3.fbx");
    assert(hModel_ >= 0);
}