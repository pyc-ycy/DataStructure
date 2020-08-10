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
// ���ֲ��ң�����������еĲ����㷨
int BinSearch(int arr[], int len, int keyValue)
{
	int low = 0, high = len - 1, mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == keyValue)
			return mid;
		else if (arr[mid] > keyValue)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}