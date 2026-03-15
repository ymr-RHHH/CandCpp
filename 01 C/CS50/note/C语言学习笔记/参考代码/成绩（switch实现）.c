#include<stdio.h>
int main()
{
	while (1)
	{
		int score = 0;
		scanf("%d", &score);
		if (0 <= score && 100 >= score)
		{
			short level = score / 10;
			switch (level)
			{
			case 10:
			case 9:
				printf("优秀\n");
				break;
			case 8:
				printf("良好\n");
				break;
			case 7:
			case 6:
				printf("及格\n");
				break;
			default:
				printf("不及格\n");
			}
		}
		else printf("你输入的成绩有误，请重新输入\n");
	}
}