#pragma once
#include "BasicEnemy.h"
#include "Player.h"

//ƒvƒŒƒCƒ„[‚ğæ‰ñ‚è‚·‚éAI
class Enemy2 : public BasicEnemy
{
public:

	Enemy2(GameObject* parent);
	void LoadModel() override;
};

