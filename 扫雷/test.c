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
	//��ʼ������
	InitBoard(Myboard, ROWS, COLS,'0');
	InitBoard(Showboard, ROWS, COLS,'*');
	//��ӡ����
	PrintBoard(Showboard, ROW, COL);
	//������
	SetMyboard(Myboard, ROW, COL);
	//����
	FindMyboard(Myboard, Showboard, ROW, COL);
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}