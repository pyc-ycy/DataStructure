#pragma once
#include <iostream>
using namespace std;

// ��򵥵�˳�����
int SimpleSqrSearch(int arr[], int len, int keyValue)
{
	for (int i = 0; i < len; i++)
		if (arr[i] == keyValue)
			return i;
	return -1;
}
//�����ڱ���˳����ң�Ҫ�������0�±겻�洢��ֵ
int SeqSearch(int arr[], int len, int keyValue)
{
	arr[0] = keyValue;
	int i;
	for (i = len; arr[i] != keyValue; i--);
	return i;
}
// ����������е�˳�����
int OrderSearch(int arr[], int len, int keyValue)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == keyValue)
			return i;
		else if (arr[i]<keyValue && arr[i + 1]>keyValue)
			return -1;
	}
}