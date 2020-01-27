#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX_COL 3
#define MAX_ROW 3
int menu()
{
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	int ret;
	scanf("%d", &ret);
	return ret;
}
void init(char chess[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess[row][col] = ' ';
		}
	}
}
void printChessBoard(char chess[MAX_ROW][MAX_COL])
{
	printf(" | 1 | 2 | 3 |\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" +---+---+---+\n");
		printf("%d| %c | %c | %c |\n", row+1,chess[row][0],
			chess[row][1], chess[row][2]);
	}
	printf(" +---+---+---+\n");
}
void PlayerMove(char chess[MAX_ROW][MAX_COL])
{
	printf("�ֵ��������!\n");
	while (1) {
		printf("��������Ҫ����λ�õ�����(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row< 1 || row >= MAX_ROW+1
			|| col < 1 || col >= MAX_COL+1) {
			printf("�������뷶Χ����! \n");
			continue;
		}
		if (chess[row-1][col-1] != ' ') {
			printf("��λ���Ѿ�������!\n");
			continue;
		}
		chess[row-1][col-1] = 'X';
		break;
	}
}

void ComputerMove(char chess[MAX_ROW][MAX_COL])
{
	printf("�ֵ���������!\n");
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess[row][col] != ' ') {
			continue;
		}
		chess[row][col] = 'O';
		break;
	}
}
int IsFull(char chess[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chess[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
char Check(char chess[MAX_ROW][MAX_COL])
{
	for (int row = 0; row < MAX_ROW; row++) {
		if (chess[row][0] != ' '
			&& chess[row][0] == chess[row][1]
			&& chess[row][0] == chess[row][2]) {
			return chess[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chess[0][col] != ' '
			&& chess[0][col] == chess[1][col]
			&& chess[0][col] == chess[2][col]) {
			return chess[0][col];
		}
	}
	if (chess[0][0] != ' '
		&& chess[0][0] == chess[1][1]
		&& chess[0][0] == chess[2][2]) {
		return chess[0][0];
	}
	if (chess[0][2] != ' '
		&& chess[0][2] == chess[1][1]
		&& chess[0][2] == chess[2][0]) {
		return chess[0][2];
	}
	if (IsFull(chess)) {
		return 'Q';
	}
	return ' ';
	return 0;
}
void Judge(char win)
{
	if (win == 'X') {
		printf("��ϲ�ɺأ���ϲ�ɺ�!\n");
	}
	else if (win == 'O') {
		printf("����ʤ��!\n");
	}
	else {
		printf("ƽ��!\n");
	}
}
void game()
{
	char chess[MAX_ROW][MAX_COL] = {0};
	init(chess);
	char win = ' ';
	srand((unsigned int)time(0));
	while (1)
	{
		printChessBoard(chess);
		PlayerMove(chess);
		win = Check(chess);
		if (win != ' ') {
			break;
		}
		ComputerMove(chess);
		win = Check(chess);
		if (win != ' ') {
			break;
		}
	}
	printChessBoard(chess);
	Judge(win);

}
int main()
{
	start:
		int ret = menu();
		switch (ret)
		{
		case 1: game();
		case 2: break;
		default:
		{
			printf("�������\n");
			goto start;
		}
		}
	return 0;
}