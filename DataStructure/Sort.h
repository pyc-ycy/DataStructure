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
// 快速排序
int Partition(int a[], int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pivot) --high;
		a[low] = a[high];
		while (low < high && a[low] <= pivot) ++low;
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		// 划分
		int pivotpos = Partition(a, low, high);
		QuickSort(a, low, pivotpos - 1);
		QuickSort(a, pivotpos + 1, high);
	}
}
// 双向冒泡排序
void DoubleBubbleSort(int a[], int n)
{
	int low = 0, high = n - 1;
	bool flag = true;
	while (low < high&& flag)
	{
		flag = false;
		for (int i = low; i < high; i++)
		{
			if (a[i] > a[i + 1])
			{
				int t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				flag = true;
			}
		}
		high--;
		for (int j = high; j > low; j--)
		{
			if (a[j] < a[j - 1])
			{
				int t = a[j];
				a[j] = a[j - 1];
				a[j - 1] = t;
				flag = true;
			}
		}
		low++;
	}
}
// 将所有奇数移动到偶数前边
void Move(int a[], int len)
{
	int i = 0, j = len - 1;
	while (i < j)
	{
		while (i < j && a[i] % 2 != 0)i++;
		while (i < j && a[i] % 2 != 1)j--;
		if (i < j)
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		i++;
		j--;
	}
}
//随机选取轴枢元素的快速排序
int Partition2(int a[], int low, int high)
{
	int rand_index = low + rand() % (high - low + 1);
	int t = a[rand_index];
	a[rand_index] = a[low];
	a[low] = t;
	int i = low;
	int pivot = a[low];
	for (int j = low + 1; j <= high; j++)
	{
		if (a[j] < pivot)
		{
			t = a[++i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	t = a[i];
	a[i] = a[low];
	a[low] = t;
	return i;
}
void QuickSort2(int a[], int low, int high)
{
	if (low < high)
	{
		// 划分
		int pivotpos = Partition2(a, low, high);
		QuickSort(a, low, pivotpos - 1);
		QuickSort(a, pivotpos + 1, high);
	}
}