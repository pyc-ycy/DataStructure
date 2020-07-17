#pragma once
#include <iostream>
using namespace std;

typedef struct StackNode
{
	int data;
	int len;
	StackNode* next;
}StackNode, * LinkStack;
bool create(LinkStack& s)
{
	s = NULL;
	return true;
}
bool init(LinkStack& s, int a[], int len)
{
	try {
		LinkStack p;
		for (int i = 0; i < len; i++)
		{
			p = new StackNode;
			p->data = a[i];
			p->next = s;
			p->len = i + 1;
			s = p;
		}
		s->len = len;
		return true;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return false;
	}
}
int getTop(LinkStack s)
{
	return s->data;
}
bool push(LinkStack& s, int value)
{
	LinkStack p = new StackNode;
	p->data = value;
	p->next = s;
	p->len = s->len + 1;
	s = p;
	return true;
}
bool pop(LinkStack& s, int& e)
{
	if (s == NULL)
	{
		cout << "Õ»¿Õ" << endl;
		return false;
	}
	e = s->data;
	LinkStack p = s;
	s = s->next;
	delete p;
	return true;
}
void traverse(LinkStack s)
{
	LinkStack p = s;
	for (int i = 0; i < s->len; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}