/*Programming Exercise5-1*/
/*
#include<stdio.h>
const int min_in_hour=60;
main()
{
	int total_min;
	int hour,min;
	char c1,c2;
	printf("please input min:\t");
	scanf("%d",&total_min);
	while(total_min>0)
	{
		(total_days>0);
		hour=total_min/min_in_hour;
		min=total_min%min_in_hour;
		//c1=(hour>1?'s':' ');
		c2=(min>1?'s':' ');
		printf("It is %d hour%c and %d min%c\n",hour,hour>1?'s':' ',min,c2);
		printf("please input min:\t");
		scanf("%d",&total_min);
	}
}
/*如果使用(c=gethcar())>0，则会吃掉第一个输入到getchar里面，也就是说第一次给total_min赋值是不准确的，最高位被吃掉*/

/*Programming Exercise5-2*/
/*
#include<stdio.h>
#define LEN 10
main()
{
	int n;
	int i;
	printf("please input a integer: ");
	scanf("%d",&n);
	for(i=n;i<=n+LEN;i++)
		printf("%d ",i);
	printf("\n");
}
*/
/*Programming Exercise5-3*/
/*
#include<stdio.h>
#include<stdio.h>
const int days_in_week=7;
main()
{
	int total_days;
	int week,days;
	char c1,c2;
	printf("please input days:\t");
	scanf("%d",&total_days);
	while(total_days>0)
	{
		
		week=total_days/days_in_week;
		days=total_days%days_in_week;
		printf("It is %d week%c and %d day%c\n",week,week>1?'s':' ',days,days>1?'s':' ');
		printf("please input days:\t");
		scanf("%d",&total_days);
	}
}
/*1.不能使用do-while，也不能给total_days固定初值，而是应该在while前面先进行第一次输入，然后判断是否运行while，并在while末尾处进行下一次输入*/
/*2.条件表达式可以在printf中直接使用*/

/*Programming Exercise5-4*/
/*
#include<stdio.h>
const double cm2inch=0.3937;
main()
{
	float hight,inches;
	int feet;
	printf("Enter a height in CM: ");
	scanf("%f",&hight);
	while(hight>0)
	{
		feet=(hight*cm2inch)/12;
		inches=(int)(hight*cm2inch)%12+((hight*cm2inch)-(int)(hight*cm2inch));
		printf("%.1fcm=%d feet,%.1finches\n",hight,feet,inches);
		printf("Enter a height in CM: ");
		scanf("%f",&hight);
	}
}

/*浮点数不能求余，只能先强制转换成int，然后对整数部分求，再加上小数部分*/


/*Programming Exercise5-5*/
/*
#include<stdio.h>
main()
{
	int sum=0;
	int i,end;
	printf("where to go?\n");
	scanf("%d",&end);
	for(i=1;i<=end;i++)
		sum=sum+i;
	printf("you get %d\n",sum);
}
*/

/*Programming Exercise5-5*/
/*
#include<stdio.h>
main()
{
	int sum=0;
	int i,end;
	printf("where to go?\n");
	scanf("%d",&end);
	for(i=1;i<=end;i++)
		sum=sum+i*i;
	printf("you get %d\n",sum);
}
*/

/*Programming Exercise5-5*/
/*
#include<stdio.h>
float cube(float);
main()
{
	float f;
	printf("input a float number:");
	scanf("%f",&f);
	printf("output number:%.1f\n",cube(f));
}

float cube(float v)
{
	return v*v*v;
}
*/

/*Programming Exercise5-5*/
#include<stdio.h>
const float x=1.8;
const float y=32.0;
const float z=273.16;
void Temperature(double);
main()
{
	double temp;
	printf("input the temperature(F)\n");
	//scanf("%lf",&temp);/*%lf读入一个double类型的*/
	while(scanf("%lf",&temp))/*但是为了判断，scanf放在while里面*/
		Temperature(temp);
}

void Temperature(double temp)
{
	float c,k;
	c=(temp-32.0)/1.8;
	k=c+z;
	printf("--------------------\n");
	printf("F\tC\tK\n");
	printf("%.1f\t%.1f\t%.1f\t\n",temp,c,k);
	printf("--------------------\n");
}	

/*对于scanf函数，读入错误的匹配，则返回0，否则返回1*/











