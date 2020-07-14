#pragma once
#include <iostream>
using namespace std;

class DNode
{
private:
	int data;
	DNode* prior, * next;
public:
	DNode();
	bool init(int a[], int len);
	void show();
	void insert(int index, int value);
	void del(int index);
};
DNode::DNode()
{
	this->data = 0;
	this->prior = nullptr;
	this->next = nullptr;
}
bool DNode::init(int a[], int len)
{
	try {
		DNode* p = this;
		DNode* s = new DNode();
		s->data = a[0];
		s->prior = p;
		p->next = s;
		p = s;
		for (int i = 1; i < len; i++)
		{
			s = new DNode();
			s->data = a[i];
			s->prior = p;
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

void DNode::show()
{
	DNode* p = this->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void DNode::insert(int index, int value)
{
	DNode* p = this->next;
	for (int i = 1; i < index - 1; i++)
		p = p->next;
	DNode* s = new DNode();
	s->data = value;
	s->prior = p;
	s->next = p->next;
	p->next = s;
}
void DNode::del(int index)
{
	DNode* p = this->next;
	for (int i = 1; i < index; i++)
		p = p->next;
	DNode* t = p->prior;
	t->next = p->next;
	p->next->prior = t;
	delete p;
}