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
	/// Astarによる経路探索をする
	/// </summary>
	/// <param name="x">スタート地点のx座標</param>
	/// <param name="y">スタート地点のy座標</param>
	/// <param name="tx">ゴール地点のx座標</param>
	/// <param name="ty">ゴール地点のy座標</param>
	void InitSearch(int x, int y, int tx, int ty);

	/// <summary>
	/// 経路の探索を実行する関数(現在位置の探索をしたあと、次に探索するノードをopenListから探し、そこの位置を引数に設定して、再起呼び出しをする)
	/// </summary>
	/// <param name="x">現在のx座標</param>
	/// <param name="y">現在のy座標</param>
	/// <param name="tx">ゴールx地点</param>
	/// <param name="ty">ゴールy地点</param>
	/// <param name="trueCost">探索するノードの実コスト</param>
	void SearchRoute(int x, int y, int tx, int ty, int trueCost);

	/// <summary>
	/// 探索が終わった後、ゴールまでの最短経路をrouteにセットする
	/// </summary>
	/// <param name="tx">ゴールx地点</param>
	/// <param name="ty">ゴールy地点</param>
	void ReturnRoute(int tx, int ty);

	/// <summary>
	/// 経路探索で、ノードをオープンにする処理を実行する関数
	/// </summary>
	/// <param name="x">オープンするノードのx座標</param>
	/// <param name="y">オープンするノードのy座標</param>
	/// <param name="tx">ゴールx地点</param>
	/// <param name="ty">ゴールy地点</param>
	/// <param name="trueCost">実コスト</param>
	/// <param name="pParent">親ノード</param>
	void Open(int x, int y, int tx, int ty, int trueCost, NodeData* pParent);

	/// <summary>
	/// 経路探索で、次に探索するノードを調べる関数
	/// </summary>
	/// <returns>次に調べるノード</returns>
	NodeData* NextNode();
	std::vector<Coordinate> GetRoute(){ return route; }
};

