#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void make_board(char **board,int size) {	// dimiourgia tou pinaka
	int i, j ;
	for ( i = 0 ; i < size ; i++ ) {
		for ( j = 0 ; j < size ; j++ ) {
			board[i][j]='.' ;
		}
	}
	return ;
}

