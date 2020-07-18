#pragma once
#include <iostream>
using namespace std;
constexpr auto maxsize = 20;
class SeqQueue
{
private:
	// 数据元素
	int* data;
	// 队头指针
	int front;
	// 队尾指针
	int rear;
	// 队长
	int  len;
public:
	SeqQueue();
	bool init(int a[], int len);
	bool isEmpty();
	bool isFull();
	int getLen();
	int getTop();
	bool EnQueue(int value);
	bool DeQueue(int& e);
	void traverse();
	bool clear();
};
// 构造空队列
SeqQueue::SeqQueue()
{
	data = new int[maxsize];
	front = rear = 0;
	len = 0;
}
// 初始化队列
bool SeqQueue::init(int a[], int len)
{
	try {
		for (int i = 0; i < len; i++)
		{
			data[rear] = a[i];
			rear = (rear + 1) % maxsize;
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
//队列判空
bool SeqQueue::isEmpty()
{
	if (rear == front)
		return true;
	return false;
}
// 队列判满
bool SeqQueue::isFull()
{
	if ((rear + 1) % maxsize == front)
		return true;
	return false;
}
int SeqQueue::getLen()
{
	if (this->isEmpty())
	{
		cout << "队列为空！" << endl;
		return 0;
	}
	return this->len;
}
int SeqQueue::getTop()
{
	if (!this->isEmpty())
		return data[front];
}
// 入队操作
bool SeqQueue::EnQueue(int value)
{
	if (this->isFull())
	{
		cout << "队满，无法入队" << endl;
		return false;
	}
	data[rear] = value;
	rear = (rear + 1) % maxsize;
	this->len += 1;
	return true;
}
// 出队操作
bool SeqQueue::DeQueue(int& e)
{
	if (this->isEmpty())
	{
		cout << "对空，无法出队！" << endl;
		return false;
	}
	e = data[front];
	front = (front + 1) % maxsize;
	this->len -= 1;
	return true;
}
//遍历
void SeqQueue::traverse()
{
	if (this->isEmpty())
	{
		cout << "队列为空！" << endl;
		return;
	}
	int f = front;
	int r = rear;
	for (; f < rear; f++)
		cout << data[f] << " ";
	cout << endl;
}
// 清空队列
bool SeqQueue::clear()
{
	if (this->isEmpty())
	{
		cout << "队列为空，不用进行清空操作！" << endl;
		return false;
	}
	front = rear = 0;
	len = 0;
	return true;
}