#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu1()
{
	printf("*******************************************\n");
	printf("****** 欢 迎 进 入 “ 扫 雷 ” 游 戏 ******\n");
	printf("*******************************************\n");
	printf("*******  1.开始游戏     0.退出游戏  *******\n");
	printf("*******************************************\n");
}

void menu2()
{
	printf("*******************************************\n");
	printf("****** 感 谢 支 持 “ 扫 雷 ” 游 戏 ******\n");
	printf("*******************************************\n");
	printf("*******  1.再来一局     0.退出游戏  *******\n");
	printf("*******************************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	init_board(mine, '0');
	char show[ROWS][COLS] = { 0 };
	init_board(show, S);
	disp_board(show);
	setmine(mine);
	disp_board(mine);
	searchmine(mine, show);
}

void test()
{
	int input;
	char ch;
	srand((unsigned int)time(NULL));
	menu1();
	do
	{
		printf("请选择(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			return;
		default:
			while (ch = getchar() != '\n')
			{

			}
			printf("输入非法，请重新选择！\n");
			break;
		}
		menu2();
	} while (1);
}

int main()
{
	test();
	return 0;
}