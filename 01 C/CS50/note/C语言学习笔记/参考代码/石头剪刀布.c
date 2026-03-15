#define _CRT_SECURE_NO_WARNINGS
//编写程序，实现以下功能：
//	猜拳小游戏：石头剪刀布
//	游戏规则：石头克制剪刀，剪刀克制布，布克制石头。
//	编写玩游戏函数，实现玩家和电脑对战。
//	电脑随机出拳（运用随机函数srand()、rand()和time(NULL)产生随机数，需要包含头文件stdlib.h和time.h）；
//	玩家输入“石头 / 剪刀 / 布”进行出拳（需要定义石头剪刀布的枚举类型来记录）；
//	玩家和电脑可以循环多次猜拳，判断猜拳的结果，
//	如果玩家赢了则输出“玩家赢了”，如果玩家输了则输出“玩家输了”，如果是平局则输出“平局”。
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef enum {
	scissor,
	paper,
	stone
}play;

void write_state(const char hum[], int*h)
{
	if (strcmp(hum, "石头") == 0)
	{
		*h = stone;
	}
	if (strcmp(hum, "剪刀") == 0)
	{
		*h = scissor;
	}
	if (strcmp(hum, "布") == 0)
	{
		*h = paper;
	}
}
void print_com(const int com)
{
	switch (com)
	{
	case scissor:
		printf("电脑出的剪刀\n");
		break;
	case paper:
		printf("电脑出的布\n");
		break;
	case stone:
		printf("电脑出的石头\n");
		break;
	default:
		printf("悲催！出bug了！\n");
		break;
	}
}

void who_win(const int hum, const int com)
{
	if (hum == scissor&&com == paper ||
		hum == stone&&com == scissor ||
		hum == paper&&com == stone)
		printf("玩家赢了\n");
	if (hum == scissor&&com == scissor ||
		hum == stone&&com == stone ||
		hum == paper&&com == paper)
		printf("平局\n");
	if (com == scissor&&hum == scissor ||
		com == stone&&hum == stone ||
		com == paper&&hum == paper)
		printf("平局\n");
}


void game()
{
	int hum, com;
	char human[6];
a:
	printf("请输入 石头剪刀布\n");
	scanf("%s", &human);
	if (strcmp(human, "石头") != 0 &&
		strcmp(human, "剪刀") != 0 &&
		strcmp(human, "布") != 0)
	{
		printf("输入错误\n");
		goto a;
	}
	write_state(human, &hum);
	com = rand() % 3;
	who_win(hum, com);
	print_com(com);
}

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		char play;
		printf("年轻的少年哦，要来一场刺激的石头剪刀布小游戏吗？Y\\N\n");
		scanf("%c", &play);
		switch (play)
		{
		case 'Y':
		case 'y':
			game();
			break;
		case 'N':
		case 'n':
			goto BREAK;
			break;
		default:
			printf("小伙子，我劝你不要搞事！\n");
		}

	}
BREAK:
	return 0;
}