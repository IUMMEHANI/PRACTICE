#include <stdio.h>
void inputgrid(char board[3][3]);
void printgrid(char board[3][3]);
char checkwinner(char board[3][3]);
void inputgrid(char board[3][3]) {
	int i,j;
	for ( i = 0 ; i < 3 ; i++) {
		for ( j = 0 ; j < 3 ; j++) {
		printf("Enter your move: ");
		scanf(" %c" , &board[i][j]);	
		}
	}
}
void printgrid(char board[3][3]) {
	int i,j;
	int move = 0;
	printf("_____BOARD______\n");
	for ( i = 0 ; i < 3 ; i++) {
		for ( j = 0 ; j < 3 ; j++) {
		printf("%c " , board[i][j]);
		}
	printf("\n");
	}
	for ( i = 0 ; i < 3 ; i++) {
		for ( j = 0 ; j < 3 ; j++) {
			if (board[i][j] == ' ') {
				printf("Space is available at row %d column %d.\n " , i , j);
				move++;
			}
		}
	}
	printf("Available moves are %d.\n" , move);
}
char checkwinner(char board[3][3]) {
	int i,j;
	char winner = 0;
	for (i = 0 ; i < 3 ;i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' '){
			winner = board[i][0];
		}
	}
	for (j = 0 ; j < 3 ; j++){
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ') {
			winner = board[0][j];	
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2]  != ' ') {
		winner = board[0][2];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0]  != ' ') {
		winner = board[0][0];
	}
	return winner;
}
int main() {
	char board[3][3];
	char winner;
	inputgrid(board);
	printgrid(board);
	winner = checkwinner(board);
	if (winner == 'x'){
		printf("X is winner.\n");
	}
	else if (winner == 'o'){
		printf("O is winner.\n");
	}
	else {
		printf("Draw.\n");
	}
	return 0;
	
}
