#pragma once
#include <iostream>
#include<string>
using namespace std;

class HeapStr
{
private:
	char* data;
	int length;
public:
	HeapStr();
	bool StrAssign(string s);
	void Show();
	void StrCopy(HeapStr s);
	bool StrEmpty();
	int StrCompare(HeapStr s);
	int StrLength();
	void SubStr(HeapStr& sub, int pos, int  len);
	void Concat(HeapStr s1, HeapStr s2);
	int Index(HeapStr sub);
	bool ClearStr();
};
// 构造串
HeapStr::HeapStr()
{
	data = NULL;
	length = 0;
}
bool HeapStr::StrAssign(string s)
{
	int len = s.length();
	try {
		data = (char*)malloc((len + 1) * sizeof(char));
		for (int i = 0; i < len; i++)
			data[i] = s[i];
		data[len] = '\0';
		length = len;
		return true;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return false;
	}
}
// 判空
bool HeapStr::StrEmpty()
{
	if (data == NULL)
	{
		cout << "未初始化赋值" << endl;
		return true;
	}
	if (length == 0)
		return true;
	return false;
}
int HeapStr::StrLength()
{
	if (data == NULL)
	{
		cout << "未初始化赋值" << endl;
		return -1;
	}
	else if (this->StrEmpty())
	{
		cout << "串空！" << endl;
		return 0;
	}
	return length;
}
void HeapStr::Show()
{
	if (data == NULL)
	{
		cout << "未初始化赋值" << endl;
		return;
	}
	else if (this->StrEmpty() || data[0] == '\0')
	{
		cout << "串空！" << endl;
		exit(0);
	}
	cout << data << endl;
}
void HeapStr::StrCopy(HeapStr s)
{
	if (s.length == 0)
	{
		cout << "参数为空串！" << endl;
		return;
	}
	if (s.data == NULL)
	{
		cout << "参数错误，未初始化赋值" << endl;
		exit(0);
	}
	int len = s.length;
	if (this->length < len)
	{
		cout << "参数串太长，将发生截断" << endl;
		for (int i = 0; i < length; i++)
			data[i] = s.data[i];
		data[length] = '\0';
	}
	for (int i = 0; i < len; i++)
		data[i] = s.data[i];
	data[len] = '\0';
}
int HeapStr::StrCompare(HeapStr s)
{
	if (data == NULL && s.data == NULL)
	{
		cout << "未初始赋值！" << endl;
		exit(0);
	}
	if (this->StrEmpty() == s.StrEmpty())
		return 0;
	int i;
	if (length < s.length)
	{
		for (i = 0; i < length; i++)
		{
			if (data[i] > s.data[i])
				return 1;
			else if (data[i] < s.data[i])
				return -1;
		}
		if (i == length)
			return 0;
	}
	for (i = 0; i < s.length; i++)
	{
		if (data[i] > s.data[i])
			return 1;
		else if (data[i] < s.data[i])
			return -1;
	}
	if (i == s.length)
		return 0;
}
void HeapStr::SubStr(HeapStr& s, int pos, int len)
{
	if (data == NULL)
	{
		cout << "未初始化赋值" << endl;
		return;
	}
	else if (this->StrEmpty())
	{
		cout << "串空！" << endl;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		s.data[i] = data[i + pos - 1];
	}
	s.data[len] = '\0';
}
void HeapStr::Concat(HeapStr s1, HeapStr s2)
{
	if (data == NULL)
	{
		cout << "未初始化赋值" << endl;
		return;
	}
	for (int i = 0; i < s1.length; i++)
		data[i] = s1.data[i];
	for (int j = 0; j < s2.length; j++)
		data[j + s1.length] = s2.data[j];
	data[s1.length + s2.length - 1] = '\0';
}
int HeapStr::Index(HeapStr sub)
{
	if (sub.length > length)
		return -1;
	int i = 0, j = 0;
	while (i < length && j < sub.length)
	{
		if (data[i] == sub.data[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 0;
		}
	}
	if (j > sub.length) return i - sub.length;
	else return 0;
}
bool HeapStr::ClearStr()
{
	if (data == NULL)
	{
		cout << "串未初始化赋值" << endl;
		exit(0);
	}
	if (length == 0)
	{
		return true;
	}
	data[0] = '\0';
	length = 0;
	return true;
}