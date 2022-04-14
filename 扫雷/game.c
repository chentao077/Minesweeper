#include"game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for ( i = 0; i < rows; i++)
	{
		for ( j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for ( i = 0; i < row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for ( i = 1; i < row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for ( j = 1; j < col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMyboard(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int get_myboard_count(char mime[ROWS][COLS], int x, int y)
{
		return mime[x - 1][y - 1] +
			mime[x - 1][y] +
			mime[x - 1][y + 1] +
			mime[x][y - 1] +
			mime[x][y + 1] +
			mime[x + 1][y - 1] +
			mime[x + 1][y] +
			mime[x + 1][y + 1] -8 * '0';
}
void FindMyboard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ���׵�����:");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//1.����
			if (mine[x][y] == '1')
			{
				printf("������ˣ���Ϸ����\n");
				PrintBoard(mine, row, col);
				break;
			}
			//û�в���
			else
			{
				//������Χ8���׵ĸ���
				int count = get_myboard_count(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
		PrintBoard(mine, row, col);
	}
}