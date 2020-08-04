#pragma once
#include <iostream>
using namespace std;
// 边表节点
typedef struct Arcnode
{
	int adjevex; //顶点号
	Arcnode* next; // 指向下一条弧
	int weight; // 边权
};
// 顶点表
typedef struct Vnode
{
	int data; // 顶点号
	Arcnode* first; // 第一条依附于该顶点的边
}AdjList;

// 图
class Graph
{
private:
	AdjList* vertice; //邻接表
	// 定点数和边数
	int vexnum, arcnum;
public:
	Graph();
	bool init(int vnum, int anum);
	bool create();
	bool adjacent(int x, int y);
	void Neighbors(int x);
	void AddVertx();
};
// 增加顶点
void Graph::AddVertx()
{
	if (vertice == NULL)
	{
		cout << "邻接表未初始化" << endl;
		return;
	}
	vertice[vexnum].data = vexnum;
	vertice[vexnum].first = NULL;
	vexnum += 1;
}
// 输出与 x 邻接的边
void Graph::Neighbors(int x)
{
	if (vertice == NULL)
	{
		cout << "邻接表未初始化" << endl;
		return;
	}
	Arcnode* p = vertice[x].first;
	while (p->next != NULL)
	{
		cout << "边(" << x << " , " << p->adjevex << ")的权为：" << p->weight << endl;
		p = p->next;
	}
}
// 判断边存不存在
bool Graph::adjacent(int x, int y)
{
	if (vertice == NULL)
	{
		cout << "邻接表未初始化" << endl;
		return false;
	}
	Arcnode* p = vertice[x].first;
	while (p->next != NULL)
	{
		if (p->adjevex == y)
			return true;
		p = p->next;
	}
	return false;
}
// 构造函数
Graph::Graph()
{
	vertice = NULL;
	vexnum = arcnum = 0;
}
bool Graph::init(int vnum, int anum)
{
	if (vertice != NULL)
		return false;
	vexnum = vnum;
	arcnum = anum;
	vertice = new Vnode[vexnum];
	for (int i = 0; i < vexnum; i++)
	{
		vertice[i].data = i + 1;
		vertice[i].first = NULL;
	}
	return true;
}
// 构造图
bool Graph::create()
{
	if (vertice == NULL)
	{
		cout << "邻接表未初始化" << endl;
		return false;
	}
	int** WN = new int* [vexnum];
	for (int i = 0; i < vexnum; i++)
		WN[i] = new int[vexnum];
	cout << "请按照图的结构输入边信息到二维数组中，注意从顶点号为 1 的开始" << endl;
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
			cin >> WN[i][j];
	}
	for (int i = 0; i < vexnum; i++)
	{
		for (int j = 0; j < vexnum; j++)
		{
			if (WN[i][j] != 0)
			{
				Arcnode* p = new Arcnode;
				p->adjevex = j + 1;
				p->weight = WN[i][j];
				p->next = NULL;
				if (vertice[i].first == NULL)
					vertice[i].first = p;
				else
				{
					Arcnode* t = vertice[i].first;
					while (t->next != NULL)
						t = t->next;
					t->next = p;
				}
			}
		}
	}
	for (int i = 0; i < vexnum; i++)
		delete[] WN[i];
	delete[] WN;
	return true;
}