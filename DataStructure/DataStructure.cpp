// DataStructure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include "BitTree.h"
using namespace std;
int main()
{
	//int a[] = { 21, 2, 3, 4, 27, 8, 10 };
	cout << "===============================================================" << endl;
	cout << "\t\t二叉树构造规则" << endl;
	cout << "采用先序规则构造二叉树，先根节点后左节点在右节点" << endl;
	cout << "如果输入的是整数 -1， \n则表示其前面刚输入的正整数的左或右子树为空。"
		<< "\n数组里最后出现的数字0 \n表示构成该树的所有正整数已输入完毕。" << endl;
	cout << "============================================================" << endl;
	BTree tree = new BitNode;
	createBiTreeNonRecursive(tree);
	if (tree != NULL)
	{
		int size1 = node(tree);
		leafCount(tree);
		cout << "先序递归遍历二叉树：" << endl;
		rDLR(tree);
		cout << endl;
		cout << "先序非递归遍历二叉树：" << endl;
		DLR(tree);
		cout << endl;
		cout << "中序递归遍历二叉树：" << endl;
		rLDR(tree);
		cout << endl;
		cout << "中序非递归遍历二叉树：" << endl;
		LDR(tree);
		cout << endl;
		cout << "后序递归遍历二叉树:" << endl;
		rLRD(tree);
		cout << endl;
		cout << "后序非递归遍历二叉树：" << endl;
		LRD(tree);
		cout << endl;
		cout << "该二叉树的叶子结点的数目：";
		cout << leaf << endl;
		int depth = Depth(tree);
		cout << "该二叉树的深度：" << depth << endl;
		cout << "该二叉树总节点数目：" << size1 << endl;
		cout << "层次遍历：" << endl;
		LevelOrder(tree);
		cout << endl;
		cout << "自下而上、从右到左层次遍历二叉树：" << endl;
		InvertLevel(tree);
		cout << endl;
	}
	else
	{
		cout << "树创建失败！" << endl;
	}
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