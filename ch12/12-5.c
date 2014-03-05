#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main(int argc, char const *argv[])
{
	int i,j;
	int num[SIZE];
	int temp;
	srand(time(NULL));
	for(i=0;i<SIZE;i++)
	{
		num[i]=rand()%10;
	}
	for(i=0;i<SIZE;i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	for(i=0;i<SIZE;i++)
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
			