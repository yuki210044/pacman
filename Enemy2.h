#pragma once
#include "BasicEnemy.h"
#include "Player.h"

//�v���C���[����肷��AI
class Enemy2 : public BasicEnemy
{
public:

	Enemy2(GameObject* parent);
	void LoadModel() override;
};

