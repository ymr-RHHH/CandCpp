#include<stdio.h>
int main()
{
	while (1)
	{
		int score = 0;
		scanf("%d", &score);
		if (0 <= score && 100 >= score)
		{
			if (100 >= score && 90 <= score)  printf("优秀\n");
			else if (80 <= score && 89 >= score)  printf("良好\n");
			else if (60 <= score && 79 >= score)  printf("及格\n");
			else  printf("不及格\n");
		}
		else printf("你输入的成绩有误，请重新输入\n");
	}
}