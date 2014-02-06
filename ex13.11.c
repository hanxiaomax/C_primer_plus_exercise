/*Programming Exercise13-1*/
/*
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main()
{
	int ch;
	FILE *fp;
	long count=0;
	char filename[SIZE];
	printf("Please input filename.\n");
	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("error:can not open %s\n",filename);
		exit(1);
	}
	while((ch=getc(fp))!=EOF)
	{
		if(ch=='\n')//结尾处有一个换行符，需要打印
			printf("\\n");
		putc(ch,stdout);
		count++;
	}
	fclose(fp);
	printf("file %s has %ld characters\n",filename,count);
	return 0;
}
/*Programming Exercise13-2*/
/*
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int ch;
	FILE *fp1,*fp2;
	if(argc!=3)
	{
		printf("useage:program sourcefile targetfile\n");
		exit(1);
	}
	fp2=fopen(argv[2],"wb");//以w打开会清空原有数据，w+是更新模式
	if((fp1=fopen(argv[1],"rb"))==NULL)//二进制模式
	{
		printf("%s does not exist\n",argv[1]);
		exit(2);
	}
	while((ch=getc(fp1))!=EOF)
		putc(ch,fp2);
	fclose(fp1);
	fclose(fp2);
	printf("%s has been coyied to %s\n",argv[1],argv[2]);
	return 0;
}

/*getc和putc与getchar和putchar非常类似，不过getc和putc需要文件指针作为参数*/

