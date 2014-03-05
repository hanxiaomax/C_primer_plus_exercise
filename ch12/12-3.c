/*Programming Exercise12-3*/
#include <stdio.h>
#define METRIC 0
#define US 1
int set_mode(int mode,int *prev);//需要通过指针修改mode
void get_info(int mode,double *pd,double *pf);//需要通过指针修改dist和fuel
void show_info(int mode,double dist,double fuel);//只需调用不需要修改

int main()
{
	int mode;
	double dist;
	double fuel;
	int prev_mode=METRIC;//储存上一个mode，文件作用域，外部链接
	printf("Enter 0 for metric mode,1 for US mode: ");
	scanf("%d",&mode);
	while(mode>=0)
	{
		mode=set_mode(mode,&prev_mode);//检查并设置合适的mode值
		get_info(mode,&dist,&fuel);//要求用户输入
		show_info(mode,dist,fuel);//计算并显示结果
		printf("Enter 0 for metric mode,1 for US mode ");
		printf("(-1 to quit):");
		scanf("%d",&mode);
	}
	printf("Done\n");
	return 0;
}
int set_mode(int mode,int *prev)
{
	if (mode!=METRIC && mode!=US)
	{
		printf("Invalid mode specified.Mode %d will be used\n",*prev);
		mode=*prev;//mode需要利用上一个mode
	}
	*prev=mode;//储存当前的mode值，作为下一次的前值
	return mode;
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
