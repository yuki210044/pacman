#pragma once
#include "Engine/GameObject.h"
#include "Astar.h"
#include "Stage.h"

class BasicAI
{
protected:
	Astar* pAstar;
	Coordinate route;
	XMFLOAT3 nowMove;


public:
	BasicAI(Stage* pStage);

	/// <summary>
    /// AIの動きを決める関数
    /// </summary>
	virtual XMFLOAT3 ChasePlayer(GameObject *pEnemy);
};

