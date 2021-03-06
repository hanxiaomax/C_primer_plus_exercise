/*Programming Exercise11-1*/
/*
#include<stdio.h>
#define SIZE 10
char *store(char *array,int len);
main()
{
	char s[SIZE];
	char *st;
	st=store(s,SIZE-1);
	printf("%s\n",s);
	


}
char *store(char *array,int len)
{
	int c;
	int i=0;
	while((c=getchar())!=EOF&&i<len)
	{
		*array++=c;
		i++;
	}
	*array='\0';
	return array;

}
/*1.数组已经通过参数传递，并且修改，所以打印还是用s作为printf的一个参数*/
/*2.对于字符数组，最重要的就是结束符。在需要时一定要手动添加*/

/*Programming Exercise11-2*/
/*
#include<stdio.h>
#define SIZE 20
char *store(char *array,int len);
main()
{
	char s[SIZE];
	char *st;
	st=store(s,SIZE-1);
	printf("%s\n",s);
	


}
char *store(char *array,int len)
{
	int c;
	int i=0;
	while((c=getchar())!=' '&&c!='\n'&&c!='\t'&&i<len)
	{
		*array++=c;
		i++;
	}
	*array='\0';
	return array;

}
/*Programming Exercise11-3*/
/*
#include<stdio.h>
#define SIZE 20
char *getword(char *array,int len);
main()
{
	char word[SIZE];
	char *st;
	st=getword(word,SIZE-1);
	printf("%s\n",word);
	


}
char *getword(char *array,int len)
{
	int c;
	int i=0;
	while((c=getchar())!=' '&&c!='\n'&&c!='\t'&&i<len)
	{
		*array++=c;
		i++;
	}
	*array='\0';
	return array;

}


/*Programming Exercise11-4*/
/*
#include<stdio.h>
#define SIZE 20
char *search(char *array,int chr);
main()
{
	char s[SIZE];
	char *st;
	char c;
	gets(s);
	while(1)
	{	
		__fpurge(stdin);
		printf("What char u wanna search?\n");
		scanf("%c",&c);
		st=search(s,c);
		if(st==NULL)
			printf("There is no %c in %s\n",c,s);
		else
			printf("%p\n",st);	
	}
	
}
char *search(char *array,int chr)
{
	int i;
	for(i=0;array[i]!='\0';i++)	
		if(array[i]==chr)
			return array+i;
	return NULL;
	

}
/*使用__fpurge(stdin)清空缓冲区的回车*/

/*Programming Exercise11-5*/
/*
#include<stdio.h>
int is_within(char c,char *str);
main()
{
	char s[100];
	char c;
	printf("Please input the string\n");
	gets(s);
	while(1)
	{
		printf("what char u wanna search?\n");
		__fpurge(stdin);
		c=getchar();
		if(is_within(c,s))	
			printf("IN\n");
		else
			printf("NOT IN\n");
	}
}

int is_within(char c,char *str)
{
	int i;
	while(*str!=c||*str!=EOF)
		str++;
	return *str;

}
/*使用__fpurge(stdin)清空缓冲区的回车*/

/*Programming Exercise11-6*/
/*
#include<stdio.h>
char *Strncpy(char *s1,char *s2,int n);
main()
{
	char s1[100],s2[100];
	int n;
	gets(s2);
	printf("Please input n:\n");
	scanf("%d",&n);
	Strncpy(s1,s2,n);
	puts(s1);

}

char *Strncpy(char *s1,char *s2,int n)
{
	int i=0;
	for(i=0;i<n;i++)
		s1[i]=s2[i];
	s1[i]='\0';

}


/*Programming Exercise11-7*/
/*
#include<stdio.h>
#include<string.h>
char *string_in(const char *s1,const char *s2);
main()
{
	char *ptr;
	ptr=string_in("transportation","transportation");
	if(ptr)
		puts(ptr);
	else
		puts("Not found");

}

char *string_in(const char *s1,const char *s2)
{
	int len1,len2;
	int no=1;
	int times;
	len2=strlen(s2);
	len1=strlen(s1);
	times=len1-len2+1;
	printf("%d %d\n",len1,len2);
	if(times>0)
		while(no=strncmp(s1,s2,len2)&&times--)
			s1++;
	if(no)	
		return NULL;
	else 
		return (char *) s1;
}

/*1.比较的次数自然要加1，否则当s1就是s2的时候会出现找不到*/
/*2.对s1进行自增运算，strncmp中的s1也就发生了变化*/

