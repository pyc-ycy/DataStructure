#pragma once
#include <iostream>
using namespace std;

class SeqStack
{
private:
	// ���Ԫ��
	int* data;
	// ջ��ָ��
	int top;
	// ջ��
	int length;
	// ���ջ��
	int max;
public:
	// �����ջ
	SeqStack();
	// ��ʼ��
	bool InitStack(int a[], int len);
	// �п�
	bool StackEmpty();
	// ��ȡջ��
	int StackLength();
	// ��ȡջ��Ԫ��
	int getTop();
	// ѹջ
	bool push(int value);
	// ��ջ
	bool pop(int& e);
	// ����ջ
	void StackTraverse();
	// ���ջ
	bool clear();
};
