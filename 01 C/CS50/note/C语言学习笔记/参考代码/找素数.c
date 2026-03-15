
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
//使用循环和分支结构判断一个数是否为素数。
//（1不是素数，素数是指大于1的自然数，除了1和该数自身外，无法被其他自然数整除的数。）

int main()
{
	while (1)
	{

		int a, flag = 1;  //flag用于将不是素数的数字从for循环中拿出去
		scanf("%d", &a);
		if (a > 1)
		{
			int i = 0;
			for (i = 2; i <= sqrt((double)a); ++i)
			{
				if (a % i == 0)
				{
					printf("这不是素数\n");
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				printf("这是素数\n");
			}
		}
		else
		{
			printf("请输入一个大于1的自然数");
		}
	}
}