/*Programming Exercise11-8*/
/*
#include<stdio.h>
#include<string.h>
void rev_string(char *s);
main()
{
	char a[100];
	gets(a);
	rev_string(a);
	puts(a);


}

void rev_string(char *s)
{
	int i=0;
	int len,temp;
	len=strlen(s);
	for(i=0;i<len/2;i++)
	{
		temp=s[i];
		s[i]=s[len-1-i];
		s[len-1-i]=temp;
	}
	
	
}
/*1.不需要使用两个数组，一个数组就可以，也不需要指针*/
/*2.注意i<len/2，因为只需要把首尾对称的元素调换即可*/


/*Programming Exercise11-9*/
/*
#include<stdio.h>
#include<string.h>
void no_space(char *s);
main()
{
	char a[100];
	gets(a);
	no_space(a);
	//puts(a);

}

void no_space(char *s)
{
	int i;
	int len;
	char *pos;
	char *start=s;
	while(*s)
	{
		
		if(*s==' ')
		{
			pos=s;
			do
			{
				*pos=*(pos+1);
				pos++;
				
			}while(*pos);	
			//printf("移动后结果：%s\n",start);
		}
		
		else
			s++;
	}
}

/*1.当有空格的时候，需要用后面的字符串覆盖前面字符串*/
/*2.当遇到空格时候，用新的指针pos指向当前位置，然后不断用后面字符覆盖前面*/
/*3.while(*pos)表明了，当遇到空格，后面覆盖前面是到字符串最终结尾为止的*/
/*4.相当于空格后面的字符串整体前移*/


