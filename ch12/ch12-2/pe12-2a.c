#include "pe12-2a.h"
#include <stdio.h>

void set_mode(int *pm)
{
	extern int prev_mode;//外部变量
	if (*pm!=METRIC && *pm!=US)
	{
		printf("Invalid mode specified.Mode %d will be used\n",prev_mode);
		*pm=prev_mode;//mode需要利用上一个mode
	}
	prev_mode=*pm;//储存当前的mode值，作为下一次的前值
}
void get_info(int mode,double *pd,double *pf)
{
	if(mode==METRIC)
	{
		printf("_______METRIC MODE_________\n");
		printf("Enter distane traveled in km : ");
		scanf("%lf",pd);
		printf("Enter fuel consumed in litter : ");
		scanf("%lf",pf);
	}
	else if(mode==US)
	{
		printf("__________US MODE_________\n");
		printf("Enter distane traveled in miles : ");
		scanf("%lf",pd);
		printf("Enter fuel consumed in gallon : ");
		scanf("%lf",pf);
	}
}
void show_info(int mode,double dist,double fuel)
{
	if(mode==METRIC)
		printf("Fuel consumption is %lf litters per 100 km.\n",(fuel/(dist*100)));
	else
		printf("Fuel consumption is %lf miles per gallon km.\n",dist/fuel);
}