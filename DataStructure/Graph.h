#pragma once
#include <iostream>
using namespace std;
// ����
typedef struct Queue
{
	int* data;
	int front;
	int rear;
	int size;
};
bool intiQueue(Queue& Q, int len)
{
	Q.data = new int[len];
	Q.front = Q.rear = 0;
	Q.size = len;
	return true;
}
bool IsEmpty(Queue q)
{
	if (q.front == q.rear)
		return true;
	return false;
}
bool EnQueue(Queue& q, int e)
{
	if ((q.rear + 1) % q.size == q.front)
		return false;
	q.data[q.rear] = e;
	q.rear = (q.rear + 1) % q.size;
	return true;
}
bool DeQueue(Queue& q, int& e)
{
	if (q.front == q.rear)
		return false;
	e = q.data[q.front];
	q.front = (q.front + 1) % q.size;
	return true;
}
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
	int FirstNeighbor(int x);
	int NextNeighbor(int x, int y);
	void BFSTraverse();
	void BFS(int v);
};
bool visited[20];
Queue Q;
void Graph::BFS(int v)
{
	cout << vertice[v].data << " ";
	visited[v] = true;
	EnQueue(Q, v);
	while (!IsEmpty(Q))
	{
		int t = 0;
		DeQueue(Q, t);
		if (t != 0)
		{
			for (int w = FirstNeighbor(t); w >= 0; w = NextNeighbor(t, w))
			{
				if (!visited[w])
				{
					cout << vertice[w].data << " ";
					visited[w] = true;
					EnQueue(Q, w);
				}
			}
		}
	}
}
// ͼ�Ĺ����������
void Graph::BFSTraverse()
{
	for (int i = 0; i < vexnum; i++)
		visited[i] = false;
	intiQueue(Q, vexnum);
	for (int i = 0; i < vexnum; i++)
	{
		if (!visited[i])
			BFS(i);
	}
}
// �� y �� x �ĵ�һ���ڽӵ㣬�򷵻س� y �������һ���ڽӵ�
int Graph::NextNeighbor(int x, int y)
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
		return 0;
	}
	if (vertice[x].first != NULL)
	{
		if (vertice[x].first->adjevex == y)
			if (vertice[x].first->next != NULL)
				return vertice[x].first->next->adjevex - 1;
	}
	return 0;
}
// ���ʶ��� x �ĵ�һ���ڽӵ�
int Graph::FirstNeighbor(int x)
{
	if (vertice == NULL)
	{
		cout << "�ڽӱ�δ��ʼ��" << endl;
		return 0;
	}
	if (vertice[x].first != NULL)
		return vertice[x].first->adjevex - 1;
	return 0;
}
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