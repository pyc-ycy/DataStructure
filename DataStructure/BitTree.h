#pragma once
#include<iostream>
using namespace std;

// �����
typedef struct BitNode
{
	int data;
	BitNode* lchild, * rchild;
	BitNode* parent;
}*BTree;

// �������������������ڵ�
typedef struct StackNode
{
	BitNode* nodePtr;
	// �����жϴ�������������������
	char flag;
	StackNode* next; //������һ�ڵ�
	StackNode* pre; //����ǰһ�ڵ�
}*StackPtr;
//==============��ջ��ز���
//��ջ
typedef struct LStack
{
	BTree elem; //������
	LStack* next; //ָ����
}*LinkStack;
//��ջ��ʼ��
void InitLS(LinkStack& ls)
{
	ls = new LStack;
	ls->next = NULL;
}
//ѹջ
void push(LinkStack& ls, BTree e)
{
	LinkStack p = new LStack; //�����½ڵ�
	p->elem = new BitNode;
	p->elem = e; //����Ҫѹջ�����ݷ����½ڵ�������
	p->next = ls; //���½ڵ�ѹ��ջ��
	ls = p; //��ջ��ͷָ���Ƶ��½ڵ㣬�Դﵽ����ջ�Ĳ���
}
//��ջ
void pop(LinkStack& ls, BTree& e)
{
	if (ls == NULL)
	{
		cout << "��ջ�������޷���ջ��" << endl;
		exit(0);
	}
	else
	{
		e = ls->elem; //��ջ��Ԫ�ص���
		LinkStack t = new LStack; //��ʱ�ڵ���ջ��Ԫ�صĵ�ַ�Դ����������ͷŸýڵ�
		t = ls;
		ls = ls->next; //����ջ��ջ��Ԫ����ջ������ǰ��һ����λ
		delete t; //�ͷ�ԭջ��Ԫ�ص��ڴ�ռ�
	}
}
//��ȡջ��Ԫ��
void gettop(LinkStack ls, BTree& e)
{
	if (ls != NULL)
	{
		e = ls->elem;
	}
}
//�ж�ջ�Ƿ��ǿ�ջ
bool stackempty(LinkStack ls)
{
	if (ls == NULL)
		return true;
	return false;
}
//���ջ��
void free(LinkStack ls)
{
	delete ls;
}
//==========================
//����ͷ���
StackPtr S, Head;
//��ʼ������
void InitStack(StackPtr& s)
{
	s = new StackNode;
	s->flag = 'L';
	s->next = NULL;
	s->pre = NULL;
}
//���������
StackNode* r = new StackNode;
//���������ڵ㣬�����������������Ҫ�ص����ڵ�Ĳ���
BTree root;
//��Ӷ������ڵ㣬ʹ���������
void addNode(BTree& treeHead, int num)
{
	if (S == NULL)
	{
		cout << "����ջδ��ʼ��!" << endl;
		exit(0);
	}
	else
	{
		if (S->next == NULL)
		{
			r = S;//������ָʾ������������
		}
		if (treeHead == NULL)
		{
			StackNode* newS = new StackNode; //�½�����һ��ͷ�ڵ�
			newS->next = NULL;
			newS->pre = r;//ͷ�ڵ��ǰһ���ڵ�Ϊ�����ַ
			r->next = newS; //���ڵ���ӵ�������
			r = newS;
			treeHead = new BitNode; //��ʼ�����������ڵ㣬�������������ڵ�ĵ�ַ����������ͷ�����
			root = new BitNode;
			root = treeHead;
			treeHead->lchild = NULL;
			treeHead->rchild = NULL;
			treeHead->parent = NULL;
			r->nodePtr = new BitNode;
			r->nodePtr = treeHead;
			r->nodePtr->data = num; //�����ڵ��������������
			r->flag = 'L'; //ָʾ��һ������������
		}
		else if (treeHead != NULL)
		{
			BTree newnode = new BitNode;  //����һ���������ڵ�
			newnode->data = num; //���������ڵ��������������
			newnode->lchild = NULL;
			newnode->rchild = NULL;
			if (r->flag == 'L') //�жϵ�ǰ�����еĶ������ڵ��Ƿ���Ҫ����������
			{
				r->nodePtr->lchild = new BitNode;
				r->nodePtr->lchild = newnode; //���½ڵ���ӵ�����������������
				newnode->parent = r->nodePtr; //�������ĸ��ڵ�Ϊ��ǰ�ڵ�
				StackNode* newS = new StackNode; //���������½ڵ㣬���ڴ�Ŷ�������һ���Ĺ�����Ϣ
				newS->next = NULL;
				newS->pre = r;//�����½ڵ��ǰһ���ڵ�Ϊ�������������ͣ���ĵ�ǰ�ڵ�
				newS->nodePtr = new BitNode;
				newS->nodePtr = r->nodePtr->lchild; //�������½ڵ�Ķ������ڵ㹴�����ѹ���õ���������
				newS->flag = 'L';
				r->next = newS; //ʹ��������������µ�����ڵ���ӵ�������
				r = newS; //�ƶ������������λ��
			}
			else if (r->flag == 'R')//�жϵ�ǰ�����еĶ������ڵ��Ƿ���Ҫ����������
			{
				if (r->nodePtr == root) //���Ҫ������Ǹ��ڵ��������
				{
					r->nodePtr->rchild = new BitNode;
					r->nodePtr->rchild = newnode;//���½ڵ���ӵ�����������������
					r->nodePtr->rchild->parent = r->nodePtr;//�������ĸ��ڵ�Ϊ��ǰ�ڵ�
				}
				else //������ͨ������
				{
					r->nodePtr->rchild = new BitNode;
					r->nodePtr->rchild = newnode;//���½ڵ���ӵ�����������������
					newnode->parent = r->nodePtr;//�������ĸ��ڵ�Ϊ��ǰ�ڵ�
				}
				StackNode* newS = new StackNode; // ���������½ڵ㣬���ڴ�Ŷ�������һ���Ĺ�����Ϣ
				newS->next = NULL;
				newS->pre = r;//�����½ڵ��ǰһ���ڵ�Ϊ�������������ͣ���ĵ�ǰ�ڵ�
				newS->nodePtr = new BitNode;
				newS->nodePtr = r->nodePtr->rchild;//�������½ڵ�Ķ������ڵ㹴�����ѹ���õ���������
				newS->flag = 'L';
				r->next = newS;//ʹ��������������µ�����ڵ���ӵ�������
				r = newS;//�ƶ������������λ��
			}
		}
	}
}
//�ж϶������ڵ��Ƿ�ΪҶ�ӽڵ㣬�Ƿ���True�����򷵻�false
bool IsLeaf(BTree t)
{
	if (t->lchild == NULL && t->rchild == NULL)
	{
		return true;
	}
	return false;
}
//�������������Ҫ������������������
void processEmptyData()
{
	if (r->flag == 'L') //���������������Ҫ���죬ֻ�轫�����־��Ϊ������
	{
		r->flag = 'R';
	}
	else if (r->flag == 'R')//���������������Ҫ����
	{
		if (r->nodePtr->parent->rchild != NULL)
		{
			if (IsLeaf(r->nodePtr->parent->lchild)) //����if����γ��жϵ�ǰ����������ڵ��Ǵ�������������Ҷ�Ӵ�
			{
				r->pre = S->next;//����ǰ����ڵ��ǰһ���ڵ����Ϊͷ���
				r->nodePtr = root; //����ǰ����������ڵ��ƶ������������ڵ㴦
			}
		}
		r->nodePtr = r->pre->nodePtr; //��ͨ����£�������������Ҫ����ʱ�������������ǰ��һλ��
										//ʹ����������ڵ�˳���Թ���Ķ�����ǰ��һ���ڵ�
	}
}
//�����������ڵ��ѹ������ʱ��Ҫ���еĲ���
void processEndData()
{
	StackNode* end = r;
	S = Head; //����������Ԫ�ڵ������ƶ�
	r = S; //�����������ͣ�Ż�������Ԫ���
	delete end;//�ͷŶ�������ڵ�
}
//����������������
void createBiTreeNonRecursive(BTree& treeHead)
{
	int num;
	bool keepRun = true;
	treeHead = NULL;
	InitStack(S);//��ʼ������
	Head = new StackNode;
	Head = S;//��־������Ԫ�ڵ��ַ
	cout << "�밴�չ����������������Ľ�����ݣ�" << endl;
	while (keepRun)
	{
		cin >> num; //���뼴����ӵ��������ڵ��е�����
		switch (num) //�ж��������ֵ
		{
		case -1://�����-1����ת������Ҫ�������������������Ĳ���
			processEmptyData();
			continue;
		case 0://�����0,��ת��������������ϵĲ���
			processEndData();
			keepRun = false; //��ֹѭ��
			break;
		default: //0��-1�����������ֵ��ת������������ڵ�Ĳ���
			addNode(treeHead, num);
		}
	}
}
//��Ҷ����
int leaf = 0;
//��Ҷ����
void leafCount(BTree rt)
{
	if (rt != NULL)
	{
		leafCount(rt->lchild);
		leafCount(rt->rchild);
		if (rt->lchild == NULL && rt->rchild == NULL)//�����ǰ�������ڵ���Ҷ�ӣ���Ҷ������һ
			leaf++;
	}
}
//��������ڵ���
int node(BTree rt)
{
	if (rt == NULL)
		return 0;
	int leftcount = node(rt->lchild);
	int rightcount = node(rt->rchild);
	int ret = leftcount + rightcount + 1;
	return ret;
}
//==============����ݹ����==============
void rDLR(BTree rt)
{
	if (rt)
	{
		cout << rt->data << " "; //��������ڵ�
		rDLR(rt->lchild); //�ٱ���������
		rDLR(rt->rchild);//������������
	}
}
//========================================
//===========�ǵݹ��������
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
		cout << "����" << endl;
		return;
	}
	while (p || !stackempty(ls))
	{
		if (count == leaf)  //����ǰ�������ڵ��Ƕ��������һ��Ҷ�ӽڵ�ʱ ���������������������������
		{
			free(ls);
			return;
		}
		if (p)
		{
			if (p != NULL)
			{
				push(ls, p); //���������ķǿսڵ�ѹ��ջ��
			}
			cout << p->data << " "; //��������ڵ�
			p = p->lchild; //�ٱ���������
		}
		else
		{
			pop(ls, q); //����ջ�еķǿն������ڵ�
			p = q->rchild; //������������
		}
		if (IsLeaf(q)) //�ۼ�Ҷ����
		{
			count++;
		}
	}
}
//========����ݹ��㷨
void rLDR(BTree rt)
{
	if (rt)
	{
		rLDR(rt->lchild);//�ȱ���������
		cout << rt->data << " ";//��������ڵ�
		rLDR(rt->rchild);//������������
	}
}
//����ǵݹ��㷨
int size2 = 0;
void LDR(BTree rt)
{
	LinkStack ls;
	BTree p = new BitNode;
	BTree q = new BitNode;
	p = rt;
	size2 = node(rt);
	int nodecount = 0;
	int count = 0;//�����ڵ����
	InitLS(ls);
	if (p == NULL)
	{
		cout << "����" << endl;
		return;
	}
	while (p || !stackempty(ls))
	{
		if (leaf != 1) //������������ֻ���������������������
		{
			if (count == leaf && nodecount == size2)//����ǰ�������ڵ��Ƕ��������һ��Ҷ�ӽڵ����Ѿ����������еĽڵ�ʱ ��
												//�������������������������
			{
				free(ls);
				return;
			}
			if (p)
			{
				if (p != NULL)
				{
					push(ls, p);//���������ķǿսڵ�ѹ��ջ��
				}
				p = p->lchild; //�ȱ���������
			}
			else
			{
				pop(ls, q);//����ջ�еķǿն������ڵ�
				cout << q->data << " "; //��������ڵ�
				nodecount++;//�ۼ��Ѿ������Ľڵ���Ŀ
				if (q->rchild != NULL)
				{
					p = q->rchild; //������������
				}
			}
			if (IsLeaf(q))//�ۼ�Ҷ����
			{
				count++;
			}
		}
		else if (leaf == 1) //��������ֻ����������������
		{
			if (rt->lchild != NULL && rt->rchild == NULL) //ֻ��������
			{
				if (p)
				{
					if (p != NULL)
					{
						push(ls, p);//���������ķǿսڵ�ѹ��ջ��
					}
					p = p->lchild;//����������
				}
				else
				{
					pop(ls, q);//����ջ�еķǿն������ڵ�
					cout << q->data << " "; //��������Ķ������ڵ������
					if (q == root) //�ص����ڵ�ʱ������������
					{
						free(ls);
						return;
					}
				}
			}
			else if (rt->rchild != NULL && rt->lchild == NULL) //ֻ��������
			{
				if (p)
				{
					if (p != NULL)
					{
						push(ls, p);//���������ķǿսڵ�ѹ��ջ��
					}
					p = p->rchild;//����������
				}
				else
				{
					pop(ls, q);//����ջ�еķǿն������ڵ�
					cout << q->data << " ";//��������Ķ������ڵ������
					if (q == root)//�ص����ڵ�ʱ������������
					{
						free(ls);
						return;
					}
				}
			}
		}
	}
}
//����ݹ��㷨
void rLRD(BTree rt)
{
	if (rt)
	{
		rLRD(rt->lchild);//�ȱ���������
		rLRD(rt->rchild);//�ڱ���������
		cout << rt->data << " "; //���������ڵ�
	}
}
//����ǵݹ��㷨
void LRD(BTree rt)
{
	LinkStack ls;
	BTree cur, pre;
	InitLS(ls);
	if (rt == NULL)
	{
		cout << "��Ϊ��" << endl;
		return;
	}
	//������ǰһ���ڵ�
	pre = NULL;
	//��������ǰ�ڵ�
	cur = NULL;
	push(ls, rt);//�ȰѸ��ڵ�ѹ��ջ��
	while (!stackempty(ls))
	{
		cur = NULL;
		gettop(ls, cur);
		if ((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " "; //���յ�ջ���������ǰ�������ڵ������
			if (cur == root)//����ѵ����ڵ㣬������������
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
				push(ls, cur->rchild);//�ٱ��������������������ڵ�ѹջ
			}
			if (cur->lchild != NULL)
			{
				push(ls, cur->lchild);//�����������������������ڵ�ѹջ
			}
		}
	}
}
//ʹ�õݹ�������������
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
//=======================================