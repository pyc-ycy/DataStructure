﻿// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "SequenceList.h"
using namespace std;
int main()
{
	SeqList list = create();
	int a[] = { 21, 2, 3, 4, 27, 8, 10 };
	int len = sizeof(a) / sizeof(int);
	initList(list, a, len);
	AddValue(list, 17);
	InsertValue(list, 23, len + 1);
	change(list, 4, 5);
	AscSort(list);
	display(list);
	SearchExchangeInsertASC(list, 21);
	display(list);
	DesSort(list);
	display(list);
	SearchExchangeInsertDSC(list, 6);
	display(list);
	int B[] = { 11, 13, 15, 17, 19 };
	int A[] = { 2, 4, 6, 8, 20 };
	int m = MSearch(A, B, 5);
	cout << m << endl;
	int arr[] = { 0,5,5,3,5,7,5,5 };
	int t = Majority(arr, 8);
	cout << t << endl;
	int c[] = { -5,3,2,3 };
	int d[] = { 1,2,3 };
	int t1 = findMissMin(c, 4);
	int t2 = findMissMin(d, 3);
	cout << t1 << " " << t2 << endl;
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