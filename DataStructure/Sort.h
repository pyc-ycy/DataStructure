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