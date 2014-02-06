/*Programming Exercise10-1*/
/*
#include<stdio.h>
#define MONTHS 12
#define YEARS 5
int main()
{
	const float rain[YEARS][MONTHS] = {
	{10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
	{9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
	{6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
	{4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
	{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
 	};
 	int year,month;
	float subtot,total;
	printf(" YEAR\t     RAINFALL (inches) \n");
	for(year=0,total=0;year<YEARS;year++)
 	{
		for(month=0,subtot=0;month<MONTHS;month++)
			subtot+=*(*(rain+year)+month);
		printf("%5d %15.1f\n",2000+year,subtot);
		total+=subtot;

	}
	printf("\n");
	printf("\nThe yearly average is %.1f inches.\n\n",total/year);
	printf("MONTHLY AVERAGES:\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec:\n");
	
	for(month=0;month<MONTHS;month++)
	{
		for(year=0,subtot=0;year<YEARS;year++)
			subtot+=*(*(rain+year)+month);
		printf("%4.1f",subtot/YEARS);
	}

	printf("\n");

 	return 0;
}

/*Programming Exercise10-2*/
/*
#include<stdio.h>
void copy_arr(double source[],double target1[],int len);
void copy_ptr(double *source,double *target1,int len);
main()
{
	double source[5]={1.1,2.2,3.3,4.4,5.5};
	double target1[5];
	double target2[5];
	int i=0;
	copy_arr(source,target1,5);
	copy_ptr(source,target2,5);
	for(i=0;i<5;i++)
		printf("%lf ",target1[i]);
	printf("\n");
	for(i=0;i<5;i++)
		printf("%lf ",target2[i]);
	printf("\n");
}
	
void copy_arr(double source[],double target1[],int len)
{
	int i=0;
	for(i=0;i<len;i++)
		target1[i]=source[i];
}
void copy_ptr(double *source,double *target1,int len)
{
	int i=0;
	while(i<len)
	{
		*target1++=*source++;
		i++;
	}
}

/*Programming Exercise10-3*/
/*
#include<stdio.h>
int max(int s[],int len);
main()
{
	int s[5];
	int i;
	printf("Please input 5 number\n");
	for(i=0;i<5;i++)
		scanf("%d",&s[i]);
	printf("The biggest number:%d",max(s,5));
	printf("\n");
}
int max(int s[],int len)
{
	int i=0;
	int max;
	max=s[i];
	for(i=1;i<len;i++)
		if(s[i]>max)
			max=s[i];
	return max;

}
/*Programming Exercise10-4*/
/*
#include<stdio.h>
int max_index(double s[],int len);
main()
{
	double s[5];
	int i;
	printf("Please input 5 number\n");
	for(i=0;i<5;i++)
		scanf("%lf",&s[i]);
	printf("The index of the biggest number:%d",max_index(s,5));
	printf("\n");
}
int max_index(double s[],int len)
{
	int i=0;
	int max,index;
	max=s[i];
	index=i;
	for(i=1;i<len;i++)
		if(s[i]>max)
			index=i;
	return index;

}

/*Programming Exercise10-5*/
/*
#include<stdio.h>
double max_min(double s[],int len);
main()
{
	double s[5];
	int i;
	printf("Please input 5 number\n");
	for(i=0;i<5;i++)
		scanf("%lf",&s[i]);
	printf("Max minus Min:%lf",max_min(s,5));
	printf("\n");
}
double max_min(double s[],int len)
{
	int i=0;
	double max,min;
	double dist;
	max=s[i];
	min=s[i];
	for(i=1;i<len;i++)
		if(s[i]>max)
			max=s[i];
		else if(s[i]<min)
			min=s[i];
	printf("max:%lf\n",max);
	printf("min:%lf\n",min);
	return max-min;

}
/*其他的思路*/
/*1.分别写两个函数，求最大，最小值，然后在该函数中调用，返回差值*/
/*2.在函数中历遍两次，分别求最大值，最小值，返回差值*/

