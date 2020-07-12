#pragma once
#include <iostream>
using namespace std;
constexpr auto Initsize = 20;

typedef struct {
	int* data;
	int Maxsize, length;
}SeqList;

// 以 20 为长度创建线性表，数组最大长度由参数指定
SeqList create(int maxsize = 20)
{
	SeqList list;
	list.data = new int[Initsize];
	list.length = 20;
	list.Maxsize = maxsize;
	return list;
}
// 初始化线性表
void initList(SeqList& list, int arr[], int len)
{
	if (len <= list.length)
	{
		for (int i = 0; i < len; i++)
		{
			list.data[i] = arr[i];
		}
		list.length = len;
	}
	else
	{
		if (list.Maxsize >= len) {
			delete[] list.data;
			list.data = new int[len];
			list.length = len;
			for (int i = 0; i < len; i++)
			{
				list.data[i] = arr[i];
			}
		}
		else
		{
			cout << "Error! The length of the arr is so long that the Maxsize of sqelist could not hold.";
		}
	}
}

// 追加元素
void AddValue(SeqList& list, int value)
{
	list.data[list.length] = value;
	list.length += 1;
}

// 插入元素
void InsertValue(SeqList& list, int value, int index)
{
	if (index > list.length)
	{
		cout << "Error! the index is invaild!" << endl;;
		return;
	}
	if (index == list.length)
		AddValue(list, value);
	else
	{
		for (int i = list.length; i >= index - 1; i--)
		{
			list.data[i] = list.data[i - 1];
		}
		list.data[index - 1] = value;
		list.length += 1;
	}
}
// 查找元素
int getValue(SeqList list, int index)
{
	if (index >= list.length)
		return NAN;
	return list.data[index - 1];
}
// 查找下标
int getIndex(SeqList list, int value)
{
	int i = 0;
	for (i = 0; i < list.length; i++)
		if (list.data[i] == value)
			break;
	if (i >= list.length)
		return NAN;
	return i + 1;
}
int getPreByValue(SeqList list, int value)
{
	int cur = getIndex(list, value);
	if (cur == 0)
	{
		cout << "The value is no exist!" << endl;
		return NAN;
	}
	return list.data[cur - 2];
}
int getLastByVlue(SeqList list, int value)
{
	int cur = getIndex(list, value);
	if (cur == 0)
	{
		cout << "The value is no exist!" << endl;
		return NAN;
	}
	return list.data[cur];
}
// 修改指定下标的元素
void change(SeqList& list, int index, int value)
{
	if (index > list.length)
	{
		cout << "Error! the index is invaild!";
		return;
	}
	list.data[index - 1] = value;
}
// 根据元素值删除下标
void delValue(SeqList& list, int value)
{
	int cur = getIndex(list, value);
	if (cur != 0)
	{
		for (int i = cur - 1; i < list.length - 1; i++)
			list.data[i] = list.data[i + 1];
		list.length -= 1;
	}
	else
		cout << "What you want delete is no exist in this seqList!" << endl;
}
// 根据下标删除元素
void delIndex(SeqList& list, int index)
{
	if (index > list.length)
	{
		cout << "Error! The index is invalid!" << endl;
		return;
	}
	for (int i = index - 1; i < list.length - 1; i++)
	{
		list.data[i] = list.data[i + 1];
	}
	list.length -= 1;
}
// 升序排序
void AscSort(SeqList& list)
{
	for (int i = 0; i < list.length; i++)
		for (int j = i + 1; j < list.length; j++)
		{
			if (list.data[i] > list.data[j])
			{
				int temp = list.data[i];
				list.data[i] = list.data[j];
				list.data[j] = temp;
			}
		}
}
// 降序排序
void DesSort(SeqList& list)
{
	for (int i = 0; i < list.length; i++)
		for (int j = i + 1; j < list.length; j++)
		{
			if (list.data[i] < list.data[j])
			{
				int temp = list.data[i];
				list.data[i] = list.data[j];
				list.data[j] = temp;
			}
		}
}
void display(SeqList list)
{
	for (int i = 0; i < list.length; i++)
		cout << list.data[i] << " ";
	cout << endl;
}
bool empty(SeqList list)
{
	if (list.length == 0)
		return true;
	return false;
}
void destroy(SeqList& list)
{
	delete[] list.data;
	list.length = 0;
	list.Maxsize = 0;
}
// 删除顺序表中值最小的元素并返回该值，空出的位置由最后一个元素填补；若顺序表为空则显示出错信息并退出运行
// 思想：搜索整个顺序表，查找最小元素并记住其位置，搜索结束后用最后一个元素填补，顺序表表长减一。
bool DelMin(SeqList& L, int& value)
{
	if (L.length == 0)
	{
		cout << "顺序表为空!" << endl;
		return false;
	}
	value = L.data[0];
	int pos = 0;
	for (int i = 1; i < L.length; i++)
	{
		if (L.data[i] < value)
		{
			value = L.data[i];
			pos = i;
		}
	}
	L.data[pos] = L.data[L.length - 1];
	L.length--;
	return true;
}
// 顺序表翻转
void reverse(SeqList& L)
{
	int temp;
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}
// 删除顺序表中所有与指定值相等的元素
void delAllX(SeqList& l, int x)
{
	// 记录不等于 x 的元素个数
	int k = 0;
	for (int i = 0; i < l.length; i++)
	{
		if (l.data[i] != x)
		{
			l.data[k] = l.data[i];
			k++;
		}
	}
	l.length = k;
}
// 从有序顺序表中删除值位于[s，t]之间的所有元素，若s和t不合理或顺序表为空，则终止操作
// 思想：从头顺序扫描顺序表，用k记录值在[s，t]之间的元素个数，对于当前元素，若值不符合条件，则前移k个位置，否则k++
bool DelInS2T(SeqList& l, int s, int t)
{
	int i, k = 0;
	if (l.length == 0 || s >= t)
		return false;
	for (i = 0; i < l.length; i++)
	{
		if (l.data[i] >= s && l.data[i] <= t)
			k++;
		else
			l.data[i - k] = l.data[i];
	}
	l.length -= k;
	return true;
}
// 删除顺序表中的重复值，使表中所有元素的值都不相同
bool DeleteSame(SeqList& l)
{
	if (l.length == 0)
		return false;
	// 存储第一个不相同的元素
	int i;
	// 工作指针
	int j;
	for (i = 0, j = 1; j < l.length; j++)
	{
		// 查找下一个与上一个元素值不同的元素
		if (l.data[i] != l.data[j])
		{
			// 找到后，将元素前移
			l.data[++i] = l.data[j];
		}
	}
	l.length = i + 1;
	return true;
}
// 合并两个有序顺序表为新表，并返回新表
bool merge(SeqList A, SeqList B, SeqList& C)
{
	if (A.length + B.length > C.length)
		return false;
	int i = 0, j = 0, k = 0;
	while (i < A.length && j < B.length)
	{
		if (A.data[i] <= B.data[j])
			C.data[k++] = A.data[i++];
		else
			C.data[k++] = B.data[j++];
	}
	while (i < A.length)
		C.data[k++] = A.data[i++];
	while (j < B.length)
		C.data[k++] = B.data[j++];
	return true;
}
// 在递增有序顺序表中查找指定值，若找到则与其后的元素交换位置，若找不到则插入
// 使用折半查找法
void SearchExchangeInsertASC(SeqList& l, int x)
{
	// 顺序表下界
	int low = 0;
	// 顺序表上界
	int high = l.length - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (l.data[mid] == x)break;
		else if (l.data[mid] < x)low = mid + 1;
		else if (l.data[mid] > x) high = mid - 1;
	}
	if (l.data[mid] == x && mid != l.length - 1)
	{
		int t = l.data[mid];
		l.data[mid] = l.data[mid + 1];
		l.data[mid + 1] = t;
	}
	if (low > high)
	{
		int i = l.length - 1;
		for (; i > high; i--)l.data[i + 1] = l.data[i];
		l.data[i + 1] = x;
		l.length += 1;
	}
}
void SearchExchangeInsertDSC(SeqList& l, int x)
{
	// 顺序表下界
	int low = 0;
	// 顺序表上界
	int high = l.length - 1;
	int mid;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (l.data[mid] == x)break;
		else if (l.data[mid] < x)high = mid - 1;
		else if (l.data[mid] > x) low = mid + 1;
	}
	if (l.data[mid] == x && mid != l.length - 1)
	{
		int t = l.data[mid];
		l.data[mid] = l.data[mid + 1];
		l.data[mid + 1] = t;
	}
	if (low > high)
	{
		int i = l.length - 1;
		for (; i > high; i--)l.data[i + 1] = l.data[i];
		l.data[i + 1] = x;
		l.length += 1;
	}
}
// 将序列的前半部分与后半部分交换，即ab变成ba，调用时直接调用converse
void reverse(int R[], int from, int to)
{
	int i, t;
	for (i = 0; i < (to - from + 1) / 2; i++)
	{
		t = R[from + i];
		R[from + i] = R[to - i];
		R[to - i] = t;
	}
}
void converse(int R[], int n, int p)
{
	reverse(R, 0, p - 1);
	reverse(R, p, n - 1);
	reverse(R, 0, n - 1);
}
// 求两个序列AB合并后的序列的中位数
int MSearch(int A[], int B[], int n)
{
	// 分别表示序列A和B的首位数、末位数、中位数
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
	while (s1 != d1 || s2 != d2)
	{
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2]) return A[m1];
		if (A[m1] < B[m2])
		{
			if ((s1 + d1) % 2 == 0)
			{
				s1 = m1;
				d2 = m2;
			}
			else
			{
				s1 = m1 + 1;
				d2 = m2;
			}
		}
		if (A[m1] > B[m1])
		{
			if ((s2 + d2) % 2 == 0)
			{
				d1 = m1;
				s2 = m2;
			}
			else
			{
				d1 = m1;
				s2 = m2 + 1;
			}
		}
	}
	return A[s1] < B[s2] ? A[s1] : B[s2];
}
// 寻找主元素，所谓主元素就是一个在序列中重复出现的值并且重复出现的次数大于序列长度的一半
// （0，5，5，3，5，7，5，5）的主元素是5，而（0，5，5，3，5，1，5，7）没有主元素
// 当序列中存在主元素时返回主元素，否则返回-1
int Majority(int A[], int n)
{
	// t 用于存储候选主元素
	int t;
	int i;
	// count 用于计数
	int count = 1;
	t = A[0];
	for (i = 1; i < n; i++)
	{
		if (A[i] == t)
			count++;
		else
		{
			if (count > 0)
				count--;
			else
			{
				t = A[i];
				count = 1;
			}
		}
	}
	if (count > 0)
	{
		for (i = count = 0; i < n; i++)
		{
			if (A[i] == t)
				count++;
		}
	}
	if (count > n / 2) return t;
	else return -1;
}
// 给定一个 n 长的序列，从中找出1~n中没有在序列中出现的最小正整数
// 例如，（-5，3，2，3）的最小正整数就是1，（1，2，3）的最小正整数是4
int findMissMin(int a[], int n)
{
	int i;
	// 标记数组
	int* b = new int[n];
	memset(b, 0, sizeof(int) * n);
	for (i = 0; i < n; i++)
		if (a[i] > 0 && a[i] <= n)
			b[a[i] - 1] = 1;
	for (i = 0; i < n; i++)
		if (b[i] == 0)break;
	return i + 1;
}