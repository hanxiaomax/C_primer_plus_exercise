/*Programming Exercise12-6*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num;
	int temp[10]={0};
	int i;
	int total=0;
	srand(time(NULL));
	for(i=0;i<1000;i++)
	{
		num=rand()%10;
		temp[num]++;/*用产生的数做索引，并把相应位置的数+1*/
	}
	for(num=0;num<10;num++)
	{
		printf("%d :%d\n", num,temp[num]);
		total+=temp[num];
	}
	printf("\n");
	printf("total:%d\n",total );
	return 0;
}
			