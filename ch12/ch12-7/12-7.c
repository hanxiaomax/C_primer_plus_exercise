#include <stdio.h>
#include <stdlib.h>
#include <time.h>	
#include "diceroll.h"

int main(int argc, char const *argv[])
{
	int roll;
	int dice,sides,sets;
	int i;
	srand((unsigned int)time(NULL));
	printf("Enter the number of sets;q to stop.\n");
	while(scanf("%d",&sets)==1 && sets>0) 
	{	
		printf("How many sides and how many dice?\n");
		scanf("%d %d",&sides,&dice);
		printf("Here are %d sets of %d %d-sided throw.\n   ",sets,sides,dice );
		for(i=0;i<sets;i++)
		{
			roll=roll_n_dice(dice,sides);
			printf("%d ", roll);
		}
		printf("\n");
		printf("Enter the number of sets;q to stop.\n");
	}
	return 0;
}