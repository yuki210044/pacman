#include "AheadAI.h"

namespace
{
    int count = 0;
    int count2 = 0;
    int count3 = 21;
    XMFLOAT3 playPos;
};

AheadAI::AheadAI(Stage* pStage) : BasicAI(pStage)
{

}

XMFLOAT3 AheadAI::ChasePlayer(GameObject* pEnemy)
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
        pAstar->InitSearch((int)playPos.x, (int)playPos.z, (int)pEnemy->GetPosition().x, (int)pEnemy->GetPosition().z);
        count2 = pAstar->GetRoute().size() - 5;
        if (count2 < 0)
        {
            count2 = 0;
        }
        Coordinate r = pAstar->GetRoute()[count2];
        pAstar->InitSearch((int)pEnemy->GetPosition().x, (int)pEnemy->GetPosition().z, r.x, r.y);
        count2 = pAstar->GetRoute().size() - 2;
        count3 = 0;
        count = 0;
    }
    else
    {
        count3++;
    }

    if (count >= 15)
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