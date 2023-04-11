#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define EMPTY 0
#define P1 1
#define P2 2
#define TIE 5
#define SPOTS 3

int boardStatus(int board[][3]);
void add(int pos1, int pos2, int *player, int board[][3]);

int main(void) {
	int currPlayer = P1;
	int pos1 = 0, pos2 = 0;
	int board[SPOTS][SPOTS];

	for (int i = 0; i < SPOTS; i++) {
		for (int j = 0; j < SPOTS; j++) {
			board[i][j] = EMPTY;
		}
	}
	printf("Welcome to Tic-Tac-Toe!\n");
	printf("Player One Starts!\n");
	while (boardStatus(board) == EMPTY)
	{
		for (int i = 0; i < SPOTS; i++) {
			printf("| ");
			for (int j = 0; j < SPOTS; j++) {
				if (board[i][j] == P1) {
					printf("X | ");
				}
				else if (board[i][j] == P2) {
					printf("O | ");
				}
				else if (board[i][j] == EMPTY) {
					printf(" | ");
				}
			}
			printf("\n");
			printf("----------\n");
		}
		printf("\n");

		if (currPlayer == P1) {
			printf("Player One, Choose your row (1-3): ");
			scanf(" %d", &pos1);
			pos1--;
			printf("Choose your column (1-3): ");
			scanf(" %d", &pos2);
			pos2--;
			add(pos1, pos2, &currPlayer, board);
		}
		else if (currPlayer == P2) {
			printf("Player Two, Choose your row (1-3): ");
			scanf(" %d", &pos1);
			pos1--;
			printf("Choose your column (1-3): ");
			scanf(" %d", &pos2);
			pos2--;
			add(pos1, pos2, &currPlayer, board);
		}
	}

	for (int i = 0; i < SPOTS; i++) {
		printf("| ");
		for (int j = 0; j < SPOTS; j++) {
			if (board[i][j] == P1) {
				printf("X | ");
			}
			else if (board[i][j] == P2) {
				printf("O | ");
			}
			else if (board[i][j] == EMPTY) {
				printf(" | ");
			}
		}
		printf("\n");
		printf("----------\n");
	}
	printf("\n");

	if (boardStatus(board) == P1) 
	{
		printf("Game Over! Player One Wins!\n");
		return P1;
	}
	else if (boardStatus(board) == P2) 
	{
		printf("Game Over! Player Two Wins!\n");
		return P2;
	}
	else {
		printf("Game Over! It's a Tie!\n");
		return TIE;
	}
}

int boardStatus(int board[][3]) {
	for (int i = 0; i < SPOTS; i++) 
	{
		if (board[i][0] == P1 && board[i][1] == P1 && board[i][2] == P1)
		{
			return P1;
		}
		else if (board[i][0] == P2 && board[i][1] == P2 && board[i][2] == P2)
		{
			return P2;
		}

		if (board[0][i] == P1 && board[1][i] == P1 && board[2][i] == P1)
		{
			return P1;
		}
		else if (board[0][i] == P2 && board[1][i] == P2 && board[2][i] == P2)
		{
			return P2;
		}

		if (board[0][0] == P1 && board[1][1] == P1 && board[2][2] == P1) {
			return P1;
		}
		else if (board[0][2] == P1 && board[1][1] == P1 && board[2][0] == P1)
		{
			return P1;
		}
		else if (board[0][0] == P2 && board[1][1] == P2 && board[2][2] == P2)
		{
			return P2;
		}
		else if (board[0][2] == P2 && board[1][1] == P2 && board[2][0] == P2)
		{
			return P2;
		}

		for (int j = 0; j < SPOTS; j++) 
		{
			if (board[i][j] == EMPTY) 
			{
				return EMPTY;
			}
		}

		

	}
	return TIE;
}

void add(int pos1, int pos2, int* player, int board[][3]) 
{
	if (board[pos1][pos2] == EMPTY) 
	{
		if (*player == P1) 
		{
			board[pos1][pos2] = P1;
			*player = P2;
		}
		else if (*player == P2) 
		{
			board[pos1][pos2] = P2;
			*player = P1;
		}
	}
	else {
		printf("Invalid spot!\n");
	}
}