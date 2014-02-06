/*Programming Exercise7-1*/
/*
#include<stdio.h>
int main()
{
	int space=0;
	int line=0;
	int cn=0;
	char c;
	while((c=getchar())!='#')
	{
		if(c==' ')
			space++;
		else if(c=='\n')
			line++;
		else
			cn++;
	}
	printf("number of spaces=%d\n",space);
	printf("number of lines=%d\n",line);
	printf("number of other char=%d\n",cn);
}


/*Programming Exercise7-2*/
/*
#include<stdio.h>
int main()
{
	char c;
	int i=0;
	while((c=getchar())!='#')
	{	
		if(c==' ')
			printf("\\b:%d",c);
		else if(c=='\t')
			printf("\\t:%d",c);
		else if(c=='\n')
			printf("\\n:%d",c);
		else
			printf("%c:%d",c,c);
		printf("\t");
		i++;
		if(i%8==0)
			printf("\n");
	}
	printf("\n");
}

/*Programming Exercise7-3*/
/*使用数组和getchar()读入*/
/*
#include<stdio.h>
#define SIZE 30
int main()
{
	char s[SIZE]; 
	int i=0;
	float odd=0;
	float even=0;
	float sum_odd=0;
	float sum_even=0;
	while((s[i]=getchar())!='0')
	{
			;
		if((s[i]-'0')%2==0)
		{
			even++;
			sum_even+=(s[i]-'0');
		}
		else 
		{
			odd++;
			sum_odd+=(s[i]-'0');
		}
		i++;
	}
	printf("number of even:%.2f\n",even);
	printf("average of even:%.2f\n",sum_even/even);
	printf("number of odd:%.2f\n",odd);
	printf("average of odd:%.2f\n",sum_odd/odd);
}

/*不使用数组，使用scanf函数*/
/*
#include<stdio.h>
int main()
{
	int n=0;
	float odd=0;
	float even=0;
	float sum_odd=0;
	float sum_even=0;
	while(scanf("%d",&n)==1&&n!=0)
	{
		if(n%2==0)
		{
			even++;
			sum_even+=n;
		}
		else 
		{
			odd++;
			sum_odd+=n;
		}
	}
	printf("number of even:%.2f\n",even);
	printf("average of even:%.2f\n",sum_even/even);
	printf("number of odd:%.2f\n",odd);
	printf("average of odd:%.2f\n",sum_odd/odd);
	return 0;
}




/*atof是对整个数组进行转换，对于单个字符或是数组元素，直接根据ascii做减法*/
/*注意i++的位置，不能使用还未赋值的s[i]*/
/*用scanf的方法，则在输入的时候，数字之间必须有空格，否则会当一个数读入*/
/*综上，还是使用数组的方法比较方便，尤其是处理文件的时候*/

/*Programming Exercise7-4*/
/*
#include<stdio.h>
#define SIZE 500
int main()
{
	int n_dot=0;
	int n_exclam=0;
	int i=0;
	char s[SIZE];
	while((s[i]=getchar())!='#')
	{
		if(s[i]=='!')
		{
			n_exclam++;
			s[i++]='!';
			s[i]='!';
		}
		else if(s[i]=='.')
		{
			s[i]='!';
			n_dot++;
		}
		else
			;
		i++;
	}
	s[i]='\0';
	printf("%s\n",s);
	printf("!---->!! :%d\n",n_exclam);
	printf(".---->!  :%d\n",n_dot);
	return 0;
}
/*出现跳过某些字符，是因为使用==代替了=*/
/*
#include<stdio.h>
int main()
{
	int n_dot=0;
	int n_exclam=0;
	int i=0;
	char c;
	while((c=getchar())!='#')
	{
		if(c=='!')
		{
			n_exclam++;
			putchar('!');
			putchar('!');
		}
		else if(c=='.')
		{
			putchar('!');
			n_dot++;
		}
		else
			putchar(c);
		i++;
	}
	putchar('\n');
	printf("!---->!! :%d\n",n_exclam);
	printf(".---->!  :%d\n",n_dot);
	return 0;
}
/*Programming Exercise7-5*/
/*
#include<stdio.h>
int main()
{
	int n_dot=0;
	int n_exclam=0;
	int i=0;
	char c;
	while((c=getchar())!='#')
	{
		switch(c)
		{
			case '!':
				putchar('!');
				putchar('!');
				n_exclam++;
			case '.':
				putchar('!');
				n_dot++;
			default:
				putchar(c);
		}
	}
	putchar('\n');
	printf("!---->!! :%d\n",n_exclam);
	printf(".---->!  :%d\n",n_dot);
	return 0;
}

/*Programming Exercise7-6*/
/*
#include<stdio.h>
int main()
{
    int c;
    int n_ei=0;
    while((c=getchar())!='#')
    {
        if(c=='e')
        {
		putchar(c);
		c=getchar();
		if(c=='i')
		{
			n_ei++;
			putchar(c);
			putchar(' ');

		}
		else
			ungetc(c,stdin);
        }
	else
		putchar(c);
    }
    printf("\nthe times of ei=%d\n",n_ei);
}
/*多一个空格*/
/*带缓冲区的实现--未完成*/
/*使用ungetc(c,stdin)，当e后面不是i的时候，把多读的这个字符压回stdin，这样才能重新判断是否是e*/
/*如果不使用ungetc(c,stdin)，则会漏掉eei这种情况*/


