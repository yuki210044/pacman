#pragma once
#include "BasicEnemy.h"


//��������������������
class Enemy3 : public BasicEnemy
{
public:
	Enemy3(GameObject* parent);
	void LoadModel() override;
};
