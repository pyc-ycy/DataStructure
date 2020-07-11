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
// ��˳�����ɾ��ֵλ��[s��t]֮�������Ԫ�أ���s��t�������˳���Ϊ�գ�����ֹ����
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