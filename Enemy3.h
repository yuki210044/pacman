#pragma once
#include "BasicEnemy.h"


//動きが速いが頭が悪い
class Enemy3 : public BasicEnemy
{
public:
	Enemy3(GameObject* parent);
	void LoadModel() override;
};
