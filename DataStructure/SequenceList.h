#pragma once
#include <iostream>
using namespace std;
constexpr auto Initsize = 20;

typedef struct {
	int* data;
	int Maxsize, length;
}SeqList;

// �� 20 Ϊ���ȴ������Ա�������󳤶��ɲ���ָ��
SeqList create(int maxsize = 20)
{
	SeqList list;
	list.data = new int[Initsize];
	list.length = 20;
	list.Maxsize = maxsize;
	return list;
}
// ��ʼ�����Ա�
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

// ׷��Ԫ��
void AddValue(SeqList& list, int value)
{
	list.data[list.length] = value;
	list.length += 1;
}

// ����Ԫ��
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
// ����Ԫ��
int getValue(SeqList list, int index)
{
	if (index >= list.length)
		return NAN;
	return list.data[index - 1];
}
// �����±�
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
// �޸�ָ���±��Ԫ��
void change(SeqList& list, int index, int value)
{
	if (index > list.length)
	{
		cout << "Error! the index is invaild!";
		return;
	}
	list.data[index - 1] = value;
}
// ����Ԫ��ֵɾ���±�
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
// �����±�ɾ��Ԫ��
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
// ��������
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
// ��������
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
// ɾ��˳�����ֵ��С��Ԫ�ز����ظ�ֵ���ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳�����
// ˼�룺��������˳���������СԪ�ز���ס��λ�ã����������������һ��Ԫ�����˳������һ��
bool DelMin(SeqList& L, int& value)
{
	if (L.length == 0)
	{
		cout << "˳���Ϊ��!" << endl;
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
// ˳���ת
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
// ɾ��˳�����������ָ��ֵ��ȵ�Ԫ��
void delAllX(SeqList& l, int x)
{
	// ��¼������ x ��Ԫ�ظ���
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
// ������˳�����ɾ��ֵλ��[s��t]֮�������Ԫ�أ���s��t�������˳���Ϊ�գ�����ֹ����
// ˼�룺��ͷ˳��ɨ��˳�����k��¼ֵ��[s��t]֮���Ԫ�ظ��������ڵ�ǰԪ�أ���ֵ��������������ǰ��k��λ�ã�����k++
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
// ɾ��˳����е��ظ�ֵ��ʹ��������Ԫ�ص�ֵ������ͬ
bool DeleteSame(SeqList& l)
{
	if (l.length == 0)
		return false;
	// �洢��һ������ͬ��Ԫ��
	int i;
	// ����ָ��
	int j;
	for (i = 0, j = 1; j < l.length; j++)
	{
		// ������һ������һ��Ԫ��ֵ��ͬ��Ԫ��
		if (l.data[i] != l.data[j])
		{
			// �ҵ��󣬽�Ԫ��ǰ��
			l.data[++i] = l.data[j];
		}
	}
	l.length = i + 1;
	return true;
}
// �ϲ���������˳���Ϊ�±��������±�
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
// �ڵ�������˳����в���ָ��ֵ�����ҵ���������Ԫ�ؽ���λ�ã����Ҳ��������
// ʹ���۰���ҷ�
void SearchExchangeInsertASC(SeqList& l, int x)
{
	// ˳����½�
	int low = 0;
	// ˳����Ͻ�
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
	// ˳����½�
	int low = 0;
	// ˳����Ͻ�
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
// �����е�ǰ�벿�����벿�ֽ�������ab���ba������ʱֱ�ӵ���converse
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
// ����������AB�ϲ�������е���λ��
int MSearch(int A[], int B[], int n)
{
	// �ֱ��ʾ����A��B����λ����ĩλ������λ��
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
// Ѱ����Ԫ�أ���ν��Ԫ�ؾ���һ�����������ظ����ֵ�ֵ�����ظ����ֵĴ����������г��ȵ�һ��
// ��0��5��5��3��5��7��5��5������Ԫ����5������0��5��5��3��5��1��5��7��û����Ԫ��
// �������д�����Ԫ��ʱ������Ԫ�أ����򷵻�-1
int Majority(int A[], int n)
{
	// t ���ڴ洢��ѡ��Ԫ��
	int t;
	int i;
	// count ���ڼ���
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
// ����һ�� n �������У������ҳ�1~n��û���������г��ֵ���С������
// ���磬��-5��3��2��3������С����������1����1��2��3������С��������4
int findMissMin(int a[], int n)
{
	int i;
	// �������
	int* b = new int[n];
	memset(b, 0, sizeof(int) * n);
	for (i = 0; i < n; i++)
		if (a[i] > 0 && a[i] <= n)
			b[a[i] - 1] = 1;
	for (i = 0; i < n; i++)
		if (b[i] == 0)break;
	return i + 1;
}