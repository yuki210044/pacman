#pragma once
#include "Engine/GameObject.h"
#include <vector>


//�����V�[�����Ǘ�����N���X
class PlayScene : public GameObject
{
	GameObject* pPlayer;
	
	std::vector<GameObject*>  EnemyList;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	template <class T>
	T CreateEnemy();
};
