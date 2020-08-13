#pragma once

// 直接插入排序
void InsertSortDirectly(int a[], int len)
{
	int i, j;
	for (i = 2; i <= len; i++)
	{
		if (a[i] < a[i - 1])
		{
			// 复制为哨兵
			a[0] = a[i];
			for (j = i - 1; a[0] < a[j]; --j)
				a[j + 1] = a[j];
			a[j + 1] = a[0];
		}
	}
}
// 折半插入排序
void InsertSortUndirectly(int a[], int len)
{
	int i, j, low, high, mid;
	for (i = 2; i <= len; i++)
	{
		a[0] = a[i];
		low = 1;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] > a[0]) high = mid - 1;
			else low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; --j)
			a[j + 1] = a[j];
		a[high + 1] = a[0];
	}
}
// 希尔排序
void ShellSort(int a[], int len)
{
	int dk, i, j;
	for (dk = len / 2; dk >= 1; dk = dk / 2) // dk 表示步长
	{
		for (i = dk + 1; i <= len; ++i)
		{
			if (a[i] < a[i - dk]) // 将 a[i] 插入有序增量子表
			{
				a[0] = a[i];
				for (j = i - dk; j > 0 && a[0] < a[j]; j -= dk)
					a[j + dk] = a[j];   //记录后移，查找插入位置
				a[j + dk] = a[0];
			}
		}
	}
}
// 冒泡排序
void BubbleSort(int a[], int len)
{
	// 标志是否发生交换
	bool flag = false;
	for (int i = 0; i < len - 1; i++)
	{
		flag = false;
		for (int j = len - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;
			}
			flag = true;
		}
		if (flag == false)
			return;
	}
}