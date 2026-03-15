#include<stdio.h>
#include<string.h>
//利用递归方法求5！阶乘。函数体中有直接或者间接调用自身函数的情况。
#define err 0
int fac(int n)
{
	if (n > 0)
	{
		if (n == 1)
		{
			return 1;
		}
		else
		{
			return n*fac(n - 1);
		}
	}
	else
	{
		printf("请输入一个正整数\n");
		return err;
	}
}

int main()
{
	printf("%d\n", fac(-1));
}
