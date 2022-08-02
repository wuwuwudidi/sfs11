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

//�������򷨣������ַ���
//ab cdef ��һ�����������
//�ڶ��� ���� �ұ� 
//������ ���� ����
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
	int len = strlen(s1);//����ת�Ŀ����������
	int i = 0;
	for (i = 0; i < len; i++)
	{
		lef_move(s1, 1);//��arr1����ȥ ��תһ��
		int ret=strcmp(s1, s2);
		if (ret == 0)
		{
			return 1;
		}
	}return 0;
}
//int main()
//{//�ж��ǲ�����ת������
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
	if (len1 != len2)//�ж��ǲ���һ����һ��ֱ�ӷ���0
		return 0;
	//1���ַ�����׷������
	//strcat( ,)���Լӱ��˲��ܼ��Լ�

	strncat(str1, str1, len1);//���Լ��Լ��೤ 

	//2�ж�str2ָ����ַ����Ƿ���str1���Ӵ�
	//strstr-���Ӵ�
	char * ret = strstr(str1, str2);//�ҵ��˾ͷ�����Ԫ�صĵ�ַ��û�оͷ���NULL
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

//���Ͼ���ÿ�����ҵ�����ÿ���ϵ��µ��������������ĳ������
//Ҫ��ʱ�临�ӳ̶�С��o��n�����ǲ���һ������
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
	//�����Ͳ���
	int ret = found(arr,k,&x,&y);//&��ʽ�����ı�ʵ�ʲ���Ҳ�����ı�
	if (ret == 1)
	{
		printf("yse\n");
		printf("�±���=%d %d\n",x,y);

	}
				else
					printf("no\n");
	return 0;
}
//������һ������ ������
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