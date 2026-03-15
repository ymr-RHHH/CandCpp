#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//基本数据类型作业，第13题

//编写一个程序，实现以下功能：
//从键盘输入一个小写字母，将其转换为对应的大写字母并输出。

int main()
{
	char wd = 0;
	scanf("%c", &wd);
	if (wd >= 97 || wd <= 122)
	{
		wd -= 32;
		//或者可以写成
		//wd &= 0xdf;
		printf("%c\n", wd);
	}
	else
	{
		printf("请输入小写字母\n");
	}
}

