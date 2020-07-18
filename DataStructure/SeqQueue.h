#pragma once
#include <iostream>
using namespace std;
constexpr auto maxsize = 20;
class SeqQueue
{
private:
	// ����Ԫ��
	int* data;
	// ��ͷָ��
	int front;
	// ��βָ��
	int rear;
	// �ӳ�
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
// ����ն���
SeqQueue::SeqQueue()
{
	data = new int[maxsize];
	front = rear = 0;
	len = 0;
}
// ��ʼ������
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
//�����п�
bool SeqQueue::isEmpty()
{
	if (rear == front)
		return true;
	return false;
}
// ��������
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
		cout << "����Ϊ�գ�" << endl;
		return 0;
	}
	return this->len;
}
int SeqQueue::getTop()
{
	if (!this->isEmpty())
		return data[front];
}
// ��Ӳ���
bool SeqQueue::EnQueue(int value)
{
	if (this->isFull())
	{
		cout << "�������޷����" << endl;
		return false;
	}
	data[rear] = value;
	rear = (rear + 1) % maxsize;
	this->len += 1;
	return true;
}
// ���Ӳ���
bool SeqQueue::DeQueue(int& e)
{
	if (this->isEmpty())
	{
		cout << "�Կգ��޷����ӣ�" << endl;
		return false;
	}
	e = data[front];
	front = (front + 1) % maxsize;
	this->len -= 1;
	return true;
}
//����
void SeqQueue::traverse()
{
	if (this->isEmpty())
	{
		cout << "����Ϊ�գ�" << endl;
		return;
	}
	int f = front;
	int r = rear;
	for (; f < rear; f++)
		cout << data[f] << " ";
	cout << endl;
}
// ��ն���
bool SeqQueue::clear()
{
	if (this->isEmpty())
	{
		cout << "����Ϊ�գ����ý�����ղ�����" << endl;
		return false;
	}
	front = rear = 0;
	len = 0;
	return true;
}