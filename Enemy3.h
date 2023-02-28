#pragma once
#include "BasicEnemy.h"


//“®‚«‚ª‘¬‚¢‚ª“ª‚ªˆ«‚¢
class Enemy3 : public BasicEnemy
{
public:
	Enemy3(GameObject* parent);
	void LoadModel() override;
};
