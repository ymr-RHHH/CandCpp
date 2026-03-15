#include<stdio.h>
//从键盘输入一个年份，判断其是否为闰年。

//闰年是指能被4整除并且不能被100整除（普通闰年），或者能被400整除的年份（世纪闰年），
//否则就为平年。

int main()
{
	int year = 0;
	do
	{
		scanf("%d", &year);
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			printf("这是闰年\n");
		}
		else
		{
			printf("这不是闰年\n");
		}
	} while (year);
}