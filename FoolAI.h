#pragma once
#include "BasicAI.h"
#include "Stage.h"

class FoolAI : public BasicAI
{
public:
	FoolAI(Stage* pStage);
	XMFLOAT3 ChasePlayer(GameObject* pEnemy) override;
};