/*Programming Exercise7-7*/
/*
#include<stdio.h>
#define BASE_SALARY 10.00
#define EXTRA_TIME 1.5
#define BELOW_300 0.15
#define NEXT_150 0.2
#define RESIDUE 0.25
int main()
{
	int hours;
	float sum_sal;
	float tax;
	float salary;
	printf("**********************************\n");
	printf("please input the hours :\n");
	scanf("%d",&hours);	
	if(hours>40)
		sum_sal=((hours-40)*EXTRA_TIME+hours)*BASE_SALARY;
	else if(hours<0)
	{
		printf("the number should bigger than 0\n");
		printf("please try again\n");
		scanf("%d",&hours);
	}
	else
		sum_sal=hours*BASE_SALARY;
	
	if(sum_sal<300)	
		tax=sum_sal*BELOW_300;
	else if(sum_sal>300&&sum_sal>450)
		tax=300*BELOW_300+(sum_sal-300)*NEXT_150;
	else 
		tax=300*BELOW_300+150*NEXT_150+(sum_sal-450)*RESIDUE;
	
	salary=sum_sal-tax;
	printf("----------------------------------\n");
	printf("Working time:%d\n",hours);
	printf("total salary\t\ttax\t\tsalary\n");
	printf("%-15.3f\t\t%-15.3f\t%-15.3f\n",sum_sal,tax,salary);
}

/*Programming Exercise7-8*/
/*
#include<stdio.h>
#define BASE_SALARY 10.00
#define EXTRA_TIME 1.5
#define BELOW_300 0.15
#define NEXT_150 0.2
#define RESIDUE 0.25
void sal_count(int hour);
int main()
{
	int n;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action\n");
	printf("1) $8.75/hrs\t\t\t\t2) $9.33/hrs\n");
	printf("3) $10.00/hrs\t\t\t\t4) $11.20/hrs\n");
	printf("5) quit\n");
	printf("*****************************************************************\n");
	while (scanf("%d", &n) == 1)
	{
		if(n==1||n==2||n==3||n==4)
		{
			switch(n)
			{
				case 1:
					printf("$8.75/hrs\n");
					sal_count(8.75);
					break;
				case 2:
					printf("$9.33/hrs\n");
					sal_count(9.33);
					break;
				case 3:
					printf("$10.00/hrs\n");
					sal_count(10.00);
					break;
				case 4:
					printf("$11.20/hrs\n");
					sal_count(11.20);
					break;

			}
		}
		else if(n==5)
		{
			printf("Thank you !\n");
			break;
		}
		else
 			printf("you should choose 1-4 or 5 to quit\n");
			printf("Enter the number corresponding to the desired pay rate or action\n");
	}	
	
	
}
void sal_count(int hours)
{
	float sum_sal;
	float tax;
	float salary;
	printf("********************************************\n");
	printf("please input the hours :\n");
	scanf("%d",&hours);	
	if(hours>40)
		sum_sal=((hours-40)*EXTRA_TIME+hours)*BASE_SALARY;
	else if(hours<0)
	{
		printf("the number should bigger than 0\n");
		printf("please try again\n");
		scanf("%d",&hours);
	}
	else
		sum_sal=hours*BASE_SALARY;
	
	if(sum_sal<300)	
		tax=sum_sal*BELOW_300;
	else if(sum_sal>300&&sum_sal>450)
		tax=300*BELOW_300+(sum_sal-300)*NEXT_150;
	else 
		tax=300*BELOW_300+150*NEXT_150+(sum_sal-450)*RESIDUE;
	
	salary=sum_sal-tax;
	printf("*************************************************\n");
	printf("Working time:%d\n",hours);
	printf("total salary\t\ttax\t\tsalary\n");
	printf("%-15.3f\t\t%-15.3f\t%-15.3f\n",sum_sal,tax,salary);
	printf("*************************************************\n");


}
/*Programming Exercise7-9*/
/*
#include<stdio.h>
int is_p(int n);
int main()
{
	int n;
	int i;
	printf("please input a number:\n");
	scanf("%d",&n);
	
	for(i=2;i<=n;i++)
		if(is_p(i))
			printf("%d ",i);
	printf("\n");

}

int is_p(int n)
{
	int i;
	int flag=1;
	if(n==2)
		return flag;
		
	else
	{	for(i=2;i<=n-1;i++)
		{
			if(n%i==0)
			{
				flag=0;
				break;
			}
			else 
				flag=1;
		}
	}
	return flag;

}
/*不能在循环中return*/

