#include "Enemy2.h"
#include "Engine/Model.h"

namespace
{
}

Enemy2::Enemy2(GameObject* parent)
	: BasicEnemy(parent, "Enemy2", AHEAD)
{

}

void Enemy2::LoadModel()
{
    //モデルデータのロード
    hModel_ = Model::Load("enemyPacman2.fbx");
    assert(hModel_ >= 0);
}