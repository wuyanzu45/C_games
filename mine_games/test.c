#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu1()
{
	printf("*******************************************\n");
	printf("****** �� ӭ �� �� �� ɨ �� �� �� Ϸ ******\n");
	printf("*******************************************\n");
	printf("*******  1.��ʼ��Ϸ     0.�˳���Ϸ  *******\n");
	printf("*******************************************\n");
}

void menu2()
{
	printf("*******************************************\n");
	printf("****** �� л ֧ �� �� ɨ �� �� �� Ϸ ******\n");
	printf("*******************************************\n");
	printf("*******  1.����һ��     0.�˳���Ϸ  *******\n");
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
		printf("��ѡ��(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			return;
		default:
			while (ch = getchar() != '\n')
			{

			}
			printf("����Ƿ���������ѡ��\n");
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