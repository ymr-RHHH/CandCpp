#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>

 //从键盘输入若干个整数，其值在1至4范围内，用 -1作为输入结束的标志。统计每个整数的个数。
 //如：
	// 输入：1 1 2 3 3 3
	// 输出：	
	//   1出现2次
	//   2出现1次
	//   3出现3次
 //	   4出现0次
 //最好可以屏蔽违规输入

int main()
{
	int arr[4]{ 0 };
	int a = 0;
	char clear = 0;
	do
	{
		scanf("%d", &a);
		while ((clear = getchar()) == ' ');
		if (clear == '\n') break;
		ungetc(clear, stdin);

		if (1 <= a && a <= 4) arr[a - 1]++;
	} while (a != -1);

	for (int i = 0; i < 4; i++)
	{
		printf("%d出现的次数是: %d \n", i + 1, arr[i]);
	}
}

//int main()
//{
//	int num=0;
//	int cnt[5] = { 0 };
//	int j;
//	while (num !=-1)
//	{
//		if (scanf("%d", &num) != '\n')
//		{
//			if (1 <= num && num <= 4) cnt[num]++;
//			if (num == -1)
//			{
//				for (j = 1; j <= 4; j++)
//				{
//					printf("%d出现的次数是%d\n", j, cnt[j]);
//				}
//				break;
//			}
//		}
//		else break;
//	}
//	return 0;
//}  //这里暂时还没有解决如何不输入-1就能跑的问题