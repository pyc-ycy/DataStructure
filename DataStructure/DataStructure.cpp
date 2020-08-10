// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include "Search.h"
using namespace std;
int main()
{
	int len = 8;
	int a[] = { 2, 4, 6, 7, 8, 10, 12, 1 };
	int b[9] = { 0, 2, 5, 3, 15, 4, 8, 2, 10 };
	int c[] = { 1, 2, 3, 4, 6, 7, 8, 10 };
	cout << SimpleSqrSearch(a, len, 8) << endl;
	cout << SeqSearch(b, len, 20) << endl;
	cout << OrderSearch(c, len, 5) << endl;
	cout << "二分查找 6:" << BinSearch(c, len, 6) << endl;
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