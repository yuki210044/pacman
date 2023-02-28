#pragma once
#include <iostream>
#include "NodeData.h"
#include "Stage.h"
#include <list>
#include <vector>

struct Coordinate
{
	int x;
	int y;
};
class Astar
{
	NodeData** node;
	Stage* pStage;
	std::list<NodeData*> openList;
	std::vector<Coordinate> route;
public:
	Astar(Stage* stage);
	void InitAstar();

	/// <summary>
	/// Astar�ɂ��o�H�T��������
	/// </summary>
	/// <param name="x">�X�^�[�g�n�_��x���W</param>
	/// <param name="y">�X�^�[�g�n�_��y���W</param>
	/// <param name="tx">�S�[���n�_��x���W</param>
	/// <param name="ty">�S�[���n�_��y���W</param>
	void InitSearch(int x, int y, int tx, int ty);

	/// <summary>
	/// �o�H�̒T�������s����֐�(���݈ʒu�̒T�����������ƁA���ɒT������m�[�h��openList����T���A�����̈ʒu�������ɐݒ肵�āA�ċN�Ăяo��������)
	/// </summary>
	/// <param name="x">���݂�x���W</param>
	/// <param name="y">���݂�y���W</param>
	/// <param name="tx">�S�[��x�n�_</param>
	/// <param name="ty">�S�[��y�n�_</param>
	/// <param name="trueCost">�T������m�[�h�̎��R�X�g</param>
	void SearchRoute(int x, int y, int tx, int ty, int trueCost);

	/// <summary>
	/// �T�����I�������A�S�[���܂ł̍ŒZ�o�H��route�ɃZ�b�g����
	/// </summary>
	/// <param name="tx">�S�[��x�n�_</param>
	/// <param name="ty">�S�[��y�n�_</param>
	void ReturnRoute(int tx, int ty);

	/// <summary>
	/// �o�H�T���ŁA�m�[�h���I�[�v���ɂ��鏈�������s����֐�
	/// </summary>
	/// <param name="x">�I�[�v������m�[�h��x���W</param>
	/// <param name="y">�I�[�v������m�[�h��y���W</param>
	/// <param name="tx">�S�[��x�n�_</param>
	/// <param name="ty">�S�[��y�n�_</param>
	/// <param name="trueCost">���R�X�g</param>
	/// <param name="pParent">�e�m�[�h</param>
	void Open(int x, int y, int tx, int ty, int trueCost, NodeData* pParent);

	/// <summary>
	/// �o�H�T���ŁA���ɒT������m�[�h�𒲂ׂ�֐�
	/// </summary>
	/// <returns>���ɒ��ׂ�m�[�h</returns>
	NodeData* NextNode();
	std::vector<Coordinate> GetRoute(){ return route; }
};

