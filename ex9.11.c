/*Programming Exercise9-1*/
/*
double min(double x,double y);
#include<stdio.h>
main()
{
	double x,y;
	scanf("%lf %lf",&x,&y);
	printf("return: %lf\n",min(x,y));
}
double min(double x,double y)
{
	return x<y?x:y;
}

/*Programming Exercise9-2*/
/*
#include<stdio.h>
void chline(char ch,int i,int j);
main()
{
	char ch;
	int i,j;
	printf("please input the char :");
	scanf("%c",&ch);
	printf("please input i and j :");
	scanf("%d %d",&i,&j);
	chline(ch,i,j);
}
void chline(char ch,int i,int j)
{
	int col=1;
	while(col++<i)
		printf(" ");	
	while(col>i&&col<=j)
	{
		col++;
		putchar(ch);
	}
	printf("\n");
}
/*Programming Exercise9-3*/
/*
#include<stdio.h>
void chprint(char ch,int i,int j);
main()
{
	char ch;
	int i,j;
	printf("please input char:\n");
	scanf("%c",&ch);
	printf("please input i and j :");
	scanf("%d %d",&i,&j);
	chprint(ch,i,j);
}
void chprint(char ch,int i,int j)
{
	int col,row;
	for(row=0;row<j;row++)
	{
		for(col=0;col<i;col++)		
			putchar(ch);
		printf("\n");
	}
}

/*Programming Exercise9-4*/
/*
#include<stdio.h>
double my_fun(double,double);
main()
{
	char ch;
	int i,j;
	printf("please input a and b :");
	scanf("%d %d",&i,&j);
	printf("result:%lf\n",my_fun(i,j));
}

double my_fun(double a,double b)
{
	return 1.0/(((1.0/a)+(1.0/b))/2);
}

/*Programming Exercise9-5*/
/*
#include<stdio.h>
void larger_of(double *x,double *y);
main()
{
	double i;
	double j;
	printf("please input i and j\n");
	scanf("%lf %lf",&i,&j);
	larger_of(&i,&j);
	printf("result:i=%lf,j=%lf\n",i,j);
}
void larger_of(double *x,double *y)
{
	if(*x<*y)
		*x=*y;
	else
		*y=*x;
}
/*把地址作为函数的实参*/
/*因为要修改外部的变量，所以需要用指针*/


/*Programming Exercise9-6*/
/*
#include<stdio.h>
int char_pos(char);
main()
{
	char c;
	int pos;
	while((c=getchar())!=EOF)
	{	
		pos=char_pos(c);
		if(pos!=-1)
			printf("%c in position %d\n",c,pos);
		else
			printf("%c is not in alphabet\n",c);
	}	
	printf("\n");
}

int char_pos(char c)
{
	if(c>='A'&&c<='Z')
		return c-'A'+1;
	else if(c>='a'&&c<='z')
		return c-'a'+1;
	else 
		return -1;
}
/*Programming Exercise9-7*/
/*
#include<stdio.h>
double power(double n,int p);
int main()
{
	double x,xpow;
	int exp;
	printf("Enter a number and integer power");
	printf("Enter q to quit.\n");
	while(scanf("%lf %d",&x,&exp)==2)
	{
		xpow=power(x,exp);
		printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
		printf("try again or enter q to quit\n");
	}
	printf("Hope you enjoyed this power trip -- Bye!\n");
	return 0;
}
double power(double n,int p)
{
	double pow=1;
	int i;
	if(p>0)
	{
		for(i=1;i<=p;i++)
			pow*=n;
		return pow;
	}
	else if(p==0)
	{
		if(n==0)
			return 0;
		else
			return 1;
		
	}
	else
	{
		printf("%d\n",p);
		for(i=1;i<=abs(p);i++)
			pow*=n;
		return 1.0/pow;
	}

}
/*负数始终不能正确运行，是因为在判断中使用了赋值，应该用==*/


/*Programming Exercise9-8*/
#include<stdio.h>
double power(double n,int p);
int main()
{
	double x,xpow;
	int exp;
	printf("Enter a number and integer power");
	printf("Enter q to quit.\n");
	while(scanf("%lf %d",&x,&exp)==2)
	{
		xpow=power(x,exp);
		printf("%.3g to the power %d is %.5g\n",x,exp,xpow);
		printf("try again or enter q to quit\n");
	}
	printf("Hope you enjoyed this power trip -- Bye!\n");
	return 0;
}
double power(double n,int p)
{
	double pow=1;
	int i;
	if(p>0)
	{
		pow=n*power(n,p-1);
		return pow;
	}
	else if(p==0)
	{
		if(n==0)
			return 0;
		else
			return 1;
		
	}
	else
	{
		printf("%d\n",p);
		for(i=1;i<=abs(p);i++)
			pow*=n;
		return 1.0/pow;
	}

}
/*使用p--是错误的，p-1正确*/

/*Programming Exercise9-9*/
/*不使用递归*/
/*
#include<stdio.h>
#define SIZE 20
void to_base_n(unsigned long n,int b);
int main()
{
	unsigned long n;
	int b;
	printf("please input the number n:");
	scanf("%lu",&n);
	printf("please input the base:");
	scanf("%d",&b);
	to_base_n(n,b);
	return 0;
}

void to_base_n(unsigned long n,int b)
{
	char s[SIZE];
	int shang,yu;
	int i=0;
	shang=n;
	while(shang>0)
	{
		yu=shang%b;
		shang/=b;
		s[i]=yu;
		i++;
	}
	while(s[i]!='\0')
		i++;
	while(--i>0)
		putchar('0'+s[i]);
	printf("\n");
	
}
/*使用递归*/
/*
#include<stdio.h>
void to_base_n(unsigned long n,int b);
int main()
{
	unsigned long n;
	int b;
	printf("please input the number n:");
	scanf("%lu",&n);
	printf("please input the base:");
	scanf("%d",&b);
	to_base_n(n,b);
	printf("\n");
	return 0;
}
void to_base_n(unsigned long n,int b)
{
	int yu;
	yu=n%b;
	if(n>=b)
		to_base_n(n/b,b);
	putchar('0'+yu);	
}
*/
/*Programming Exercise9-10*/
/*
#include<stdio.h>
#define SIZE 20
int Fibonacci(int n);
int main()
{
	int n,F;
	printf("input n:");
	scanf("%d",&n);
	while(!Fibonacci(n))
	{
		printf("input n:");
	 	scanf("%d",&n);
	}
	printf("\n");
	
}
int Fibonacci(int n)
{
	int s[SIZE];
	int i=n;
	s[0]=0;
	s[1]=1;
	if(n<0)
	{
		printf("n must biger than 0\n");
		printf("please try again \n");
		return 0;
	}
	else if(n==0)
		putchar('0'+s[0]);
	else if(n==1)
	{
		putchar('0'+s[0]);
		putchar(',');
		putchar('0'+s[1]);
	}
	else
	{	
		putchar('0'+s[0]);
		putchar(',');
		putchar('0'+s[1]);
		for(i=2;i<n;i++)
		{
			s[i]=s[i-1]+s[i-2];
			printf(",%d",s[i]);
		}
	}
	return 1;
}
/*不能倒着计算s[i]，否则没有前面的数参考，后面的数是乱码*/









