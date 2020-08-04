#pragma once
#include <iostream>
using namespace std;
// �߱�ڵ�
typedef struct Arcnode
{
	int adjevex; //�����
	Arcnode* next; // ָ����һ����
	int weight; // ��Ȩ
};
// �����
typedef struct Vnode
{
	int data; // �����
	Arcnode* first; // ��һ�������ڸö���ı�
}AdjList;

// ͼ
class Graph
{
private:
	AdjList* vertice; //�ڽӱ�
	// �������ͱ���
	int vexnum, arcnum;
public:
	Graph();
	bool init(int vnum, int anum);
	bool create();
	bool adjacent(int x, int y);
	void Neighbors(int x);
	void AddVertx();
};
// ���Ӷ���
void Graph::AddVertx()
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
		return;
	}
	vertice[vexnum].data = vexnum;
	vertice[vexnum].first = NULL;
	vexnum += 1;
}
// ����� x �ڽӵı�
void Graph::Neighbors(int x)
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
		return;
	}
	Arcnode* p = vertice[x].first;
	while (p->next != NULL)
	{
		cout << "��(" << x << " , " << p->adjevex << ")��ȨΪ��" << p->weight << endl;
		p = p->next;
	}
}
// �жϱߴ治����
bool Graph::adjacent(int x, int y)
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
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
// ���캯��
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
// ����ͼ
bool Graph::create()
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
		return false;
	}
	int** WN = new int* [vexnum];
	for (int i = 0; i < vexnum; i++)
		WN[i] = new int[vexnum];
	cout << "�밴��ͼ�Ľṹ�������Ϣ����ά�����У�ע��Ӷ����Ϊ 1 �Ŀ�ʼ" << endl;
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