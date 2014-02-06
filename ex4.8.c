/*Programming Exercise4-1*/
/*
#include<stdio.h>
#define maxchar 50
main()
{
	char name[maxchar],xing[maxchar];
	printf("请输入名字和姓氏\n");
	scanf("%s %s",name,xing);
	printf("%s,%s\n",name,xing);
}
*/

/*Programming Exercise4-2*/
/*
#include<stdio.h>
#include<string.h>
#define maxchar 50
main()
{
	char name[maxchar],xing[maxchar];
	printf("请输入名字和姓氏\n");
	scanf("%s %s",name,xing);
	printf("\"%s %s\"\n",name,xing);
	printf("\"%20s\"\n",name);
	printf("\"%-20s\"\n",name);
	printf("\"%*s\"\n",strlen(name)+3,name);
}
*/


/*Programming Exercise4-3*/
/*
#include<stdio.h>
int main()
{
	float num;
	printf("please input a float number:\t");
	scanf("%f",&num);
	printf("the input is %5.1f or %5.1e\n",num,num);
	printf("the input is %+5.3f or %5.3e\n",num,num);
}
*/
/*Programming Exercise4-4*/
/*
#include<stdio.h>
int main()
{
	float hight;
	printf("please input you hight(feet):\t");
	scanf("%f",&hight);
	printf("Dabney,you are %.3f feet tall\n",hight);
}
*/
/*
#include<stdio.h>
int main()
{
	float hight;
	printf("please input you hight(cm):\t");
	scanf("%f",&hight);
	printf("Dabney,you are %.2f m tall\n",hight/100.0);
}
*/

/*Programming Exercise4-5*/
/*
#include<stdio.h>
#include<string.h>
#define SIZE 50
int main()
{
	char name[SIZE],xing[SIZE];
	printf("please input you NAME and LASTNAME:\t");
	scanf("%s %s",name,xing);
	printf("%s %s\n",name,xing);
	printf("%*d %*d\n",strlen(name),strlen(name),strlen(xing),strlen(xing));
	printf("%s %s\n",name,xing);
	printf("%d %*d\n",strlen(name),strlen(name),strlen(xing));
}
*/

/*Programming Exercise4-6*/
/*
#include<stdio.h>
#include<float.h>
main()
{
	double d=1.0/3.0;
	float f=1.0/3.0;
	printf("double:%.4f\t%.12f\t%.16f\n",d,d,d);
	printf("float:%.4f\t%.12f\t%.16f\n\n",f,f,f);
	printf("FLT_DIG\tDBL_DIG\n");
	printf("%d\t%d\n",FLT_DIG,DBL_DIG);
	
}
*/	

/*Programming Exercise4-7*/
#include<stdio.h>
const float g2l=3.785;
const float m2k=1.609;
main()
{
	float mile,gasoline;
	printf("please input the mile and the cost of gasoline:\t");
	scanf("%f %f",&mile,&gasoline);
	printf("%.1f miles per gallon\n",mile/gasoline);
	printf("%.5f L per 100KM\n",(gasoline*g2l)/(100.0*mile*m2k));
	
	
}










