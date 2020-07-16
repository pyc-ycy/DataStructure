#include "SeqStack.h"

SeqStack::SeqStack()
{
	this->data = NULL;
	this->top = -1;
	this->length = 0;
	this->max = 20;
}

bool SeqStack::InitStack(int a[], int len)
{
	try {
		if (len > this->max)
			return false;
		this->data = new int[len];
		for (int i = 0; i < len; i++)
		{
			this->data[i] = a[i];
			this->top++;
		}
		this->length = len;
		return true;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return false;
	}
}

bool SeqStack::StackEmpty()
{
	if (this->top == -1)
		return true;
	return false;
}

int SeqStack::StackLength()
{
	return this->length;
}

int SeqStack::getTop()
{
	if (this->StackEmpty())
		return 0;
	return this->data[this->top];
}

bool SeqStack::push(int value)
{
	if (this->top == this->max - 1)
	{
		cout << "Õ»ÒÑÂú£¬ÇëÏÈµ¯Õ»£¬ÔÙÑ¹Õ»£¡" << endl;
		return false;
	}
	this->data[length] = value;
	top += 1;
	length += 1;
}

bool SeqStack::pop(int& e)
{
	if (top == -1)
	{
		cout << "Õ»ÒÑ¿Õ£¬ÎÞ·¨µ¯Õ»" << endl;
		return false;
	}
	e = data[top--];
	length -= 1;
	return true;
}

void SeqStack::StackTraverse()
{
	if (this->StackEmpty())
	{
		cout << "¿ÕÕ»£¡" << endl;
		return;
	}
	for (int i = top; i >= 0; i--)
		cout << data[i] << " ";
	cout << endl;
}
bool SeqStack::clear()
{
	if (this->StackEmpty())
	{
		cout << "¿ÕÕ»£¡" << endl;
		return false;
	}
	top = -1;
	length = 0;
	return true;
}
bool SeqStack::destroy()
{
	if (this->data == NULL)
	{
		cout << "Õ»²»´æÔÚ»òÎ´³õÊ¼»¯£¡" << endl;
		return false;
	}
	int* t = this->data;
	this->data = NULL;
	top = -1;
	length = 0;
	free(t);
}