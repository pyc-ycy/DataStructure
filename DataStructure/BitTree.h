#pragma once
#include<iostream>
using namespace std;

// 树结点
typedef struct BitNode
{
	int data;
	BitNode* lchild, * rchild;
	int ltag = 0, rtag = 0;
	BitNode* parent;
}*BTree, ThreadNode, * ThreadTree;

// 辅助构造二叉树的链表节点
typedef struct StackNode
{
	BitNode* nodePtr;
	// 用于判断创建右子树还是左子树
	char flag;
	StackNode* next; //链表下一节点
	StackNode* pre; //链表前一节点
}*StackPtr;
//==============链栈相关操作
//链栈
typedef struct LStack
{
	BTree elem; //数据域
	LStack* next; //指针域
}*LinkStack;
//链栈初始化
void InitLS(LinkStack& ls)
{
	ls = new LStack;
	ls->next = NULL;
}
//压栈
void push(LinkStack& ls, BTree e)
{
	LinkStack p = new LStack; //申请新节点
	p->elem = new BitNode;
	p->elem = e; //将将要压栈的数据放入新节点数据域
	p->next = ls; //将新节点压入栈中
	ls = p; //将栈的头指针移到新节点，以达到更新栈的操作
}
//弹栈
void pop(LinkStack& ls, BTree& e)
{
	if (ls == NULL)
	{
		cout << "空栈，错误，无法弹栈！" << endl;
		exit(0);
	}
	else
	{
		e = ls->elem; //将栈顶元素弹出
		LinkStack t = new LStack; //临时节点存放栈顶元素的地址以待后续步奏释放该节点
		t = ls;
		ls = ls->next; //更新栈，栈表元素向栈顶方向前移一个单位
		delete t; //释放原栈顶元素的内存空间
	}
}
//获取栈顶元素
void gettop(LinkStack ls, BTree& e)
{
	if (ls != NULL)
	{
		e = ls->elem;
	}
}
//判断栈是否是空栈
bool stackempty(LinkStack ls)
{
	if (ls->next == NULL)
		return true;
	return false;
}
//清空栈表
void free(LinkStack ls)
{
	delete ls;
}
//==========================
//链表头结点
StackPtr S, Head;
//初始化链表
void InitStack(StackPtr& s)
{
	s = new StackNode;
	s->flag = 'L';
	s->next = NULL;
	s->pre = NULL;
}
//链表操作器
StackNode* r = new StackNode;
//二叉树根节点，便于子树构建完毕需要回到根节点的操作
BTree root;
//添加二叉树节点，使用先序规则
void addNode(BTree& treeHead, int num)
{
	if (S == NULL)
	{
		cout << "错误，栈未初始化!" << endl;
		exit(0);
	}
	else
	{
		if (S->next == NULL)
		{
			r = S;//将链表指示器与链表链接
		}
		if (treeHead == NULL)
		{
			StackNode* newS = new StackNode; //新建链表一个头节点
			newS->next = NULL;
			newS->pre = r;//头节点的前一个节点为链表地址
			r->next = newS; //将节点添加到链表中
			r = newS;
			treeHead = new BitNode; //初始化二叉树根节点，并将二叉树根节点的地址存在在链表头结点中
			root = new BitNode;
			root = treeHead;
			treeHead->lchild = NULL;
			treeHead->rchild = NULL;
			treeHead->parent = NULL;
			r->nodePtr = new BitNode;
			r->nodePtr = treeHead;
			r->nodePtr->data = num; //往根节点数据域添加数据
			r->flag = 'L'; //指示下一步构造左子树
		}
		else if (treeHead != NULL)
		{
			BTree newnode = new BitNode;  //创建一个二叉树节点
			newnode->data = num; //往二叉树节点数据域添加数据
			newnode->lchild = NULL;
			newnode->rchild = NULL;
			if (r->flag == 'L') //判断当前链表中的二叉树节点是否需要构造左子树
			{
				r->nodePtr->lchild = new BitNode;
				r->nodePtr->lchild = newnode; //将新节点添加到二叉树的左子树中
				newnode->parent = r->nodePtr; //左子树的父节点为当前节点
				StackNode* newS = new StackNode; //创建链表新节点，用于存放二叉树下一步的构造信息
				newS->next = NULL;
				newS->pre = r;//链表新节点的前一个节点为链表操作器的所停留的当前节点
				newS->nodePtr = new BitNode;
				newS->nodePtr = r->nodePtr->lchild; //将链表新节点的二叉树节点勾连到已构造好的左子树中
				newS->flag = 'L';
				r->next = newS; //使用链表操作器将新的链表节点添加到链表中
				r = newS; //移动链表操作器的位置
			}
			else if (r->flag == 'R')//判断当前链表中的二叉树节点是否需要构造右子树
			{
				if (r->nodePtr == root) //如果要构造的是根节点的右子树
				{
					r->nodePtr->rchild = new BitNode;
					r->nodePtr->rchild = newnode;//将新节点添加到二叉树的右子树中
					r->nodePtr->rchild->parent = r->nodePtr;//右子树的父节点为当前节点
				}
				else //构造普通右子树
				{
					r->nodePtr->rchild = new BitNode;
					r->nodePtr->rchild = newnode;//将新节点添加到二叉树的右子树中
					newnode->parent = r->nodePtr;//右子树的父节点为当前节点
				}
				StackNode* newS = new StackNode; // 创建链表新节点，用于存放二叉树下一步的构造信息
				newS->next = NULL;
				newS->pre = r;//链表新节点的前一个节点为链表操作器的所停留的当前节点
				newS->nodePtr = new BitNode;
				newS->nodePtr = r->nodePtr->rchild;//将链表新节点的二叉树节点勾连到已构造好的右子树中
				newS->flag = 'L';
				r->next = newS;//使用链表操作器将新的链表节点添加到链表中
				r = newS;//移动链表操作器的位置
			}
		}
	}
}
//判断二叉树节点是否为叶子节点，是返回True，否则返回false
bool IsLeaf(BTree t)
{
	if (t->lchild == NULL && t->rchild == NULL)
	{
		return true;
	}
	return false;
}
//处理二叉树不需要构造左子树或右子树
void processEmptyData()
{
	if (r->flag == 'L') //如果是左子树不需要构造，只需将构造标志改为右子树
	{
		r->flag = 'R';
	}
	else if (r->flag == 'R')//如果是右子树不需要构造
	{
		if (r->nodePtr->parent->rchild != NULL)
		{
			if (IsLeaf(r->nodePtr->parent->lchild)) //两个if语句形成判断当前游离二叉树节点是处于左子树的右叶子处
			{
				r->pre = S->next;//将当前链表节点的前一个节点更改为头结点
				r->nodePtr = root; //将当前游离二叉树节点移动到二叉树根节点处
			}
		}
		r->nodePtr = r->pre->nodePtr; //普通情况下，当右子树不需要构造时，将链表操作器前移一位，
										//使游离二叉树节点顺着以构造的二叉树前移一个节点
	}
}
//二叉树各个节点已构造完毕时所要进行的操作
void processEndData()
{
	StackNode* end = r;
	S = Head; //避免链表首元节点意外移动
	r = S; //将链表操作器停放会链表首元结点
	delete end;//释放对于链表节点
}
//以先序规则构造二叉树
void createBiTreeNonRecursive(BTree& treeHead)
{
	int num;
	bool keepRun = true;
	treeHead = NULL;
	InitStack(S);//初始化链表
	Head = new StackNode;
	Head = S;//标志链表首元节点地址
	cout << "请按照构造规则输入二叉树的结点数据：" << endl;
	while (keepRun)
	{
		cin >> num; //输入即将添加到二叉树节点中的数据
		switch (num) //判断输入的数值
		{
		case -1://如果是-1，则转到不需要构造左子树或右子树的操作
			processEmptyData();
			continue;
		case 0://如果是0,则转到二叉树构造完毕的操作
			processEndData();
			keepRun = false; //终止循环
			break;
		default: //0和-1以外的其他数值，转到构造二叉树节点的操作
			addNode(treeHead, num);
		}
	}
}
//求叶子数
int leaf = 0;
//求叶子数
void leafCount(BTree rt)
{
	if (rt != NULL)
	{
		leafCount(rt->lchild);
		leafCount(rt->rchild);
		if (rt->lchild == NULL && rt->rchild == NULL)//如果当前二叉树节点是叶子，则叶子数加一
			leaf++;
	}
}
//求二叉树节点数
int node(BTree rt)
{
	if (rt == NULL)
		return 0;
	int leftcount = node(rt->lchild);
	int rightcount = node(rt->rchild);
	int ret = leftcount + rightcount + 1;
	return ret;
}
//==============先序递归遍历==============
void rDLR(BTree rt)
{
	if (rt)
	{
		cout << rt->data << " "; //先输出根节点
		rDLR(rt->lchild); //再遍历左子树
		rDLR(rt->rchild);//最后遍历右子树
	}
}
//========================================
//===========非递归先序遍历
void DLR(BTree rt)
{
	LinkStack ls;
	BTree p = new BitNode;
	BTree q = new BitNode;
	p = rt;
	int count = 0;
	InitLS(ls);
	if (p == NULL)
	{
		cout << "树空" << endl;
		return;
	}
	while (p || !stackempty(ls))
	{
		if (count == leaf)  //当当前二叉树节点是二叉树最后一个叶子节点时 ，无需后续操作，结束函数调用
		{
			free(ls);
			return;
		}
		if (p)
		{
			if (p != NULL)
			{
				push(ls, p); //将二叉树的非空节点压入栈中
			}
			cout << p->data << " "; //先输出根节点
			p = p->lchild; //再遍历左子树
		}
		else
		{
			pop(ls, q); //弹出栈中的非空二叉树节点
			p = q->rchild; //最后遍历右子树
		}
		if (IsLeaf(q)) //累计叶子数
		{
			count++;
		}
	}
}
//========中序递归算法
void rLDR(BTree rt)
{
	if (rt)
	{
		rLDR(rt->lchild);//先遍历左子树
		cout << rt->data << " ";//再输出根节点
		rLDR(rt->rchild);//最后遍历右子树
	}
}
//中序非递归算法
int size2 = 0;
void LDR(BTree rt)
{
	LinkStack ls;
	BTree p = new BitNode;
	BTree q = new BitNode;
	p = rt;
	size2 = node(rt);
	int nodecount = 0;
	int count = 0;//遍历节点计数
	InitLS(ls);
	if (p == NULL)
	{
		cout << "树空" << endl;
		return;
	}
	while (p || !stackempty(ls))
	{
		if (leaf != 1) //当二叉树不是只有左子树或右子树的情况
		{
			if (count == leaf && nodecount == size2)//当当前二叉树节点是二叉树最后一个叶子节点且已经遍历完所有的节点时 ，
												//无需后续操作，结束函数调用
			{
				free(ls);
				return;
			}
			if (p)
			{
				if (p != NULL)
				{
					push(ls, p);//将二叉树的非空节点压入栈中
				}
				p = p->lchild; //先遍历左子树
			}
			else
			{
				pop(ls, q);//弹出栈中的非空二叉树节点
				cout << q->data << " "; //再输出根节点
				nodecount++;//累计已经遍历的节点数目
				if (q->rchild != NULL)
				{
					p = q->rchild; //最后遍历右子树
				}
			}
			if (IsLeaf(q))//累计叶子数
			{
				count++;
			}
		}
		else if (leaf == 1) //当二叉树只有右子树或左子树
		{
			if (rt->lchild != NULL && rt->rchild == NULL) //只有左子树
			{
				if (p)
				{
					if (p != NULL)
					{
						push(ls, p);//将二叉树的非空节点压入栈中
					}
					p = p->lchild;//遍历左子树
				}
				else
				{
					pop(ls, q);//弹出栈中的非空二叉树节点
					cout << q->data << " "; //输出弹出的二叉树节点的数据
					if (q == root) //回到根节点时结束函数调用
					{
						free(ls);
						return;
					}
				}
			}
			else if (rt->rchild != NULL && rt->lchild == NULL) //只有右子树
			{
				if (p)
				{
					if (p != NULL)
					{
						push(ls, p);//将二叉树的非空节点压入栈中
					}
					p = p->rchild;//遍历右子树
				}
				else
				{
					pop(ls, q);//弹出栈中的非空二叉树节点
					cout << q->data << " ";//输出弹出的二叉树节点的数据
					if (q == root)//回到根节点时结束函数调用
					{
						free(ls);
						return;
					}
				}
			}
		}
	}
}
//后序递归算法
void rLRD(BTree rt)
{
	if (rt)
	{
		rLRD(rt->lchild);//先遍历左子树
		rLRD(rt->rchild);//在遍历右子树
		cout << rt->data << " "; //最后输出根节点
	}
}
//后序非递归算法
void LRD(BTree rt)
{
	LinkStack ls;
	BTree cur, pre;
	InitLS(ls);
	if (rt == NULL)
	{
		cout << "树为空" << endl;
		return;
	}
	//二叉树前一个节点
	pre = NULL;
	//二叉树当前节点
	cur = NULL;
	push(ls, rt);//先把根节点压入栈中
	while (!stackempty(ls))
	{
		cur = NULL;
		gettop(ls, cur);
		if ((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " "; //按照弹栈次序输出当前二叉树节点的数据
			if (cur == root)//如果已到根节点，结束函数调用
			{
				free(ls);
				return;
			}
			pre = cur;
			pop(ls, cur);
		}
		else
		{
			if (cur->rchild != NULL)
			{
				push(ls, cur->rchild);//再遍历右子树，将右子树节点压栈
			}
			if (cur->lchild != NULL)
			{
				push(ls, cur->lchild);//最后遍历左子树，将左子树节点压栈
			}
		}
	}
}
//使用递归求二叉树的深度
int Depth(BTree rt)
{
	int deep = 0;
	if (rt)
	{
		int leftdeep = Depth(rt->lchild);
		int rightdeep = Depth(rt->rchild);
		deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
	}
	return deep;
}
//=============层次遍历==========================
typedef struct QueueNode
{
	BTree elem;
	QueueNode* next;
};
typedef struct LinkQueue
{
	QueueNode* front, * rear;
};
bool initQueue(LinkQueue& q)
{
	q.front = q.rear = new QueueNode;
	q.front->next = NULL;
	return true;
}
void EnQueue(LinkQueue& q, BTree e)
{
	QueueNode* s = new QueueNode;
	s->elem = e;
	s->next = NULL;
	q.rear->next = s;
	q.rear = s;
}
bool DeQueue(LinkQueue& q, BTree& e)
{
	if (q.front == q.rear) return false;
	QueueNode* p = q.front->next;
	e = p->elem;
	q.front->next = p->next;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	return true;
}
bool IsEmpty(LinkQueue q)
{
	if (q.rear == q.front)
		return true;
	return false;
}
void vist(BTree e)
{
	if (e != NULL && e->data != NULL)
		cout << e->data << " ";
	return;
}
void LevelOrder(BTree T)
{
	LinkQueue Q;
	initQueue(Q);
	BTree p;
	EnQueue(Q, T);
	while (!IsEmpty(Q))
	{
		DeQueue(Q, p);
		vist(p);
		if (p->lchild != NULL)
			EnQueue(Q, p->lchild);
		if (p->rchild != NULL)
			EnQueue(Q, p->rchild);
	}
}
//======================
// 中序线索二叉树
// 线索化
void InThread(ThreadTree& p, ThreadTree& pre)
{
	if (p != NULL)
	{
		InThread(p->lchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->rchild, pre);
	}
}
// 创建线索化二叉树
void CreateInThread(ThreadTree T)
{
	ThreadTree pre = NULL;
	if (T != NULL)
	{
		InThread(T, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
ThreadNode* Firstnode(ThreadNode* p)
{
	while (p->ltag == 0)p = p->lchild;
	return p;
}
ThreadNode* Nextnode(ThreadNode* p)
{
	if (p->rtag == 0) return Firstnode(p->rchild);
	else return p->rchild;
}
ThreadNode* Prenode(ThreadNode* p)
{
	if (p->ltag == 0) return Firstnode(p->lchild);
	else return p->lchild;
}
ThreadNode* Endnode(ThreadNode* p)
{
	while (p->rtag == 0)p = p->rchild;
	return p;
}
void Inorder(ThreadNode* T)
{
	for (ThreadNode* p = Firstnode(T); p != NULL; p = Nextnode(p))
		vist(p);
}
//自上而下、从左到右层次遍历二叉树
void InvertLevel(BTree bt)
{
	LinkStack s = new LStack;
	LinkQueue Q;
	BTree p;
	if (bt != NULL)
	{
		InitLS(s);
		initQueue(Q);
		EnQueue(Q, bt);
		while (IsEmpty(Q) == false)
		{
			DeQueue(Q, p);
			push(s, p);
			if (p->lchild)
				EnQueue(Q, p->lchild);
			if (p->rchild)
				EnQueue(Q, p->rchild);
		}
		while (stackempty(s) == false)
		{
			pop(s, p);
			if (p != NULL && p->data != NULL)
				cout << p->data << " ";
		}
	}
}