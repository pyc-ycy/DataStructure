// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include "HeapStr.h"
using namespace std;
int main()
{
	//int a[] = { 21, 2, 3, 4, 27, 8, 10 };
	string a = "abcdefgh";
	string b = "abcde";
	string c = "a";
	HeapStr hs1, hs2, hs3;
	hs1.StrAssign(a);
	hs2.StrAssign(b);
	hs3.StrAssign(c);
	hs1.Show();
	cout << hs1.StrLength() << endl;
	hs2.Show();
	hs3.Show();
	cout << hs2.StrLength() << endl;
	cout << hs1.Index(hs2) << endl;
	hs1.SubStr(hs3, 1, 5);
	hs3.Show();
	cout << hs2.StrCompare(hs3) << endl;
	hs3.Concat(hs1, hs2);
	hs3.Show();
	hs3.ClearStr();
	hs3.Show();
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