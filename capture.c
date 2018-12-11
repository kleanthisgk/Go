// capture.c

#include "play.h"
#include <stdio.h>

int capture(char **board, int i, int j, int size ,char player) {
	int k=0, p ;								//epistrefei k=0 an den exei ginei capture
	if ( i+1 < size ) {							// elegxos gia na min bgoume ekso apo ta oria tou pinaka
		if ( (board[i+1][j] != '.') && (board[i+1][j] != player) ) {	// an to katw stoixeio den einai . i stone tou allou paixti
			if ( liberties(board,size,i+1,j,board[i+1][j]) == 0 ) {	// an oi eleutheries tou einai 0
				capture2(board,size,i+1,j,board[i+1][j]) ;	// kalese ti capture2
				k=1 ;						// epistrefei 1 an exei ginei capture mia petra i mia omada petron
			}
		}
	}
        if ( j+1 < size ) {							// i logiki einai idia
                if ( (board[i][j+1] != '.') && (board[i][j+1] != player) ) {
                        if ( liberties(board,size,i,j+1,board[i][j+1]) == 0 ) {
				capture2(board,size,i,j+1,board[i][j+1]) ;
				k=1 ;
                        }
                }
        }
        if ( i > 0 ) {
                if ( (board[i-1][j]!='.') && (board[i-1][j]!=player) ) {
                        if ( liberties(board,size,i-1,j,board[i-1][j]) == 0 ) {
				capture2(board,size,i-1,j,board[i-1][j]) ;
				k=1;
                        }
                }
        }
        if ( j > 0 ) {
                if ( (board[i][j-1] != '.' ) && (board[i][j-1] != player) ) {
                        if ( liberties(board,size,i,j-1,board[i][j-1]) == 0 ) {
				capture2(board,size,i,j-1,board[i][j-1]) ;
				k=1;
                        }
                }
        }
	return k ;
}
