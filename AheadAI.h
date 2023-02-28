#pragma once
#include "BasicAI.h"
#include "Stage.h"
class AheadAI : public BasicAI
{
public:
	AheadAI(Stage* pStage);
	XMFLOAT3 ChasePlayer(GameObject* pEnemy) override;
};

