#include <iostream>
using namespace std;
bool dealsb(int a, int b)
{
	return a < b;
}

void setsort(int* src, int n)
{
	/*选择排序*/
	int i, j, w;
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
			if (src[i] < src[j])//进行比较
	   //比较后进行交换
			{
				w = src[i];
				src[i] = src[j];
				src[j] = w;
			}
	}
	 
}
void insertsort(int* src, int n)
{
	bool (*ps)(int, int) = dealsb ;
	int i, j, tmp;
	for (i=1;i<n;++i)
	{
		tmp = src[i]; 
		for (j=i;j>0&& ps(src[j - 1], tmp);--j)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}
void insertsort(float * src, int n)
{
	 
	int i, j;
	float tmp;
	for (i = 1; i < n; ++i)
	{
		tmp = src[i];
		for (j = i; j > 0 &&  src[j-1]>tmp; --j)
		{
			src[j] = src[j - 1];
		}
		src[j] = tmp;
	}
}

void dealMergeSort(int *src, int* tmp, int  str, int  end)
{
	if (str >= end)
	{
		return;

	}
	int mid = (str + end) / 2;
	dealMergeSort(src, tmp, str, mid);
	dealMergeSort(src, tmp, mid + 1, end);
	int a = str;
	int b = mid + 1;
	int c = str;//1,5,6,15,8,26,5,55,9,0 
	while (a <= mid && b <= end)
	{

		if (src[a] > src[b])
		{
			tmp[c] = src[a];
			a++;
		}
		else
		{
			tmp[c] = src[b];
			b++;
		}
		c++;
	}
	for (; a <= mid; a++, c++)
	{
		tmp[c] = src[a];
	}
	for (; b <= end; b++, c++)
	{
		tmp[c] = src[b];
	}
	int i = 0;
	for (i = 0; i <= end; ++i)
	{
		src[i] = tmp[i];
	}
}
void MergeSort(int *src, int n)
{
	int *tmp = (int*)malloc(n * sizeof(int));
	dealMergeSort(src, tmp, 0, n - 1);//传入下标
	free(tmp);
}
void sort(int*src, int n, int point = 0)
{
	switch (point)
	{
	case 0:
		insertsort(src, n);
		break;
	case 1:
		setsort(src, n);
		break;
	case 2:
		MergeSort(src, n);
		break;
	}
}
void sort(float*src, int n, int point = 0)
{
 		insertsort(src, n);
		 
}
int mainx()
{
	int arr[10] = { 5,6,8,1,0,1,6,56,92,84 };
	float arr1[10]= { 5.0,6,8,1,0,1.2656,6,56,92,84 };
	sort(arr1, 10);
	//nsertsort(arr, 10);
	for (auto i : arr)
		cout << i << " ";
	system("pause"); 
	return 0;
}