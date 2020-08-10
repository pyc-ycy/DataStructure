#pragma once
#include <iostream>
using namespace std;

// 最简单的顺序查找
int SimpleSqrSearch(int arr[], int len, int keyValue)
{
	for (int i = 0; i < len; i++)
		if (arr[i] == keyValue)
			return i;
	return -1;
}
//设有哨兵的顺序查找，要求数组的0下标不存储数值
int SeqSearch(int arr[], int len, int keyValue)
{
	arr[0] = keyValue;
	int i;
	for (i = len; arr[i] != keyValue; i--);
	return i;
}
// 针对有序序列的顺序查找
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
// 二分查找，针对有序序列的查找算法
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