/*Programming Exercise10-6*/
/*
#include<stdio.h>
#define MONTHS 12
#define YEARS 5
void copy_arr(double source[],double target1[],int len);
int main()
{
	double rain[YEARS][MONTHS] = {
	{10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
	{9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
	{6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
	{4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
	{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
 	};
	int i=0;
	int j,k;
	double rain_copy[YEARS][MONTHS];
 	for(i=0;i<YEARS;i++)
	{
		copy_arr(rain[i],rain_copy[i],MONTHS);
		
	}
	printf("the original array:rain\n");
	for(j=0;j<YEARS;j++)
	{
		for(k=0;k<MONTHS;k++)
			printf("%4.1f ",rain[j][k]);
		printf("\n");
	}
	printf("the copy array:rain_copy\n");
	for(j=0;j<YEARS;j++)
	{
		for(k=0;k<MONTHS;k++)
			printf("%4.1f ",rain_copy[j][k]);
		printf("\n");
	}
	return 0;		
}
void copy_arr(double source[],double target1[],int len)
{
	int i=0;
	for(i=0;i<len;i++)
		target1[i]=source[i];
}
/*Programming Exercise10-7*/
/*
#include<stdio.h>
void copy_arr(int aim[],int *start,int num);
main()
{
	int source[7];
	int s2[3];
	int i;
	printf("Please input 7 number\n");
	for(i=0;i<7;i++)
		scanf("%d",&source[i]);
	copy_arr(s2,source+2,3);
	for(i=0;i<3;i++)
		printf("%d ",s2[i]);
	printf("\n");
}


void copy_arr(int aim[],int *start,int num)
{
	while(num>0)
	{
		*aim++=*start++;
		num--;
	}

}
/*Programming Exercise10-8*/
/*Programming Exercise10-9*/
/*
#include<stdio.h>
#define LEN 5
void add_arr(int source1[],int source2[],int aim[],int len);
main()
{
	int source1[LEN];
	int source2[LEN];
	int aim[LEN];
	int i;
	printf("Please input 7 number for source1\n");
	for(i=0;i<LEN;i++)
		scanf("%d",&source1[i]);
	printf("Please input 7 number for source2\n");
	for(i=0;i<LEN;i++)
		scanf("%d",&source2[i]);
	
	add_arr(source1,source2,aim,LEN);
	printf("add source 1 to source2:\n");
	for(i=0;i<LEN;i++)
		printf("%d ",aim[i]);
	printf("\n");
}

void add_arr(int source1[],int source2[],int aim[],int len)
{
	while(len>0)
	{
		*aim++=(*source1++) + (*source2++);
		len--;
	}
}

/*Programming Exercise10-10*/
/*二维数组做参数*/
/*
#include<stdio.h>
void double_fun(int a[][5],int m,int n);
void print_arr(int a[][5],int m,int n);
int main()
{
	int flag=1;
	int array[3][5]={
			{1,2,3,4,5},
			{2,4,6,8,10},
			{6,7,8,9,0}
			};
	while(flag==1)
	{
		print_arr(array,3,5);
		double_fun(array,3,5);
		printf("again?\n");
		printf("1) yes\t2) no\n");
		scanf("%d",&flag);
	}
	printf("Thank you!\n");
}

void double_fun(int a[][5],int m,int n)
{
	int j,k;
	for(j=0;j<m;j++)
	{
		for(k=0;k<n;k++)
			a[j][k]*=2;
	}
}
void print_arr(int a[][5],int m,int n)
{
	int j,k;
	for(j=0;j<m;j++)
	{
		for(k=0;k<n;k++)
			printf("%5d ",a[j][k]);
		printf("\n");
	}

}
/*1.void double_fun(int a[][5],int m,int n)注意使用int a[][5]*/
/*2.在函数中使用数组长度，需要把长度作为参数传递进来，对一维二维都是*/
/*3.实参永远都只能是数组名，不论一维二维*/
/*4.函数能否更灵活？*/
/*Programming Exercise10-11*/
/*
#include<stdio.h>
#define MONTHS 12
#define YEARS 5
void year_rain(const float source[][MONTHS],int m,int n);
void mon_avr(const float source[][MONTHS],int m,int n);
void print_arr(const float a[][MONTHS],int m,int n);
int main()
{
	
	float rain[YEARS][MONTHS] = {
	{10.2, 8.1, 6.8, 4.2, 2.1, 1.8, 0.2, 0.3, 1.1, 2.3, 6.1, 7.4},
	{9.2, 9.8, 4.4, 3.3, 2.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 5.2},
	{6.6, 5.5, 3.8, 2.8, 1.6, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 4.2},
	{4.3, 4.3, 4.3, 3.0, 2.0, 1.0, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
	{8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.2}
 	};
	//print_arr(rain,YEARS,MONTHS);
 	year_rain(rain,YEARS,MONTHS);
	mon_avr(rain,YEARS,MONTHS);
	//print_arr(rain,YEARS,MONTHS);
 	return 0;
}

void year_rain(const float source[][MONTHS],int m,int n)
{
	int year,month;
	float subtot,total;
	printf(" YEAR\t     RAINFALL (inches) \n");
	for(year=0,total=0;year<m;year++)
 	{
		for(month=0,subtot=0;month<n;month++)
			subtot+=*(*(source+year)+month);
		printf("%5d %15.1f\n",2000+year,subtot);
		total+=subtot;

	}
	printf("\n");
	printf("\nThe yearly average is %.1f inches.\n\n",total/year);
}
void mon_avr(const float source[][MONTHS],int m,int n)
{
	int year,month;
	float subtot,total;
	printf("MONTHLY AVERAGES:\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec:\n");
	
	for(month=0;month<n;month++)
	{
		for(year=0,subtot=0;year<m;year++)
			subtot+=*(*(source+year)+month);
		printf("%4.1f",subtot/YEARS);
	}

	printf("\n");
}

/*原数组作为数据来源，一定要保护好，使用const类型*/
/*但是本题没有修改数组，所以不是必须要使用const  */
/*可以使用函数print_arr在开始和结束时打印数组，进行检查*/
/*
void print_arr(const float a[][MONTHS],int m,int n)
{
	int j,k;
	for(j=0;j<m;j++)
	{
		for(k=0;k<n;k++)
			printf("%5.2f ",a[j][k]);
		printf("\n");
	}

}

/*Programming Exercise10-11*/
/*
#include<stdio.h>
#define LEN 5
#define ROWS 3
#define COLS 5
void a_store(double array[],int n);
double b_average(double s[],int len);
double c_all_aver(double s[][COLS],int num_of_array);
double d_max(double s[][COLS],int M);
void e_print(double s[][COLS]);
void print_arr(double a[][COLS],int m,int n);
main()
{
	double array[ROWS][COLS];
	int i;
	//double aver,all_aver,max;
	
	for(i=0;i<ROWS;i++)
	{
		printf("Please input 5 number for source%d\n",i+1);
		a_store(array[i],COLS);
	}
	print_arr(array,ROWS,COLS);
	e_print(array);
}

void a_store(double array[],int n)
{
	int i;
	for(i=0;i<n;i++)
		scanf("%5lf",&array[i]);
}
double b_average(double s[],int len)
{
	int i,sum=0;	
	for(i=0;i<len;i++)
		sum+=s[i];
	return sum/len;
}

double c_all_aver(double s[][COLS],int num_of_array)
{
	int i;
	double sum=0;
	for(i=0;i<num_of_array;i++)
		sum+=b_average(s[i],COLS);
	return sum/num_of_array;

}
double d_max(double s[][COLS],int M)
{
	int i,j;
	double max=s[0][0];
	for(i=0;i<M;i++)
		for(j=0;j<COLS;j++)
			if(s[i][j]>max)
				max=s[i][j];

	return max;
}

void e_print(double array[][COLS])
{
	int i;
	double aver,all_aver,max;

	for(i=0;i<ROWS;i++)
	{
		aver=b_average(array[i],COLS);
		printf("Average of array%d:%lf\n",i+1,aver);	
	}

	all_aver=c_all_aver(array,ROWS);
	printf("\nAverage of all %d array:%lf\n",ROWS,all_aver);
	

	max=d_max(array,ROWS);
	printf("\nThe max number is %lf\n",max);

}
void print_arr(double a[][COLS],int m,int n)
{
	int j,k;
	printf("array:\n");
	for(j=0;j<m;j++)
	{
		for(k=0;k<n;k++)
			printf("%5.2f ",a[j][k]);
		printf("\n");
	}

}
/*1.用一个循环来输入3个数组并分别储存，不要先输入三个，再储存*/
/*2.double b_average(double s[],int len)中sum=0必须要有,如果没有，有时可能是对的，但是实际上是错误的，最后的reslut也无法运行，会显示很奇怪的数字，一般是未初始化的结果*/



#include<stdio.h>
#define IN 1
#define OUT 0
main()
{
	int c,nl,nw,nc,state;
	state=OUT;
	nl=nw=nc=0;
	while((c=getchar())!=EOF)
	{
		++nc;
		if(c=='\n')
			++nl;
		if(c==' '||c=='\n'||c=='\t')
			state=OUT;
		else if(state==OUT)
		{
			state=IN;
			++nw;
		}
	}
	printf("%d %d %d\n",nl,nw,nc);
}



















