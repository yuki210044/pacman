#include "PlayScene.h"
#include "Stage.h"
#include"Player.h"
#include "Engine/Camera.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Engine/Input.h"
//コンストラクタ
PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent, "PlayScene")
{
}

//初期化
void PlayScene::Initialize()
{
	Camera::SetPosition(XMFLOAT3(7, 20, 3));

	Camera::SetTarget(XMFLOAT3(7, -1, 7));
	Instantiate<Stage>(this);
	pPlayer = Instantiate<Player>(this);
	
	CreateEnemy<Enemy>();
	CreateEnemy<Enemy2>();
	CreateEnemy<Enemy3>();
	EnemyList[0]->SetPosition(XMFLOAT3(1.5f,0,13.5f));
	EnemyList[1]->SetPosition(XMFLOAT3(12.5f, 0, 13.5f));
	EnemyList[2]->SetPosition(XMFLOAT3(12.5f, 0, 1.5f));
}

//更新
void PlayScene::Update()
{
	if (pPlayer != nullptr)
	{
		XMFLOAT3 pPos = pPlayer->GetPosition();
		XMFLOAT3 ePos[3];
		ePos[0] = EnemyList[0]->GetPosition();
		ePos[1] = EnemyList[1]->GetPosition();
		ePos[2] = EnemyList[2]->GetPosition();
		for (int i = 0; i < 3; i++)
		{

			if (pPos.x == ePos[i].x && pPos.z == ePos[i].z)
			{
				pPlayer->KillMe();
				break;
			}
		}
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		if(FindObject("Player") == nullptr)
			pPlayer = Instantiate<Player>(this);

	}
}

//描画
void PlayScene::Draw()
{
}

//開放
void PlayScene::Release()
{
}

template <class T>
T PlayScene::CreateEnemy()
{
	GameObject* pEnemy = Instantiate<T>(this);
	EnemyList.push_back(pEnemy);
	return pEnemy;
}