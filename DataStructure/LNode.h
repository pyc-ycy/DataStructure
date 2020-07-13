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
};
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