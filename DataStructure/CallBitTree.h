#pragma once
#include "BitTree.h"

// 非递归求二叉树深度
int Btdepth(BTree t)
{
	if (!t)
		return 0;
	int front = -1, rear = -1;
	int last = 0, level = 0;
	BTree Q[20];
	Q[++rear] = t;
	BTree p;
	while (front < rear)
	{
		p = Q[++front];
		if (p->lchild)
			Q[++rear] = p->lchild;
		if (p->rchild)
			Q[++rear] = p->rchild;
		if (front == last) {
			level++;
			last = rear;
		}
	}
	return level;
}
// 判断是否是完全二叉树
bool IsComplete(BTree t)
{
	BTree p;
	LinkQueue Q;
	initQueue(Q);
	if (!t)
		return 1;
	EnQueue(Q, t);
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		if (p)
		{
			EnQueue(Q, p->lchild);
			EnQueue(Q, p->rchild);
		}
		else
		{
			while (!IsEmpty(Q))
			{
				DeQueue(Q, p);
				if (p)
					return 0;
			}
		}
		return 1;
	}
}
// 计算二叉树双分支节点
int DsonNodes(BTree T)
{
	if (T == NULL)
		return 0;
	else if (T->lchild != NULL && T->rchild != NULL)
		return DsonNodes(T->lchild) + DsonNodes(T->rchild) + 1;
	else
		return DsonNodes(T->lchild) + DsonNodes(T->rchild);
}
// 判断两棵树是否相似
int similar(BTree T1, BTree T2)
{
	int leftS, rightS;
	if (T1 == NULL && T2 == NULL)
		return 1;
	else if (T1 == NULL || T2 == NULL)
		return 0;
	else
	{
		leftS = similar(T1->lchild, T2->lchild);
		rightS = similar(T1->rchild, T2->rchild);
		return leftS && rightS;
	}
}