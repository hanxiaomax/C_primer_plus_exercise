/*Programming Exercise8-1*/
/*
#include<stdio.h>
main()
{
	int num=0;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			;
		else
			num++;
	}
	printf("%d characters read\n",num);
	return 0;
}
*/


/*Programming Exercise8-2*/
/*
#include<stdio.h>
main()
{
	char c;
	printf("The program will receive the char and print the char and its ASCII\n");
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			printf("\\n\n");
		else if(c=='\t')
			printf("\\t\n");
		else if(c>0&&c<27)
			printf("^%c\n",c+64);
		else
			printf("%c\t\t%d\n",c,c);
	}
	return 0;
}
/*并未按要求每行打印10对值，不美观*/


/*Programming Exercise8-3*/
/*
#include<stdio.h>
#include<ctype.h>
main()
{
	int c;
	int up=0,low=0;
	printf("count the uppercase and lowercase\n");
	while((c=getchar())!=EOF)
	{
		if(isupper(c))
			up++;
		else if(islower(c))
			low++;
		else
			;
	}
	printf("The number of uppercase:%d\n",up);
	printf("The number of lowercase:%d\n",low);
	return 0;
}
*/

/*Programming Exercise8-4*/
/*
#include<stdio.h>
#include<ctype.h>
int main()
{
	float num_c=0;
	float num_words=1;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c==' ')
			num_words++;
		else if(ispunct(c))
			;
		else
			num_c++;
	}
	printf("there are %.0f words and %.0f charactors\n",num_words,num_c);
	printf("the average char in word is %.3f\n",num_c/num_words);
	return 0;
}
*/

/*Programming Exercise8-5*/
/*
#include<stdio.h>
int main()
{
	int x;
	int c;
	int start=0,end=100;
	int y=(start+end)/2;
	printf("---------------------------------------\n");
	printf("please set a number between 0 and 100: ");
	
	scanf("%d",&x);
	printf("---------------------------------------\n");
	printf("h:high\tl:low\tc:correct\n");
	printf("---------------------------------------\n");
	printf("computer:\"Is %d high,low or correct?\"\n",y);
	while((c=getchar())!='c')
	{
		
		if((c=getchar())=='h')
		{	
			end=y;
			y=(start+end)/2;
		}
		else if(c=='l')
		{	
			start=y;
			y=(start+end)/2;
		}
		else if(c=='c')
		{	
			printf("oh!!!yeah!!!\n");
			break;
		}
		else
			printf("invalid input\n");
		printf("computer:\"Is %d high,low or correct?\"\n",y);
	}		
	return 0;
}
*/
/*Programming Exercise8-6*/
/*
#include<stdio.h>
#include<ctype.h>
char get_first(void);
int main()
{
	int c;
	c=get_first();
	printf("%c is the first char\n",c);
	return 0;
}

char get_first(void)
{	
	int c;
	while((c=getchar())!=EOF)
	{
		if(c==' '||c=='\t')
			;
		else
			return c;
	}
}
*/
/*Programming Exercise8-7*/
/*
#include<stdio.h>
int main()
{
	int x;
	int start=0,end=100;
	int y=(start+end)/2;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a) $8.75/hr\t\tb) $9.33/hr\n");
	printf("c) $10.00/hr\t\td) $11.20/hr\n");
	printf("q) quit\n");
	printf("*****************************************************************\n");
	x=getchar();
	switch(x)
	{
		case 'a':
			break;
		case 'b':
			break;
		case 'c':
			break;
		case 'd':
			break;
		case 'q':
			break;
	}
}
*/

/*Programming Exercise8-8*/

#include<stdio.h>
#include<ctype.h>/*包含isdigit()*/
#include<stdlib.h>/*包含atof()*/
#define N 20
void Add(void);
void Subtract(void);
void Mutliply(void);
void Divide(void);
float get_num(void);
int main()
{
	int x;
	int start=0,end=100;
	int y=(start+end)/2;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a) add\t\t\ts) subtract\n");
	printf("m) multiply\t\td) divide\n");
	printf("q) quit\n");
	printf("*****************************************************************\n");
	x=getchar();
	switch(x)
	{
		case 'a':
			Add();
			break;
		case 's':
			Subtract();
			break;
		case 'm':
			Mutliply();
			break;
		case 'd':
			Divide();
			break;
		case 'q':
			printf("Bye~~~~~~\n");
			break;
	}
}

void Add(void)
{ 
	float num1,num2;
	printf("The first numbers:\n");
	num1=get_num();
	printf("The second numbers:\n");
	num2=get_num();
	printf("%.3f +%c%.3f%c= %.3f\n",num1,num2<0?'(':' ',num2,num2<0?')':' ',num1+num2);
}

void Subtract(void)
{
	float num1,num2;
	printf("The first numbers:\n");
	num1=get_num();
	printf("The second numbers:\n");
	num2=get_num();
	printf("%.3f -%c%.3f%c= %.3f\n",num1,num2<0?'(':' ',num2,num2<0?')':' ',num1-num2);
}

void Mutliply(void)
{
	float num1,num2;
	printf("The first numbers:\n");
	num1=get_num();
	printf("The second numbers:\n");
	num2=get_num();
	printf("%.3f *%c%.3f%c= %.3f\n",num1,num2<0?'(':' ',num2,num2<0?')':' ',num1*num2);
	
}
void Divide(void)
{
	float num1,num2;
	printf("The first numbers:\n");
	num1=get_num();
	printf("The second numbers:\n");
	num2=get_num();
	while(!num2)
	{
		printf("Enter a number other than 0\n");
		num2=get_num();
	}
	printf("%.3f /%c%.3f%c= %.3f\n",num1,num2<0?'(':' ',num2,num2<0?')':' ',num1/num2);
}



float get_num(void)
{
	char a[N];
	float num;
	do
	{
		scanf("%s",a);
		num=atof(a);
		if(num)
			break;
		else
		{
			if(isdigit(a))
			{
				break;
			}
			else
			{
				printf("%s is not a number.\n",a);
				printf("Please input a number,such as 2.5,-1.78E8,or 3\n");
			}
		}
	}while(!atof(a));
	return num;
}

/*此程序不能正确处理0的情况，待完善*/

