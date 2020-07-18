#pragma once
#include <iostream>
using namespace std;

class LinkNode
{
public:
	int data;
	LinkNode* next;
	LinkNode()
	{
		data = 0;
		next = NULL;
	}
};

class LinkQueue
{
private:
	// 队头指针
	LinkNode* front;
	// 队尾指针
	LinkNode* rear;
	int len;
public:
	LinkQueue();
	bool init(int a[], int len);
	bool isEmpty();
	int getLen();
	int getTop();
	bool enQueue(int value);
	bool deQueue(int& e);
	void traverse();
	bool clear();
};
LinkQueue::LinkQueue()
{
	front = rear = new LinkNode();
	front->next = NULL;
	len = 0;
}
bool LinkQueue::init(int a[], int len)
{
	try
	{
		LinkNode* p;
		for (int j = 0; j < len; j++)
		{
			p = new LinkNode();
			p->data = a[j];
			this->rear->next = p;
			this->rear = p;
			this->len += 1;
		}
		return true;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		return false;
	}
}
bool LinkQueue::isEmpty()
{
	if (this->front == NULL && this->rear == NULL)
		return true;
	return false;
}
int LinkQueue::getLen()
{
	if (this->isEmpty())
		return 0;
	return this->len;
}
int LinkQueue::getTop()
{
	return this->front->next->data;
}
bool LinkQueue::enQueue(int value)
{
	try
	{
		LinkNode* p = new LinkNode();
		p->data = value;
		p->next = NULL;
		this->rear->next = p;
		this->rear = p;
		this->len += 1;
		return true;
	}
	catch (exception e)
	{
		cout << e.what() << endl;
		return false;
	}
}
bool LinkQueue::deQueue(int& e)
{
	if (this->isEmpty())
	{
		cout << "队空，无法出队！" << endl;
		return false;
	}
	LinkNode* p = this->front->next;
	e = p->data;
	this->front->next = p->next;
	this->len -= 1;
	if (this->rear == p)this->rear = this->front;
	delete p;
	return true;
}
void LinkQueue::traverse()
{
	if (this->isEmpty())
	{
		cout << "队空！" << endl;
		return;
	}
	LinkNode* p = this->front->next;
	for (int i = 0; i < this->len; i++)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
bool LinkQueue::clear()
{
	if (this->isEmpty())
	{
		cout << "队空！无需进行清空！" << endl;
		return false;
	}
	LinkNode* p = this->front;
	this->rear = this->front;
	this->front->next = nullptr;
	this->len = 0;
	delete p;
	return true;
}