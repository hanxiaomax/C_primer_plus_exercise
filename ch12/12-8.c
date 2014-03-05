/*Programming Exercise12-8*/
#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem,int val);
void show_array(const int ar[],int n);

int main()
{
	int *pa;
	int size;
	int value;
	printf("Enter the number of elements: ");
	scanf("%d",&size);
	while(size>0) 
	{
		printf("Enter the initialization value: ");
		scanf("%d",&value);
		pa=make_array(size,value);//如果没有分配成功返回NULL
		if(pa)//分配成功
		{
			show_array(pa,size);
				free(pa);//使用malloc就要free
		}
		printf("Enter the number of elements(<1 to stop)\n");
		scanf("%d",&size);
	}
	printf("Done.\n");
	return 0;
}
int * make_array(int elem,int val)
{
	int *p;
	int *start;
	int i;
	p=(int *)malloc(sizeof(int)*elem);//分配elem个int大小的空间
	start=p;//保存指针初始位置
	for(i=0;i<elem;i++)
	{
		*(p++)=val;//指针移动，所以要保存初始指针位置
	}
	return start;//返回数组首地址
}
void show_array(const int ar[],int n)//使用const防止修改数组
{
	int i;
	for(i=0;i<n;i++)
	{
		if (i%8==0)
			printf("\n");//每个8个数字进行一次换行
		printf("%d ", ar[i]);
	}
	printf("\n");
}