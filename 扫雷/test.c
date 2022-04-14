#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("******* 1.play *******\n");
	printf("******* 2.exit *******\n");
	printf("**********************\n");
}
void game()
{
	char Myboard[ROWS][COLS] = { 0 };
	char Showboard[ROWS][COLS] = { 0 }; 
	//初始化棋盘
	InitBoard(Myboard, ROWS, COLS,'0');
	InitBoard(Showboard, ROWS, COLS,'*');
	//打印棋盘
	PrintBoard(Showboard, ROW, COL);
	//布置雷
	SetMyboard(Myboard, ROW, COL);
	//排雷
	FindMyboard(Myboard, Showboard, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}