/*Programming Exercise13-3*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 50
int main()
{
	int ch;
	FILE *fp1,*fp2;
	char filename1[SIZE],filename2[SIZE];
	printf("sourcefile:");
	gets(filename1);
	printf("targetfile:");
	gets(filename2);
	fp2=fopen(filename2,"w");
	if((fp1=fopen(filename1,"r"))==NULL)
	{
		printf("%s does not exist\n",filename1);
		exit(2);
	}
	while((ch=getc(fp1))!=EOF)
		putc(toupper(ch),fp2);
	fclose(fp1);
	fclose(fp2);
	printf("%s has been coyied to %s\n",filename1,filename2);
	return 0;
}

/*Programming Exercise13-4*/
/*
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int ch,i;
	FILE *fp;
	if(argc<=1)
	{
		printf("useage:program sourcefile targetfile\n");
		exit(1);
	}
	for(i=1;i<=argc-1;i++)//argc=4 argv[1],argv[2],argv[3]
	{
		if((fp=fopen(argv[i],"r"))==NULL)//二进制模式
		{
			printf("%s does not exist\n",argv[i]);
			exit(2);
		}
		else
		{
			printf("%s:\n",argv[i]);
			while((ch=getc(fp))!=EOF)
				putchar(ch);
		}
		printf("\n");
		fclose(fp);
	}
	return 0;
}

/*Programming Exercise13-5*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source,FILE *dest);
int main(int argc,char *argv[])
{
	FILE *fs,*fa;
	int files=0;
	char *file_tar=argv[1];
	char *file_src;
	int i;
	printf("destination file: %s\n",argv[1]);
	if((fa=fopen(file_tar,"a"))==NULL)
	{
		fprintf(stderr,"Can't open %s\n",file_tar);
		exit(2);
	}
	if(setvbuf(fa,NULL,_IOFBF,BUFSIZE)!=0)
	{
		fputs("Can't create output buffer\n",stderr);
		exit(3);
	}
	
	for(i=2;i<argc;i++)
	{
		file_src=argv[i];
		printf("source file %d: %s \n",i-1,file_src);
		if(strcmp(file_src,file_tar)==0)
			fputs("Cant append file to itself\n",stderr);	
		else if((fs=fopen(file_src,"r"))==NULL)
			printf("Cant open %s ",file_src);
		else
		{
			if(setvbuf(fs,NULL,_IOFBF,BUFSIZE)!=0)
			{
				fputs("Cant create input buffer\n",stderr);
				continue;
			}
			append(fs,fa);
			if(ferror(fs)!=0)
				fprintf(stderr,"Error in reading file %s.\n",file_src);
			if(ferror(fa)!=0)
				fprintf(stderr,"Error in writing file %s.\n",file_tar);
			fclose(fs);
			
		}
	}
	printf("Done.%d files appended.\n",argc-2);
	fclose(fa);
	return 0;		
}
void append(FILE *source,FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];
	while((bytes=fread(temp,sizeof(char),BUFSIZE,source))>0)
		fwrite(temp,sizeof(char),bytes,dest);
}

/*Programming Exercise13-6*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
int main()
{
	FILE *in,*out;
	int ch;
	char name[LEN];//压缩后的文件名
	char file_src[LEN];//原始文件名
	int count=0;
	printf("Please input the source file name: ");
	gets(file_src);
	if((in=fopen(file_src,"r"))==NULL)
	{
		fprintf(stderr,"I couldn't open the file \"%s\"\n",file_src);
		exit(1);
	}
	strcpy(name,file_src);
	strcat(name,".red");
	if((out=fopen(name,"w"))==NULL)
	{
		fprintf(stderr,"I create the output file \"%s\"\n",name);
		exit(2);
	}
	while((ch=getc(in))!=EOF)
		if(count++%3==0)
			putc(ch,out);
	fclose(in);
	fclose(out);
	printf("Done.\"%s\" has been created\n",name);
}


/*Programming Exercise13-7*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 200
FILE *fp1,*fp2,*fp;
int ch1,ch2;
void a_fun(void);
void b_fun(void);
int main()
{
	char filename1[SIZE],filename2[SIZE];
	char filename[]="store";
	int num;
	//读取两个文件名
	printf("file 1:");
	gets(filename1);
	printf("file 2:");
	gets(filename2);

	if((fp1=fopen(filename1,"r"))==NULL)
	{
		printf("%s does not exist\n",filename1);
		exit(1);
	}
	if((fp2=fopen(filename2,"r"))==NULL)
	{
		printf("%s does not exist\n",filename2);
		exit(2);
	}
	//用来存储结果
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("%s does not exist\n",filename);
		exit(3);
	}
	printf("-------------------------\n");
	printf("1.a\n2.b\n");
	printf("-------------------------\n");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
				a_fun();
				break;
		case 2:
				b_fun();
				break;
		default:
				printf("I cant do it my lord\n");
				break;
	}
	return 0;
}
void a_fun(void)
{	
	ch1=getc(fp1);
	ch2=getc(fp2);
	while (ch1 != EOF || ch2 != EOF)
    	{
        	while (ch1!=EOF&&ch1!='\n') 
       		{
            		putc(ch1,fp);
            		ch1 = getc(fp1);
       		}
        	if (ch1!=EOF)//当ch为当前行的换行符，但不是EOF时
        	{
            		putc('\n',fp);//添加一个换行符
            		ch1=getc(fp1);//读取下一行的首字符（就是下一个字符）
        	}
        	while (ch2!= EOF&&ch2!='\n')
        	{
            		putc(ch2,fp);
            		ch2 = getc(fp2);
        	}
       	 	if (ch2!=EOF)
        	{
            		putc('\n',fp);
            		ch2 = getc(fp2);
        	}
   	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp);
	return;
}

void b_fun(void)
{
	ch1=getc(fp1);
	ch2=getc(fp2);
	while (ch1!=EOF||ch2!=EOF)
    {
        	while (ch1!=EOF&&ch1!='\n') 
       		{
            		putc(ch1,fp);
            		ch1=getc(fp1);
       		}
        	while (ch2!=EOF&&ch2!='\n')
        	{
            		putc(ch2,fp);
            		ch2=getc(fp2);
        	}
			putc('\n',fp);
       	 	ch1=getc(fp1);
			ch2=getc(fp2);
   	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp);
	return;
}
/*Programming Exercise13-8*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c_in_file(char ,FILE *);
int main(int argc,char *argv[])
{
	char ch;//字符
	FILE *fp;
	int num;
	int files=argc-2;
	int i;
	if(argc<2)
		puts("Useage:程序 字符 文件(可选)\n");
	if(strlen(argv[1])>1)
	{
		printf("only 1 charactor\n");
		exit(1);
	}
	else
		ch=*argv[1];
	if(argc<3)
	{
		printf("Not appoint to any user-files\n");
		printf("open stdin file...\n");
		num=c_in_file(ch,stdin);
		printf("there are %d %c in stdin file",num,ch);
	}
	else
	{
		for(i=2;i<argc;i++)
		{
			printf("Search %c in :",ch);
			printf("%s\t",argv[i]);
			if((fp=fopen(argv[i],"r"))==NULL)//读取输入文件
			{
				printf("error:can not open %s!",argv[i]);
				exit(3);
			}
			num=c_in_file(ch,fp);
			printf("there are %d %c in %s file\n",num,ch,argv[i]);
		}
	}
	fclose(fp);
}
int c_in_file(char ch ,FILE *fp)
{
	int count=0;
	int c;
	while((c=getc(fp))!=EOF)
	{	
			if(c==ch)
				count++;
	}
	return count;
}
/*Programming Exercise13-9*/
/*
#include<stdio.h>
#include<stdlib.h>
#define MAX 40	
int main(void)
{
	FILE *fp;
	char words[MAX];
	int i=0;
	if((fp=fopen("word list","a+"))==NULL)
	{
		fprintf(stdout,"Cant open \"words\" file.\n");
		exit(1);
	}
	//计算当前文件中单词个数
	rewind(fp);
    while (fgets(words, MAX-1, fp) != NULL)//fp会不断后退
    	i++;
    rewind(fp);//fp回滚到文件开头，因为是a+模式，所以仍然是追加

	puts("Enter words to add to the file: press the Enter");
	puts("Key at the beginning of a line to terminate.");
	while(gets(words)!=NULL&&words[0]!='\0')//一次输入一个单词
		fprintf(fp,"%d:%s\n",++i,words);
    puts("File contents:");
    rewind(fp);          
    while (fgets(words, MAX - 1, fp) != NULL)
    	fputs(words, stdout);
    if (fclose(fp) != 0)
		fprintf(stderr,"Error closing file\n");
    return 0;
}

/*Programming Exercise13-10*/
/*
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int main()
{
	FILE *fp;
	char filename[SIZE];
	int n,c;
	int last;
	printf("Please input the file name\n");
	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("error:can not open %s\n",filename);
		exit(1);
	}
	else
		printf("%s has been opened\n",filename);
	printf("where do you want to start : ");
	fseek(fp,0,SEEK_END);//fseek负责移动指针
	last=ftell(fp);//ftell函数返回文件当前位置
	while(scanf("%d",&n)==1&&n<last)
	{
		fseek(fp,n,SEEK_SET);
		while((c=getc(fp))!='\n'&&c!=EOF)
			putchar(c);
		printf("\nwhere do you want to start : ");
	}
	printf("OVER!\n")
	return 0;

}

/*Programming Exercise13-11*/
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define BUFSIZE 500
int main(int argc,char *argv[])
{
	FILE *fp;
	char buf[BUFSIZE];//字符串缓冲数组
	if(argc!=3)
	{
		printf("Useage:./program \"string\" filename\n");
		exit(1);
	}
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("Can not open %s\n",argv[2]);
		exit(2);
	}
	printf("The following linse contains \"%s\"\n\n",argv[1]);
	while(fgets(buf,BUFSIZE-1,fp))
	{
		if((strstr(buf,argv[1]))!=NULL)
			fputs(buf,stdout);
	}
	fclose(fp);
}

/*Programming Exercise13-12*/
#include<stdio.h>
#define COLS 30
#define ROWS 20
#define SYBOSIZE 10
#define SIZE 20
const char symbo[SYBOSIZE]=" .':~*=&%#";
void init(char pic[][COLS],int src[][COLS]);
void gen_pic(char pic[][COLS])
int main()
{
	FILE *fp;
	char filename[SIZE];
	char pic[ROWS][COLS];
	int number[ROWS*ROLS];
	printf("Please input filename\n");
	gets(filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("Can not open %s\n",filename);
		exit(1);
	}
	



}












