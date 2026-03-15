#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
//彩票系统
//（1）.编程实现生成1~36范围内任意的7个数字
//（2）.保证7个数字是不重复的。
//（3）.输入一组号码与程序生成的随机号码对比，相同中奖，不同则反之

int main()
{
	int num[7] = { 0 };
	int gus[7] = { 0 };
	int judge = 0;
	srand((unsigned int)time(NULL));
	printf("请输入1~36范围内任意的7个数字\n");
	for (int i = 0; i < 7; i++)
	{
		//先给数组num赋值
		num[i] = rand() % 36 + 1;

		//顺道输入一下gus
		scanf("%d", &gus[i]);
	}
	//去除重复元素
Else:
	for(int i=0;i<7;i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (num[i] == num[j])//如果有重复就重新赋值，重新判断
			{
				num[i] = rand() % 36 + 1;
				goto Else;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (gus[i] != num[i])
		{
			judge++;
		}
	}
	if (judge == 0)
	{
		printf("恭喜你，中奖了！\n");
	}
	else printf("悲催！！！竟然没有中奖！\n");

	printf("\n本期中奖号码是：\n");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
}