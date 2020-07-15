#pragma once
#include <iostream>
using namespace std;

//������
class LNode
{
private:
	int data;
	LNode* next;
public:
	LNode();
	bool init(int* a, int len);
	int value();
	int getValue(int index);
	void show();
	LNode* getIndex(int value);
	bool insert(int index, int value);
	bool del(int index);
	bool isEmpty();
	LNode* getPre(int index);
	LNode* getNext(int index);
	int length();
	bool append(int value);
	bool change(int index, int value);
	void Ascending();
	bool DelX(int x);
	friend void ReversePrint(LNode* L);
	bool DelMin();
	void reverse();
	void insertSort();
	bool RangeDel(int min, int max);
	LNode* searchCommon(LNode* L1);
	LNode* divide();
	void DelSame();
};
//ȥ������������ֵ��ͬ�Ķ���Ԫ�أ���ȥ��
void LNode::DelSame()
{
	LNode* p = this->next, * q;
	if (p == NULL)
		return;
	while (p->next != NULL)
	{
		q = p->next;
		if (p->data == q->data)
		{
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	}
}
// ��һ����������ŵ���ż�ֱ�����������
LNode* LNode::divide()
{
	int i = 0;
	LNode* B = new LNode();
	LNode* ra = this, * rb = B;
	LNode* p = this->next;
	this->next = NULL;
	while (p != NULL)
	{
		i++;
		if (i % 2 == 0)
		{
			rb->next = p;
			rb = p;
		}
		else
		{
			ra->next = p;
			ra = p;
		}
		p = p->next;
	}
	ra->next = NULL;
	rb->next = NULL;
	return B;
}
//Ѱ����������Ĺ������
LNode* LNode::searchCommon(LNode* L1)
{
	int len1 = this->length();
	int len2 = L1->length();
	int dist;
	LNode* longL, * shortL;
	if (len1 > len2)
	{
		longL = this->next;
		shortL = L1->next;
		dist = len1 - len2;
	}
	else {
		longL = L1->next;
		shortL = this->next;
		dist = len2 - len1;
	}
	while (dist--)
		longL = longL->next;
	while (longL != NULL)
	{
		if (longL == shortL)
			return longL;
		else {
			longL = longL->next;
			shortL = shortL->next;
		}
	}
	return NULL;
}
// ɾ��ֵ��ָ����Χ�ڵ�Ԫ�ص�ֵ
bool LNode::RangeDel(int min, int max)
{
	if (this->isEmpty())
		return false;
	LNode* pre = this, * p = this->next;
	while (p != NULL)
	{
		if (p->data > min && p->data < max)
		{
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
//ʹ�ò�������ʹ��������
void LNode::insertSort()
{
	LNode* p = this->next, * pre;
	LNode* r = p->next;
	p->next = NULL;
	p = r;
	while (p != NULL)
	{
		r = p->next;
		pre = this;
		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}
//�͵���������
void LNode::reverse()
{
	// r Ϊ p �ĺ�̣����ڷ�ֹ����
	LNode* p, * r;
	p = this->next;
	this->next = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = this->next;
		this->next = p;
		p = r;
	}
}
//ɾ�������е���Сֵ
bool LNode::DelMin()
{
	if (this->isEmpty())
		return false;
	// ����ָ��
	LNode* pre = this, * p = pre->next;
	// �洢��Сֵ�����ָ��
	LNode* minpre = pre, * minp = p;
	while (p != NULL)
	{
		if (p->data < minp->data)
		{
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next;
	free(minp);
	return true;
}
//�����������
void ReversePrint(LNode* L)
{
	if (L->next != NULL)
		ReversePrint(L->next);
	if (L != NULL && L->data != 0)
		cout << L->data << " ";
}
// ɾ������������ֵ����x�Ľ��
bool LNode::DelX(int x)
{
	if (this->isEmpty())
		return false;
	LNode* p = this->next, * pre = this, * q;
	while (p != NULL)
	{
		if (p->data == x)
		{
			q = p;
			p = p->next;
			pre->next = p;
			free(q);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	return true;
}
//����������
LNode::LNode()
{
	this->data = 0;
	this->next = NULL;
}
//����β�巨��ʼ��������
bool LNode::init(int* a, int len)
{
	LNode* s;
	LNode* p = this;
	try {
		for (int i = 0; i < len; i++)
		{
			s = new LNode();
			s->data = a[i];
			p->next = s;
			p = s;
		}
		return true;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return false;
	}
}
//�������п�
bool LNode::isEmpty()
{
	if (this->next == NULL)
		return true;
	return false;
}
//�������ȡֵ
int LNode::getValue(int index)
{
	if (!this->isEmpty())
	{
		int count = 1;
		LNode* p = this->next;
		if (index == 0)
			return this->data;
		if (index < 1)
			return NULL;
		while (p && count < index) {
			p = p->next;
			count++;
		}
		return p->data;
	}
	return -1;
}
//��ȡ��ǰ�ڵ��ֵ
int LNode::value()
{
	return this->data;
}
//����ָ��ֵ���ؽ��
LNode* LNode::getIndex(int value)
{
	if (this->isEmpty())
		return NULL;
	LNode* p = this->next;
	while (p != NULL && p->data != value)
		p = p->next;
	return p;
}
//��ȡ��
int LNode::length()
{
	if (this->isEmpty())
		return 0;
	LNode* p = this->next;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}
//��ȡָ���±��ǰ��
LNode* LNode::getPre(int index)
{
	if (this->isEmpty())
		return NULL;
	LNode* p = this->next;
	for (int i = 1; i < index - 1; i++)
		p = p->next;
	return p;
}
// ��ȡָ���±�ĺ��
LNode* LNode::getNext(int index)
{
	if (this->isEmpty())
		return NULL;
	LNode* p = this->next;
	for (int i = 1; i <= index; i++)
		p = p->next;
	return p;
}
//���������
bool LNode::insert(int index, int value)
{
	if (this->isEmpty())
		return false;
	int len = this->length();
	if (index <= 0 || index > len)
		return false;
	LNode* p = this->getPre(index);
	LNode* s = new LNode();
	s->data = value;
	s->next = p->next;
	p->next = s;
	return true;
}
//������׷��
bool LNode::append(int value)
{
	if (this->isEmpty())
		return false;
	LNode* p = this->next;
	while (p->next)
		p = p->next;
	LNode* s = new LNode();
	s->data = value;
	p->next = s;
	return true;
}
//��������޸�ĳ������ֵ
bool LNode::change(int index, int value)
{
	if (this->isEmpty())
		return false;
	int len = this->length();
	if (index <= 0 || index > len)
		return false;
	LNode* p = this->getPre(index + 1);
	p->data = value;
}
// �������ɾ��ĳ�����
bool LNode::del(int index)
{
	if (this->isEmpty())
		return false;
	int len = this->length();
	if (index <= 0 || index > len)
		return false;
	LNode* p = this->getPre(index);
	LNode* q = p->next;
	p->next = q->next;
	free(q);
}
//����������
void LNode::show()
{
	LNode* p = this->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void LNode::Ascending()
{
	LNode* p = this->next;
	LNode* q = p->next;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (p->data > q->data)
			{
				int t = p->data;
				p->data = q->data;
				q->data = t;
			}
			q = q->next;
		}
		p = p->next;
	}
}