/*Programming Exercise11-10*/
/*
#include<stdio.h>
#include<string.h>
#define MAXLINES 10
#define MAXLEN 100
#define ALLOCSIZE 1000
int Readlines(char *lineptr[],int nlines);
void Writelines(char *lineptr[],int nlines);
void qsort(void *v[],int left,int right,int (*comp)(void *,void *));
void as_order(char *lineptr[],int lines);
void s2l_order(char *lineptr[],int lines);
void word_order(char *lineptr[],int lines);
main()
{	
	char *list[MAXLINES];
	int flag=1;
	int n,lines;
	printf("----------------------------------------------\n\n");
	printf(" * Please input 10 strings\n");
	while((lines=Readlines(list,MAXLINES))<=0)//括号要有，赋值优先级低
		printf("Please input 10 strings\n");
	printf("\n* Input succeed!\n");
	printf("* U have input %d lines\n",lines);
	printf("\n----------------------------------------------\n");
	printf("1.按初始顺序输出\t2.按ASCII顺序输出\n");
	printf("3.按长度递增顺序输出\t4.按首单词长度顺序输出\n");
	printf("q.退出\n");
	printf("----------------------------------------------\n");
	__fpurge(stdin);
	printf("PLease chose ur function\n");
	flag=scanf("%d",&n);
	while(flag==1)
	{
		switch(n)
		{
			case 1:
				printf("按初始顺序输出:\n");	
				Writelines(list,lines);
				break;
			case 2:
				printf("按ASCII顺序输出:\n");
				as_order(list,lines);
				break;
			case 3:
				printf("按长度递增顺序输出:\n");
				s2l_order(list,lines);
				break;
			case 4:
				printf("按首单词长度顺序输出:\n");
				word_order(list,lines);
				break;
			default:
				printf("\nError:You should choose from the table!\n");
				break;
		}
		printf("----------------------------------------------\n");
		printf("PLease chose ur function\n");
		flag=scanf("%d",&n);
	}
}

int Getline(char line[],int maxline);//读入字符串函数
char *alloc(int);//储存空间分配函数
int Readlines(char *lineptr[],int maxlines)
{
	int len;
	int nlines;
	char *p;//永久储存空间的字符串指针
	char line[MAXLEN];
	nlines=0;
	while((len=Getline(line,MAXLEN))>0)
		if(nlines>=maxlines||(p=alloc(len))==NULL)
			return -1;//不做小于10行的判断，只规定不能超过10行
		else	
		{
			line[len-1]='\0';	//删除换行符
			strcpy(p,line);		//把临时空间line中字符串复制到永久空间
			lineptr[nlines++]=p;//储存指针地址
		}
	return nlines;//允许小于10行的任意行输出

}
int Getline(char s[],int lim)
{
	int c,i;
	for(i=0;i<(lim-1)&&(c=getchar())!=EOF&&c!='\n';i++)
		s[i]=c;
	if(c=='\n')
	{
		s[i]=c;
		++i;	
	}
	s[i]='\0';
	return i;
}
void Writelines(char *lineptr[],int nlines)
{
	while(nlines-->0)
	{
		printf("%s\n",*lineptr++);
	}
	
}
static char allocbuf[ALLOCSIZE];//永久储存空间
static char *allocp=allocbuf;
char *alloc(int n)
{
	if(allocbuf+ALLOCSIZE-allocp>=n)
	{
		allocp+=n;
		return allocp-n;
	}
	else
		return 0;
}

void qsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
	int i,last;
	void swap(void *v[],int i,int j);
	if(left>=right)
		return ;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if((*comp)(v[i],v[left])<0)
			swap(v,++last,i);
	swap(v,left,last);
	qsort(v,left,last-1,comp);
	qsort(v,last+1,right,comp);
}

int lencmp(char v1[],char v2[])
{
	int len1,len2;
	len1=strlen(v1);
	len2=strlen(v2);
	if(len1>len2)
		return 1;
	else if(len1<len2)
		return -1;
	else
		return 0;
}
int wordcmp(char v1[],char v2[])
{
	int i,j;
	i=j=0;
	while(v1[i]!=' ')
		i++;
	while(v2[j]!=' ')
		j++;
	if(i>j)
		return 1;
	else if(i<j)
		return -1;
	else
		return 0;
}
void swap(void *v[],int i,int j)
{
	void *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}

void s2l_order(char *lineptr[],int lines)
{
	qsort((void **)lineptr,0,lines-1,(int (*)(void *,void *))(lencmp));
	Writelines(lineptr,lines);
}

void word_order(char *lineptr[],int lines)
{
	qsort((void **)lineptr,0,lines-1,(int (*)(void *,void *))(wordcmp));
	Writelines(lineptr,lines);
}
void as_order(char *lineptr[],int lines)
{
	qsort((void **)lineptr,0,lines-1,(int (*)(void *,void *))(strcmp));
	Writelines(lineptr,lines);
}


/*Programming Exercise11-11*/
/*
#include<stdio.h>
#include<ctype.h>
int word_count(char *s);
int upper_count(char *s);
int lower_count(char *s);
int punct_count(char *s);
int digit_count(char *s);
int isword(char *s);
#define SIZE 100
main()
{
	int c;
	char s[SIZE];
	int i=0;
	int nword,nupper,nlower,npunct,ndigit;
	nword=nupper=nlower=npunct=ndigit=0;
	printf("Please input a string\n");	
	while((c=getchar())!=EOF&&c!='\n')
	{
		s[i]=c;
		i++;
	}
	s[i]='\0';
	printf("输入的字符串：%s\n",s);
	nword=word_count(s);
	nupper=upper_count(s);
	nlower=lower_count(s);
	npunct=punct_count(s);
	ndigit=digit_count(s);
	printf("words:%d\n",nword);
	printf("upper-case:%d\n",nupper);
	printf("lower-case:%d\n",nlower);
	printf("punctuation:%d\n",npunct);
	printf("digit:%d\n",ndigit);
	
}
#define OUT 0
#define IN 1
int word_count(char *s)
{
	int i=0;
	int count=0;
	int state=OUT;
	while(s[i]!='\0'&&s[i]==' ')
		i++;
	while(s[i]!='\0')
	{
		if((ispunct(s[i])&&s[i]!='-')||isblank(s[i])||s[i]=='\n')
			state=OUT;
		else if(state==OUT&&!isdigit(s[i]))
		{
			state=IN;
			count++;
		}
		i++;

	}
	return count;

}
int upper_count(char *s)
{
	int i=0;
	int count=0;
	while(s[i]!='\0')
	{
		if(isupper(s[i]))
			count++;
		i++;
	}
	return count;
}
int lower_count(char *s)
{
	int i=0;
	int count=0;
	while(s[i]!='\0')
	{
		if(islower(s[i]))
			count++;
		i++;
	}
	return count;
}
int punct_count(char *s)
{
	int i=0;
	int count=0;
	while(s[i]!='\0')
	{
		if(ispunct(s[i]))
			count++;
		i++;
	}
	return count;
}
int digit_count(char *s)
{
	int i=0;
	int count=0;
	while(s[i]!='\0')
	{
		if(isdigit(s[i]))
			count++;
		i++;
	}
	return count;
}

/*Programming Exercise11-12*/
/*
#include<stdio.h>
int main(int argc,char *argv[])
{
	int i=argc;
	while(i-->1)
		argv++;//首先把指针移动到倒数第二个位置
	while(argc-->1)
		printf("%s ",*argv--);//逆序打印但是不能打印argv[0]
	printf("\n");
}

/*Programming Exercise11-13*/
/*
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	double base,power,temp=1,result=1;//必须有初值
	base=atof(argv[1]);
	power=atof(argv[2]);
	if(power==0)
		result=1;
	else if(power<0)
	{
		power=-power;//为了递减，需要变成正数
		while(power-->0)
			temp*=base;
		result=1/temp;
	}
	else
		while(power-->0)
			result*=base;
	printf("%.3f^%.3f=%.3f\n",base,power,result);
}


/*Programming Exercise11-14*/
/*
#include<stdio.h>
#include<ctype.h>
#define SIZE 100
int myatoi(char *s);
main()
{
	int num,c,i=0;
	char s[SIZE];
	printf("Please input a string\n");
	while((c=getchar())!='\n')
	{
		s[i]=c;
		i++;
	}
	s[i]='\0';
	printf("the int number: \n");
	if(num=myatoi(s))
		printf("%d\n",num);
	else
		printf("the string is not a int number!\n");
}

int myatoi(char *s)
{
	int sign=1;
	int i=0;
	int n=0;
	if(s[i]=='-')
	{
		sign=-1;
		i++;//只有当s[0]是负号的时候才跳过
	}
	else
		sign=1;//否则仍让从s[0]开始
	
	while(s[i]!='\0')
	{
		if(isdigit(s[i]))	
		{
			n=n*10+s[i]-'0';
		}
		else
			return 0;
		i++;
	}
	return n*sign;

}

/*Programming Exercise11-15*/
#include<stdio.h>
#include<ctype.h>	
#define SIZE 1000
int main(int argc,char *argv[])
{
	int c,i=0;
	char s[SIZE];
	char *p;
	while((c=getchar())!=EOF)
	{
		s[i]=c;
		i++;
	}
	s[i]='\0';
	p=s;
	//printf("%c %c\n",*argv[1],*(argv[1]+1));
	if(argc>1&&*argv[1]=='-')
	{
		if(*(argv[1]+1)=='p')
		{
			printf("按照原样输出：\n");
			while(*p!='\0')
				putchar(*p++);

		}	
		else if(*(argv[1]+1)=='u')
		{
			printf("全部转换为大写字母：\n");
			while(*p!='\0')
				putchar(toupper(*p++));

		}
		else if(*(argv[1]+1)=='l')
		{
			printf("全部转换为大写字母：\n");
			while(*p!='\0')
				putchar(tolower(*p++));
		}
		else
			printf("Only -p,-l,-u please!\n");
	}
	else
		printf("请输入命令行参数-p,-l,-u\n");
}
























