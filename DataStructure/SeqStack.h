#pragma once
#include <iostream>
using namespace std;

class SeqStack
{
private:
	// 存放元素
	int* data;
	// 栈顶指针
	int top;
	// 栈长
	int length;
	// 最大栈长
	int max;
public:
	// 构造空栈
	SeqStack();
	// 初始化
	bool InitStack(int a[], int len);
	// 判空
	bool StackEmpty();
	// 获取栈长
	int StackLength();
	// 获取栈顶元素
	int getTop();
	// 压栈
	bool push(int value);
	// 弹栈
	bool pop(int& e);
	// 遍历栈
	void StackTraverse();
	// 清空栈
	bool clear();
};
