// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include "Sort.h"
using namespace std;
int main()
{
	int len = 8;
	int a[] = { -1,49,38,65,97,76,13,27,49 };
	int len1 = 10;
	int a1[] = { -1, 49,38,65,97,76,13,27,49,55,04 };
	int a2[] = { 49,38,65,97,76,13,27,49,55,04 };
	int a3[] = { 49,38,4,65,97,76,6,8,13,27,49, 10 };
	int a4[] = { 49,38,4,65,97,76,6,8,13,27,49, 10 };
	int a5[] = { -1, 49,38,65,97,76,13,27,49,55,04 };
	//InsertSortDirectly(a, len);
	InsertSortUndirectly(a, len);
	cout << "折半插入排序：";
	for (int i = 1; i <= len; i++)
		cout << a[i] << " ";
	cout << endl << "希尔排序：";
	ShellSort(a1, len1);
	for (int i = 1; i <= len1; i++)
		cout << a1[i] << " ";
	DoubleBubbleSort(a2, len1);
	cout << endl << "冒泡排序：";
	for (int i = 0; i < len1; i++)
		cout << a2[i] << " ";
	cout << endl << "快速排序：";
	QuickSort2(a3, 0, 11);
	for (int i = 0; i < 12; i++)
		cout << a3[i] << " ";
	cout << endl << "直接选择排序：";
	SelectSort(a4, 12);
	for (int i = 0; i < 12; i++)
		cout << a4[i] << " ";
	cout << endl << "堆排序·大堆根：";
	MaxHeapSort(a5, 10);
	for (int i = 1; i <= 10; i++)
		cout << a5[i] << " ";
	int a6[] = { -1, 49,38,65,97,76,13,27,49,55,04 };
	cout << endl << "小堆根排序：";
	MinHeapSort(a6, 10);
	for (int i = 1; i <= 10; i++)
		cout << a6[i] << " ";
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件