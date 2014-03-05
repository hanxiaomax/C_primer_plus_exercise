/*Programming Exercise12-4*/
#include <stdio.h>
void call_time();
int times=0;
int i;
int main(int argc, char const *argv[])
{
	for(i=0;i<10;i++)
	{
		call_time();
	}
	printf("%d\n",times);
	return 0;
}

void call_time()
{
	times++;
}		
