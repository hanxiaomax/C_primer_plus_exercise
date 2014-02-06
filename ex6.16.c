/*Programming Exercise6-1*/
/*
#include<stdio.h>
int main()
{
	char s[26];
	int i;
	for(i=0;i<26;i++)
		s[i]='a'+i;
	printf("%s\n",s);
}
/*Programming Exercise6-2*/
/*
#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=5;i++)
	{
		for(j=1;j<=i;j++)
		{
			putchar('$');
			
		}
		putchar('\n');
	}
}

/*Programming Exercise6-3*/
/*
#include<stdio.h>
int main()
{
	int i,j;
	for(i=0;i<=5;i++)
	{
		for(j=0;j<=i;j++)
		{
			putchar('F'-j);
			
		}
		putchar('\n');
	}
}



/*Programming Exercise6-4*/
/*
#include<stdio.h>
int main()
{
	int i,k;
	int c;
	printf("please input a uppercase char:\n");
	c=getchar();
	printf("--------------------------------------\n");
	for(i=0;i<=(c-'A');i++)
	{
		for(k=1;k<=(c-'A')-i;k++)
			putchar(' ');
		for(k=(c-'A');k>=(c-'A')-i;k--)
			putchar(c-k);
		for(k=1;k<=i;k++)
			putchar(c-k);
		
		putchar('\n');
	}
}

/*Programming Exercise6-5*/
/*
#include<stdio.h>
int main()
{
	int i;
	int s,e;
	printf("------------------------\n");
	printf("START:\n");
	scanf("%d",&s);
	printf("END:\n");
	scanf("%d",&e);
	printf("------------------------\n");
	for(i=s;i<=e;i++)
	{
		printf("%d\t%d\t%d\n",i,i*i,i*i*i);
	}
}

/*Programming Exercise6-6*/
/*
#include<stdio.h>
#include<string.h>
#define SIZE 20
int main()
{
	char s[SIZE];
	int i=0;
	while((s[i]=getchar())!=EOF)
		i++;
	s[i]='\0';
	for(i=strlen(s);i>=0;i--)
		putchar(s[i]);
	putchar('\n');
}

/*Programming Exercise6-7*/
/*
#include<stdio.h>
#define SIZE 20
int main()
{
	float x,y,z;
	while(scanf("%f %f",&x,&y)==2)
	{
		z=(x-y)/(x*y);
		printf("%.5f\n",z);
	}
}

/*Programming Exercise6-8*/
/*
#include<stdio.h>
float fun(float x,float y);
int main()
{
	float x,y,z;
	while(scanf("%f %f",&x,&y)==2)
	{
		z=fun(x,y);
		printf("%.5f\n",z);
	}
}


float fun(float x,float y)
{
	return (x-y)/(x*y);	
}

/*Programming Exercise6-9*/
/*
#include<stdio.h>
int main()
{
	int s,e,z=0;
	int i;
	printf("START:\n");
	scanf("%d",&s);
	printf("END:\n");
	scanf("%d",&e);
	while(s<=e)
	{
		for(i=s;i<=e;i++)
			z+=(i*i);
		printf("%d\n",z);
		
		printf("START:\n");
		scanf("%d",&s);
		printf("END:\n");
		scanf("%d",&e);
	}
	printf("Bye!!\n");
}
/*Programming Exercise6-10*/
/*
#include<stdio.h>
#define SIZE 20
int main()
{
	int s[SIZE],c;
	int i=0;
	int k=0;
	while((c=getchar())!='\n')
	{
		s[i]=c-'0';
		i++;
	}
	i--;
	
	for(k=i;k>=0;k--)
		printf("%d",s[k]);
	putchar('\n');
}
/*Programming Exercise6-11*/
/*
#include<stdio.h>
void fun1(void);
void fun2(void);
int main()
{
	int n;
	printf("---------------------------\n");
	printf("1) 1.0+1.0/2.0+1.0/3.0.....\n");
	printf("2) 1.0-1.0/2.0+1.0/3.0.....\n");
	printf("---------------------------\n");
	while(scanf("%d",&n)==1)
	{
		switch(n)
		{
			case 1:
				fun1();
				break;
			case 2:
				fun2();
				break;
			default:
				break;
		}
	}
}
void fun1(void)
{
	int e;
	int i=0;
	float s=0;
	printf("1.0+1.0/2.0+1.0/3.0.....\n");
	printf("Input end number: ");
	scanf("%d",&e);
	while(i<e)
	{
		i++;
		s+=1.0/i;
	}
	printf("%.3f\n",s);
}
void fun2(void)
{
	int e;
	int i=0;
	float s=0;
	printf("1.0-1.0/2.0+1.0/3.0.....\n");
	printf("Input end number: ");
	scanf("%d",&e);
	while(i<e)
	{
		i++;
		s+=(-1)*(-1.0/i);
	}
	printf("%.3f\n",s);
}
/*Programming Exercise6-12*/
/*
#include<stdio.h>
int power(int a,int n);
int main()
{
	int s[8];
	int i;
	for(i=0;i<8;i++)
	{
		s[i]=power(2,i+1);
	}
	i=0;
	do
	{
		printf("%d ",s[i]);
		i++;	
	}while(i<8);
	
	printf("\n");
}

int power(int a,int n)
{
	int i;
	int s=1;
	for(i=0;i<n;i++)
		s*=a;

	return s;

}
/*重复使用index i的时候，要注意归零*/


/*Programming Exercise6-13*/
/*
#include<stdio.h>
int main()
{
	double s[8],q[8];
	int i;
	for(i=0;i<8;i++)
	{
		scanf("%lf",&s[i]);
	}
	for(i=0;i<8;i++)
		printf("%-4.1lf ",s[i]);
	printf("\n");
	q[0]=s[0];
	for(i=1;i<8;i++)
		q[i]=(q[i-1]+s[i]);
	for(i=0;i<8;i++)
		printf("%-4.1lf ",q[i]);
	printf("\n");
}
/*Programming Exercise6-14*/

/*
#include<stdio.h>
int main()
{
	char s[255];
	int i=0,k;
	while(scanf("%c",&s[i])&&s[i]!='\n')
		i++;
	s[i]='\0';
	for(k=i;k>=0;k--)
		printf("%c",s[k]);
	printf("\n");
}

/*Programming Exercise6-15*/
/*

#include<stdio.h>
int main()
{
	float da,de,d;
	int year=1;
	da=de=100;
	do
	{
		da+=10;
		de=1.05*de;
		printf("%f  ",da);
		printf("%f\n",de);
		year++;
	}while(de<=da);
	printf("year:%d\n",year);
	printf("Daphne get %f\n",da);
	printf("Deirdre get %f\n",de);
}

/*不能使用de=da，因为不存在这样的时刻*/


/*Programming Exercise6-16*/

#include<stdio.h>
int main()
{
	float or=100.0;
	float re;
	int year=1;
	for(year=1;or>0;year++)
	{
		or=or*1.08;
		or-=10;
		printf("%f\n",or);
	}
	printf("year:%d\n",year-1);
	
}
/*使用while会多一年*/

























