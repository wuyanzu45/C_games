#include "game.h"

void menu1()//�˵�
{
	printf("**********************************************\n");
	printf("****** �� ӭ �� �� �� �� �� �� �� �� Ϸ ******\n");
	printf("**********************************************\n");
	printf("********  1.��ʼ��Ϸ      0.�˳���Ϸ  ********\n");
	printf("**********************************************\n");
}
void menu2()
{
	printf("**********************************************\n");
	printf("****** �� л ֧ �� �� �� �� �� �� �� Ϸ ******\n");
	printf("**********************************************\n");
	printf("********  1.����һ��      0.�˳���Ϸ  ********\n");
	printf("**********************************************\n");
}

void game()
{
	char P, C, input;
	char board[ROW][COL] = { 0 };
	P = sel_playermark();//ѡ����ҼǺ�
	C = sel_computermark(P);//ѡ����ԼǺ�
	input = who_first();//ѡ���Ƿ�����
	init_board(board);//��ʼ������
	disp_board(board);//��ʾ����
	start_game(board, input, P, C);//��ʼ��Ϸ
}

void test()
{
	int input, ch;
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
			//printf("x:%c\n", getchar());
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			while (ch = getchar() != '\n')
			{

			}
			printf("����Ƿ���������ѡ��\n");
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