/*Programming Exercise7-10*/
/*
#include<stdio.h>
void tax_count(int n);
int main()
{
	int n;
	printf("*************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action\n");
	printf("1) 单身\t\t\t2) 户主\n");
	printf("3) 已婚，共有\t\t4) 已婚，离异\n");
	printf("5) quit\n");
	printf("*************************************************\n");
	while (scanf("%d", &n) == 1)
	{
		if(n==1||n==2||n==3||n==4)
		{
			switch(n)
			{
				case 1:
					printf("种类：单身\n");
					tax_count(17850);
					break;
				case 2:
					printf("种类：户主\n");
					tax_count(23900);
					break;
				case 3:
					printf("种类：已婚，共有\n");
					tax_count(29750);
					break;
				case 4:
					printf("种类：已婚，离异\n");
					tax_count(14875);
					break;

			}
		}
		else if(n==5)
		{
			printf("Thank you !\n");
			break;
		}
		else
 			printf("you should choose 1-4 or 5 to quit\n");
			printf("Enter the number corresponding to the desired pay rate or action\n");
	}	

}
void tax_count(int n)
{
	int income;
	float tax;
	printf("**************************\n");
	printf("please input the income :\n");
	scanf("%d",&income);	
	if(income>n)
		tax=n*0.15+(income-n)*0.28;
	else
		tax=income*0.15;
	printf("************************\n");
	printf("Income:%d\n",income);
	printf("Tax:%.3f\n",tax);
	printf("************************\n");

}

/*Programming Exercise7-11*/
#include<stdio.h>
#define artichoke 1.25
#define beet 0.65
#define carrot 0.89
void bill_count(float a,float b,float c);
int main()
{
	int o;
	float a,b,c,bill;
	printf("********************************************\n");
	printf("-----Welcome to the ordering system------\n");
	printf("Please choose the goods and input the pound\n");
	printf("Please use q to quit and send the order to us \n");
	printf("********************************************\n");
	printf("a:artichoke\t$1.25/pound\nb:beet\t\t$0.65/pound\nc:carro\t\t$0.89/pound\n");
	printf("********************************************\n");
	while((o=getchar())!='q')
	{
			switch(o)
			{
				case 'a':
						printf("pound:");
						scanf("%f",&a);
						break;
				case 'b':
						printf("pound:");
						scanf("%f",&b);
						break;
				case 'c':
						printf("pound:");
						scanf("%f",&c);
						break;
			}
	}
	printf("---------------Here is your bill------------------\n\n");
	printf("---------------Here is your order-----------------\n");
	printf("Goods\t\tweight\t\tprice\tcost\n");
	printf("a:artichoke\t%.2f\t\t1.25\t%.2f\n",a,a*1.25);
	printf("b:beet\t\t%.2f\t\t0.65\t%.2f\n",b,b*0.65);
	printf("c:carro\t\t%.2f\t\t0.89\t%.2f\n",c,c*0.89);
	printf("-------------------------------------------------\n");
	bill_count(a,b,c);
	printf("Thank you!!!");
}

void bill_count(float a,float b,float c)
{
	float price,bill,shipment,discount=0.0;
	float pound;
	price=a*artichoke+b*beet+c*carrot;
	pound=a+b+c;
	if(pound<=5)
		shipment=3.5;
	else if(pound>5&&pound<20)
		shipment=10.00;
	else if(pound>=20)
		shipment=8+0.1*pound;
	bill=price+shipment;
	if(bill>100)
	{
		discount=0.95;
		bill=bill*discount;
	}
	printf("Total weight:\t%.3f\n",pound);
	printf("Price:\t\t%.3f\n",price);
	if(discount>0)
		printf("Discount:\t0.95\n");
	else
		printf("Discount:\tSorry.No discount for this order\n");
	printf("Shipment fee:\t%.3f\n",shipment);
	printf("Bill in all:\t%.3f\n",bill);
	printf("-------------------------------------------------\n");


}



























