#include "FoolAI.h"

namespace
{
    int count = 0;
    int count2 = 0;
    int count3 = 21;
    int count4 = 0;
    XMFLOAT3 playPos;
};

FoolAI::FoolAI(Stage* pStage) : BasicAI(pStage)
{

}

XMFLOAT3 FoolAI::ChasePlayer(GameObject* pEnemy)
{
    XMFLOAT3 returnTrans = pEnemy->GetPosition();
    if (count4 > 60)
    {
        GameObject* pPlayer = pEnemy->FindObject("Player");
        if (pPlayer == nullptr)
        {
            return returnTrans;
        }
        playPos = pPlayer->GetPosition();

        if (count2 <= 0)
        {
            pAstar->InitSearch((int)pEnemy->GetPosition().x, (int)pEnemy->GetPosition().z, (int)playPos.x, (int)playPos.z);
            count2 = pAstar->GetRoute().size() - 1;
            count3 = 0;
            count = 0;
            count4 = 0;
        }
        else
        {
            count3++;
        }

        if (count >= 5)
        {
            if (count2 >= 0)
            {
                route = pAstar->GetRoute()[count2 - 1];
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
    }
    else
    {
        count4++;
    }
    return returnTrans;
}