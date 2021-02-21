#include "game.h"

void menu1()//菜单
{
	printf("**********************************************\n");
	printf("****** 欢 迎 进 入 “ 五 子 棋 ” 游 戏 ******\n");
	printf("**********************************************\n");
	printf("********  1.开始游戏      0.退出游戏  ********\n");
	printf("**********************************************\n");
}
void menu2()
{
	printf("**********************************************\n");
	printf("****** 感 谢 支 持 “ 五 子 棋 ” 游 戏 ******\n");
	printf("**********************************************\n");
	printf("********  1.再来一局      0.退出游戏  ********\n");
	printf("**********************************************\n");
}

void game()
{
	char P, C, input;
	char board[ROW][COL] = { 0 };
	P = sel_playermark();//选择玩家记号
	C = sel_computermark(P);//选择电脑记号
	input = who_first();//选择是否先下
	init_board(board);//初始化棋盘
	disp_board(board);//显示棋盘
	start_game(board, input, P, C);//开始游戏
}

void test()
{
	int input, ch;
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
			//printf("x:%c\n", getchar());
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			while (ch = getchar() != '\n')
			{

			}
			printf("输入非法，请重新选择！\n");
			break;
		}
		menu2();
	} while (input);
}
int main()
{
	test();
	return 0;
}
