/*Programming Exercise12-5*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main(int argc, char const *argv[])
{
	int i,j;
	int num[SIZE];
	int temp;/*用于交换的中间容器*/
	srand(time(NULL));
	for(i=0;i<SIZE;i++)
	{
		num[i]=rand()%10;/*生成0-10的随机数，储存在一个数组中等待排序
	}
	for(i=0;i<SIZE;i++)/*打印原始数据*/
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	for(i=0;i<SIZE;i++)/*冒泡排序*/
	{
		for(j=SIZE-1;j>i;j--)
		{
			if (num[j]>num[j-1])
			{
				temp=num[j-1];
				num[j-1]=num[j];
				num[j]=temp;
			}
			
		}
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	return 0;
}
			