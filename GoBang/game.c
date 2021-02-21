#include "game.h"

void disp_marks()
{
	printf("***************************************************\n");
	printf("*** 1.X  2.O  3.#  4.*  5.$  6.%%  7.@  8.!  9.& ***\n");
	printf("***************************************************\n");
}

char sel_playermark()
{
	int input, ch;
	char marks[] = { 'X', 'O', '#', '*', '$', '%', '@', '!', '&' };
	while (1)
	{
		disp_marks();
		printf("请选择属于自己的记号:>");
		scanf("%d", &input);
		if (1 <= input && input <= 9)
			break;
		else
		{
			while (ch = getchar() != '\n')
			{

			}
			printf("输入非法，请重新选择！\n");
		}
	}
	return marks[input - 1];
}

char sel_computermark(char P)
{
	int input, ch;
	char marks[] = { 'X', 'O', '#', '*', '$', '%', '@', '!', '&' };
	while (1)
	{
		disp_marks();
		printf("请选择属于电脑的记号:>");
		scanf("%d", &input);
		if (1 <= input && input <= 9)
		{
			if (marks[input - 1] == P)
				printf("不能选择与玩家相同的记号！\n");
			else
				break;
		}
		else
		{
			while (ch = getchar() != '\n')
			{

			}
			printf("输入非法，请重新选择！\n");
		}
	}
	return marks[input - 1];
}

void init_board(char board[ROW][COL])//初始化棋盘
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//void disp_board(char board[ROW][COL])//显示棋盘
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		if (i == 0)
//		{
//			for (int j = 0; j < COL; j++)
//			{
//				if (j == 0)
//					printf(" ---");
//				else
//					printf("----");
//			}
//			printf("\n");
//		}
//		for (int j = 0; j < COL; j++)
//		{
//			if (j == 0)
//			{
//				printf("|");
//			}
//			printf(" %c |", board[i][j]);
//		}
//		printf("\n");
//		if (i < ROW - 1)
//		{
//			for (int j = 0; j < COL; j++)
//			{
//				if (j == 0)
//				{
//					printf("|");
//				}
//				printf("---|");
//			}
//			printf("\n");
//		}
//		else
//		{
//			for (int j = 0; j < COL; j++)
//			{
//				if (j == 0)
//					printf(" ---");
//				else
//					printf("----");
//			}
//			printf("\n");
//		}
//	}
//}

void disp_board(char board[ROW][COL])//显示棋盘
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
			printf(" %c |", board[i][j]);
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

char who_first()//选择是否先下
{
	char input;
	while (1)
	{
		printf("您是否要先下【是[Y]/否[N]】:>");
		getchar();
		scanf("%c", &input);
		if ('y' == input || 'Y' == input)
			return 'Y';
		if ('n' == input || 'N' == input)
			return 'N';
		printf("输入非法，请重新选择！\n");
	}
}

char is_over(char board[ROW][COL], int x, int y, char S)
{
	//横向（先左后右）
	int count = 1;
	for (int i = 1; i < 5; i++)
	{
		if (x - i < 0 || S != board[x - i][y])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count) 
	{
		return S;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x + i > ROW - 1 || S != board[x + i][y])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	//纵向（先上后下）
	count = 1;
	for (int i = 1; i < 5; i++)
	{
		if (y - i < 0 || S != board[x][y - i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	for (int i = 1; i < 5; i++)
	{
		if (y + i > COL - 1 || S != board[x][y + i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	//"\"向
	count = 1;
	for (int i = 1; i < 5; i++)
	{
		if (x - i < 0 || y - i < 0 || S != board[x - i][y - i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count) 
	{
		return S;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x + i > ROW - 1 || y + i > COL - 1 || S != board[x + i][y + i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	//"/"向
	count = 1;
	for (int i = 1; i < 5; i++)
	{
		if (x + i > ROW - 1 || y - i < 0 || S != board[x + i][y - i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	for (int i = 1; i < 5; i++)
	{
		if (x - i < 0 || y + i > COL - 1 || S != board[x - i][y + i])
		{
			break;
		}
		else
		{
			count++;
		}
	}
	if (5 <= count)
	{
		return S;
	}
	static int times = ROW * COL;
	if (!(--times))
	{
		return '=';
	}
	return 'c';
}

char playermove(char board[ROW][COL], char P)
{
	int x, y;
	char ch, ret;
	printf("玩家走:>\n");
	while (1)
	{
		printf("请输入要下的坐标:>");
		scanf("%d%d", &x, &y);
		if (1 <= x && x <= ROW && 1 <= y && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = P;
				disp_board(board);//显示棋盘
				ret = is_over(board, x - 1, y - 1, P);//是否结束
				return ret;
			}
			printf("该坐标已被占用！\n");
		}
		else
			while (ch = getchar() != '\n')
			{

			}
		printf("输入坐标非法，请重新输入！\n");
	}
}

char computermove(char board[ROW][COL], char C)
{
	int x, y;
	char ret;
	printf("电脑走:>\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = C;
			disp_board(board);//显示棋盘
			ret = is_over(board, x, y, C);//是否结束
			return ret;
		}
	}
}

//char is_over(char board[ROW][COL])
//{
//	for (int i = 0; i < ROW; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//			return board[i][1];
//	}
//	for (int i = 0; i < COL; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
//			return board[1][i];
//	}
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//		return board[1][1];
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
//		return board[1][1];
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			if (board[i][j] == ' ')
//				return 'c';
//		}
//	}
//	return '=';
//}


void start_game(char board[ROW][COL], char input, char P, char C)
{
	char ret;
	if (input == 'Y')
	{
		while (1)
		{
			ret = playermove(board, P);//玩家走
			//disp_board(board);//显示棋盘
			//ret = is_over(board);//是否结束
			if (ret != 'c')
				break;
			ret = computermove(board, C);//电脑走
			//disp_board(board);
			//ret = is_over(board);
			if (ret != 'c')
				break;
		}
		if (P == ret)
			printf("你获胜！\n");
		else if (C == ret)
			printf("电脑获胜\n");
		else
			printf("平局\n");
	}
	else
	{
		while (1)
		{
			ret = computermove(board, C);//电脑走
			//disp_board(board);//显示棋盘
			//ret = is_over(board);//是否结束
			if (ret != 'c')
				break;
			ret = playermove(board, P);//玩家走
			//disp_board(board);
			//ret = is_over(board);
			if (ret != 'c')
				break;
		}
		if (P == ret)
			printf("你获胜！\n");
		else if (C == ret)
			printf("电脑获胜\n");
		else
			printf("平局\n");
	}
}