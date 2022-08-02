#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//left_move(char*arr, int k)
//{
//	assert(arr);
//	int i = 0;
//	int len = strlen(arr);
//	for (i = 0; i < k; i++)
//	{
//		char tmp = *arr;
//		int j = 0;
//		for (j = 0; j < len-1 ; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//		*(arr + len - 1) = tmp;
//	}
//
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	left_move(arr, 2);
//
//	printf("%s\n", arr);
//	return 0;
//}

//三步逆序法，左旋字符串
//ab cdef 第一步，逆序左边
//第二步 逆序 右边 
//第三步 整体 逆序
void reserve(char*left,char*right)
{
	assert(left);
	assert(right);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;

	}
}
void lef_move(char *arr,int k)
{
	int len = strlen(arr);
	assert(k <= len);
	assert(arr);
	reserve(arr,arr+k-1 );
	reserve(arr+k, arr + len-1);
	reserve(arr , arr + len - 1);


}
//int main()
//{
//char arr[] = "abcdef";
//	lef_move(arr,2);
//
//	return 0;
//}
int is_left_move(char*s1, char*s2)
{
	int len = strlen(s1);//把旋转的可能性求出来
	int i = 0;
	for (i = 0; i < len; i++)
	{
		lef_move(s1, 1);//把arr1传过去 旋转一个
		int ret=strcmp(s1, s2);
		if (ret == 0)
		{
			return 1;
		}
	}return 0;
}
//int main()
//{//判断是不是旋转得来的
//	char * arr1[] = "abcdef";
//	char * arr2[] = "fedcba";
//	int ret=is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("yse\n");
//	else
//		printf("no\n");
//	return 0;
//
int left_move(char *str1,char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2)//判断是不是一样不一样直接返回0
		return 0;
	//1在字符串里追加自身
	//strcat( ,)可以加别人不能加自己

	strncat(str1, str1, len1);//可以加自己多长 

	//2判断str2指向的字符串是否是str1的子串
	//strstr-找子串
	char * ret = strstr(str1, str2);//找到了就返回首元素的地址，没有就返回NULL
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "abcdef";
//	int ret = left_move(arr1, arr2);
//	if (ret == 1)
//				printf("yse\n");
//			else
//				printf("no\n");
//			return 0;
//	return 0;
//}

//杨氏矩阵，每行左到右递增，每列上到下递增，在这里查找某个数字
//要求；时间复杂程度小于o（n）就是不能一个个找
int found(int arr[][3],int k,int* px,int* py )
{
	int x = 0;
	int y = *py - 1;
	while (y>=0 && x<=* px-1)
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		if (arr[x][y]> k)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
			
	}
	return 0;
}
int main()
{
	int arr[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	int k = 7;
	int x = 3;
	int y = 3;
	//返回型参数
	int ret = found(arr,k,&x,&y);//&形式参数改变实际参数也发生改变
	if (ret == 1)
	{
		printf("yse\n");
		printf("下标是=%d %d\n",x,y);

	}
				else
					printf("no\n");
	return 0;
}
//和上面一样但是 带坐标
//int found(int arr[][3], int k, int row, int col)
//{
//	int x = 0;
//	int y = col - 1;
//	while (y >= 0 && x <= row - 1)
//	{
//		if (arr[x][y] < k)
//		{
//			x++;
//		}
//		if (arr[x][y]> k)
//		{
//			y--;
//		}
//		else
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	int k = 7;
//	int ret = found(arr, k, 3, 3);
//	if (ret == 1)
//		printf("yse\n");
//	else
//		printf("no\n");
//	return 0;
//}