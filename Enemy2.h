#pragma once
#include "BasicEnemy.h"
#include "Player.h"

//プレイヤーを先回りするAI
class Enemy2 : public BasicEnemy
{
public:

	Enemy2(GameObject* parent);
	void LoadModel() override;
};

