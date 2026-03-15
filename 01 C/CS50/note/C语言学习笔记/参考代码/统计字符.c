#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// 编写程序，实现以下功能：
// 	 编写一个函数，用于统计一个字符串中字母、数字、空格和其他字符的个数。
//	 在主函数中输入该字符串后，调用上述函数，并输出统计结果，要求用指针实现。
// 	 如：字符串"a1! B@2 c3 # &"，
//	 输出结果为：字母有3个，数字有3个，空格有4个，其他字符4个


void count(char* ch)
{
	int cnt_word = 0;
	int cnt_blank = 0;
	int cnt_num = 0;
	int cnt_other = 0;

	for (int i = 0; *(ch + i) != '\0'; i++)
	{
		if ('A' <= *(ch + i) && *(ch + i) <= 'Z' || 'a' <= *(ch + i) && *(ch + i) <= 'z')
		{
			cnt_word++;
		}
		else if ('0' <= *(ch + i) && *(ch + i) <= '9')
		{
			cnt_num++;
		}
		else if (*(ch + i) == ' ')
		{
			cnt_blank++;
		}
		else
			cnt_other++;

	}

	printf("该字符串中字母有%d个\n", cnt_word);
	printf("该字符串中空格有%d个\n", cnt_blank);
	printf("该字符串中数字有%d个\n", cnt_num);
	printf("该字符串中其他字符有%d个\n", cnt_other);
}


int main()
{
	char ch[100] = "ymrYJ\t156  ";

	count(ch);
}



