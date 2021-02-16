#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_board(char board[][COLS], char set)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

//void disp_board(char board[][COLS])
//{
//	for (int i = 0; i <= ROW; i++)
//	{
//		printf(" %d", i);
//	}
//	printf("\n");
//	for (int i = 1; i <= ROW; i++)
//	{
//		printf(" %d", i);
//		for (int j = 1; j <= COL; j++)
//		{
//			printf(" %c", board[i][j]);
//		}
//		printf("\n");
//	}
//}

void disp_board(char board[][COLS])//显示棋盘
{
	printf("  y→\nX 0 ");
	for (int i = 1; i <= COL; i++)
	{
		printf(" %2d ", i);
	}
	printf("\n");
	for (int i = 0; i < ROW; i++)
	{
		if (i == 0)
		{
			printf("↓  ");
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
					printf(" ---");
				else
					printf("----");
			}
			printf("\n");
		}
		printf(" %2d ", i + 1);
		for (int j = 0; j < COL; j++)
		{
			if (j == 0)
			{
				printf("|");
			}
			printf(" %c |", board[i + 1][j + 1]);
		}
		printf("\n");
		printf("    ");
		if (i < ROW - 1)
		{
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
				{
					printf("|");
				}
				printf("---|");
			}
			printf("\n");
		}
		else
		{
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
					printf(" ---");
				else
					printf("----");
			}
			printf("\n");
		}
	}
}

void setmine(char board[][COLS])
{
	int x, y;
	int count = NUMBER;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if ('0' == board[x][y])
		{
			board[x][y] = '*';
			count--;
		}
	}
}

int getmine(char board[][COLS], int x, int y)
{
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if ('*' == board[i][j])
			{
				count++;
			}
		}
	}
	return count;
}

void blooming(char mine[][COLS], char show[][COLS], int x, int y)
{
	int n;
	show[x][y] = ' ';
	for (int i = x - 1; i <= x + 1; i++)
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (S == show[i][j] && 1 <= i && i <= ROW && 1 <= j && j <= COL)
			{
				if (!(n = getmine(mine, i, j)))
				{
					blooming(mine, show, i, j);
				}
				else
				{
					show[i][j] = '0' + n;
				}
			}
		}
	}
}

int is_win(char board[][COLS])
{
	int count = 0;
	for (int i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= COL; j++)
		{
			if (S == board[i][j])
			{
				count++;
			}
		}
	}
	if (NUMBER == count)
	{
		for (int i = 1; i <= ROW; i++)
		{
			for (int j = 1; j <= COL; j++)
			{
				if (S == board[i][j])
				{
					board[i][j] = '*';
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void last_disp_board(char mine[][COLS], char board[][COLS])
{
	for (int i = 0; i <= COL; i++)
	{
		printf("  %d ", i);
	}
	printf("\n");
	for (int i = 0; i < ROW; i++)
	{
		if (i == 0)
		{
			printf("    ");
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
					printf(" ---");
				else
					printf("----");
			}
			printf("\n");
		}
		printf("  %d ", i + 1);
		for (int j = 0; j < COL; j++)
		{
			if (j == 0)
			{
				printf("|");
			}
			if (S == board[i + 1][j + 1] || '*' == board[i + 1][j + 1])
			{
				if ('*' == mine[i + 1][j + 1])
				{
					if ('*' == board[i + 1][j + 1])
					{
						printf("[*]|");
					}
					else
					{
						printf(" * |");
					}
				}
				else
				{
					printf("   |");

				}
			}
			else
			{
				printf(" %c |", board[i + 1][j + 1]);
			}
		}
		printf("\n");
		printf("    ");
		if (i < ROW - 1)
		{
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
				{
					printf("|");
				}
				printf("---|");
			}
			printf("\n");
		}
		else
		{
			for (int j = 0; j < COL; j++)
			{
				if (j == 0)
					printf(" ---");
				else
					printf("----");
			}
			printf("\n");
		}
	}
}

void searchmine(char mine[][COLS], char show[][COLS])
{
	char ch;
	int x, y;
	int ret = 0;
	while (!ret)
	{
		printf("请输入要排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if (1 <= x && x <= ROW && 1 <= y && y <= COL)
		{
			if ('*' == mine[x][y])
			{
				show[x][y] = '*';
				last_disp_board(mine, show);
				printf("很遗憾，你被炸死了！\n");
				break;
			}
			else if (S != show[x][y])
			{
				printf("该坐标已排查，请重新输入！\n");
			}
			else
			{
				int n = getmine(mine, x, y);
				if (!n)
				{
					blooming(mine, show, x, y);
				}
				else
				{
					show[x][y] = '0' + n;
				}
				ret = is_win(show);
				disp_board(show);
			}
		}
		else
		{
			while (ch = getchar() != '\n')
			{

			}
			printf("输入坐标非法，请重新输入！\n");
		}
	}
	if (ret)
	{
		printf("恭喜你，排雷成功！\n");
	}
}