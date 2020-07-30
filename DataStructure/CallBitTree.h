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
