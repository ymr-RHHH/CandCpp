#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//如有以下定义：
//	char str[20] = “Hello World!”;
//	将此字符串存入文件”test1.txt”中，然后逆序从此文件中读取出来
//	并逆序输出。程序完成后输出结果为!dlroW olleH
int main()
{
	char str[] = "Hello World!";
	FILE* fp = fopen("text1.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return EOF;
	}
	else
	{
		printf("文件打开成功\n");
	}
	fprintf(fp, str);
	fclose(fp);

	fp = fopen("text1.txt", "r");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return EOF;
	}
	else
	{
		printf("文件打开成功\n");
	}

	for (int i = 1; i <= (sizeof(str) / sizeof(str[0])); i++)
	{
		fseek(fp, -i, SEEK_END);
		printf("%c", fgetc(fp));
	}
	printf("\n");

	fclose(fp);

}