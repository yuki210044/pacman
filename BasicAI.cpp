#include "BasicAI.h"

namespace
{
    int count = 0;
    int count2 = 0;
    int count3 = 21;
    XMFLOAT3 playPos;
};

BasicAI::BasicAI(Stage* pStage) : nowMove(0, 0, 0)
{
    assert(pStage != nullptr);
    pAstar = new Astar(pStage);


    count2 = pAstar->GetRoute().size() - 1;
}

XMFLOAT3 BasicAI::ChasePlayer(GameObject* pEnemy)
{
    XMFLOAT3 returnTrans = pEnemy->GetPosition();
    GameObject* pPlayer = pEnemy->FindObject("Player");
    if (pPlayer == nullptr)
    {
        return returnTrans;
    }
    playPos = pPlayer->GetPosition();

    if ((count2 < 0 || count3 > 20))
    {
            pAstar->InitSearch((int)pEnemy->GetPosition().x, (int)pEnemy->GetPosition().z, (int)playPos.x, (int)playPos.z);
            count2 = pAstar->GetRoute().size() - 2;
            count3 = 0;
            count = 0;
    }
    else
    {
        count3++;
    }

    if (count >= 21)
    {
        if (count2 >= 0)
        {
            route = pAstar->GetRoute()[count2];
            nowMove.x = ((route.x + 0.5f) - pEnemy->GetPosition().x) / 10;
            nowMove.z = ((route.y + 0.5f) - pEnemy->GetPosition().z) / 10;
            count = 0;
            count2--;
            returnTrans.x = route.x + 0.5f;
            returnTrans.z = route.y + 0.5f;
        }
    }
    else
    {
        count++;
    }
    return returnTrans;
}