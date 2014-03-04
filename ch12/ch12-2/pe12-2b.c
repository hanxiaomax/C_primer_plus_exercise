#include "pe12-2a.h"
#include <stdio.h>

int prev_mode=METRIC;//储存上一个mode，文件作用域，外部链接
int main()
{
	int mode;
	double dist;
	double fuel;
	printf("Enter 0 for metric mode,1 for US mode: ");
	scanf("%d",&mode);
	while(mode>=0)
	{
		set_mode(&mode);//检查并设置合适的mode值
		get_info(mode,&dist,&fuel);//要求用户输入
		show_info(mode,dist,fuel);//计算并显示结果
		printf("Enter 0 for metric mode,1 for US mode ");
		printf("(-1 to quit):");
		scanf("%d",&mode);
	}
	printf("Done\n");
	return 0;
}